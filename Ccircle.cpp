#include "CCircle.h"

CCircle::CCircle(Point c, int radius, GfxInfo circleGfxInfo) : CFigure(circleGfxInfo)
{
	Center = c;
	Radius = radius;
}

bool CCircle::IsPointInsideFig(int x, int y)
{
	float dis = sqrt(pow(Center.x - x, 2) + pow(Center.y - y, 2));
	if (dis <= Radius)
		return true;

	return false;
}

void CCircle::Draw(Output* pOut) const
{
	GfxInfo gfx = FigGfxInfo;
	gfx.FillClr = IsGreyed ? GREY : FigGfxInfo.FillClr;
	pOut->DrawCircle(Center, Radius, gfx, Selected);
}

void CCircle::Rotate(bool IsClock) {}

bool CCircle::CanRotate()
{
	return false;
}

void CCircle::MoveTo(Point newCenter)
{
	Center = newCenter;
}

Point CCircle::GetCenter()
{
	return Center;
}

CFigure* CCircle::Clone()
{
	return new CCircle(*this);
}
