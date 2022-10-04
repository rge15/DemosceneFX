#include <cstdint>
#include <iostream>
#include <vector>
#include <fstream>
#include <picopng.hpp>
#include <cstring>
#include "asserts.hpp"

class Sprite
{
	public:
		uint32_t _width{ 0 }, _height{ 0 };
		
		std::vector<uint32_t> _data {};

		uint32_t _posX, _posY;

	public:
		
		Sprite( std::string p_fileSrc ) noexcept;

		~Sprite() noexcept;

		void fillSpriteData(std::ifstream& p_spriteData) noexcept;
};