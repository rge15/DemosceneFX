extern "C"
{
	#include <tinyptc.h>
}
#include <cstdint>
#include <math.h>
#include <iostream>

#define WIDTH_SCREEN 720
#define HEIGHT_SCRREN 480
#define HALF_WIDTH_SCREEN 720/2
#define HALF_HEIGHT_SCRREN 480/2
#define TOTAL_PIXELS ( WIDTH_SCREEN * HEIGHT_SCRREN )  

constexpr float PI = 3.14159265359;
uint32_t _screen[ TOTAL_PIXELS ];
int _sinus[512];

struct Blob
{
	int x { 0 }, y{ 0 };
	int speedScaleX { 0 }, speedScaleY { 0 };
};

constexpr int numBlobs = 5;
Blob blobs[ numBlobs ];

void init()
{
	for(auto& blob : blobs)
	{
		blob.speedScaleX = rand()%4;
		blob.speedScaleY = rand()%4;
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

	uint32_t time{ 0 };
	int dbx { 0 }, dby { 0 };
	float sumDist { 0.f };
	uint32_t color { 0 };

	uint32_t* _ptrScreen = _screen;

	init();

	for(;;)
	{
		for(auto& blob : blobs)
		{
			//TODO : HAcer que vayan de forma aleatoria con unas ricas lissajous curves
			blob.x =  HALF_WIDTH_SCREEN + (_sinus[( (time >> blob.speedScaleX) + time )%512]);
			blob.y =  HALF_HEIGHT_SCRREN + (_sinus[( (time >> blob.speedScaleY) + time + 381)%512]);
		}

		for(y = 0; y < HEIGHT_SCRREN; y++ )
		{
			for(x = 0 ; x < WIDTH_SCREEN; x++)
			{
				sumDist = .05;
				for(auto& blob : blobs )
				{
					dbx = x - blob.x;
					dbx *= dbx;
					dby = y - blob.y;
					dby *= dby;
					sumDist *= sqrt( dbx + dby );
				}

				//?Variant I
				color = max( min( int( floor( sumDist ) ) , 255 ) , 0 );
				
				//?Variant II
				// color = max( min(  5 * int(floor(  sumDist )) , 255 ) , 0 );

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