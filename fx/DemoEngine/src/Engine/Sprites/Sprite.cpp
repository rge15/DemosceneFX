#include "Sprite.hpp"

Sprite::Sprite( std::string p_fileSrc ) noexcept
{
	std::ifstream file ( p_fileSrc, std::ios::binary);

	ASSERT(file.is_open(), "Error opening the img for the sprite")

	fillSpriteData( file );

	file.close();
}

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

	uint8_t r,g,b;
	uint32_t value;
	for( uint32_t i = 0 ; i < height; i++)
	{
		for( uint32_t j = 0 ; j < width; j++)
		{
			value = _data[i*height+j]; 
			value <<= 8;
			value >>= 8;
			r = value;
			value >>= 8;
			g = value;
			value >>= 8;
			b = value;
			value = r;
			value <<= 8;
			value += g;
			value <<= 8;
			value += b;
			_data[i*height+j] = value;
		}
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void
Sprite::Draw( uint32_t* p_buffer, uint32_t p_width, uint32_t p_height  ) noexcept
{
	int iStart, jStart, iEnd{ _height }, jEnd{ _width };
	int i, j;
	int finalX, finalY;

	finalX = DemoMath::max<int>( _posX, 0 );
	finalY = DemoMath::max<int>( _posY, 0 );

	jStart = abs(DemoMath::min<int>( _posX, 0 ));
	iStart = abs(DemoMath::min<int>( _posY, 0 ));
	
	if( finalX + _width > p_width )
		jEnd = p_width - finalX;

	if( finalY + _height > p_height )
		iEnd = p_height - finalY;

	for( i = iStart ; i < iEnd ; i++)
		for( j = jStart ; j< jEnd ; j++)
			p_buffer[ (finalY + i - iStart) * p_width + (finalX + j - jStart) ] = _data[ i * _width + j];

	_posX += _speedX ;
	_posY += _speedY ;

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void
Sprite::setPos( int p_x, int p_y ) noexcept
{
	_posY = p_y;
	_posX = p_x;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void
Sprite::setSpeed( int p_speedX, int p_speedY ) noexcept
{
	_speedY = p_speedY;
	_speedX = p_speedX;
}
