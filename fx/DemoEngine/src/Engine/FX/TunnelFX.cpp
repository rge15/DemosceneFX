#include "TunnelFX.hpp"

TunnelFX::TunnelFX( uint32_t p_time, std::string p_spritePath ) noexcept
: bufferFX { p_time }, _spr { std::make_unique<Sprite>( p_spritePath ) }
{
	Init();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void
TunnelFX::Init()
{
	_heightText = _spr.get()->_height;
	_widthText = _spr.get()->_width;

	float dy{ 0 }, dx{ 0 };
	int ratio = 32;

	int doubleHeight = _heightScr * 2;
	int doubleWidth = _widthScr * 2;

	for(int y = 0; y < doubleHeight ; y++)
	{
		dy = y - _heightScr ;
		for(int x = 0; x < doubleWidth ; x++)
		{
			dx = x - _widthScr;
			distance[y*(_widthScr*2) + x] = int( ratio * _heightText / sqrt( dy*dy + dx*dx ) ) % _heightText;
			angle[y*(_widthScr*2) + x] = (unsigned int) 2 * _widthText * atan2( dy, dx )/ DemoMath::PI ;
			shade[y*(_widthScr*2) + x] = DemoMath::min(sqrt( dy * dy + dx * dx ),255.)/255.;
		}
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void
TunnelFX::Render( uint32_t* p_bufferStart )
{
	float uvx, uvy, shadeValue;
	int shiftx, shifty, centerx, centery, bufferPos;
	uint32_t color;
	uint8_t r,g,b;

	shiftx = _widthText * 2 * _time * 1/1000;
	shifty = _heightText * 0.25 * _time * 1/1000;

	//TODO : ESto habrá q cambiarlo por una tabla de sinus precalculada
	centerx = _widthScr / 2 + _widthScr / 4 * (sin( _time * 7./1000.));
	centery = _heightScr / 2 + _heightScr / 3 * (sin( _time * 11./1000.));

	for(int i = 0; i < _heightScr; i++)
	{
		for(int j = 0; j < _widthScr; j++)
		{
			bufferPos = (i+centery)*_widthScr*2 + j + centerx;

			uvx = (unsigned int)(distance[ bufferPos ] + shiftx) % _widthText;
			uvy = (unsigned int)(angle[ bufferPos ] + shifty) % _heightText;
			shadeValue = shade[ bufferPos ];

			//?Esto se podrá hacer de alguna forma más eficiente?
			color = _spr.get()->_data[uvy*_widthText + uvx];

			r = (color >> 16) * shadeValue;
			g = (color >> 8) * shadeValue;
			b = color * shadeValue;

			color = (r << 16) + (g << 8) + b;

			*p_bufferStart = color;
			++p_bufferStart;
		}
	}

	++_time;

}