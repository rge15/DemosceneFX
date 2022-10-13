#include "Sprite.hpp"

Sprite::Sprite( std::string p_fileSrc ) noexcept
{
	std::ifstream file ( p_fileSrc, std::ios::binary);

	ASSERT(file.is_open(), "Error opening the img for the sprite")

	fillSpriteData( file );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

Sprite::~Sprite() noexcept
{}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void Sprite::fillSpriteData(std::ifstream& p_spriteData) noexcept
{
	std::vector<unsigned char> pixels {};
	unsigned long width {0}, height {0};

	std::vector<unsigned char> fileData{
		std::istreambuf_iterator<char> {p_spriteData},
		std::istreambuf_iterator<char> {}
	};

	decodePNG( pixels, width, height, fileData.data(), fileData.size());

	ASSERT( (width<=UINT32_MAX) , "Width of png greater than posible")
	ASSERT( (height<=UINT32_MAX) , "Height of png greater than posible")
	
	_width = width;
	_height = height;

	_data.resize( pixels.size()>>2 );
	memcpy( _data.data(), pixels.data(), pixels.size());
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void
Sprite::Draw( uint32_t* p_buffer, uint32_t p_width, uint32_t p_height  ) noexcept
{
	int iStart { 0 }, jStart{ 0 }, iEnd{ _height }, jEnd{ _width };
	int i, j;
	int finalX { _posX }, finalY { _posY };

	if( finalX < 0 )
	{
		finalX = 0;
		jStart = _width + _posX ;
	}

	if( finalY < 0 )
	{
		finalY = 0;
		iStart = _height + _posY ;
	}

	if( finalX + _width > p_width )
	{
		iEnd = p_width - finalX;
	}

	if( finalY + _height > p_height )
	{
		jEnd = p_height - finalY;
	}

	for( i = iStart ; i < iEnd ; i++)
	{
		for( j = jStart ; j< jEnd ; j++)
		{
			p_buffer[ (finalY + i - iStart) * p_width + (finalX + j - jStart) ] = _data[ i * _width + j];
		}
	}

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void
Sprite::setPos( int p_x, int p_y ) noexcept
{
	_posY = p_y;
	_posX = p_x;
}

