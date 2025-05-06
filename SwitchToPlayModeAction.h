#pragma once
#include "Action.h"
class SwitchToPlayModeAction : public Action
{
public:
	SwitchToPlayModeAction(ApplicationManager* pApp);

	void ReadActionParameters() override;

	void Execute() override;
};

