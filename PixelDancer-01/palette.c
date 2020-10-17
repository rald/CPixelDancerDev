#include "palette.h"

Palette *Palette_New(int x,int y,int w,int sz,int idx,int numColors,...) {
	Palette *palette=malloc(sizeof(Palette));
	if(palette) {

		palette->x=x;
		palette->y=y;
		palette->w=w;
		palette->sz=sz;
		palette->idx=idx;
	
		palette->numColors=numColors;
		palette->colors=malloc(sizeof(GLuint)*numColors);
		
		va_list args;
		va_start(args,numColors);
		for(int i=0;i<numColors;i++) {
			palette->colors[i]=va_arg(args,GLuint);
		}
		va_end(args);
	}
	return palette;
}

void Palette_Draw(Palette *palette) {
	for(int i=0;i<palette->numColors;i++) {
		int x0=(i%palette->w)*palette->sz+palette->x;
		int y0=(i/palette->w)*palette->sz+palette->y;
		int x1=x0+palette->sz;
		int y1=y0+palette->sz;
		glBoxFilled(x0+4,y0+4,x1-4,y1-4,palette->colors[i]);
		if(i==palette->idx) {
			 glBox(x0,y0,x1,y1,palette->colors[3]);
		}
	}
}
