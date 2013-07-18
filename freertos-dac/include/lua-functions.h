#ifndef __LUA_FUNCTIONS_H
#define __LUA_FUNCTIONS_H

#include "main.h"

//------------------------------------------------exported functions-----------

extern int function_stepmotor(lua_State *lua_state);
extern int function_sleep(lua_State *lua_state);
extern int function_dac_write(lua_State *lua_state);
extern int function_dac_audio(lua_State *lua_state);
extern int function_set_sample(lua_State *lua_state);

//-----------------------------------------------------------------------------

#endif //__LUA_FUNCTIONS_H
