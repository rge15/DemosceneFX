#include "DemoMath.hpp"


namespace DemoMath
{
	int min( int a, int b) noexcept
	{
		if( a < b )
			return a;
		return b;
	}
}