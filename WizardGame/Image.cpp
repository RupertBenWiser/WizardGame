#include "Image.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


Image::Image(char* texture)
{
	int width, height, bpp;
	unsigned char* rgb = stbi_load(texture, &width, &height, &bpp, STBI_rgb_alpha);

	glGenTextures(1, &_tex);
	glBindTexture(GL_TEXTURE_2D, _tex);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, width, 0, GL_RGBA, GL_UNSIGNED_BYTE, rgb);

	glBindTexture(GL_TEXTURE_2D, 0);

	stbi_image_free(rgb);
}

void Image::bind() {
	glBindTexture(GL_TEXTURE_2D, _tex);
}

void Image::unbind() {
	glBindTexture(GL_TEXTURE_2D, 0);
}
