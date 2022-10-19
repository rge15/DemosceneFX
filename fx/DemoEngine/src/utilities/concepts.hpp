#pragma once

template<typename T>
	concept Arithmetic =
	requires (T a, T b)
	{
		{ a/b };
		{ a*b };
		{ a+b };
		{ a-b };
		{ a++ };
		{ ++a };
		{ --a };
		{ a-- };
		{ a<=>b };
	};