#ifndef THUMBNAIL_H
#define THUMBNAIL_H

#include <GL/glfw.h>
#include <GL/gl2d.h>

#include <palette.h>
#include <canvas.h>

typedef struct Thumbnail Thumbnail;

struct Thumbnail {
	int x,y;
	int sz;
};

Thumbnail *Thumbnail_New(int x,int y,int sz);
void Thumbnail_Free(Thumbnail **thumbnail);
void Thumbnail_Draw(Thumbnail *thumbnail,Canvas *canvas,Palette *palette);

#endif
