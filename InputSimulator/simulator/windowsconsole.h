#ifndef __WINDOWSCONSOLE_H__
#define __WINDOWSCONSOLE_H__
#include "console.h"
class WindowsConsole : public Console
{
public:
	WindowsConsole();
	virtual ~WindowsConsole();
	virtual void log(const std::string& text) override;
};
#endif // !__WINDOWSCONSOLE_H__
