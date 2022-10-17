#include <Engine/DemoEngine.hpp>
#include <Engine/FX/bufferFX.hpp>
#include <Engine/FX/FireFX.hpp>
#include <Engine/FX/PlasmaUpFX.hpp>
#include <Engine/utils/Timer.hpp>
#include <utilities/alias.hpp>
#include <Engine/Sprites/Sprite.hpp>

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
		fx->Init();
	}

	// TODO 18 OCTUBRE
	//? [2] : Dibujar sprites con FX para la parte inicial de la Demo.
	//? [2.1] : Hacer una clase derivada del bufferFX encargada de dibujar sprites
	//? [2.2] : Hacer un spriteFX que tenga los sprites que quiera dibujar 
	//? [2.3] : Podemos hacer que este SpriteFX tenga un puntero al effecto que quiere ejecutar mientras dibuja los sprites
	//? [2.3] : Incluso puede tener su propio dibujado con más de un efecto
	//? [2.4] : Se pueden hacer variaciones de este buffer para que tenga un updatePos que mueva los sprite en forma de sinusoidal o algo

	Vector<uniqPtr<Sprite>> sprs{};
	sprs.push_back( std::make_unique<Sprite>("img/prueba.png") );
	sprs.push_back( std::make_unique<Sprite>("img/prueba.png") );
	sprs[1].get()->setPos(30,30);

	//Habrá que hacer un drawSystem 
	//Only BufferFX loop
	for(auto& fx : fxs )
	{
		demoTimer._totalFXTime += fx->_secTime;
		while( demoTimer.ellapsedSeconds() < demoTimer._totalFXTime )
		{
			if(	demoTimer.updateDraw() )
			{
				fx->Render( engine._buffer );
				for(auto& spr : sprs)
					spr.get()->Draw( engine._buffer, width, height );
				engine.updateDraw();
			}
		}
	}

}
