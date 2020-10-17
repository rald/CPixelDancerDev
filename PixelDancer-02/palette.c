#include "palette.h"



Palette *Palette_New(int numColors,...) {
	Palette *palette=malloc(sizeof(Palette));

	if(palette) {

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



void Palette_Free(Palette **palette) {
	free((*palette)->colors);
	(*palette)->colors=NULL;
	free(*palette);
	(*palette)=NULL;
}
