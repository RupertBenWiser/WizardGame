#pragma once

class Image
{
private:
	int width;
	int height;
	int bpp;
	unsigned char* rgb;
public:
	Image();
	~Image();

	unsigned char* getImage();
	int getWidth();
	int getHeight();
};

