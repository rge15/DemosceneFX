#include "PlasmaUpFX.hpp"


PlasmaUpFX::PlasmaUpFX( uint32_t p_time ) noexcept
: bufferFX { p_time }
{
	Init();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void
PlasmaUpFX::Init()
{
	_jInitPos = _widthScr * (_heightScr - 2);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void
PlasmaUpFX::Render( uint32_t* p_bufferStart )
{
	uint32_t i { 0 }, fireValue { 0 };
	uint32_t j = _jInitPos;
	uint32_t* _ptrScreen = p_bufferStart + _pixelCount - 1;
	uint32_t rngVal { 0 };

	for(i = _pixelCount ; i > j ; i--)
	{
		//GET RANDOM VALUE
		rngVal = rand();

		//Sets a random default value on RED Channel
		*_ptrScreen = (rngVal%255)  << 16;

		//We pass inte the prev pixel to set value
		--_ptrScreen;
	};

	_ptrScreen = p_bufferStart + _pixelCount - 1;

	for( ; i > _widthScr ; i-- )
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

		fireValue &= 0x00FFFF00;

		if(fireValue <= 0x00300000)
			fireValue = 0;


		*above = fireValue;

		--_ptrScreen;

	}

}
