#include "windowsconsole.h"
#include <iostream>
WindowsConsole::WindowsConsole()
{
}

WindowsConsole::~WindowsConsole()
{
}

void WindowsConsole::log(const std::string& text)
{
	std::cout << text << std::endl;
}