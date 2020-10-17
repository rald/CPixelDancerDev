#include <GL/glfw.h>
#include <GL/gl2d.h>

#include "palette.h"



#define GAME_TITLE "PixelDancer"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600



bool inrect(int x,int y,int rx,int ry,int rw,int rh) {
	return x>=rx && x<=rx+rw && y>=ry && y<=ry+rh;
}



int main(int argc, char *argv[]) {

	double timeStart=0;
	bool quit=false;

	glScreenInit(SCREEN_WIDTH,SCREEN_HEIGHT);
	glfwSetWindowTitle(GAME_TITLE);
	glfwSwapInterval(1);
	glBlendMode(GL2D_ALPHA);

	Palette *palette=Palette_New(
		0,0,4,32,0,4,
		GL2D_RGBA(  0,  0,  0,255),
		GL2D_RGBA(103,103,103,255),
		GL2D_RGBA(182,182,182,255),
		GL2D_RGBA(255,255,255,255)
	);

	while(!quit) {

		glBoxFilled(0,0,SCREEN_WIDTH-1,SCREEN_HEIGHT-1,palette->colors[1]);

		Palette_Draw(palette);

		glfwSwapBuffers();

		timeStart=glfwGetTime();
		while(glfwGetTime()-timeStart<1.0/60.0) {};

		quit=glfwGetKey(GLFW_KEY_ESC)|!glfwGetWindowParam(GLFW_OPENED);

	}

	glfwTerminate();

	return 0;
}
