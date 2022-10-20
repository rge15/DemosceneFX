#pragma once
#include "bufferFX.hpp"

constexpr int numBlobs = 5;

class BlobsFX : public bufferFX
{
	struct Blob
	{
		int x { 0 }, y{ 0 };
		int speedScaleX { 0 }, speedScaleY { 0 };
	};

	private:
		//Heigth pos on the buffer for applying the BlobsFX
		int _time {};
		
		Blob blobs[ numBlobs ];
		int _sinus[360];

	public:
		BlobsFX( uint32_t p_time ) noexcept;
		~BlobsFX() = default;

		/**
		 * 	@brief Method that inits the BlobsFX resources
		*/
		void
		Init() override;

		/**
		 * 	@brief Method that renders the BlobsFX
		 * 
		 * 	@param p_bufferStart Pointer to the buffer to draw on
		*/
		void
		Render( uint32_t* p_bufferStart ) override;

};