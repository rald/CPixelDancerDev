#ifndef PALETTE_H
#define PALETTE_H

#include <stdlib.h>
#include <stdarg.h>

#include <GL/glfw.h>
#include <GL/gl2d.h>



typedef struct Palette Palette;

struct Palette {
	int x,y;
	int w;
	int sz;
	int numColors;
	GLuint *colors;
	int idx;
};



Palette *Palette_New(int x,int y,int w,int sz,int numColors,...);
void Palette_Free(Palette **palette);
void Palette_Draw(Palette *palette);
void Palette_HandleEvents(Palette *palette);

#endif
