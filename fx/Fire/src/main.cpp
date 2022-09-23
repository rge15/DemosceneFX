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
	uint32_t j = WIDTH_SCREEN * (HEIGHT_SCRREN - 1); 
	uint32_t* _ptrScreen = _screen + TOTAL_PIXELS - 1;
	for(;;)
	{

		for(i = TOTAL_PIXELS ; i > j ; i--)
		{
			uint32_t rngVal = rand();
			*_ptrScreen = ((rngVal%122 + 122) << 16 ) + ((rngVal%122) << 8) ;

			--_ptrScreen;
		};

		for(; i > 0 ; i--)
		{
			uint32_t rngVal = rand();

			auto moduleResult = i%WIDTH_SCREEN;
			if( moduleResult == 0 )
			{
				*_ptrScreen = ((rngVal%122 + 122) << 8 ) + (rngVal%122) ;
			}else if ( moduleResult == 1)
			{
				*_ptrScreen = ((rngVal%122 + 122) << 8 ) + (rngVal%122) ;
			}else
			{
				*_ptrScreen = (rngVal%122) ;
			}
			

			--_ptrScreen;
		};

		_ptrScreen = _screen + TOTAL_PIXELS - 1;
		ptc_update( _screen );
	}

	ptc_close();

	return 0;
}