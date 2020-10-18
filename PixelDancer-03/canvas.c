#include "canvas.h"



Canvas *Canvas_New(int x,int y,int w,int h,int sz) {
	Canvas *canvas=malloc(sizeof(Canvas));
	if(canvas) {
		canvas->x=x;
		canvas->y=y;
		canvas->w=w;
		canvas->h=h;
		canvas->sz=sz;
		canvas->pixels=malloc(sizeof(int)*(w*h));

		for(int j=0;j<h;j++) {
			for(int i=0;i<w;i++) {
				canvas->pixels[i+j*w]=-1;
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



static void Canvas_DrawCell(Canvas *canvas,Palette *palette,int x,int y) {
	int hf=canvas->sz/2;
	int sz=canvas->sz;
	int x0=x*sz+canvas->x;
	int y0=y*sz+canvas->y;
	int x1=x0+sz;
	int y1=y0+sz;
	int pixel=canvas->pixels[x+y*canvas->w];

	if(pixel==-1) {
		glBoxFilled(x0,y0,x0+hf,y0+hf,palette->colors[3]);
		glBoxFilled(x0+hf,y0,x0+sz,y0+hf,palette->colors[2]);
		glBoxFilled(x0,y0+hf,x0+hf,y0+sz,palette->colors[2]);
		glBoxFilled(x0+hf,y0+hf,x0+sz,y0+sz,palette->colors[3]);			
	} else {
		glBoxFilled(x0,y0,x1,y1,palette->colors[pixel]);
	}
	
	glBox(x0,y0,x1,y1,palette->colors[1]);
}


void Canvas_Draw(Canvas *canvas,Palette *palette) {
	for(int j=0;j<canvas->h;j++) {
		for(int i=0;i<canvas->w;i++) {
			Canvas_DrawCell(canvas,palette,i,j);
		}
	}
}



void Canvas_HandleEvents(Canvas *canvas,Palette *palette) {
	int mouseX,mouseY;

	glfwGetMousePos(&mouseX,&mouseY);
	
	int x=(mouseX-canvas->x)/canvas->sz;
	int y=(mouseY-canvas->y)/canvas->sz;

	if(glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT)==GLFW_PRESS) {

		if(x>=0 && x<=canvas->w && y>=0 && y<=canvas->h) {
			canvas->pixels[x+y*canvas->w]=palette->idx;
			Canvas_DrawCell(canvas,palette,x,y);
		}

	}
	
	if(glfwGetMouseButton(GLFW_MOUSE_BUTTON_RIGHT)==GLFW_PRESS) {
		if(x>=0 && x<=canvas->w && y>=0 && y<=canvas->h) {
			Palette_EraseCursor(palette);
			palette->idx=canvas->pixels[x+y*canvas->w];
			Palette_DrawCursor(palette,palette->idx);
			
		}
	}

	if(glfwGetMouseButton(GLFW_MOUSE_BUTTON_MIDDLE)==GLFW_PRESS) {
		int pixel=canvas->pixels[x+y*canvas->w];
		if(pixel!=palette->idx) {
			Canvas_FloodFill(canvas,palette,x,y,pixel);
		}
	}

}


void Canvas_FloodFill(Canvas *canvas,Palette *palette,int x,int y,int targetColorIndex) {

	if(x<0 || x>=canvas->w || y<0 || y>=canvas->h) return;

	if(canvas->pixels[x+y*canvas->w]==targetColorIndex) {

		canvas->pixels[x+y*canvas->w]=palette->idx;

		Canvas_DrawCell(canvas,palette,x,y);

		Canvas_FloodFill(canvas,palette,x,y-1,targetColorIndex);
		Canvas_FloodFill(canvas,palette,x,y+1,targetColorIndex);
		Canvas_FloodFill(canvas,palette,x-1,y,targetColorIndex);
		Canvas_FloodFill(canvas,palette,x+1,y,targetColorIndex);
		
	}
 
}
