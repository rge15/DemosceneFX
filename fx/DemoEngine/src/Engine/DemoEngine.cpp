#include "DemoEngine.hpp"


DemoEngine::DemoEngine() noexcept
{
	ptc_open("MK I - BitBoy 1st demo", _widthScr, _heightScr);
}

DemoEngine::~DemoEngine()
{
	ptc_close();
}

void
DemoEngine::updateDraw() noexcept
{
	ptc_update( _screen );
}