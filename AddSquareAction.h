#ifndef ADD_RECT_ACTION_H
#define ADD_RECT_ACTION_H

#include "Actions/Action.h"

class AddSquareAction : public Action
{
	Point P1;
	Point P2;
	GfxInfo SquareGfxInfo;

public:
	AddSquareAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

#endif