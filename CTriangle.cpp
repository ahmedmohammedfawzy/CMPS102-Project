#include "CTriangle.h"
#include "Helpers.h"

CTriangle::CTriangle(Point p1, Point p2, Point p3, GfxInfo gfx): CFigure(gfx)
{
	P1 = p1;
	P2 = p2;
	P3 = p3;
}

bool CTriangle::IsPointInsideFig(int x, int y)
{
	return isInsideTriangle(P1, P2, P3, Point{x,y});
}

void CTriangle::Draw(Output* pOut) const
{
	pOut->DrawTri(P1, P2, P3, FigGfxInfo, Selected);
}
