#include <Engine/DemoEngine.hpp>
#include <Engine/FX/bufferFX.hpp>
#include <Engine/FX/FireFX.hpp>
#include <Engine/FX/PlasmaUpFX.hpp>
#include <Engine/utils/Timer.hpp>
#include <utilities/alias.hpp>
#include <Engine/FX/SpriteFX.hpp>

int main()
{
	auto demoEngine = std::make_unique<DemoEngine>();
	auto& engine = *demoEngine.get();
	auto width = engine._widthScr;
	auto height = engine._heightScr;
	auto& drawer = engine.getDrawer();

	auto& sprBuffer = drawer.addBuffer<SpriteFX>( width, height, 10 );
	sprBuffer.addSprite("img/prueba.png", 10);
	sprBuffer.setBufferFX( std::make_unique<FireFX>(width, height, 10) );

	drawer.addBuffer<FireFX>( width, height, 10 );
	drawer.addBuffer<PlasmaUpFX>( width, height, 10 );
	
	// TODO 19 OCTUBRE
	//? [2.4]{SpriteFX} : Se pueden hacer variaciones de este buffer para que tenga un updatePos que mueva los sprite en forma de sinusoidal o algo

	engine.Draw();
}
