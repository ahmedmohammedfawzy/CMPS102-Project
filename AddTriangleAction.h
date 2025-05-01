#pragma once
#include "Action.h"

class AddTriangleAction: public Action
{
private:
	Point P1, P2, P3; //Rectangle Corners
	GfxInfo TriGfxInfo;
public:
	AddTriangleAction(ApplicationManager* pApp);

	void ReadActionParameters() override;

	void Execute() override;
};

