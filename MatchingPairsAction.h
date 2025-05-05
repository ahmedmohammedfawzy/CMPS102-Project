#pragma once
#
#include<string>
#include "Action.h"

#include "SelectAction.h"
#include "ApplicationManager.h"

#include "input.h"
#include "Output.h"
class MatchingPairsAction : public Action
{
private:
    Point P1;
    Point P2;
    int Score;
public:
    MatchingPairsAction(ApplicationManager* pApp);
    void ReadActionParameters() override;
    void Execute() override;
};

