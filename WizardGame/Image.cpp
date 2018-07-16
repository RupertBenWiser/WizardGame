#include "Image.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


Image::Image()
{
	rgb = stbi_load("test.png", &width, &height, &bpp, STBI_rgb_alpha);
}


Image::~Image()
{
	stbi_image_free(rgb);
}

unsigned char* Image::getImage() {
	return rgb;
}

int Image::getWidth() {
	return this->width;
}

int Image::getHeight() {
	return height;
}
