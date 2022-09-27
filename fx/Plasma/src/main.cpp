extern "C"
{
	#include <tinyptc.h>
}
#include <cstdint>
#include <math.h>
#include <iostream>

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
	uint32_t* _ptrScreen = _screen + TOTAL_PIXELS - 1;

	int uvx, uvy;
	uint32_t timeInx{0}, timeIny{0};
	
	uint32_t lenght;
	int value, valueR, valueG ;

	init();

	std::cout << "Calculado el seno" << std::endl;

	for(;;)
	{

		for( i = 0; i< HEIGHT_SCRREN; i++)
		{
			uvy = i + timeIny;
			uvy %= HEIGHT_SCRREN;
			auto remapValY = (uint32_t)remap(uvy, HEIGHT_SCRREN, 512 );

			for( j = 0; j < WIDTH_SCREEN; j++)
			{
				uvx =  (j * 5.) + timeInx;
				uvx %= WIDTH_SCREEN;
				
				lenght = (uvx << 1) + (uvy << 1);
				lenght *= 1/lenght;
				lenght -= timeInx;
				lenght %= 512;

				auto remapValX = (uint32_t)remap(uvx, WIDTH_SCREEN, 512 );

				value = max(_sinus[remapValX] + _sinus[remapValY] + _sinus[lenght],0);

				value /= 3;

				valueR = _sinus[value];

				value = valueR;
				value <<= 16;

				_screen[i*WIDTH_SCREEN+j] = value;
			}
		}

		timeInx += 2;
		timeIny += 1;

		ptc_update( _screen );
	}

	ptc_close();

	return 0;
}