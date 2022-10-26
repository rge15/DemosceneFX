#include "bufferFX.hpp"

bufferFX::bufferFX( uint32_t p_time, DrawerSrc& p_src ) noexcept 
: _secTime { p_time }, _src { p_src }
{}