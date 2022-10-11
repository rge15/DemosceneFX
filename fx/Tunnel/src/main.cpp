extern "C"
{
	#include <tinyptc.h>
}
#include <cstdint>
#include <math.h>
#include <iostream>
#include "Sprite.hpp"

constexpr float PI = 3.14159265359;
constexpr int WIDTH_SCREEN = 720;
constexpr int HEIGHT_SCRREN = 480;
constexpr int TOTAL_PIXELS = WIDTH_SCREEN * HEIGHT_SCRREN;  

uint32_t _screen[TOTAL_PIXELS];
int distance[TOTAL_PIXELS*4];
int angle[TOTAL_PIXELS*4];
float shade[TOTAL_PIXELS*4];
int widthText = 0, heightText = 0;

int min( int a, int b)
{
	if( a < b )
		return a;
	return b;
}

void init()
{
	float dy{ 0 }, dx{ 0 };
	int ratio = 32;

	int doubleHeight = HEIGHT_SCRREN * 2;
	int doubleWidth = WIDTH_SCREEN * 2;

	for(int y = 0; y < doubleHeight ; y++)
	{
		dy = y - HEIGHT_SCRREN ;
		for(int x = 0; x < doubleWidth ; x++)
		{
			dx = x - WIDTH_SCREEN;
			distance[y*(WIDTH_SCREEN*2) + x] = int( ratio * heightText / sqrt( dy*dy + dx*dx ) ) % heightText;
			angle[y*(WIDTH_SCREEN*2) + x] = (unsigned int) 2 * widthText * atan2( dy, dx )/ PI;
			shade[y*(WIDTH_SCREEN*2) + x] = min(sqrt( dy * dy + dx * dx ),255.)/255.;
		}
	}
}

int main()
{
	ptc_open("window", WIDTH_SCREEN, HEIGHT_SCRREN);

	uint32_t i { 0 };
	uint32_t j { 0 };

	Sprite spr("img/prueba.png");

	widthText = spr._width;
	heightText = spr._height;

	float uvx { 0.f }, uvy { 0.f }, shadeValue { 0.f };
	int shiftx {0}, shifty{0}, centerx{0}, centery{0}, bufferPos{0};
	uint32_t time{0};

	uint32_t* ptr_screen = _screen;
	uint32_t color { 0 };
	uint8_t r { 0 },g { 0 },b { 0 };

	init();

	for(;;)
	{ 
		shiftx = widthText * 2 * time * 1/1000;
		shifty = heightText * 0.25 * time * 1/1000;

		//TODO : ESto habrá q cambiarlo por una tabla de sinus precalculada
		centerx = WIDTH_SCREEN / 2 + WIDTH_SCREEN / 4 * (sin(time*7./1000.));
		centery = HEIGHT_SCRREN / 2 + HEIGHT_SCRREN / 3 * (sin(time*11./1000.));

		for(i = 0; i < HEIGHT_SCRREN; i++)
		{
			for(j = 0; j < WIDTH_SCREEN; j++)
			{
				bufferPos = (i+centery)*WIDTH_SCREEN*2 + j + centerx;

				uvx = (unsigned int)(distance[ bufferPos ] + shiftx) % widthText;
				uvy = (unsigned int)(angle[ bufferPos ] + shifty) % heightText;
				shadeValue = shade[ bufferPos ];

				//?Esto se podrá hacer de alguna forma más eficiente?
				color = spr._data[uvy*widthText + uvx];

				r = (color >> 16) * shadeValue;
				g = (color >> 8) * shadeValue;
				b = color * shadeValue;

				color = (r << 16) + (g << 8) + b;

				*ptr_screen = color;
				++ptr_screen;
			}
		}

		++time;
		ptc_update( _screen );
		ptr_screen = _screen;
	}

	ptc_close();

	return 0;
}