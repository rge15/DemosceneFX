#include "PlasmaFX.hpp"

PlasmaFX::PlasmaFX( uint32_t p_time ) noexcept
: bufferFX { p_time }
{
	Init();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void
PlasmaFX::Init()
{
	// 1º = 0.0174533 rad
	float rad { 0.f }, resul;
	for(int i = 0; i < 360 ; i++)
	{
		rad = (i) * 0.0174533;
		resul = sin(rad);
		//Range for a color channel
		_sinus[i] = resul*255;
	}

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
		uvy2 = i + _sinus[(_time+270)%360];

		uvytimed = i + _timeIny;

		uvy %= _heightScr;
		uvytimed %= _heightScr;

		remapUVytimed = DemoMath::remap(uvytimed, _heightScr, 360 );

		for(uint32_t j = 0; j < _widthScr; j++)
		{
			uvx =  j - _widthScr/3;
			uvxtimed = (j << 2) + _timeInx;
			
			uvx %= _widthScr;
			uvxtimed %= _widthScr;
			
			mod1 = uvx * uvx  + uvy * uvy;
			mod1 *= 1/mod1;
			mod1 -= _timeInx;
			mod1 %= 360;

			uvx += _sinus[(_time)%360];
			mod2 = sqrt(uvx*uvx+uvy2*uvy2);
			mod2 += _timeInx + mod2;
			mod2 %= maxDistScreen;

			mod2 = DemoMath::remap(mod2, maxDistScreen, 360);

			remapUVxtimed = DemoMath::remap(uvxtimed, _widthScr, 360 );

			value = DemoMath::max<int>( _sinus[remapUVxtimed] + _sinus[remapUVytimed] + _sinus[mod1] + _sinus[mod2],0);			

			value >>= 1;

			value %= 360;

			valueR = DemoMath::max<int>(_sinus[value],0);
			valueG = DemoMath::max<int>(_sinus[((value+270)%360)],0);

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
