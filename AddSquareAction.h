#pragma once
#include "Action.h"

class AddSquareAction : public Action
{
	Point P1;
	Point P2;
	GfxInfo SquareGfxInfo;

public:
	AddSquareAction(ApplicationManager* pApp);

	void ReadActionParameters() override;

	void Execute() override;
};
