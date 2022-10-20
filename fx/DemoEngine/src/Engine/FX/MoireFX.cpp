#include "MoireFX.hpp"

MoireFX::MoireFX( uint32_t p_time ) noexcept
: bufferFX { p_time }
{
	Init();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void
MoireFX::Init()
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
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void
MoireFX::Render( uint32_t* p_bufferStart )
{
	int uvx, uvy, p1x, p1y, p2x, p2y;
	uint32_t length, finalCol { 0 };

	p1x = _widthScr/2 + (_sinus[(_time>>2)%360]);
	p1y = _heightScr/2 + (_sinus[(_time/3)%360]);

	p2x = _widthScr/2 - (_sinus[((_time+270)>>2)%360]);
	p2y = _heightScr/2 + (_sinus[(_time+270)%360]);

	for (int i = 0; i < _heightScr; i++)
	{
		uvy = i;
		for (int j = 0; j < _widthScr; j++)
		{
			uvx = j;
		
			length = sqrt((uvx-p1x)*(uvx-p1x)+(uvy-p1y)*(uvy-p1y));
			length ^= (uint32_t)(sqrt((uvx-p2x)*(uvx-p2x)+(uvy-p2y)*(uvy-p2y)));

			length >>= 5;
			length &= 1;
			length *= 255;		
		
			finalCol = (length << 16) + (length << 8) + length;

			p_bufferStart[ i * _widthScr + j ] = finalCol;	
		}
	}
	
	_time += 2;

}
