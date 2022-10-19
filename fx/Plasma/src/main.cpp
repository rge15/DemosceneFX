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
int _sinus[360];

void init()
{
	// 360/360 = 0.703125
	// 1º = 0.0174533 rad
	float rad { 0.f }, resul;
	for(int i = 0; i < 360 ; i++)
	{
		rad = (i) * 0.0174533;
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

	int uvx, uvy, uvy2, uvxtimed, uvytimed;
	uint32_t timeInx{0}, timeIny{0}, time{0};
	
	uint32_t mod1, mod2, remapUVxtimed, remapUVytimed;
	int value, valueR{0}, valueG {0} ;

	int maxDistScreen = sqrt((HEIGHT_SCRREN/2)*(HEIGHT_SCRREN/2)+(WIDTH_SCREEN/2)*(WIDTH_SCREEN/2));

	init();

	std::cout << "Calculado el seno" << std::endl;

	for(;;)
	{

		for( i = 0; i< HEIGHT_SCRREN; i++)
		{
			uvy = i - HEIGHT_SCRREN/2;
			uvy2 = i + _sinus[(time+270)%360];

			uvytimed = i + timeIny;
			
			uvy %= HEIGHT_SCRREN;
			uvytimed %= HEIGHT_SCRREN;

			remapUVytimed = (uint32_t)remap(uvytimed, HEIGHT_SCRREN, 360 );

			for( j = 0; j < WIDTH_SCREEN; j++)
			{
				uvx =  j - WIDTH_SCREEN/3;
				uvxtimed = (j << 2) + timeInx;
				
				uvx %= WIDTH_SCREEN;
				uvxtimed %= WIDTH_SCREEN;
				
				mod1 = uvx * uvx  + uvy * uvy;
				mod1 *= 1/mod1;
				mod1 -= timeInx;
				mod1 %= 360;

				uvx += _sinus[(time)%360];
				mod2 = sqrt(uvx*uvx+uvy2*uvy2);
				mod2 += timeInx + mod2;
				mod2 %= maxDistScreen;

				mod2 = remap(mod2, maxDistScreen, 360);

				remapUVxtimed = (uint32_t)remap(uvxtimed, WIDTH_SCREEN, 360 );

				//? GOOD VARIATION
				// value = abs(_sinus[remapUVxtimed] + _sinus[remapUVytimed] + _sinus[mod1] + _sinus[mod2]);
				value = max( _sinus[remapUVxtimed] + _sinus[remapUVytimed] + _sinus[mod1] + _sinus[mod2],0);
				
				value >>= 1;

				value %= 360;

				valueR = max(_sinus[value],0);
				valueG = max(_sinus[((value+270)%360)],0);

				value = valueR;
				value <<= 8;
				value += valueG;
				value <<= 8;
				// value += max(_sinus[(j+timeInx)%360],0);

				_screen[i*WIDTH_SCREEN+j] = value;
			}
		}

		timeInx += 2;
		timeIny += 3;
		time +=1;

		ptc_update( _screen );
	}

	ptc_close();

	return 0;
}