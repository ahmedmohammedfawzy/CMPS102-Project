#pragma once

#include "Action.h"

class AddRectAction: public Action
{
private:
	Point P1, P2; //Rectangle Corners
	GfxInfo RectGfxInfo;
public:
	AddRectAction(ApplicationManager *pApp);

	void ReadActionParameters() override;
	
	void Execute() override;
};

