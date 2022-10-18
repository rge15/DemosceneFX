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
		explicit DemoEngine() noexcept;
		~DemoEngine() noexcept;

		void
		Draw() noexcept;

		Drawer&
		getDrawer() const noexcept
		{
			return *_drawer.get();
		}

	private:
		void
		updateDraw() noexcept;

};

