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
	_bufferFX.get()->Render( p_bufferStart );
	for( auto& spr : _sprites )
	{
		spr._sprite.get()->Draw( p_bufferStart, _bufferWidth, _bufferHeigth );
	}
}

void
SpriteFX::addSprite( std::string p_filename, int p_time )
{
	auto spr = std::make_unique<Sprite>(p_filename);

	_sprites.push_back( TimedSprite( std::move(spr), p_time ) );
}

void
SpriteFX::setBufferFX( std::unique_ptr<bufferFX>&& p_bufferFX ) noexcept
{
	_bufferFX.release();
	_bufferFX = std::move(p_bufferFX);
}
