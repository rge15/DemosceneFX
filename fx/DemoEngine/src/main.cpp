#include <Engine/DemoEngine.hpp>
#include <Engine/FX/bufferFX.hpp>
#include <Engine/FX/FireFX.hpp>
#include <Engine/FX/PlasmaUpFX.hpp>
#include <Engine/utils/Timer.hpp>
#include <utilities/alias.hpp>
// #include <Engine/Sprites/Sprite.hpp>
#include <Engine/FX/SpriteFX.hpp>

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

	// TODO 18 OCTUBRE
	//? [2] : Dibujar sprites con FX para la parte inicial de la Demo.
	//? [2.1] : Hacer una clase derivada del bufferFX encargada de dibujar sprites
	//? [2.2] : Hacer un spriteFX que tenga los sprites que quiera dibujar 
	//? [2.3] : Podemos hacer que este SpriteFX tenga un puntero al effecto que quiere ejecutar mientras dibuja los sprites
	//? [2.3] : Incluso puede tener su propio dibujado con más de un efecto
	//? [2.4] : Se pueden hacer variaciones de este buffer para que tenga un updatePos que mueva los sprite en forma de sinusoidal o algo
	//? [3] : Hacer después algun tipo de drawSystem que sea el encargado de dibujar los efectos

	Vector<uniqPtr<Sprite>> sprs{};
	sprs.push_back( std::make_unique<Sprite>("img/prueba.png") );
	sprs.push_back( std::make_unique<Sprite>("img/prueba.png") );
	sprs[1].get()->setPos(30,30);

	SpriteFX sprFX( width, height, 10 );
	sprFX.addSprite("img/prueba.png");

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
				engine.updateDraw();
			}
		}
	}

}
