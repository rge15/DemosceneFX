#include "Timer.hpp"


DemoTimer::DemoTimer( int p_frameRate ) noexcept
: _frameRate { p_frameRate }
{}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

double
DemoTimer::ellapsedTime() const noexcept
{
	return ( DemoTimer::clock::now() - _initTime ).count();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

double
DemoTimer::ellapsedSeconds() const noexcept
{
	return ( ellapsedTime() / 1000000000.0f );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

double
DemoTimer::deltaTime() noexcept
{
	return ellapsedSeconds() - _lastTime;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

bool
DemoTimer::updateDraw() noexcept
{
	if( deltaTime() >= _refreshTime )
	{
		_lastTime = ellapsedSeconds();
		return true;
	}

	return false;
}

