#include "SpriteFX.hpp"


SpriteFX::SpriteFX( uint32_t p_bufferWidth, uint32_t p_bufferHeigth, uint32_t p_time ) noexcept
: bufferFX { p_bufferWidth, p_bufferHeigth, p_time }
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void
SpriteFX::addNewSprite( std::string p_fileSrc, int p_x, int p_y , int p_time) noexcept
{
	auto spr = std::make_unique<Sprite>( p_fileSrc, p_x, p_y );

	_sprites.push_back( timedSprite(std::move(spr), p_time) );

	if( p_time > _secTime)
		_secTime = p_time;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void
SpriteFX::drawSprites() const noexcept
{
	for(auto& spr : _sprites )
	{
		spr._sprite.get()->Draw( _buffer, _bufferWidth, _bufferHeigth );
	}
}
