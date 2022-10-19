#pragma once
#include "bufferFX.hpp"
#include <Engine/Sprites/Sprite.hpp>
#include <utilities/alias.hpp>

class SpriteFX : public bufferFX
{
	public:

		//Struct that contains the sprite and his time to be alive
		struct TimedSprite
		{
			uniqPtr<Sprite> _sprite { nullptr };
			int				_time { 0 };
		};
		
		//Manager of TimedSprites
		Vector<TimedSprite> _sprites {};
		//Manager of the FX to be draw with the sprites
		uniqPtr<bufferFX> _bufferFX { nullptr };

		SpriteFX( uint32_t p_bufferWidth, uint32_t p_bufferHeigth, uint32_t p_time ) noexcept;
		~SpriteFX() = default;

		/**
		 * 	@brief Method that inits the SpriteFX resources
		*/
		void
		Init() override;

		/**
		 * 	@brief Method that renders the SpriteFX sprites and FX
		 * 
		 * 	@param p_bufferStart Pointer to the buffer to draw on
		*/
		void
		Render( uint32_t* p_bufferStart ) override;

		/**
		 *	@brief Method thas adds a sprite to the BufferFX 
		 * 
		 * 	@param p_filename Path to the image Sprite
		 * 	@param p_time Lifetime of the sprite ( Currently dissabled )
		*/		
		Sprite&
		addSprite( std::string p_filename, int p_time = 10 );

		/**
		 *	@brief Method thas sets a bufferFX to be draw with the sprites 
		 * 
		 * 	@param p_buffer BufferFX to be executed
		*/
		void
		setBufferFX( std::unique_ptr<bufferFX>&& p_bufferFX ) noexcept;

};