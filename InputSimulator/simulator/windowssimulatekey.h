#ifndef __WINDOWSSIMULATEKEY_H__
#define __WINDOWSSIMULATEKEY_H__
#include "simulatekey.h"
#include <atomic>
#include <thread>
#include <memory>
class WindowsSimulateKey : public SimulateKey
{
public:
	WindowsSimulateKey();
	virtual ~WindowsSimulateKey() override;
	virtual void keyDown(int code) override;
	virtual void keyUp(int code) override;
	virtual void keyClick(int code) override;
private:
	std::atomic_bool mKeyDown;
	std::shared_ptr<std::thread> mKeyDownThread;
};
#endif
