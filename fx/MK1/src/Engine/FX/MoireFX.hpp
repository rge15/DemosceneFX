#pragma once
#include "bufferFX.hpp"

class MoireFX : public bufferFX
{
	private:
		int _time { 0 };

	public:
		MoireFX( uint32_t p_time, DrawerSrc& p_src ) noexcept;
		~MoireFX() = default;

		/**
		 * 	@brief Method that inits the MoireFX resources
		*/
		void
		Init() override;

		/**
		 * 	@brief Method that renders the MoireFX
		 * 
		 * 	@param p_bufferStart Pointer to the buffer to draw on
		*/
		void
		Render( uint32_t* p_bufferStart ) override;

};