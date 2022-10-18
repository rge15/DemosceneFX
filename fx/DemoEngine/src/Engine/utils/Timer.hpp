#pragma once
#include <chrono>

struct DemoTimer
{
	public:
		using clock = std::chrono::steady_clock;
		using timePoint = std::chrono::time_point<clock>;

		timePoint _initTime = clock::now();

		int _totalFXTime { 0 };

		//TODO : Alomejor el framerate dependeria del buffer y no del engine(Timer)
		int _frameRate { 60 };
		double _refreshTime { 1.f / _frameRate };

		double _lastTime { 0.f };


	public:
		explicit
		DemoTimer( int p_frameRate ) noexcept;

		~DemoTimer() = default;

		double
		ellapsedTime() const noexcept;

		double
		ellapsedSeconds() const noexcept;

		double
		deltaTime() noexcept;
	
		bool
		updateDraw() noexcept;

		void
		reset( int p_frameRate = 0 ) noexcept;
};