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

	_data.reserve( pixels.size()>>2 );
	memcpy( _data.data(), pixels.data(), pixels.size());
}

