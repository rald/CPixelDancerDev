#ifndef CANVAS_H
#define CANVAS_H

#include <stdlib.h>

#include <GL/glfw.h>
#include <GL/gl2d.h>

#include "palette.h"



typedef struct Canvas Canvas;

struct Canvas {
	int x,y;
	int w,h;
	int sz;
	int *pixels;
};

Canvas *Canvas_New(int x,int y,int w,int h,int sz);
void Canvas_Free(Canvas **canvas);  
void Canvas_Draw(Canvas *canvas,Palette *palette);
bool Canvas_HandleEvents(Canvas *canvas,Palette *palette);
void Canvas_FloodFill(Canvas *canvas,Palette *palette,int x,int y,int targetColorIndex);

#endif
