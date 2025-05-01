#include "CCircle.h"

CCircle::CCircle(Point c, Point p2, GfxInfo circleGfxInfo) : CFigure(circleGfxInfo)
{
	Center = c;
	P2 = p2;
}

void CCircle::Draw(Output* pOut) const
{
	pOut->DrawCircle(Center, P2, FigGfxInfo, Selected);
}
