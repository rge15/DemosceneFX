#include <cstdint>
#include <iostream>
#include <vector>
#include <fstream>
#include <picopng.hpp>
#include <cstring>
#include <Engine/utils/asserts.hpp>

class Sprite
{
	public:
		int32_t _width{ 0 }, _height{ 0 };
		
		std::vector<uint32_t> _data {};

		int32_t _posX { 0 }, _posY { 0 };

	public:
		
		Sprite( std::string p_fileSrc, int p_x, int p_y ) noexcept;

		~Sprite() noexcept;

		void setPos( int p_x, int p_y ) noexcept;

		void fillSpriteData(std::ifstream& p_spriteData) noexcept;

		void Draw( uint32_t* p_buffer, uint32_t p_width, uint32_t p_height ) noexcept;
};