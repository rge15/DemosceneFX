#pragma once
#include <utilities/config.hpp>
#include <utilities/alias.hpp>
#include "Drawer.hpp"
class DemoEngine
{
	public :
		static const uint32_t _widthScr { 720 };
		static const uint32_t _heightScr { 480 };
		uint32_t _buffer[ _widthScr * _heightScr ];

		uniqPtr<Drawer> _drawer { std::make_unique<Drawer>( _buffer ) };

	public:
		/**	@brief Opens the window to draw in */
		explicit DemoEngine() noexcept;

		/**	@brief Destroys the opened window */
		~DemoEngine() noexcept;

		/** @brief Draws all the FXs set on _drawer */
		void
		Draw() noexcept;

		/**	
		 * 	@brief Gets the reference to the engine _drawer 
		 * 
		 * 	@return Reference to _drawer
		*/
		Drawer&
		getDrawer() const noexcept
		{
			return *_drawer.get();
		}

};

