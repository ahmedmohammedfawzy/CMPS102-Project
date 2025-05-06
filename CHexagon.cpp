#include "CHexagon.h"
#include "Helpers.h"
#include "sstream"
#include "fstream"

void CHexagon::CalculateVertices()
{
	Vertices[0] = { HEXAGON_SIZE, 0 };
	Vertices[1] = { (HEXAGON_SIZE / 2), (int)((sqrt(3) / 2) * HEXAGON_SIZE) };
	Vertices[2] = { -(HEXAGON_SIZE / 2), (int)((sqrt(3) / 2) * HEXAGON_SIZE) };
	Vertices[3] = { -HEXAGON_SIZE, 0 };
	Vertices[4] = { -(HEXAGON_SIZE / 2), (int)(-(sqrt(3) / 2) * HEXAGON_SIZE) };
	Vertices[5] = { (HEXAGON_SIZE / 2), (int)(-(sqrt(3) / 2) * HEXAGON_SIZE) };

	for (int i = 0; i < 6; i++)
	{
		Vertices[i].x += Center.x;
		Vertices[i].y += Center.y;
	}
}

CHexagon::CHexagon(Point center, GfxInfo hexagonGfxInfo): CFigure(hexagonGfxInfo)
{
	Center = center;
	CalculateVertices();

}
bool CHexagon::IsPointInsideFig(int x, int y)
{
	for (int i = 0; i < 6; i++)
	{
		Point p1 = Vertices[i];
		Point p2 = Vertices[(i + 1) % 6];

		if (isInsideTriangle(p1, p2, Center, { x,y }))
			return true;
	}
	return false;
}

void CHexagon::Draw(Output* pOut) const
{
	GfxInfo gfx = FigGfxInfo;
	gfx.FillClr = IsGreyed ? GREY : FigGfxInfo.FillClr;
	pOut->DrawHexagon(Vertices, gfx, Selected);
}

void CHexagon::Rotate(bool isClock)
{
	for (int i = 0; i < 6; i++)
	{
		Vertices[i] = Rotate90DegPointAroundCenter(Vertices[i], Center, isClock);
	}
}

bool CHexagon::CanRotate()
{
	return true;
}

void CHexagon::MoveTo(Point newCenter)
{
	Center = newCenter;
	CalculateVertices();
}

Point CHexagon::GetCenter()
{
	return Center;
}
string CHexagon::SaveInfo()
{
	ostringstream hexinfo;
	hexinfo << "Hexagon " << ID <<" " <<Center.x <<" "<<Center.y <<" " << (int)FigGfxInfo.FillClr.ucRed << " " << (int)FigGfxInfo.FillClr.ucGreen << " " << (int)FigGfxInfo.FillClr.ucBlue;
	return hexinfo.str();
}

void CHexagon::Load(ifstream& in)
{
	int r, g, b;
	in >> ID >> Center.x >> Center.y >> r >> g >> b;
	FigGfxInfo.FillClr = color(r, g, b);
}
CFigure* CHexagon::Clone()
{
	return new CHexagon(*this);

}
