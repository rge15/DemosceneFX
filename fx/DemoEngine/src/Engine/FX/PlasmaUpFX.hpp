#pragma once
#include "bufferFX.hpp"


class PlasmaUpFX : public bufferFX
{
	private:
		std::size_t _pixelCount { 0 };
		std::size_t _jInitPos {};

	public:
		PlasmaUpFX( uint32_t p_bufferWidth, uint32_t p_bufferHeigth, uint32_t p_time ) noexcept;
		~PlasmaUpFX() = default;

		void
		Init() override;

		void
		Render( uint32_t* p_bufferStart ) override;

};