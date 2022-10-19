#include <Engine/DemoEngine.hpp>
#include <Engine/FX/bufferFX.hpp>
#include <Engine/FX/FireFX.hpp>
#include <Engine/FX/PlasmaUpFX.hpp>
#include <Engine/FX/PlasmaFX.hpp>
#include <Engine/utils/Timer.hpp>
#include <utilities/alias.hpp>
#include <Engine/FX/SpriteFX.hpp>

int main()
{
	auto demoEngine = std::make_unique<DemoEngine>();
	auto& engine = *demoEngine.get();
	// auto width = engine._widthScr;
	// auto height = engine._heightScr;
	auto& drawer = engine.getDrawer();

	// auto& sprBuffer = drawer.addBuffer<SpriteFX>( 10 );
	// auto& spr1 = sprBuffer.addSprite("img/test-1.png", 10);

	// spr1.setPos( 100,100 );

	// sprBuffer.setBufferFX( std::make_unique<FireFX>( 10 ) );

	drawer.addBuffer<PlasmaFX>( 10 );
	// drawer.addBuffer<FireFX>( 10 );
	// drawer.addBuffer<PlasmaUpFX>( 10 );
	// drawer.addTunnelBuffer( 10, "img/tunnel_1.png" );


	// TODO 19 OCTUBRE
	//? [1]	: Pasar los otros FX de los efectos y una vez checkear todos hacer otra TODO list de
	//?		todos los recursos(sprites/logos/música) y optimizaciones que hacer
	//?
	//? [2.4]{SpriteFX} : Se pueden hacer variaciones de este buffer para que tenga un updatePos
	//?					que mueva los sprite en forma de sinusoidal o algo

	engine.Draw();
}
