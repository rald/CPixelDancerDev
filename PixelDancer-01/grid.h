#ifndef GRID_H
#define GRID_H

#include <stdlib.h>

#include <GL/glfw.h>
#include <GL/gl2d.h>



typedef struct Grid Grid;

struct Grid {
	int x,y;
	int w,h;
	int sz;
};

Grid *Grid_New(int x,int y,int w,int h,int sz);
void Grid_Draw(Grid *grid,GLuint *palette,int numPalette);

#endif
