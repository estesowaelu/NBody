#include "loadTexture.h"


using namespace corona;

LoadTexture::LoadTexture()
{


}

LoadTexture::~LoadTexture()
{


}

int LoadTexture::load(char *filename)
{
	Image* image;
	GLuint texname;
	image=OpenImage(filename, PF_R8G8B8A8);
	if(!image)
	{
		printf("Error loading image file: %s\n", filename);
		return 0;
	}

	int width  = image->getWidth();
	int height = image->getHeight();
	image=FlipImage(image, CA_X);
	
	// Generate texture names
	glGenTextures(1, &texname);
	
	// bind a named texture to a texturing target
	glBindTexture(GL_TEXTURE_2D, texname);
	
	// set pixel storage modes
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	// build a 2D mipmap - builds a series of prefiltered 2D texture maps of decreasing resolutions
	gluBuild2DMipmaps(GL_TEXTURE_2D, 4, width, height, GL_RGBA, GL_UNSIGNED_BYTE, image->getPixels());


	// set texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//use GL_MODULATE for standard texturing
	//GL_DECAL for unlightedness
	//GL_BLEND for interaction with a background color using alpha channel of image
	//GL_REPLACE to completely disregard lighting and replace it with the actual colors from the texture image
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	float col[]={1, 1, 1, 1};
	//I think this sets the background color of the object for GL_BLEND
	glTexEnvfv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, col);

	delete image;
		printf("Loading tex %i\n", texname);
	return texname;

}
