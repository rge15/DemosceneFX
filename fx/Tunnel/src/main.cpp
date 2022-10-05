extern "C"
{
	#include <tinyptc.h>
}
#include <cstdint>
#include <math.h>
#include <iostream>
#include "Sprite.hpp"

#define PI 3.14159265359 
#define WIDTH_SCREEN 720
#define HEIGHT_SCRREN 480
#define TOTAL_PIXELS ( WIDTH_SCREEN * HEIGHT_SCRREN )  

uint32_t _screen[TOTAL_PIXELS];
int distance[TOTAL_PIXELS];
//Para ahorrar memoria alomejor el de angles se puede hacer mucho más pequeño y normalizar los valores, aunque se quede un poco más feo
int angle[TOTAL_PIXELS];
float shade[TOTAL_PIXELS];
int widthText, heightText;

int min( int a, int b)
{
	if( a < b )
		return a;
	return b;
}

void init()
{
	float dy, dx;
	int ratio = 32;
	int maxDist = sqrt((-HEIGHT_SCRREN/2)*(-HEIGHT_SCRREN/2)+(-WIDTH_SCREEN/2)*(-WIDTH_SCREEN/2));
	for(int y {0}; y < HEIGHT_SCRREN; y++)
	{
		dy = (y - HEIGHT_SCRREN / 2);
		for(int x {0}; x < WIDTH_SCREEN; x++)
		{
			dx = (x - WIDTH_SCREEN / 2);
			distance[y*WIDTH_SCREEN + x] = int( ratio * heightText / sqrt( dy*dy + dx*dx ) )%heightText;
			angle[y*WIDTH_SCREEN + x] = 0.5 * widthText * (atan2( dy, dx )/ PI  );
			shade[y*WIDTH_SCREEN + x] = min(sqrt( dy * dy + dx * dx ),255.)/255.;
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

	float uvx, uvy, shadeValue;
	int shiftx, shifty;
	uint32_t time{0};

	uint32_t* ptr_screen = _screen;
	uint32_t color { 0 };
	uint8_t r { 0 },g { 0 },b { 0 };

	init();

	for(;;)
	{ 
		shiftx = widthText * 1 * time * 1/1000;
		shifty = heightText * 0.25 * time * 1/1000;

		for(i = 0; i < HEIGHT_SCRREN; i++)
		{
			for(j = 0; j < WIDTH_SCREEN; j++)
			{
				uvx = (unsigned int)(distance[i*WIDTH_SCREEN+j] + shiftx) % widthText;
				uvy = (unsigned int)(angle[i*WIDTH_SCREEN+j] + shifty) % heightText;
				shadeValue = shade[i*WIDTH_SCREEN+j];

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