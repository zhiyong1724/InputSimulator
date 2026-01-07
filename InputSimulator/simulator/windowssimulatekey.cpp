#ifndef __SIMULATEKEY_H__
#define __SIMULATEKEY_H__
#include "windowssimulatekey.h"
#include <windows.h>
WindowsSimulateKey::WindowsSimulateKey()
{
    mKeyDown.store(false);
}

WindowsSimulateKey::~WindowsSimulateKey()
{
}

void WindowsSimulateKey::keyDown(int code)
{
	if (!mKeyDown.exchange(true))
	{
		mKeyDownThread = std::make_shared<std::thread>([&, code]() {
			INPUT input = { 0 };
			input.type = INPUT_KEYBOARD;
			input.ki.wVk = (WORD)code;
			while (mKeyDown.load())
			{
				SendInput(1, &input, sizeof(INPUT)); // 按下
				std::this_thread::sleep_for(std::chrono::milliseconds(50));
			}
			});
	}
}

void WindowsSimulateKey::keyUp(int code)
{
	if (mKeyDown.exchange(false))
	{
		mKeyDown.store(false);
		mKeyDownThread->join();
		INPUT input = { 0 };
		input.type = INPUT_KEYBOARD;
		input.ki.wVk = (WORD)code;
		input.ki.dwFlags = KEYEVENTF_KEYUP;
		SendInput(1, &input, sizeof(INPUT)); // 弹起
	}
}

void WindowsSimulateKey::keyClick(int code)
{
	INPUT input = { 0 };
	input.type = INPUT_KEYBOARD;
	input.ki.wVk = (WORD)code;
	SendInput(1, &input, sizeof(INPUT)); // 按下
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	input.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &input, sizeof(INPUT)); // 弹起
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
}
#endif
