
#include <stdio.h>
#include <memory>
#include <string.h>
#include "simulator.h"
#include "windowssimulatekey.h"
#include "windowssimulatemouse.h"
#include "windowsconsole.h"
int main(int argc, char **argv)
{
	const char* filePath = "start.json";
	if (argc > 1)
		filePath = argv[1];
	auto windowsSimulateKey = std::make_shared<WindowsSimulateKey>();
	auto windowsSimulateMouse = std::make_shared<WindowsSimulateMouse>();
	auto windowsConsole = std::make_shared<WindowsConsole>();
	printf("开始加载脚本...\n");
	auto simulator = std::make_shared<Simulator>(windowsSimulateKey.get(), windowsSimulateMouse.get(), windowsConsole.get());
	if (!simulator->loadScript(filePath))
		return -1;
	printf("开始执行脚本，输入q，按回车键结束...\n");
	simulator->start();
	char buff[256];
	while (true)
	{
		::scanf("%s", buff);
		if (::strcmp(buff, "q") == 0)
		{
			simulator->stop();
			break;
		}
	}
	return 0;
}
