#pragma once
#include "bufferFX.hpp"
#include <Engine/Sprites/Sprite.hpp>
#include <utilities/alias.hpp>

class SpriteFX : public bufferFX
{
	public:
		Vector<uniqPtr<Sprite>> _sprites {};

		SpriteFX( uint32_t p_bufferWidth, uint32_t p_bufferHeigth, uint32_t p_time ) noexcept;
		~SpriteFX() = default;

		void
		Init() override;

		void
		Render( uint32_t* p_bufferStart ) override;

		void
		addSprite( std::string p_filename );

};