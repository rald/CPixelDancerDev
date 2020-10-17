#ifndef PALETTE_H
#define PALETTE_H

#include <stdlib.h>
#include <stdarg.h>

#include <GL/glfw.h>
#include <GL/gl2d.h>

typedef struct Palette Palette;

struct Palette {
	int numColors;
	GLuint *colors;
};

Palette *Palette_New(int numColors,...);
void Palette_Free(Palette **palette);

#endif
