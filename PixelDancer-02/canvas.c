#include "canvas.h"



Canvas *Canvas_New(int w,int h) {
	Canvas *canvas=malloc(sizeof(Canvas));
	if(canvas) {
		canvas->w=w;
		canvas->h=h;
		canvas->pixels=malloc(sizeof(int)*(w*h));

		for(int j=0;j<h;j++) {
			for(int i=0;i<w;i++) {
				canvas->pixels[i+j*w]=0;
			}
		}
		
	}
	return canvas;
}



void Canvas_Free(Canvas **canvas) {
	free((*canvas)->pixels);
	(*canvas)->pixels=NULL;
	free(*canvas);
	(*canvas)=NULL;
}
