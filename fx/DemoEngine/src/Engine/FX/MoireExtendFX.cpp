#include "MoireExtendFX.hpp"

MoireExtendFX::MoireExtendFX( uint32_t p_time, DrawerSrc& p_src ) noexcept
: bufferFX { p_time, p_src }
{
	Init();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void
MoireExtendFX::Init()
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void
MoireExtendFX::Render( uint32_t* p_bufferStart )
{
	int uvx, uvy, p1x, p1y, p2x, p2y;
	uint32_t length, finalCol { 0 };

	p1x = _widthScr/2 + ( _src._colourSinus[(_time>>2) % _sinusTableIndices ]);
	p1y = _heightScr/2 + ( _src._colourSinus[(_time/3) % _sinusTableIndices ]);

	p2x = _widthScr/2 - ( _src._colourSinus[(( _time + _cosOffsetTable )>>2)%_sinusTableIndices]);
	p2y = _heightScr/2 + ( _src._colourSinus[( _time + _cosOffsetTable )%_sinusTableIndices]);

	for (int i = 0; i < _heightScr; i++)
	{
		uvy = i;
		for (int j = 0; j < _widthScr; j++)
		{
			uvx = j;
		
			length = sqrt((uvx-p1x)*(uvx-p1x)+(uvy-p1y)*(uvy-p1y));
			length ^= (uint32_t)(sqrt((uvx-p2x)*(uvx-p2x)+(uvy-p2y)*(uvy-p2y)));

			length &= 255;		
		
			finalCol = (length << 16) + (length << 8) + length;

			p_bufferStart[ i * _widthScr + j ] = finalCol;	
		}
	}
	
	_time += 2;

}
