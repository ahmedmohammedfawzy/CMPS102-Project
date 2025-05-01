#pragma once
#include "Action.h"
class AddCircleAction : public Action
{
private:
	Point Center, P2;
	GfxInfo CircleGfxInfo;
public:
	AddCircleAction(ApplicationManager* pApp);

	void ReadActionParameters() override;

	void Execute() override;
};

