#ifndef _TEXTURE_INITIALIZED_
#define _TEXTURE_INITIALIZED_

#include "stb_image.h"

class Texture {
	unsigned int textureBuffer;
	int width, height;

	unsigned char* imageBuffer;

	int textureUniformLocation;
public:
	Texture(const char* path, const unsigned int const* program, const char* uniformName);

	~Texture();

	void setTexture();
};

#endif