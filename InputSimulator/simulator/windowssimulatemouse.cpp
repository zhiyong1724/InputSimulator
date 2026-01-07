#include "windowssimulatemouse.h"
#include <windows.h>
#include <thread>
WindowsSimulateMouse::WindowsSimulateMouse()
{
}

WindowsSimulateMouse::~WindowsSimulateMouse()
{
}

void WindowsSimulateMouse::MoveTo(int x, int y)
{
	POINT currentPos;
	GetCursorPos(&currentPos); // 获取当前鼠标位置

	//int dx = x - currentPos.x; // 计算x方向上的移动距离
	//int dy = y - currentPos.y; // 计算y方向上的移动距离

	// 准备鼠标移动的结构体数组
	INPUT input;
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_MOVE; // 移动标志
	input.mi.dx = x * 65536 / GetSystemMetrics(SM_CXSCREEN); // 转换为屏幕坐标系
	input.mi.dy = y * 65536 / GetSystemMetrics(SM_CYSCREEN); // 转换为屏幕坐标系
	input.mi.mouseData = 0;
	input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE; // 使用绝对坐标
	input.mi.time = 0;
	input.mi.dwExtraInfo = 0;

	// 发送鼠标移动命令
	SendInput(1, &input, sizeof(INPUT));
}

void WindowsSimulateMouse::leftKeyClick()
{
	INPUT input = { 0 };
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	SendInput(1, &input, sizeof(INPUT));
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	SendInput(1, &input, sizeof(INPUT));
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

void WindowsSimulateMouse::rightKeyClick()
{
	INPUT input = { 0 };
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
	SendInput(1, &input, sizeof(INPUT));
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
	SendInput(1, &input, sizeof(INPUT));
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

void WindowsSimulateMouse::leftKeyDoubleClick()
{
	leftKeyClick();
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	leftKeyClick();
}

void WindowsSimulateMouse::rightKeyDoubleClick()
{
	rightKeyClick();
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	rightKeyClick();
}