#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.

const int HEXAGON_SIZE = 100;
const int SQUARE_SIZE = 125;

enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,		//Draw Rectangle
	DRAW_SQUA,
	DRAW_TRI,
	DRAW_CIRC,
	DRAW_HEX,

	SELECT,
	SWAP,
	ROTATE,
	DEL,
	CLEAR,
	COPY,
	CUT,
	PASTE,
	SAVE_GRAPH,
	LOAD_GRAPH,

	PLAY_MISSING_SHAPES,
	PLAY_MISSING_PAIRS,

	EXIT,			//Exit
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS			//A click on the status bar
};

struct Point	//To be used for figures points
{
	int x, y;

	float GetDistance(Point p2) 
	{
		float dis = sqrt(pow(p2.x - x, 2) + pow(p2.y - y, 2));
		return dis;
	}
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif