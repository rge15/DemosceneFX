#include <Engine/DemoEngine.hpp>
#include <Engine/FX/IncludeFX.hpp>

int main()
{
	auto demoEngine = std::make_unique<DemoEngine>();
	auto& engine = *demoEngine.get();
	auto& drawer = engine.getDrawer();

	// auto& sprBuffer = drawer.addBuffer<SpriteFX>( 10 );
	// auto& B1 = sprBuffer.addSprite("img/B2.png", 10);
	// auto& B2 = sprBuffer.addSprite("img/B2.png", 10);
	// auto& Y = sprBuffer.addSprite("img/Y2.png", 10);
	// auto& O = sprBuffer.addSprite("img/O2.png", 10);


	// B1.setPos( 200,100 );
	// B1.setSpeed( 1, 0 );

	// B2.setPos( 250, 185 );
	// B2.setSpeed( 1, 0 );

	// O.setPos( 330, 215 );
	// O.setSpeed( 1, 0 );

	// Y.setPos( 381, 200 );
	// Y.setSpeed( 1, 0 );


	// sprBuffer.setBufferFX( std::make_unique<FireFX>( 10, *(drawer._src.get()) ) );

	// drawer.addBuffer<PlasmaFX>( 3 );
	// drawer.addBuffer<FireUpDownFX>( 20 );

	drawer.addTunnelBuffer( 10, "img/Tunel_1.png" );
	drawer.addBuffer<MoireFX>( 3 );
	drawer.addBuffer<MoireTimedFX>( 3 );
	drawer.addBuffer<MoireExtendFX>( 3 );


	// TODO 19 OCTUBRE
	//? [1]	: Pasar los otros FX de los efectos y una vez checkear todos hacer otra TODO list de
	//?		todos los recursos(sprites/logos/música) y optimizaciones que hacer
	//?		- Sprites [Presents MK I]
	//?		- Sprite 1 Tunnel
	//?		- Sprite 2 Tunnel
	//?		- Música ?

	//? Hacer un bufferFX own?

	//? [Windows?]

	engine.Draw();
}
