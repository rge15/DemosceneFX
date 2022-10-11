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

constexpr float PI = 3.14159265359;
uint32_t _screen[ TOTAL_PIXELS ];
int _sinus[512];

struct Blob
{
	int x { 0 }, y{ 0 };
	float speed { 0.f };
	float speedScaleX { 0.f }, speedScaleY { 0.f };
};

constexpr int numBlobs = 5;
Blob blobs[ numBlobs ];

void init()
{
	for(auto& blob : blobs)
	{
		blob.speedScaleX = rand() * 0.6;
		blob.speedScaleY = rand() * 0.6;
		blob.speed = rand() * PI * 32 - PI * 16;
		blob.x = rand()%WIDTH_SCREEN;
	}

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

auto min(auto val1, auto val2)
{
	if(val1 > val2)
		return val2;
	return val1;
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

	uint32_t x { 0 };
	uint32_t y { 0 };

	uint32_t time{ 1 }, shift { 0 };
	float anim { 0.f };
	int dbx { 0 }, dby { 0 }, sumDist{ 0 };
	uint32_t color { 0 };

	uint32_t* _ptrScreen = _screen;

	init();

	for(;;)
	{
		anim = time/50000;
		shift = 0;
		for(auto& blob : blobs)
		{

			//TODO : HAcer que vayan de forma aleatoria con unas ricas lissajous curves
			blob.x =  WIDTH_SCREEN/2 + (_sinus[(time + shift)%512]);
			blob.y =  (HEIGHT_SCRREN/2)*0.8 + (_sinus[(time + shift)%512]);
			
			shift += 20;
		}

		for(y = 0; y < HEIGHT_SCRREN; y++ )
		{
			for(x = 0 ; x < WIDTH_SCREEN; x++)
			{
				sumDist = 1.;
				for(auto& blob : blobs )
				{
					dbx = x - blob.x;
					dbx *= dbx;
					dby = y - blob.y;
					dby *= dby;
					sumDist *= sqrt( dbx + dby );
				}

				color = max( min( int(floor( sumDist )) , 255 ) , 0 );

				*_ptrScreen = color;
				++_ptrScreen;
			}
		}

		_ptrScreen = _screen;
		
		time +=1;
		ptc_update( _screen );
	}

	ptc_close();

	return 0;
}