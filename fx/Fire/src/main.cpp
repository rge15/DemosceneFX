extern "C"
{
	#include <tinyptc.h>
}
#include <cstdlib>
#include <cstdint>

#define WIDTH_SCREEN 720
#define HEIGHT_SCRREN 480
#define TOTAL_PIXELS ( WIDTH_SCREEN * HEIGHT_SCRREN )  

uint32_t _screen[ TOTAL_PIXELS ];

int main()
{
	ptc_open("window", WIDTH_SCREEN, HEIGHT_SCRREN);

	uint32_t i = 0;
	uint32_t j = WIDTH_SCREEN * (HEIGHT_SCRREN - 2); 
	uint32_t* _ptrScreen = _screen + TOTAL_PIXELS - 1;
	for(;;)
	{

		for(i = TOTAL_PIXELS ; i > j ; i--)
		{
			uint32_t rngVal = rand();
			*_ptrScreen = ((rngVal%122 + 122) << 16 ) + ((rngVal%122) << 8) ;

			--_ptrScreen;
		};

		_ptrScreen = _screen + TOTAL_PIXELS - 1;

		for( i = TOTAL_PIXELS ; i > WIDTH_SCREEN*5 ; i--)
		{

			uint32_t* prev = _ptrScreen-1;
			uint32_t* next = _ptrScreen+1;
			uint32_t* above = _ptrScreen-WIDTH_SCREEN;
			uint32_t  fireValue { 0 };
			auto moduleResult = i%WIDTH_SCREEN;

			//TODO : Las sumas suman todos los valores y mezclan los RGB Values
			//TODO : Hacer una macro/funcion que pille los valores R y G por separado 
			//TODO : que los sume y que haga modulo de 255 y los ponga donde toque
			//TODO : Valdría con hacer >> 8 ,<< 16 Y >> 8 ||  >> 8, << 8 y obtener el minimo comun multiplo de 2 ^ 23 (creo que con puesta XOR)
			if( moduleResult == 0 )
			{
				fireValue = *(_ptrScreen) + *(prev) + *(above)  ;
			}else if ( moduleResult == 1)
			{
				fireValue = *(_ptrScreen) + *(next) + *(above)  ;
			}else
			{
				fireValue = *(_ptrScreen) + *(prev) + *(above) + *(next) ;
			}
			fireValue /= 3;
			*above = fireValue;

			--_ptrScreen;
		};

		_ptrScreen = _screen + TOTAL_PIXELS - 1;
		ptc_update( _screen );
	}

	ptc_close();

	return 0;
}