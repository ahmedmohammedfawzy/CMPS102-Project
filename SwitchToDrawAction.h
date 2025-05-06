#pragma once
#include "Action.h"
class SwitchToDrawAction : public Action
{
public:
	SwitchToDrawAction(ApplicationManager* pApp);

	void ReadActionParameters() override;

	void Execute() override;
};

