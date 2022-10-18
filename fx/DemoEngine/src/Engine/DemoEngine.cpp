#include "DemoEngine.hpp"


DemoEngine::DemoEngine() noexcept
{
	ptc_open("MK I - BitBoy 1st demo", _widthScr, _heightScr);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

DemoEngine::~DemoEngine()
{
	ptc_close();
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void
DemoEngine::Draw() noexcept
{
	_drawer.get()->Draw();
}