#ifndef __WINDOWSSIMULATEMOUSE_H__
#define __WINDOWSSIMULATEMOUSE_H__
#include "simulatemouse.h"
class WindowsSimulateMouse : public SimulateMouse
{
public:
	WindowsSimulateMouse();
	virtual ~WindowsSimulateMouse() override;
	virtual void MoveTo(int x, int y) override;
	virtual void leftKeyClick() override;
	virtual void rightKeyClick() override;
	virtual void leftKeyDoubleClick() override;
	virtual void rightKeyDoubleClick() override;
};
#endif
