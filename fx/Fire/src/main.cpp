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

	uint32_t i { 0 };
	uint32_t j = WIDTH_SCREEN * (HEIGHT_SCRREN - 2);
	uint32_t* _ptrScreen = _screen + TOTAL_PIXELS - 1;

	for(;;)
	{
		//! BASE LINES VALUE
		for(i = TOTAL_PIXELS ; i > j ; i--)
		{
			uint32_t rngVal = rand();

			*_ptrScreen = (rngVal%255) << 16;

			// if(rngVal%3 == 1)
				// *_ptrScreen = ((rngVal%122+122) << 16) + ((rngVal%255) << 8);

			if(rngVal%30 == 1)
				*_ptrScreen = 0;

			--_ptrScreen;
		};

		_ptrScreen = _screen + TOTAL_PIXELS - WIDTH_SCREEN;

		//!	FIRE DISPERSION MATHS
		for( ; i > WIDTH_SCREEN ; i--)
		{

			uint32_t* prev = _ptrScreen-1;
			uint32_t* next = _ptrScreen+1;
			uint32_t* above = _ptrScreen-WIDTH_SCREEN;

			uint32_t prevVal = *prev;
			uint32_t nextVal = *next;
			uint32_t aboveVal = *above;
			uint32_t thisVal = *_ptrScreen;

			uint32_t  fireValue { 0 };

			auto moduleResult = i%WIDTH_SCREEN;
			if( moduleResult == 0 ) //RIGHT BAND SCREEN
			{
				fireValue = thisVal + prevVal + aboveVal;
				fireValue /= 3;
			}else if ( moduleResult == 1) //LEFT BAND SCREEN
			{
				fireValue = thisVal + nextVal + aboveVal;
				fireValue /= 3;
			}else //MIDDLE SCREEN
			{
				fireValue = thisVal + prevVal + aboveVal + nextVal ;
				fireValue >>= 2;
			}

			//! COLOR VARIATION
			//?VARIANT I?
			// fireValue &= 0x00FFFF00;

			//?VARIANT II?
			// fireValue &= 0x00FFFF00;

			// if(fireValue <= 0x00300000)
				// fireValue = 0;

			//?VARIANT III?
			// if(fireValue <= 0x00300000)
				// fireValue = 0;
			
			//?VARIANT IV?
			fireValue &= 0x00FF0000;

			if(fireValue <= 0x00300000)
				fireValue = 0;

			*above = fireValue;

			--_ptrScreen;
		};

		_ptrScreen = _screen + TOTAL_PIXELS - 1;
		ptc_update( _screen );
	}

	ptc_close();

	return 0;
}