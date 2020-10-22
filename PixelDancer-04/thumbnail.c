#include "thumbnail.h"

Thumbnail *Thumbnail_New(int x,int y,int sz) {
	Thumbnail *thumbnail=malloc(sizeof(Thumbnail));
	if(thumbnail) {
		thumbnail->x=x;
		thumbnail->y=y;
		thumbnail->sz=sz;
	}
	return thumbnail;
}

void Thumbnail_Free(Thumbnail **thumbnail) {
	free(*thumbnail);
	(*thumbnail)=NULL;
}

void Thumbnail_Draw(Thumbnail *thumbnail,Canvas *canvas,Palette *palette) {

	glBoxFilled(
		thumbnail->x+1,
		thumbnail->y+1,
		thumbnail->x+canvas->w*thumbnail->sz,
		thumbnail->y+canvas->h*thumbnail->sz,
		palette->colors[1]
	);

	for(int j=0;j<canvas->h;j++) {
		for(int i=0;i<canvas->w;i++) {
			int x0=i*thumbnail->sz+thumbnail->x+1;
			int y0=j*thumbnail->sz+thumbnail->y+1;
			int x1=x0+thumbnail->sz;
			int y1=y0+thumbnail->sz;
			glBoxFilled(x0,y0,x1,y1,palette->colors[canvas->pixels[i+j*canvas->w]]);
		}
	}
	glBox(thumbnail->x,thumbnail->y,thumbnail->x+canvas->w*thumbnail->sz+1,thumbnail->y+canvas->h*thumbnail->sz+1,palette->colors[3]);
}
