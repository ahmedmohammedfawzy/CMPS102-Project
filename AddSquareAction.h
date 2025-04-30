#pragma once
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
