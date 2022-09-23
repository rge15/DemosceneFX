extern "C"
{
	#include <tinyptc.h>
}
#include <cstdlib>
#include <cstdint>

#define WIDTH_SCREEN 720
#define HEIGHT_SCRREN 480
#define TOTAL_PIXELS ( WIDTH_SCREEN * HEIGHT_SCRREN )  

uint32_t _screen[ TOTAL_PIXELS ];

int main()
{
	ptc_open("window", WIDTH_SCREEN, HEIGHT_SCRREN);

	uint32_t i = 0;
	uint32_t j = WIDTH_SCREEN * (HEIGHT_SCRREN - 10) ; 
	uint32_t* _ptrScreen = _screen;
	for(;;)
	{

		for( i = 0; i < j ; i++)
		{
			// _screen[i] = 0x0000FF00;
			*_ptrScreen = rand();

			++_ptrScreen;
		};

		for( ; i < TOTAL_PIXELS ; i++)
		{
			*_ptrScreen = rand();
			++_ptrScreen;
		};

		_ptrScreen = _screen;
		ptc_update( _screen );
	}

	ptc_close();

	return 0;
}