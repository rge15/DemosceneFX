template <typename bufferT>
bufferT&
Drawer::addBuffer( uint32_t p_time )
{
	_FXs.push_back( std::make_unique<bufferT>( p_time ) );

	auto& buffer =  static_cast<bufferT&>( *(_FXs.back().get()) );
	return buffer;
}