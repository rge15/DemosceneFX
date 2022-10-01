extern "C"
{
	#include <tinyptc.h>
}
#include <cstdint>
#include <math.h>
#include <iostream>
#include <fstream>
#include "Sprite.hpp"

#define WIDTH_SCREEN 720
#define HEIGHT_SCRREN 480
#define TOTAL_PIXELS ( WIDTH_SCREEN * HEIGHT_SCRREN )  

uint32_t _screen[ TOTAL_PIXELS ];
int _sinus[512];

void init()
{
	// 360/512 = 0.703125
	// 1º = 0.0174533 rad
	float rad { 0.f }, resul;
	for(int i = 0; i < 512 ; i++)
	{
		rad = (i * 0.703125) * 0.0174533;
		resul = sin(rad);
		_sinus[i] = resul*255;
	}
}

float remap( float value, float actualMax, float targetMax )
{
	return (value * (targetMax / actualMax));
}

auto max(auto val1, auto val2)
{
	if(val1 > val2)
		return val1;
	return val2;
}

int main()
{
	ptc_open("window", WIDTH_SCREEN, HEIGHT_SCRREN);

	uint32_t i { 0 };
	uint32_t j { 0 };
	uint32_t finalCol { 0 };

	int uvx, uvy, time;

	uint32_t* _ptrScreen = _screen;

	Sprite spr1("img/readBin.data",2,2);

	for(;;)
	{

		//TODO : Esto es como dibujar un sprite en pantalla limpiarlo y dejarlo bonico
		for(i=0; i < spr1._height; i++)
		{
			for(j=0; j< spr1._width; j++)
			{
				_screen[i*WIDTH_SCREEN+j] = spr1._data[i*spr1._width+j];
			}
		}

		++time;
		ptc_update( _screen );
	}

	ptc_close();

	return 0;
}