#include "FireUpDownFX.hpp"


FireUpDownFX::FireUpDownFX( uint32_t p_time, DrawerSrc& p_src ) noexcept
: bufferFX { p_time, p_src }
{
	Init();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void
FireUpDownFX::Init()
{
	_jInitPos = _widthScr * (_heightScr - 2);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void
FireUpDownFX::Render( uint32_t* p_bufferStart )
{
	uint32_t i { 0 }, fireValue { 0 };
	uint32_t* _ptrScreen = (p_bufferStart + _pixelCount - 1) - (_widthScr * _pos);
	uint32_t rngVal { 0 };

	for(i = 0 ; i <= _widthScr ; i++)
	{
		//GET RANDOM VALUE
		rngVal = rand();

		//Sets a random default value on RED Channel
		*_ptrScreen = (rngVal%255)  << 16;

		//We pass into the prev pixel to set value
		--_ptrScreen;
	};

	_ptrScreen = (p_bufferStart + _pixelCount - 1) - (_widthScr * _pos);
	i =  (_pixelCount - 1) - (_widthScr * _pos);

	for( ; i >= _widthScr ; i-- )
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

	_ptrScreen = (p_bufferStart + _pixelCount - 1) - (_widthScr * (_pos + 1) );
	i = (_pixelCount - 1) - (_widthScr *  _pos  );

	for( ; i <= _pixelCount - 1; i++ )
	{
		//We get the pointers to the around pixels
		uint32_t* prev = _ptrScreen-1;
		uint32_t* next = _ptrScreen+1;
		uint32_t* below = _ptrScreen+_widthScr;

		//And their value
		uint32_t prevVal = *prev;
		uint32_t nextVal = *next;
		uint32_t belowVal = *below;
		uint32_t thisVal = *_ptrScreen;

		//We add all the around values and we divide by the number of values added
		fireValue = thisVal + prevVal + belowVal + nextVal ;
		fireValue >>= 2;

		fireValue &= 0x00FF0000;

		if(fireValue <= 0x00330000)
			fireValue = 0;

		*below = fireValue;

		++_ptrScreen;

	}

	if( _pos >= _heightScr-2 )
		_speedY = -1;
	else if( _pos <= 2)
		_speedY = 1;

	_pos += _speedY;

}
