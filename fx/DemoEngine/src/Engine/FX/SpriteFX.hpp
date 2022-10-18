#pragma once
#include "bufferFX.hpp"
#include <Engine/Sprites/Sprite.hpp>
#include <utilities/alias.hpp>

class SpriteFX : public bufferFX
{
	public:

		struct TimedSprite
		{
			uniqPtr<Sprite> _sprite { nullptr };
			int				_time { 0 };
		};
		
		Vector<TimedSprite> _sprites {};
		uniqPtr<bufferFX> _bufferFX { nullptr };

		SpriteFX( uint32_t p_bufferWidth, uint32_t p_bufferHeigth, uint32_t p_time ) noexcept;
		~SpriteFX() = default;

		void
		Init() override;

		void
		Render( uint32_t* p_bufferStart ) override;

		void
		addSprite( std::string p_filename, int p_time = 10 );

		void
		setBufferFX( std::unique_ptr<bufferFX>&& p_bufferFX ) noexcept;

};