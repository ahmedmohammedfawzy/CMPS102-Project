#include "CSquare.h"
#include"sstream"
#include"fstream"

void CSquare::CalculateCorners()
{
	Corner2.x = Center.x + SQUARE_SIZE / 2;
	Corner2.y = Center.y + SQUARE_SIZE / 2;

	Corner1.x = Center.x - SQUARE_SIZE / 2;
	Corner1.y = Center.y - SQUARE_SIZE / 2;
}

CSquare::CSquare(Point c, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = c;
	CalculateCorners();
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
	GfxInfo gfx = FigGfxInfo;
	gfx.FillClr = IsGreyed ? GREY : FigGfxInfo.FillClr;
	pOut->DrawRect(Corner1, Corner2, gfx, Selected);
}

void CSquare::Rotate(bool IsClock)
{
}

bool CSquare::CanRotate()
{
	return false;
}

void CSquare::MoveTo(Point newCenter)
{
	Center = newCenter;
	CalculateCorners();
}

Point CSquare::GetCenter()
{
	return { (Corner1.x + Corner2.x) / 2, (Corner1.y + Corner2.y) / 2 };

}
string CSquare::SaveInfo()
{

	ostringstream Squarinfo;
	Squarinfo << "Square " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << (int)FigGfxInfo.FillClr.ucRed << " " << (int)FigGfxInfo.FillClr.ucGreen << " " << (int)FigGfxInfo.FillClr.ucBlue;
	return Squarinfo.str();
}

void CSquare::Load(ifstream& in)
{
	int r, g, b;
	in >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> r >> g >> b;
	FigGfxInfo.FillClr = color(r, g, b);
}

CFigure* CSquare::Clone()
{
	return new CSquare(*this);
}
