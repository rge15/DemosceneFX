#include "FireFX.hpp"


FireFX::FireFX( uint32_t p_time, DrawerSrc& p_src ) noexcept
: bufferFX { p_time, p_src }
{
	Init();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void
FireFX::Init()
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void
FireFX::Render( uint32_t* p_bufferStart )
{
	uint32_t i { _widthScr }, fireValue { 0 };
	uint32_t* _ptrScreen = p_bufferStart + _pixelCount - 1;
	uint32_t rngVal { 0 };

	for( ; i > 0 ; i--)
	{
		//GET RANDOM VALUE
		rngVal = rand();

		//Sets a random default value on RED Channel
		*_ptrScreen = (rngVal%255)  << 16;

		//We pass into the prev pixel to set value
		--_ptrScreen;
	};

	_ptrScreen = p_bufferStart + _pixelCount - 1;

	i = _pixelCount - _widthScr;

	for( ; i > 0 ; i-- )
	{
		//We get the pointers to the around pixels
		uint32_t* prev = _ptrScreen-1;
		uint32_t* next = _ptrScreen+1;
		uint32_t* above = _ptrScreen-_widthScr;

		//And their value
		uint32_t prevVal = *prev;
		uint32_t nextVal = *next;
		uint32_t aboveVal = *above;
		uint32_t thisVal = *_ptrScreen;

		//We add all the around values and we divide by the number of values added
		fireValue = thisVal + prevVal + aboveVal + nextVal ;
		fireValue >>= 2;

		fireValue &= 0x00FF0000;

		if(fireValue <= 0x00330000)
			fireValue = 0;

		*above = fireValue;

		--_ptrScreen;

	}

}
