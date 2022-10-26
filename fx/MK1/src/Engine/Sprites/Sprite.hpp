#pragma once
#include <cstdint>
#include <iostream>
#include <vector>
#include <fstream>
#include <picopng.hpp>
#include <cstring>
#include <utilities/DemoMath.hpp>
#include "../utils/asserts.hpp"

class Sprite
{
	private:		
		//Pos of the sprite in the screen
		int32_t _posX { 0 }, _posY { 0 };
		int32_t _speedX { 0 }, _speedY { 0 };

	public:
		//Data of the sprite
		std::vector<uint32_t> _data {};

		// Size of the sprite
		int32_t _width{ 0 }, _height{ 0 };

	public:
		/**
		 * 	@brief Cosntructor of the class Sprite
		 * 
		 * 	@param p_fileSrc String with the path of the Image
		*/
		Sprite( std::string p_fileSrc ) noexcept;

		/** @brief Destructor of the Sprite class */
		~Sprite() = default;

		/**
		 * 	@brief Sets the position of the sprite
		 * 
		 * 	@param p_x Position on the X axis
		 * 	@param p_y Position on the Y axis
		*/
		void
		setPos( int p_x, int p_y ) noexcept;

		/**
		 * 	@brief Sets the speed of the sprite
		 * 
		 * 	@param p_speedX Speed on the X axis
		 * 	@param p_speedY Speed on the Y axis
		*/
		void
		setSpeed( int p_speedX, int p_speedY ) noexcept;

		/**
		 * 	@brief Method tha fills the sprite data
		 * 
		 * 	@param p_spriteData Ifstream reference with ths sprite file opened
		*/
		void
		fillSpriteData(std::ifstream& p_spriteData) noexcept;

		/**
		 * 	@brief Draws the sprite on the specified buffer
		 * 
		 * 	@param p_buffer Pointer to the start of the buffer
		*/
		void
		Draw( uint32_t* p_buffer, uint32_t p_width, uint32_t p_height ) noexcept;

		/**
		 * 	@brief Updates the position of the sprite
		*/
		void
		updatePos() noexcept;

};