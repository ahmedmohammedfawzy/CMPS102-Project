#include "CSquare.h"

CSquare::CSquare(Point P, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	center = P;
}

void CSquare::Draw(Output* pOut) const
{
	int sqaureLength = 150;
	Point P1;
	Point P2;

	P2.x = 75 + center.x;
	P2.y = center.y + 75;

	P1.x = center.x - 75;
	P1.y = center.y - 75;

	pOut->DrawRect(P1, P2, FigGfxInfo, Selected);
}
