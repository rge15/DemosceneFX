#include "Drawer.hpp"


Drawer::Drawer( uint32_t* p_buffer )
: _buffer { *p_buffer }
{
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void
Drawer::Draw() noexcept
{
	_timer.reset();
	for(auto& fx : _FXs )
	{
		_timer._totalFXTime += fx->_secTime;
		while( _timer.ellapsedSeconds() < _timer._totalFXTime )
		{
			if(	_timer.updateDraw() )
			{
				fx->Render( &_buffer );
				updateDraw();
			}
		}
	}

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void
Drawer::updateDraw() noexcept
{
	ptc_update( &_buffer );
}
