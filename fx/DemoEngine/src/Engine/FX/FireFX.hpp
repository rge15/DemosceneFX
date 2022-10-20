#pragma once
#include "bufferFX.hpp"


class FireFX : public bufferFX
{
	private:
		//Heigth pos on the buffer for applying the FIre FX
		std::size_t _jInitPos {};

	public:
		FireFX( uint32_t p_time, DrawerSrc& p_src ) noexcept;
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