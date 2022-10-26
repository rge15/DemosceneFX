#pragma once
#include "bufferFX.hpp"
#include <Engine/Sprites/Sprite.hpp>
#include <utilities/alias.hpp>

class TunnelFX : public bufferFX
{
	private:
		//Heigth pos on the buffer for applying the FIre FX
		std::size_t _jInitPos {};

		//Sprite of the Tunnel
		uniqPtr<Sprite> _spr { nullptr };
	
		//Size of the tunnel
		int _widthText { 0 };
		int _heightText { 0 };

		int _time { 0 };

		int distance[ _pixelCount * 4 ];
		int angle[ _pixelCount * 4 ];
		float shade[ _pixelCount * 4 ];


	public:
		TunnelFX( uint32_t p_time, DrawerSrc& p_src, std::string p_spritePath ) noexcept;
		~TunnelFX() = default;

		/**
		 * 	@brief Method that inits the TunnelFX resources
		*/
		void
		Init() override;

		/**
		 * 	@brief Method that renders the TunnelFX
		 * 
		 * 	@param p_bufferStart Pointer to the buffer to draw on
		*/
		void
		Render( uint32_t* p_bufferStart ) override;

};