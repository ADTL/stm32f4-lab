#include "lua.h"
#include "task-stepmotor.h"
#include "usart.h"

extern const int wav_beep_size;
extern const char wav_beep[];

int sample_rate_factor = 5000;

char* itoa(int val)
{
	static char buf[32] =
	{ 0 };

	int i = 30;

	if (val == 0)
	{
		buf[0] = '0';
		buf[1] = '\0';
		return &buf[2];
	}
	for (; val && i; --i, val /= 10)

		buf[i] = "0123456789abcdef"[val % 10];

	return &buf[i + 1];
}

/**
 *
 */
int function_stepmotor(lua_State *lua_state)
{
	int argc = lua_gettop(lua_state);

	if (lua_gettop(lua_state) != 1)
	{
		usart1_write_string(
				"--- error: usage is stepmotor(param) where param is between 0 and 100.\r\n");
		return 0;
	}

	if (lua_type(lua_state, 1) != LUA_TNUMBER)
	{
		usart1_write_string(
				"--- error: usage is stepmotor(param) where param is between 0 and 100.\r\n");
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
	while (--value)
	{
		;
	}

	return 0; // number of return values
}

/**
 *
 */
int function_dac_write(lua_State *lua_state)
{
	int argc = lua_gettop(lua_state);

	if (lua_gettop(lua_state) != 1)
	{
		usart1_write_string("--- error: usage is dac(value).\r\n");
		return 0;
	}

	if (lua_type(lua_state, 1) != LUA_TNUMBER)
	{
		usart1_write_string("--- error: usage is dac(value).\r\n");
		return 0;
	}

	int value = lua_tointeger(lua_state, 1);

	DAC ->DHR12R1 = value & 0xfff;

	return 0; // number of return values
}

/**
 *
 */
int function_dac_audio(lua_State *lua_state)
{
	int argc = lua_gettop(lua_state);

	if (lua_gettop(lua_state) != 1)
	{
		usart1_write_string("--- error: usage is audio(loops).\r\n");
		return 0;
	}

	if (lua_type(lua_state, 1) != LUA_TNUMBER)
	{
		usart1_write_string("--- error: usage is audio(loops).\r\n");
		return 0;
	}

	int value = lua_tointeger(lua_state, 1);

	uint16_t data = 0;

	while (value-- > 0)
	{
		int i = 0;
		uint16_t* val = (uint16_t*)wav_beep;
		for (i = 0; i < wav_beep_size/2; i++)
		{
			uint16_t data = *val;
			data += 32768;
			data /= 10;
			val++;
			DAC->DHR12R1 = data & 0xfff;

			int sleep = sample_rate_factor;
			while(--sleep)
			{
				;
			}
		}

//		if (data == 0) data = 0xfff;
//		else if (data == 0xfff) data = 0x7ff;
//		else if (data == 0x7ff) data = 0;
//
//		if (data == 0)
//			data = 0xfff;
//		else
//			data = 0;
//
//		DAC ->DHR12R1 = data; // & 0xfff;
//
//		int sleep = sample_rate_factor;
//
////		vTaskDelay();
//		while (--sleep)
//		{
//			;
//		}
	}

	usart1_write_string("--- audio loop finished.\r\n");

	return 0; // number of return values
}

int function_set_sample(lua_State *lua_state)
{
	int argc = lua_gettop(lua_state);

	if (lua_gettop(lua_state) != 1)
	{
		usart1_write_string("--- error: usage is setsample(timer).\r\n");
		return 0;
	}

	if (lua_type(lua_state, 1) != LUA_TNUMBER)
	{
		usart1_write_string("--- error: usage is setsample(timer).\r\n");
		return 0;
	}

	int value = lua_tointeger(lua_state, 1);

	if (value > 65535)
		value = 65535;
	else if (value <= 0)
		value = 1;

	sample_rate_factor = value;
	usart1_write_string("--- sample rate factor adjusted to ");
	usart1_write_string(itoa(value));
	usart1_write_string("\r\n");

	return 0;
}
