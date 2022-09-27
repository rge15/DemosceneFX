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
	
	uint32_t mod1, mod2, remapUVx, remapUVy;
	int value, valueR, valueG ;

	init();

	std::cout << "Calculado el seno" << std::endl;

	for(;;)
	{

		for( i = 0; i< HEIGHT_SCRREN; i++)
		{
			uvy = (i * 0.5) + timeIny;
			uvy %= HEIGHT_SCRREN;
			remapUVy = (uint32_t)remap(uvy, HEIGHT_SCRREN, 512 );

			for( j = 0; j < WIDTH_SCREEN; j++)
			{
				//TODO : Mañana tengo que revisar todo el efecto y tener en cuenta que en el shadertoy
				//TODO : Todos los usos de UV estan noramlizados de -1 a 1
				//TODO : Crear una variable mapeada de -1 a 1 puede ayudar
				uvx =  (j << 2) + timeInx;
				uvx %= WIDTH_SCREEN;

				remapUVx = (uint32_t)remap(uvx, WIDTH_SCREEN, 512 );

				mod1 = uvx * uvx  + uvy * uvy;
				mod1 *= 1/mod1;
				mod1 -= timeInx;
				mod1 %= 512;

				value = max(_sinus[remapUVx] + _sinus[remapUVy] + _sinus[mod1],0);
				value >>= 2;

				uint32_t cx = uvx * 0.5 * _sinus[timeInx%512];
				uint32_t cy = uvy * 0.5 * _sinus[timeIny%512];

				value = (cx*cx)%512;

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