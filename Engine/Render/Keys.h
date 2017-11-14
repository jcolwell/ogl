#ifndef INPUT_MANAGER_KEYS_H__
#define INPUT_MANAGER_KEYS_H__
//===========================================================================
// FILE: Keys.h
// DESC: 
//===========================================================================

//===========================================================================
// INCLUDES
//===========================================================================
#include "Common.h"
//===========================================================================

enum class Modifier
{
	None = 0
	, Shift = GLFW_MOD_SHIFT
	, Ctrl  = GLFW_MOD_CONTROL
	, Alt	= GLFW_MOD_ALT
};

enum class Key
{
	Unknown = GLFW_KEY_UNKNOWN
	, A = GLFW_KEY_A
	, B = GLFW_KEY_B
	, C = GLFW_KEY_C
	, D = GLFW_KEY_D
	, E = GLFW_KEY_E
	, F = GLFW_KEY_F
	, G = GLFW_KEY_G
	, H = GLFW_KEY_H
	, I = GLFW_KEY_I
	, J = GLFW_KEY_J
	, K = GLFW_KEY_K
	, L = GLFW_KEY_L
	, M = GLFW_KEY_M
	, N = GLFW_KEY_N
	, O = GLFW_KEY_O
	, P = GLFW_KEY_P
	, Q = GLFW_KEY_Q
	, R = GLFW_KEY_R
	, S = GLFW_KEY_S
	, T = GLFW_KEY_T
	, U = GLFW_KEY_U
	, V = GLFW_KEY_V
	, W = GLFW_KEY_W
	, X = GLFW_KEY_X
	, Y = GLFW_KEY_Y
	, Z = GLFW_KEY_Z
	, One = GLFW_KEY_1
	, Two = GLFW_KEY_2
	, Three = GLFW_KEY_3
	, Four = GLFW_KEY_4
	, Five = GLFW_KEY_5
	, Six = GLFW_KEY_6
	, Seven = GLFW_KEY_7
	, Eight = GLFW_KEY_8
	, Nine = GLFW_KEY_9
	, F1 = GLFW_KEY_F1
	, F2 = GLFW_KEY_F2
	, F3 = GLFW_KEY_F3
	, F4 = GLFW_KEY_F4
	, F5 = GLFW_KEY_F5
	, F6 = GLFW_KEY_F6
	, F7 = GLFW_KEY_F7
	, F8 = GLFW_KEY_F8
	, F9 = GLFW_KEY_F9
	, F10 = GLFW_KEY_F10
	, F11 = GLFW_KEY_F11
	, F12 = GLFW_KEY_F12
	, Grave = GLFW_KEY_GRAVE_ACCENT
	, Escape = GLFW_KEY_ESCAPE
	, Minus = GLFW_KEY_MINUS
	, Equal = GLFW_KEY_EQUAL
	, Backspace = GLFW_KEY_BACKSPACE
	, Tab = GLFW_KEY_TAB
	, LBracket = GLFW_KEY_LEFT_BRACKET
	, RBracket = GLFW_KEY_RIGHT_BRACKET
	, Backslash = GLFW_KEY_BACKSLASH
	, Capslock = GLFW_KEY_CAPS_LOCK
	, SemiColon = GLFW_KEY_SEMICOLON
	, Apostrophe = GLFW_KEY_APOSTROPHE
	, LShift = GLFW_KEY_LEFT_SHIFT
	, Comma = GLFW_KEY_COMMA
	, Peroid = GLFW_KEY_PERIOD
	, Slash = GLFW_KEY_SLASH
	, RShift = GLFW_KEY_RIGHT_SHIFT
	, LControl = GLFW_KEY_LEFT_CONTROL
	, LAlt = GLFW_KEY_LEFT_ALT
	, RControl = GLFW_KEY_RIGHT_CONTROL
	, RAlt = GLFW_KEY_RIGHT_ALT
	, Delete = GLFW_KEY_DELETE
	, ArrowDown = GLFW_KEY_DOWN
	, ArrowUp = GLFW_KEY_UP
	, ArrowLeft = GLFW_KEY_LEFT
	, ArrowRight = GLFW_KEY_RIGHT
	, Enter = GLFW_KEY_ENTER
	, End = GLFW_KEY_END
	, Home = GLFW_KEY_HOME
	, Insert = GLFW_KEY_INSERT
	, PrintScreen = GLFW_KEY_PRINT_SCREEN
	, PageUp = GLFW_KEY_PAGE_UP
	, PageDown = GLFW_KEY_PAGE_DOWN

	//NUMPAD KEYS

	//MOUSE KEYS
	, MouseOne = GLFW_MOUSE_BUTTON_1
	, MouseTwo = GLFW_MOUSE_BUTTON_2
	, MouseThree = GLFW_MOUSE_BUTTON_3
	, MouseFour = GLFW_MOUSE_BUTTON_4
	, MouseFive = GLFW_MOUSE_BUTTON_5
	, MouseSix = GLFW_MOUSE_BUTTON_6
	, MouseSeven = GLFW_MOUSE_BUTTON_7
	, MouseEight = GLFW_MOUSE_BUTTON_8
	, MouseLeft = GLFW_MOUSE_BUTTON_LEFT
	, MouseMiddle = GLFW_MOUSE_BUTTON_MIDDLE
	, MouseRight = GLFW_MOUSE_BUTTON_RIGHT

	, NUM_KEY_CODES
};


#endif // !INPUT_MANAGER_KEYS_H__
