#pragma once
#include <utilities/config.hpp>
#include <Engine/DemoEngineConfig.hpp>
#include <utilities/DemoMath.hpp>
#include <Engine/DrawerSrc.hpp>
using namespace Demoengine::Config;

class bufferFX
{
	protected:
		const DrawerSrc& _src;

	public:
		// Time of the buffer to be displaying
		uint32_t _secTime { 0 };

		/**	@brief Constructor for abstract bufferFX class */
		explicit bufferFX( uint32_t p_time, DrawerSrc& p_drawSrc ) noexcept;
		/**	@brief Destrcutor for abstract bufferFX class */
		virtual ~bufferFX() = default;

		/**
		 * 	@brief Virtual method to be overwriten that inits the resources for each FX  
		*/
		virtual
		void Init() = 0;

		/**
		 * 	@brief Virtual method to be overwriten that renders the FX
		 * 
		 * 	@param p_bufferStart Pointer to the buffer to draw on
		*/
		virtual
		void Render( uint32_t* p_bufferStart ) = 0;
};