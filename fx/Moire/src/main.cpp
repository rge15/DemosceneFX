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
	uint32_t finalCol { 0 };

	int uvx, uvy, p1x, p1y, p2x, p2y;
	uint32_t time{0}, length;
	
	int maxDistScreen = sqrt((HEIGHT_SCRREN/2)*(HEIGHT_SCRREN/2)+(WIDTH_SCREEN/2)*(WIDTH_SCREEN/2));

	init();

	std::cout << "Calculado tabla de senos" << std::endl;

	for(;;)
	{
		//TODO : Ver de ralentizar la velocidad de las bolas
		p1x = WIDTH_SCREEN/2 + (_sinus[(time>>2)%512]);
		p1y = HEIGHT_SCRREN/2 + (_sinus[(time/3)%512]);

		p2x = WIDTH_SCREEN/2 - (_sinus[((time+318)>>2)%512]);
		p2y = HEIGHT_SCRREN/2 + (_sinus[(time+318)%512]);


		for(i = 0; i < HEIGHT_SCRREN; i++ )
		{
			uvy = i;
			for(j = 0; j < WIDTH_SCREEN; j++)
			{
				//TODO : Hacer que las bandas se muevan hacia el centro de los puntos

				uvx = j;
				//?Position and behaviour of dots
				//?Variation I?
				length = sqrt((uvx-p1x)*(uvx-p1x)+(uvy-p1y)*(uvy-p1y));
				length ^= (uint32_t)(sqrt((uvx-p2x)*(uvx-p2x)+(uvy-p2y)*(uvy-p2y)));

				//?Variation II?
				// length = sqrt((uvx-p1x)*(uvx-p1x)+(uvy-p1y)*(uvy-p1y)) + time;
				// length ^= (uint32_t)(sqrt((uvx-p2x)*(uvx-p2x)+(uvy-p2y)*(uvy-p2y))-time);

				//?Colors and displays of the effect
				//?Variation I?
				length >>= 5;
				length &= 1;
				length *= 255;
				
				//?Variation II?
				// length &= 255;

				finalCol = (length << 16) + (length << 8) + length;

				_screen[i*WIDTH_SCREEN+j] = finalCol;
			}
		
		}

		++time;
		ptc_update( _screen );
	}

	ptc_close();

	return 0;
}