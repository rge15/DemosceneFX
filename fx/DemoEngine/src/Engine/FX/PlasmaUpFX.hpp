#pragma once
#include "bufferFX.hpp"


class PlasmaUpFX : public bufferFX
{
	private:
		//Number total of pizels on the buffer
		std::size_t _pixelCount { 0 };

		//Heigth pos on the buffer for applying the FIre FX
		std::size_t _jInitPos {};

	public:
		PlasmaUpFX( uint32_t p_bufferWidth, uint32_t p_bufferHeigth, uint32_t p_time ) noexcept;
		~PlasmaUpFX() = default;

		/**
		 * 	@brief Method that inits the PlasmaUpFX resources
		*/
		void
		Init() override;

		/**
		 * 	@brief Method that renders the PLasmaUpFX
		 * 
		 * 	@param p_bufferStart Pointer to the buffer to draw on
		*/
		void
		Render( uint32_t* p_bufferStart ) override;

};