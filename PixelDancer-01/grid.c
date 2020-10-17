#include "grid.h"



Grid *Grid_New(int x,int y,int w,int h,int sz) {
	Grid *grid=malloc(sizeof(Grid));

	if(grid) {
		grid->x=x;
		grid->y=y;
		grid->w=w;
		grid->h=h;
		grid->sz=sz;
	}
	
	return grid;
}

void Grid_Draw(Grid *grid,Canvas *canvas,Palette *palette) {
	for(int j=0;j<grid->h;j++) {
		for(int i=0;i<grid->w;i++) {
			int x0=i*grid->sz;
			int y0=j*grid->sz;
			int x1=x0+grid->sz;
			int y1=y0+grid->sz;
			glBox(x0,y0,x1,y1,palette[3]);
		}
	}
}

