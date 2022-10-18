#pragma once
#include "bufferFX.hpp"


class FireFX : public bufferFX
{
	private:
		//Number total of pizels on the buffer
		std::size_t _pixelCount { 0 };

		//Heigth pos on the buffer for applying the FIre FX
		std::size_t _jInitPos {};

	public:
		FireFX( uint32_t p_bufferWidth, uint32_t p_bufferHeigth, uint32_t p_time ) noexcept;
		~FireFX() = default;

		/**
		 * 	@brief Method that inits the FireFX resources
		*/
		void
		Init() override;

		/**
		 * 	@brief Method that renders the FireFX
		 * 
		 * 	@param p_bufferStart Pointer to the buffer to draw on
		*/
		void
		Render( uint32_t* p_bufferStart ) override;

};