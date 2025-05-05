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
	pOut->DrawCircle(Center, Radius, FigGfxInfo, Selected);
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
