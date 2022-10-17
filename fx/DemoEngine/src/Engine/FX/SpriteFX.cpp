#include "SpriteFX.hpp"


SpriteFX::SpriteFX( uint32_t p_bufferWidth, uint32_t p_bufferHeigth, uint32_t p_time ) noexcept
: bufferFX { p_bufferWidth, p_bufferHeigth, p_time }
{
	Init();
}

void
SpriteFX::Init()
{
}

void
SpriteFX::Render( uint32_t* p_bufferStart )
{

	for( auto& spr : _sprites )
	{
		spr.get()->Draw( p_bufferStart, _bufferWidth, _bufferHeigth );
	}

}

void
SpriteFX::addSprite( std::string p_filename )
{
	_sprites.push_back( std::make_unique<Sprite>(p_filename) );
}
