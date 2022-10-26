#pragma once
#include "bufferFX.hpp"

class MoireTimedFX : public bufferFX
{
	private:
		int _sinus[360];
		int _time { 0 };

	public:
		MoireTimedFX( uint32_t p_time, DrawerSrc& p_src ) noexcept;
		~MoireTimedFX() = default;

		/**
		 * 	@brief Method that inits the MoireTimedFX resources
		*/
		void
		Init() override;

		/**
		 * 	@brief Method that renders the MoireTimedFX
		 * 
		 * 	@param p_bufferStart Pointer to the buffer to draw on
		*/
		void
		Render( uint32_t* p_bufferStart ) override;

};