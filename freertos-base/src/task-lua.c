#include "main.h"
#include "leds.h"
#include "usart.h"
#include "lua-functions.h"
#include "task-lua.h"
#include "task-stepmotor.h"

#include <lua.h>
#include <string.h>

#define LUA_BUFFER_LEN 256


xTaskHandle lua_handle;
xQueueHandle *_p_queue_lua_commands;


char command[MAX_STRLEN + 1];

void stack_dump (lua_State *lua_state)
{
	static char buffer[LUA_BUFFER_LEN];

	while (lua_gettop(lua_state) > 0)
	{
		/* repeat for each level */
		int t = lua_type(lua_state, 1);
		switch (t)
		{
			case LUA_TSTRING:  /* strings */
			sprintf(buffer, "`%s'", lua_tostring(lua_state, 1));
			break;

			case LUA_TBOOLEAN:  /* booleans */
			sprintf(buffer, lua_toboolean(lua_state, 1) ? "true" : "false");
			break;

			case LUA_TNUMBER:  /* numbers */
			sprintf(buffer, "%g", lua_tonumber(lua_state, 1));
			break;

			default:  /* other values */
			sprintf(buffer, "%s", lua_typename(lua_state, 1));
			break;
		}

		lua_pop(lua_state, 1);

		strncat(buffer, "\r\n", LUA_BUFFER_LEN);  /* put a separator */

		usart1_write_string(buffer);
	}
}

void task_lua(void* param)
{
	(void)param;

	/* Declare a Lua State, open the Lua State and load the libraries (see above). */
	lua_State *lua_state = luaL_newstate();
	if (NULL == lua_state)
	{
		ledlib_set_error_state();
		usart1_write_string("lua:cannot create engine, not enough memory!\r\n");

		vTaskDelete(lua_handle);
		return;
	}

	usart1_write_string("lua engine started\r\n");

	luaopen_base(lua_state);
	luaopen_io(lua_state);
	luaopen_string(lua_state);
	luaopen_math(lua_state);

	lua_register(lua_state, "stepmotor", function_stepmotor);
	lua_register(lua_state, "sleep", function_sleep);

	/*
	 * Empty stack. For some reason when lua starts, the stack gets filled with some booleans.
	 */
	while (lua_gettop(lua_state) > 0)
	{
		lua_pop(lua_state, 1);
	}

	usart1_write_string("lua waiting for commands\r\n");

	while (1)
	{
		if (pdPASS == xQueueReceive(
				*_p_queue_lua_commands,
				command,
				portMAX_DELAY))
		{
			if (luaL_dostring(lua_state, command))
			{
//				set_error_state();
				usart1_write_string("lua: error running argument:\r\n");
			}

			if (0 == lua_checkstack(lua_state, 130))
			{
				usart1_write_string("lua:no stack available!\r\n");
				break;
			}

			stack_dump(lua_state);
		}
	}

	/* Remember to destroy the Lua State */
	lua_close(lua_state);

	// TODO restart lua after x seconds
	ledlib_set_error_state();

	vTaskDelete(lua_handle);
}


void task_lua_init(xQueueHandle *p_queue_lua_commands)
{
	_p_queue_lua_commands = p_queue_lua_commands;

    xTaskCreate(task_lua, (signed char*)"task-lua", 8192, 0, tskIDLE_PRIORITY, &lua_handle);
}
