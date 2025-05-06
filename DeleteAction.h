#pragma once
#include "Action.h"

class DeleteAction :
    public Action
{
public:
	DeleteAction(ApplicationManager* pApp);

	void ReadActionParameters() override;

	void Execute() override;
};

