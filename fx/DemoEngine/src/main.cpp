#include <Engine/DemoEngine.hpp>
#include <Engine/FX/bufferFX.hpp>
#include <Engine/FX/FireFX.hpp>
#include <Engine/FX/PlasmaUpFX.hpp>
#include <Engine/utils/Timer.hpp>
#include <utilities/alias.hpp>

int main()
{
	DemoTimer demoTimer{ 60 };

	auto demoEngine = std::make_unique<DemoEngine>();
	auto& engine = *demoEngine.get();
	
	auto width = engine._widthScr;
	auto height = engine._heightScr;

	Vector<uniqPtr<bufferFX>> fxs{};
	fxs.push_back( std::make_unique<FireFX>(width, height, 10) );
	fxs.push_back( std::make_unique<PlasmaUpFX>(width, height, 10) );

	for(auto& fx : fxs )
	{
		fx->Init(engine._screen);
	}

	// TODO 17 OCTUBRE
	//? [2] : Dibujar sprites con FX para la parte inicial de la Demo.
	//? [2.3] : Podemos hacer que este SpriteFX tenga un puntero al effecto que quiere ejecutar mientras dibuja los sprites
	//? [2.4] : Se pueden hacer variaciones de este buffer para que tenga un updatePos que mueva los sprite en forma de sinusoidal o algo

	// TODO ADD LIST 17 OCT
	//? [1] : Ver de hacer el doble buffer


	//TODO : Entiendo que mejor hacer un primer bucle dibujando cosas
	//TODO : y hacer otro después más de full FX solamente

	//SpriteFX and BufferFX loop


	//Only BufferFX loop
	for(auto& fx : fxs )
	{
		demoTimer._totalFXTime += fx->_secTime;
		while( demoTimer.ellapsedSeconds() < demoTimer._totalFXTime )
		{
			if(	demoTimer.updateDraw() )
			{
				fx->Render();
				engine.updateDraw();
			}
		}
	}

}
