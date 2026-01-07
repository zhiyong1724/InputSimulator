#include "windowsconsole.h"
#include <iostream>
#include <windows.h>
WindowsConsole::WindowsConsole()
{
	SetThreadExecutionState(ES_SYSTEM_REQUIRED | ES_DISPLAY_REQUIRED | ES_CONTINUOUS);
}

WindowsConsole::~WindowsConsole()
{
	SetThreadExecutionState(ES_CONTINUOUS);
}

void WindowsConsole::log(const std::string& text)
{
	std::cout << text << std::endl;
}