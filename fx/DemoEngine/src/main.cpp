#include <Engine/DemoEngine.hpp>
#include <Engine/FX/IncludeFX.hpp>

int main()
{
	auto demoEngine = std::make_unique<DemoEngine>();
	auto& engine = *demoEngine.get();
	auto& drawer = engine.getDrawer();

	// auto& sprBuffer = drawer.addBuffer<SpriteFX>( 10 );
	// auto& B1 = sprBuffer.addSprite("img/B.png", 10);
	// auto& B2 = sprBuffer.addSprite("img/B.png", 10);
	// auto& Y = sprBuffer.addSprite("img/Y.png", 10);
	// auto& O = sprBuffer.addSprite("img/O.png", 1);
	// auto& I = sprBuffer.addSprite("img/I.png", 10);
	// auto& T = sprBuffer.addSprite("img/T.png", 10);

	// auto& M = sprBuffer.addSprite("img/M.png", 10);
	// auto& K = sprBuffer.addSprite("img/K.png", 10);
	// auto& ONE = sprBuffer.addSprite("img/1.png", 10);

	// B1.setPos( 200,100 );
	// B1.setSpeed( 1, 0 );

	// I.setPos( 280,120 );
	// I.setSpeed( 1, 0 );
	
	// T.setPos( 330,120 );
	// T.setSpeed( 1, 0 );

	// B2.setPos( 250, 185 );
	// B2.setSpeed( 1, 0 );

	// O.setPos( 330, 215 );
	// O.setSpeed( 1, 0 );

	// Y.setPos( 381, 200 );	
	// Y.setSpeed( 1, 0 );

	// M.setPos( 50, 0 );
	// K.setPos( 200, 0 );
	// ONE.setPos( 300, 0 );



	// sprBuffer.setBufferFX( std::make_unique<FireFX>( 10, *(drawer._src.get()) ) );

	// drawer.addBuffer<PlasmaFX>( 3 );
	// drawer.addBuffer<FireUpDownFX>( 20 );

	// drawer.addTunnelBuffer( 5, "img/tun_1.png" );
	// drawer.addTunnelBuffer( 5, "img/tun_2.png" );
	drawer.addTunnelBuffer( 5, "img/tun_3.png" );
	// drawer.addTunnelBuffer( 5, "img/tun_4.png" );
	// drawer.addTunnelBuffer( 5, "img/tun_5.png" );
	// drawer.addTunnelBuffer( 5, "img/tun_5.png" );
	drawer.addTunnelBuffer( 5, "img/tun_6.png" );
	// drawer.addTunnelBuffer( 5, "img/tun_7.png" );
	drawer.addTunnelBuffer( 5, "img/tun_8.png" );
	// drawer.addTunnelBuffer( 5, "img/tun_9.png" );
	// drawer.addTunnelBuffer( 5, "img/tun_10.png" );
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
