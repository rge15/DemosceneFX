#pragma once
#include "bufferFX.hpp"


class FireFX : public bufferFX
{
	private:
		std::size_t _pixelCount { 0 };
		std::size_t _jInitPos {};

	public:
		FireFX( uint32_t p_bufferWidth, uint32_t p_bufferHeigth, uint32_t p_time ) noexcept;
		~FireFX() = default;

		void
		Init() override;

		void
		Render( uint32_t* p_bufferStart ) override;

};