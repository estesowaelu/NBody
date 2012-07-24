#ifndef _LOADJPG_H
#define _LOADJPG_H

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "glut.h"

#include "corona.h"

class LoadTexture
{
public:

	LoadTexture();
	~LoadTexture();
	
	int load(char *filename);

};

#endif
