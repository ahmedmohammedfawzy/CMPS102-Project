#include "CSquare.h"

CSquare::CSquare(Point c, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	center = c;
	Corner2.x = center.x + SQUARE_SIZE / 2;
	Corner2.y = center.y + SQUARE_SIZE / 2;

	Corner1.x = center.x - SQUARE_SIZE / 2;
	Corner1.y = center.y - SQUARE_SIZE / 2;
}

bool CSquare::IsPointInsideFig(int x, int y)
{
	if (x > Corner1.x && x < Corner2.x && y > Corner1.y && y < Corner2.y)
	{
		return true;
	}
	return false;
}

void CSquare::Draw(Output* pOut) const
{
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

void CSquare::Rotate(bool IsClock)
{
}

bool CSquare::CanRotate()
{
	return false;
}
