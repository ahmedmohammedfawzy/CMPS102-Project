#pragma once
#include "Action.h"
class SelectAction : public Action
{
private:
	Point P;

public:
	SelectAction(ApplicationManager* pApp);

	void ReadActionParameters() override;

	void Execute() override;
};

