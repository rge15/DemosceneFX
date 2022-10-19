#pragma once
#include <concepts>
#include <utilities/concepts.hpp>

namespace DemoMath
{

	constexpr float PI = 3.14159265359;
	
	template<Arithmetic numT>
	numT
	min( numT a, numT b) noexcept;

	float
	remap( float value, float actualMax, float targetMax ) noexcept;

	template<Arithmetic numT>
	float
	remap( numT value, float actualMax, float targetMax ) noexcept;

	template<Arithmetic numT>
	numT
	max(numT val1, numT val2) noexcept;

}

#include "DemoMath.tpp"