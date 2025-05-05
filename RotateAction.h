#pragma once
#include "Action.h"
class RotateAction : public Action
{
private:
	bool IsClock;

public:
	RotateAction(ApplicationManager* pApp);

	void ReadActionParameters() override;

	void Execute() override;
};

