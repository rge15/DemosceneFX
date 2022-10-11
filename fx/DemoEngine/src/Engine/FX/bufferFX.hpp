#pragma once
#include <utilities/config.hpp>

class bufferFX
{
	protected:
		uint32_t _bufferWidth { 0 }, _bufferHeigth{ 0 };

	public:

		explicit bufferFX( uint32_t p_bufferWidth, uint32_t p_bufferHeigth ) noexcept;
		virtual ~bufferFX() = default;

		virtual
		void Init() = 0;

		virtual
		void Render() = 0;
};