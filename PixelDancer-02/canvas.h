#ifndef CANVAS_H
#define CANVAS_H

#include <stdlib.h>



typedef struct Canvas Canvas;

struct Canvas {
	int w,h;
	int *pixels;
};

Canvas *Canvas_New(int w,int h);
void Canvas_Free(Canvas **canvas);  

#endif
