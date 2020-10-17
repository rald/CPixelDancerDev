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



void checkered(int x,int y,Grid *grid,Palette *palette) {
	int sz=grid->sz;
	int hf=grid->sz/2;
	int x0=x*sz;
	int y0=y*sz;
	
	glBoxFilled(x0   ,y0   ,x0+hf,y0+hf,palette->colors[3]);
	glBoxFilled(x0+hf,y0   ,x0+sz,y0+hf,palette->colors[2]);
	glBoxFilled(x0   ,y0+hf,x0+hf,y0+sz,palette->colors[2]);
	glBoxFilled(x0+hf,y0+hf,x0+sz,y0+sz,palette->colors[3]);
		
}



void Grid_Draw(Grid *grid,Canvas *canvas,Palette *palette) {
	for(int j=0;j<grid->h;j++) {
		for(int i=0;i<grid->w;i++) {
			int x0=i*grid->sz;
			int y0=j*grid->sz;
			int x1=x0+grid->sz;
			int y1=y0+grid->sz;

			if(i>=0 && i<=canvas->w && j>=0 && j<=canvas->h) {
				if(canvas->pixels[i+j*canvas->w]==-1) {
					checkered(i,j,grid,palette);
				} else {
					glBoxFilled(x0,y0,x1,y1,palette->colors[canvas->pixels[i+j*canvas->w]]);
				}
			}
			
			if(grid->visible) {
				glBox(x0,y0,x1,y1,palette->colors[1]);
			}
		}
	}
	glBox(grid->x,grid->y,grid->x+grid->sz*grid->w,grid->y+grid->sz*grid->h,palette->colors[3]);
}



void Grid_HandleEvents(Grid *grid,Canvas *canvas,Palette *palette,int currentColorIndex) {

	glfwGetMousePos(&mouseX,&mouseY);
	
	int x=(mouseX-grid->x)/grid->sz;
	int y=(mouseY-grid->y)/grid->sz;

	if(glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT)==GLFW_PRESS) {
		if(x>=0 && x<=grid->w && y>=0 && y<=grid->h) {
			canvas->pixels[palette->colors[currentColorIndex]];
		}
	}
}
