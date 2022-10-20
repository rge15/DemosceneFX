#include "BlobsFX.hpp"


BlobsFX::BlobsFX( uint32_t p_time, DrawerSrc& p_src ) noexcept
: bufferFX { p_time, p_src }
{
	Init();
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void
BlobsFX::Init()
{
	for(auto& blob : blobs)
	{
		blob.speedScaleX = rand()%4;
		blob.speedScaleY = rand()%4;
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void
BlobsFX::Render( uint32_t* p_bufferStart )
{
	int dbx { 0 }, dby { 0 };
	float sumDist { 0.f };
	uint32_t color { 0 };

	for(auto& blob : blobs)
	{
		blob.x =  _halfWidthScr + ( _src._colourSinus[( ( _time >> blob.speedScaleX) +  _time ) % _sinusTableIndices]);
		blob.y =  _halfHeightScr + ( _src._colourSinus[( ( _time >> blob.speedScaleY) +  _time + 270) % _sinusTableIndices ]);
	}

	for( int y = 0; y < _heightScr ; y++ )
	{
		for( int x = 0 ; x < _widthScr ; x++)
		{
			sumDist = .05;
			for(auto& blob : blobs )
			{
				dbx = x - blob.x;
				dbx *= dbx;
				dby = y - blob.y;
				dby *= dby;
				sumDist *= sqrt( dbx + dby );
			}

			color = DemoMath::max<float>( DemoMath::min<float>( int( floor( sumDist ) ) , 255 ) , 0 );
			
			*p_bufferStart = color;
			++p_bufferStart;
		}
	}

	++_time;

}
