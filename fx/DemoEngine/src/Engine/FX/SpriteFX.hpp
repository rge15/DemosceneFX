#pragma once
#include "bufferFX.hpp"
#include <utilities/alias.hpp>
#include <utilities/config.hpp>
#include <Engine/Sprites/Sprite.hpp>


class SpriteFX : bufferFX
{
	private:

		struct timedSprite
		{
			uniqPtr<Sprite> _sprite;
			double			_time;
		};

		Vector<timedSprite> _sprites {};

		

	public:
		SpriteFX( uint32_t p_bufferWidth, uint32_t p_bufferHeigth, uint32_t p_time ) noexcept;
		~SpriteFX() = default;

		void
		addNewSprite( std::string p_fileSrc, int p_x, int p_y, int p_time ) noexcept;

		void
		drawSprites() const noexcept;

};