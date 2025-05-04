#pragma once
#include "Action.h"
class SwapAction : public Action
{
public:
	SwapAction(ApplicationManager* pApp);

	void ReadActionParameters() override;

	void Execute() override;
};

