#pragma once
#include <utilities/config.hpp>


class DemoEngine
{
	public :
		static const uint32_t _widthScr { 720 };
		static const uint32_t _heightScr { 480 };
		uint32_t _screen[ _widthScr * _heightScr ];

	public:
		explicit DemoEngine() noexcept;
		~DemoEngine() noexcept;

		void
		updateDraw() noexcept;
};

