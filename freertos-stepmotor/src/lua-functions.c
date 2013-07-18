#include "lua.h"
#include "task-stepmotor.h"
#include "usart.h"

/**
 *
 */
int function_stepmotor(lua_State *lua_state)
{
	int argc = lua_gettop(lua_state);

	if (lua_gettop(lua_state) != 1)
	{
		usart1_write_string("--- error: usage is stepmotor(param) where param is between 0 and 100.\r\n");
		return 0;
	}

	if (lua_type(lua_state, 1) != LUA_TNUMBER)
	{
		usart1_write_string("--- error: usage is stepmotor(param) where param is between 0 and 100.\r\n");
		return 0;
	}

	int value = lua_tointeger(lua_state, 1);
	task_stepmotor_send_dutycycle(value);

//	lua_pushstring(lua_state, "ok");

	return 0; // number of return values
}

/**
 *
 */
int function_sleep(lua_State *lua_state)
{
	int argc = lua_gettop(lua_state);

	if (lua_gettop(lua_state) != 1)
	{
		usart1_write_string("--- error: usage is sleep(ms).\r\n");
		return 0;
	}

	if (lua_type(lua_state, 1) != LUA_TNUMBER)
	{
		usart1_write_string("--- error: usage is sleep(ms).\r\n");
		return 0;
	}

	int value = lua_tointeger(lua_state, 1);

	value *= 13360;
	while(--value)
	{
		;
	}

	return 0; // number of return values
}
