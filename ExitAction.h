#pragma once
#include "Action.h"
class ExitAction : public Action
{
public:
	ExitAction(ApplicationManager* pApp);

	void ReadActionParameters() override;

	void Execute() override;
};

