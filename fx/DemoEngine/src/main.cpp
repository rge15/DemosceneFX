#include <Engine/DemoEngine.hpp>
#include <Engine/FX/bufferFX.hpp>
#include <Engine/FX/FireFX.hpp>
#include <Engine/FX/PlasmaUpFX.hpp>

int main()
{
	auto demoEngine = std::make_unique<DemoEngine>();
	auto& engine = *demoEngine.get();
	
	auto width = engine._widthScr;
	auto height = engine._heightScr;

	std::vector<bufferFX*> fxs {};

	//TODO : Ver como cambiar el numero de iteraciones a una unidad de tiempo OK
	fxs.push_back( new FireFX( width, height, 2000) );
	fxs.push_back( new PlasmaUpFX( width, height, 2000) );

	std::size_t i { 0 };

	for(auto& fx : fxs )
	{
		fx->Init(engine._screen);
	}

	for(auto& fx : fxs )
	{
		for( i = 0; i < fx->_time; i++ )
		{
			fx->Render();
			engine.updateDraw();
		}
	}

	for(auto& fx : fxs )
	{
		delete fx;
	}

}
