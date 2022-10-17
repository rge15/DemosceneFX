#pragma once
#include <utilities/config.hpp>

class bufferFX
{
	protected:
		uint32_t _bufferWidth { 0 }, _bufferHeigth{ 0 };
		uint32_t* _buffer { nullptr };
	public:
		uint32_t _secTime { 0 };

		explicit bufferFX( uint32_t p_bufferWidth, uint32_t p_bufferHeigth, uint32_t p_time ) noexcept;
		virtual ~bufferFX() = default;

		virtual
		void Init( uint32_t* p_bufferStart ) = 0;

		virtual
		void Render() = 0;
};