#pragma once
#include <Engine/FX/bufferFX.hpp>
#include <utilities/alias.hpp>
#include <Engine/utils/Timer.hpp>
#include <Engine/FX/bufferFX.hpp>

class Drawer
{
	private:
		Vector<uniqPtr<bufferFX>> _FXs {};
	
		DemoTimer	_timer { 60 };
		uint32_t&	_buffer;

		void
		updateDraw() noexcept;

	public:
		Drawer( uint32_t* p_buffer );
		~Drawer() = default;

		void
		Draw() noexcept;

		template<typename bufferT>
		bufferT& addBuffer( uint32_t p_bufferWidth, uint32_t p_bufferHeigth, uint32_t p_time );
};

#include "Drawer.tpp"