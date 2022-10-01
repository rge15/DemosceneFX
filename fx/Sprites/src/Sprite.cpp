#include "Sprite.hpp"

Sprite::Sprite( const char* p_fileSrc, uint32_t p_width, uint32_t p_height ) noexcept
: _width { p_width }, _height { p_height }
{
	FILE* spriteData = std::fopen( "img/readBin.data" , "rb" );

	ASSERT(spriteData, "Error opening the img for the sprite")

	_data.resize(_width*_height);
	fillSpriteData(spriteData);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

Sprite::~Sprite() noexcept
{}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void Sprite::fillSpriteData(FILE* p_spriteData) noexcept
{
	int dataByte, color, i{ 0 }, counterData{ 0 };

	uint32_t* ptrArrayData = &_data[0];

	while( (dataByte = std::fgetc(p_spriteData)) != EOF )
	{
		color += dataByte;

		//Each 3 bytes of data is new value for the array
		if(i == 2)
		{
			*ptrArrayData = color;
			++ptrArrayData;
			color = 0;
			i = 0;
			++counterData;
		}
		else
		{
			color <<= 8;
			++i;
		}
	}

	ASSERT(counterData == _width*_height, "The sprite has different size from the dimensions specified")
}

