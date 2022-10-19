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
		/**	@brief Constructor of Drawer class
		 * 
		 * 	@param p_buffer Pointer to the start of the buffer to draw in
		 */
		Drawer( uint32_t* p_buffer );

		/**	@brief Default destructor for Drawe class */
		~Drawer() = default;

		/**
		 * 	@brief It draws all the FXs on _FXs
		*/
		void
		Draw() noexcept;

		/**
		 * 	@brief Adds a new bufferFX to be drawn
		 * 	
		 * 	@tparam Type of buffer to be created
		 * 
		 * 	@param	p_bufferWidth Width of the buffer for the bufferFX constructor
		 * 	@param	p_bufferHeigth Heigth of the buffer for the bufferFX constructor
		 * 	@param	p_time Time to the bufferFX to be drawn
		*/
		template<typename bufferT>
		bufferT&
		addBuffer( uint32_t p_bufferWidth, uint32_t p_bufferHeigth, uint32_t p_time );
};

#include "Drawer.tpp"