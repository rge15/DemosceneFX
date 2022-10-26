#include "SpriteFX.hpp"


SpriteFX::SpriteFX( uint32_t p_time, DrawerSrc& p_src ) noexcept
: bufferFX { p_time, p_src }
{
	Init();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void
SpriteFX::Init()
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void
SpriteFX::Render( uint32_t* p_bufferStart )
{
	if( _bufferFX.get() )
		_bufferFX.get()->Render( p_bufferStart );
	
	for( auto& spr : _sprites )
	{
		spr.get()->Draw( p_bufferStart, _widthScr, _heightScr );
		spr.get()->updatePos();
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

Sprite&
SpriteFX::addSprite( std::string p_filename )
{
	auto spr = std::make_unique<Sprite>(p_filename);

	_sprites.push_back( std::move(spr) );

	return *(_sprites.back().get());
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void
SpriteFX::setBufferFX( std::unique_ptr<bufferFX>&& p_bufferFX ) noexcept
{
	_bufferFX.release();
	_bufferFX = std::move(p_bufferFX);
}
