extern "C"
{
	#include <tinyptc.h>
}
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
			//GET RANDOM VALUE
			uint32_t rngVal = rand();

			//Sets a random default value on RED Channel
			*_ptrScreen = (rngVal%255) << 16;

			//Handler of variation for one randmo Color Value   
			uint8_t variationColour = 200;
			//Some random value for setting a higher Color Value   
			if(rngVal%3 == 1)
				*_ptrScreen = (rngVal%55 + variationColour) << 16;

			//Also randomly we set a 0 Color Value 
			if(rngVal%9 == 1)
				*_ptrScreen = 0;

			//We pass inte the prev pixel to set value
			--_ptrScreen;
		};

		//We set the screen pointer to the penultimate last row for setting the values to the next row 
		_ptrScreen = _screen + TOTAL_PIXELS - 1 - WIDTH_SCREEN;

		//Fire color value
		uint32_t  fireValue { 0 };
		//!	FIRE DISPERSION MATHS
		for( ; i > WIDTH_SCREEN ; i--)
		{

			//We get the pointers to the around pixels
			uint32_t* prev = _ptrScreen-1;
			uint32_t* next = _ptrScreen+1;
			uint32_t* above = _ptrScreen-WIDTH_SCREEN;

			//And their value
			uint32_t prevVal = *prev;
			uint32_t nextVal = *next;
			uint32_t aboveVal = *above;
			uint32_t thisVal = *_ptrScreen;

			//We add all the around values and we divide by the number of value
			fireValue = thisVal + prevVal + aboveVal + nextVal ;
			fireValue >>= 2;

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