#include <cstdint>
#include <iostream>
#include <vector>
#include "asserts.hpp"

class Sprite
{
	public:
		uint32_t _width{ 0 }, _height{ 0 };
		
		std::vector<uint32_t> _data {};

		uint32_t _posX, _posY;

	public:
		Sprite( const char* p_fileSrc, uint32_t p_width, uint32_t p_height) noexcept;

		~Sprite() noexcept;

		void fillSpriteData(FILE* p_spriteData) noexcept;
};