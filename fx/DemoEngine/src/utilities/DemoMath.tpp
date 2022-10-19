#include <utilities/concepts.hpp>

namespace DemoMath
{

	template<Arithmetic numT>
	numT
	min( numT a, numT b) noexcept
	{
		if( a < b )
			return a;
		return b;
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	template<Arithmetic numT>
	float
	remap( numT value, float actualMax, float targetMax ) noexcept
	{
		return (value * (targetMax / actualMax));
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	template<Arithmetic numT>
	numT
	max( numT a, numT b) noexcept
	{
		if( a > b )
			return a;
		return b;
	}

}