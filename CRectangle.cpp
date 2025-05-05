#include "CRectangle.h"
#include "Helpers.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

bool CRectangle::IsPointInsideFig(int x, int y)
{
	if (x > Corner1.x && x < Corner2.x && y > Corner1.y && y < Corner2.y) 
	{
		return true;
	}
	return false;
}
	

void CRectangle::Draw(Output* pOut) const
{
	GfxInfo gfx = FigGfxInfo;
	gfx.FillClr = IsGreyed ? GREY : FigGfxInfo.FillClr;
	pOut->DrawRect(Corner1, Corner2, gfx, Selected);
}

void CRectangle::Rotate(bool IsClock)
{
	Point cen = GetCenter();
	Corner1 = Rotate90DegPointAroundCenter(Corner1, cen, IsClock);
	Corner2 = Rotate90DegPointAroundCenter(Corner2, cen, IsClock);
}

bool CRectangle::CanRotate()
{
	return true;
}

void CRectangle::MoveTo(Point newCenter)
{
	Point oldCen = GetCenter();
	Corner1 = { Corner1.x - oldCen.x + newCenter.x, Corner1.y - oldCen.y + newCenter.y };
	Corner2 = { Corner2.x - oldCen.x + newCenter.x, Corner2.y - oldCen.y + newCenter.y };
}

Point CRectangle::GetCenter()
{
	return { (Corner1.x + Corner2.x) / 2, (Corner1.y + Corner2.y) / 2 };
}

CFigure* CRectangle::Clone()
{
	return new CRectangle(*this);
}

