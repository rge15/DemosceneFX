#pragma once
#include "bufferFX.hpp"

class PlasmaFX : public bufferFX
{
	private:
		int _sinus[360];
		int _time { 0 }, _timeInx { 0 }, _timeIny { 0 };
		int maxDistScreen { 0 };

	public:
		PlasmaFX( uint32_t p_time ) noexcept;
		~PlasmaFX() = default;

		/**
		 * 	@brief Method that inits the PlasmaFX resources
		*/
		void
		Init() override;

		/**
		 * 	@brief Method that renders the PlasmaFX
		 * 
		 * 	@param p_bufferStart Pointer to the buffer to draw on
		*/
		void
		Render( uint32_t* p_bufferStart ) override;

};