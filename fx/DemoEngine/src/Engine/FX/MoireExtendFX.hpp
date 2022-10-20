#pragma once
#include "bufferFX.hpp"

class MoireExtendFX : public bufferFX
{
	private:
		int _sinus[360];
		int _time { 0 };

	public:
		MoireExtendFX( uint32_t p_time ) noexcept;
		~MoireExtendFX() = default;

		/**
		 * 	@brief Method that inits the MoireExtendFX resources
		*/
		void
		Init() override;

		/**
		 * 	@brief Method that renders the MoireExtendFX
		 * 
		 * 	@param p_bufferStart Pointer to the buffer to draw on
		*/
		void
		Render( uint32_t* p_bufferStart ) override;

};