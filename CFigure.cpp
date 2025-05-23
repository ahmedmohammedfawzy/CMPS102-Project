#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	IsGreyed = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }


void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

int CFigure::getID()
{
	return ID;
}

void CFigure::setID(int id)
{
	ID = id;
}
color CFigure::GetFillClr()
{
	return FigGfxInfo.FillClr;
}
void CFigure::setGreyColor(bool isGrey)
{
	IsGreyed = isGrey;
}

