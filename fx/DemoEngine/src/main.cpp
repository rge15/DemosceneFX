#include <Engine/DemoEngine.hpp>
#include <Engine/FX/IncludeFX.hpp>

int main()
{
	auto demoEngine = std::make_unique<DemoEngine>();
	auto& engine = *demoEngine.get();
	auto& drawer = engine.getDrawer();

	auto& sprBuffer = drawer.addBuffer<SpriteFX>( 10 );
	auto& spr1 = sprBuffer.addSprite("img/B2.png", 10);

	spr1.setPos( 200,100 );

	spr1.setSpeed( 1, 0 );

	sprBuffer.setBufferFX( std::make_unique<FireFX>( 10, *(drawer._src.get()) ) );

	drawer.addBuffer<PlasmaFX>( 3 );
	drawer.addBuffer<FireUpDownFX>( 20 );

	drawer.addTunnelBuffer( 10, "img/tunnel_1.png" );
	drawer.addBuffer<MoireFX>( 3 );
	drawer.addBuffer<MoireTimedFX>( 3 );
	drawer.addBuffer<MoireExtendFX>( 3 );


	// TODO 19 OCTUBRE
	//? [1]	: Pasar los otros FX de los efectos y una vez checkear todos hacer otra TODO list de
	//?		todos los recursos(sprites/logos/música) y optimizaciones que hacer
	//?		- Sprites MK I
	//?		- Sprite 1 Tunnel
	//?		- Sprite 2 Tunnel
	//?		- Música ?

	//? [2.4]{SpriteFX} : Se pueden hacer variaciones de este buffer para que tenga un updatePos
	//?					que mueva los sprite en forma de sinusoidal o algo

	//? FireUp&Down variation?
	//? Hacer un bufferFX own?

	//? [Windows?]

	engine.Draw();
}
