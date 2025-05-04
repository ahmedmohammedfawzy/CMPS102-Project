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

void CTriangle::Rotate(bool IsClock)
{
	Point cen = GetCenter();
	P1 = Rotate90DegPointAroundCenter(P1, cen, IsClock);
	P2 = Rotate90DegPointAroundCenter(P2, cen, IsClock);
	P3 = Rotate90DegPointAroundCenter(P3, cen, IsClock);
}

bool CTriangle::CanRotate()
{
	return true;
}

void CTriangle::MoveTo(Point newCenter)
{
	Point oldCen = GetCenter();
	P1 = { P1.x - oldCen.x + newCenter.x, P1.y - oldCen.y + newCenter.y };
	P2 = { P2.x - oldCen.x + newCenter.x, P2.y - oldCen.y + newCenter.y };
	P3 = { P3.x - oldCen.x + newCenter.x, P3.y - oldCen.y + newCenter.y };
}

Point CTriangle::GetCenter()
{
	return { (P1.x + P2.x + P3.x) / 3, (P1.y + P2.y + P3.y) / 3 };
}
