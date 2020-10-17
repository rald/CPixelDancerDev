#include <GL/glfw.h>
#include <GL/gl2d.h>



#define GAME_TITLE "PixelDancer"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480



GLuint palette[]={
	GL2D_RGBA(  0,  0,  0,255),
	GL2D_RGBA(103,103,103,255),
	GL2D_RGBA(182,182,182,255),
	GL2D_RGBA(255,255,255,255)
};

int numPalette=4;



bool inrect(int x,int y,int rx,int ry,int rw,int rh) {
	return x>=rx && x<=rx+rw && y>=ry && y<=ry+rh;
}



void Grid_Draw(int x,int y,int size,int w,int h,int *pixels,GLuint *palette) {
	for(int j=0;j<h;j++) {
		for(int i=0;i<w;i++) {
			int xc=i*size+x;
			int yc=j*size+y;
			if(pixels[i+j*w]==-1) {
				glBoxFilled(xc,yc,xc+size/2,yc+size/2,palette[3]);					
				glBoxFilled(xc+size/2,yc,xc+size,yc+size/2,palette[2]);					
				glBoxFilled(xc,yc+size/2,xc+size/2,yc+size,palette[2]);					
				glBoxFilled(xc+size/2,yc+size/2,xc+size,yc+size,palette[3]);								
			} else {
				glBoxFilled(xc,yc,xc+size,yc+size,palette[pixels[i+j*w]]);			
			}
			glBox(xc,yc,xc+size,yc+size,palette[1]);			
		}
	}
	glBox(x,y,x+w*size,y+h*size,palette[3]);
}



void Palette_Draw(int x,int y,int size,int currentPalette,int numPalette,GLuint *palette) {
	for(int i=-1;i<numPalette;i++) {
		int xc=(i+1)*size+x;
		int yc=y;
		if(i==-1) {
			glBoxFilled(xc+4,yc+4,xc+size/2,yc+size/2,palette[3]);					
			glBoxFilled(xc+size/2,yc+4,xc+size-4,yc+size/2,palette[2]);					
			glBoxFilled(xc+4,yc+size/2,xc+size/2,yc+size-4,palette[2]);					
			glBoxFilled(xc+size/2,yc+size/2,xc+size-4,yc+size-4,palette[3]);								
		} else {
			glBoxFilled(xc+4,yc+4,xc+size-4,yc+size-4,palette[i]);					
		}
	}
	glBox((currentPalette+1)*size+x,y,(currentPalette+1)*size+size+x,size+y,palette[3]);					
}



int main(int argc, char *argv[]) {

	double timeStart=0;
	bool quit=false;
	int mouseX=0,mouseY=0;

	int bitmapWidth=16;
	int bitmapHeight=16;

	int bitmapPixels[bitmapHeight*bitmapWidth];

	int gridSize=16;

	int gridX=0,gridY=0;

	int paletteX=0,paletteY=SCREEN_HEIGHT-1-32;

	int paletteSize=32;
	
	int currentPalette=0;

	glScreenInit(SCREEN_WIDTH,SCREEN_HEIGHT);
	glfwSetWindowTitle(GAME_TITLE);
	glfwSwapInterval(1);
	glBlendMode(GL2D_ALPHA);

	for(int j=0;j<bitmapHeight;j++) {
		for(int i=0;i<bitmapWidth;i++) {
			bitmapPixels[i+j*bitmapWidth]=-1;
		}
	}
	
	while(!quit) {

		glfwGetMousePos(&mouseX,&mouseY);

		glBoxFilled(0,0,SCREEN_WIDTH-1,SCREEN_HEIGHT-1,palette[1]);

		Grid_Draw(gridX,gridY,gridSize,bitmapWidth,bitmapHeight,bitmapPixels,palette);

		Palette_Draw(paletteX,paletteY,paletteSize,currentPalette,numPalette,palette);

		if(glfwGetMouseButton(GLFW_MOUSE_BUTTON_LEFT)) {

			if(inrect(mouseX,mouseY,0,0,bitmapWidth*gridSize,bitmapHeight*gridSize)) {
				int x=(mouseX-gridX)/gridSize;
				int y=(mouseY-gridY)/gridSize;
				if(x>=0 && x<=bitmapWidth && y>=0 && y<=bitmapHeight) {
					bitmapPixels[x+y*bitmapWidth]=currentPalette;
				}
			}
	
			if(inrect(mouseX,mouseY,paletteX,paletteY,(numPalette+1)*paletteSize+paletteX,paletteY+paletteSize)) {
				int i=(mouseX-paletteX)/paletteSize-1;
				if(i>=-1 && i<numPalette) {
					currentPalette=i;
				}
			}

		}

		glfwSwapBuffers();

		timeStart=glfwGetTime();
		while(glfwGetTime()-timeStart<1.0/60.0) {};

		quit=glfwGetKey(GLFW_KEY_ESC)|!glfwGetWindowParam(GLFW_OPENED);

	}

	glfwTerminate();

	return 0;
}
