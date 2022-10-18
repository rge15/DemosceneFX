template <typename bufferT>
bufferT&
Drawer::addBuffer( uint32_t p_bufferWidth, uint32_t p_bufferHeigth, uint32_t p_time )
{
	_FXs.push_back( std::make_unique<bufferT>( p_bufferWidth, p_bufferHeigth, p_time ) );

	auto& buffer =  static_cast<bufferT&>( *(_FXs.back().get()) );
	return buffer;
}