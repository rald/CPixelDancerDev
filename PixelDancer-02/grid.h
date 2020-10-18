#ifndef GRID_H
#define GRID_H



#include <stdlib.h>
#include <stdbool.h>

#include <GL/glfw.h>
#include <GL/gl2d.h>

#include "palette.h"
#include "canvas.h"



typedef struct Grid Grid;

struct Grid {
	int x,y;
	int w,h;
	int sz;
	bool visible;
};

Grid *Grid_New(int x,int y,int w,int h,int sz);
void Grid_Free(Grid *grid);
void Grid_Draw(Grid *grid,Canvas *canvas,Palette *palette);
void Grid_HandleEvents(Grid *grid,Canvas *canvas,Palette *palette,int currentColorIndex);

#endif
