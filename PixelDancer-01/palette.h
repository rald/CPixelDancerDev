#ifndef PALETTE_H
#define PALETTE_H

#include <stdlib.h>
#include <stdarg.h>

#include <GL/glfw.h>
#include <GL/gl2d.h>

typedef struct Palette Palette;

struct Palette {
	GLuint *colors;
	int numColors;
	int x,y;
	int w;
	int sz;
	int idx;
};

Palette *Palette_New(int x,int y,int w,int sz,int idx,int numColors,...);
void Palette_Draw(Palette *palette);

#endif
