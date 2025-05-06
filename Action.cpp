#include "Action.h"
#include "ApplicationManager.h"

color Action::PromptUserForColor()
{
    pManager->GetOutput()->PrintMessage("Choose figure color: (r) red, (b) blue, (g) green, (bl) black, (w) white");
    string input = pManager->GetInput()->GetString(pManager->GetOutput());

    if (input == "r") 
    {
        return RED;
    } 
    else if (input == "b")
    {
        return BLUE;
    }
    else if (input == "g")
    {
        return GREEN;
    } 
    else if (input == "bl")
    {
        return BLACK;
    }
    else 
    {
        return WHITE;
    }
}
