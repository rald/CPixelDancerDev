#include "grid.h"



Grid *Grid_New(int x,int y,int w,int h,int sz) {
	Grid *grid=malloc(sizeof(Grid));

	if(grid) {
		grid->x=x;
		grid->y=y;
		grid->w=w;
		grid->h=h;
		grid->sz=sz;
		grid->visible=true;
	}
	
	return grid;
}



void Grid_Free(Grid *grid) {
	free(grid);
	grid=NULL;
}



void Grid_Draw(Grid *grid,Canvas *canvas,Palette *palette) {
	for(int j=0;j<grid->h;j++) {
		for(int i=0;i<grid->w;i++) {
			int x0=i*grid->sz;
			int y0=j*grid->sz;
			int x1=x0+grid->sz;
			int y1=y0+grid->sz;
			if(i>=0 && i<=canvas->w && j>=0 && j<=canvas->h) {
				glBoxFilled(x0,y0,x1,y1,palette->colors[canvas->pixels[i+j*canvas->w]]);
			}
			if(grid->visible) {
				glBox(x0,y0,x1,y1,palette->colors[3]);
			}
		}
	}
}



void Grid_HandleEvents(Grid *grid) {
}
