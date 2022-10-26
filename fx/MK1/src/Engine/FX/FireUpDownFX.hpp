#pragma once
#include "bufferFX.hpp"


class FireUpDownFX : public bufferFX
{
	private:
		//Heigth pos on the buffer for applying the FIre FX
		std::size_t _jInitPos {};
		int _pos { 1 };
		int _speedY { 1 };

	public:
		FireUpDownFX( uint32_t p_time, DrawerSrc& p_src ) noexcept;
		~FireUpDownFX() = default;

		/**
		 * 	@brief Method that inits the FireUpDownFX resources
		*/
		void
		Init() override;

		/**
		 * 	@brief Method that renders the FireUpDownFX
		 * 
		 * 	@param p_bufferStart Pointer to the buffer to draw on
		*/
		void
		Render( uint32_t* p_bufferStart ) override;

};