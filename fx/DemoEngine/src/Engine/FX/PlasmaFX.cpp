#include "PlasmaFX.hpp"

PlasmaFX::PlasmaFX( uint32_t p_time, DrawerSrc& p_src ) noexcept
: bufferFX { p_time, p_src }
{
	Init();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void
PlasmaFX::Init()
{
	maxDistScreen = sqrt((_heightScr/2)*(_heightScr/2)+(_widthScr/2)*(_widthScr/2));
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void
PlasmaFX::Render( uint32_t* p_bufferStart )
{
	uint32_t mod1, mod2, remapUVxtimed, remapUVytimed;
	int value, valueR{0}, valueG {0};
	int uvx, uvy, uvy2, uvxtimed, uvytimed;

	for(uint32_t i = 0; i< _heightScr; i++)
	{
		uvy = i - _heightScr/2;
		uvy2 = i + _src._colourSinus[(_time + _cosOffsetTable ) % _sinusTableIndices ];

		uvytimed = i + _timeIny;

		uvy %= _heightScr;
		uvytimed %= _heightScr;

		remapUVytimed = DemoMath::remap(uvytimed, _heightScr, _sinusTableIndices );

		for(uint32_t j = 0; j < _widthScr; j++)
		{
			uvx =  j - _widthScr/3;
			uvxtimed = (j << 2) + _timeInx;
			
			uvx %= _widthScr;
			uvxtimed %= _widthScr;
			
			mod1 = uvx * uvx  + uvy * uvy;
			mod1 *= 1/mod1;
			mod1 -= _timeInx;
			mod1 %= _sinusTableIndices;

			uvx += _src._colourSinus[(_time)%_sinusTableIndices];
			mod2 = sqrt(uvx*uvx+uvy2*uvy2);
			mod2 += _timeInx + mod2;
			mod2 %= maxDistScreen;

			mod2 = DemoMath::remap(mod2, maxDistScreen, _sinusTableIndices);

			remapUVxtimed = DemoMath::remap(uvxtimed, _widthScr, _sinusTableIndices );

			value = DemoMath::max<int>( _src._colourSinus[remapUVxtimed] + _src._colourSinus[remapUVytimed] + _src._colourSinus[mod1] + _src._colourSinus[mod2],0);			

			value >>= 1;

			value %= _sinusTableIndices;

			valueR = DemoMath::max<int>(_src._colourSinus[value],0);
			valueG = DemoMath::max<int>(_src._colourSinus[((value + _cosOffsetTable )%_sinusTableIndices)],0);

			value = valueR;
			value <<= 8;
			value += valueG;
			value <<= 8;

			p_bufferStart[i*_widthScr+j] = value;
		}
	}

	_timeInx += 2;
	_timeIny += 3;
	_time +=1;


}
