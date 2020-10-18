#include "palette.h"



Palette *Palette_New(int x,int y,int w,int sz,int numColors,...) {
	Palette *palette=malloc(sizeof(Palette));

	if(palette) {

		palette->x=x;
		palette->y=y;
		palette->w=w;
		palette->sz=sz;

		palette->numColors=numColors;
		palette->colors=malloc(sizeof(GLuint)*numColors);
		palette->idx=0;
		
		va_list args;
		va_start(args,numColors);
		for(int i=0;i<numColors;i++) {
			palette->colors[i]=va_arg(args,GLuint);
		}
		va_end(args);
	}

	return palette;
}



void Palette_Free(Palette **palette) {
	free((*palette)->colors);
	(*palette)->colors=NULL;
	free(*palette);
	(*palette)=NULL;
}


void Palette_DrawCursor(Palette *palette,int i) {
	int hf=palette->sz/2;
	int sz=palette->sz;
	int x0=((i+1)%palette->w)*sz+palette->x;
	int y0=((i+1)/palette->w)*sz+palette->y;
	int x1=x0+sz;
	int y1=y0+sz;
	
	if(i==-1) { 
		glBoxFilled(x0+4,y0+4,x0+hf,y0+hf,palette->colors[3]);
		glBoxFilled(x0+hf,y0+4,x0+sz-4,y0+hf,palette->colors[2]);
		glBoxFilled(x0+4,y0+hf,x0+hf,y0+sz-4,palette->colors[2]);
		glBoxFilled(x0+hf,y0+hf,x0+sz-4,y0+sz-4,palette->colors[3]);
	} else {
		glBoxFilled(x0+4,y0+4,x1-4,y1-4,palette->colors[i]);
	}

	if(i==palette->idx) {
		glBox(x0,y0,x1,y1,palette->colors[3]);		
	}
}

void Palette_EraseCursor(Palette *palette) {
	int x2=((palette->idx+1)%palette->w)*palette->sz+palette->x;
	int y2=((palette->idx+1)/palette->w)*palette->sz+palette->y;
	int x3=x2+palette->sz;
	int y3=y2+palette->sz;

	glBox(x2,y2,x3,y3,palette->colors[1]);
}

void Palette_Draw(Palette *palette) {
	for(int i=-1;i<palette->numColors;i++) {
		Palette_DrawCursor(palette,i);
	}
}

void Palette_HandleEvents(Palette *palette) {
	
	int mouseX,mouseY;

	glfwGetMousePos(&mouseX,&mouseY);

	if(glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT)==GLFW_PRESS) {

		for(int i=-1;i<palette->numColors;i++) {
			int x0=((i+1)%palette->w)*palette->sz+palette->x;
			int y0=((i+1)/palette->w)*palette->sz+palette->y;
			int x1=x0+palette->sz;
			int y1=y0+palette->sz;
			
			if(mouseX>=x0 && mouseX<=x1 && mouseY>=y0 && mouseY<=y1) {
				Palette_EraseCursor(palette);
				Palette_DrawCursor(palette,i);
				palette->idx=i;
				break;
			}
		}

	}

}
