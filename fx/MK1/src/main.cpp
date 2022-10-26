#include <Engine/DemoEngine.hpp>
#include <Engine/FX/IncludeFX.hpp>

int main()
{
	auto demoEngine = std::make_unique<DemoEngine>();
	auto& engine = *demoEngine.get();
	auto& drawer = engine.getDrawer();

	// auto& sprBuffer = drawer.addBuffer<SpriteFX>( 12 ); // 18
	// auto& B1 = sprBuffer.addSprite("img/B.png");
	// auto& B2 = sprBuffer.addSprite("img/B.png");
	// auto& Y = sprBuffer.addSprite("img/Y.png");
	// auto& O = sprBuffer.addSprite("img/O.png");
	// auto& I = sprBuffer.addSprite("img/I.png");
	// auto& T = sprBuffer.addSprite("img/T.png");

	// auto& M = sprBuffer.addSprite("img/M.png");
	// auto& K = sprBuffer.addSprite("img/K.png");
	// auto& ONE = sprBuffer.addSprite("img/1.png");

	// B1.setPos( 720,100 );
	// B1.setSpeed( -2, 0 );
	// I.setPos( 800,120 );
	// I.setSpeed( -2, 0 );
	// T.setPos( 850,120 );
	// T.setSpeed( -2, 0 );

	// B2.setPos( -201, 195 );
	// B2.setSpeed( 2, 0 );
	// O.setPos( -121, 225 );
	// O.setSpeed( 2, 0 );
	// Y.setPos( -70, 210 );
	// Y.setSpeed( 2, 0 );

	// M.setPos( -1221, 150 );
	// M.setSpeed( 2, 0 );
	// K.setPos( -1121, 150 );
	// K.setSpeed( 2, 0 );
	// ONE.setPos( -1000, 160 );
	// ONE.setSpeed( 2, 0 );

	// sprBuffer.setBufferFX( std::make_unique<FireFX>( 10, *(drawer._src.get()) ) );
	
	drawer.addBuffer<FireUpDownFX>( 16 );
	// drawer.addBuffer<PlasmaUpFX>( 20 );// 20
	// drawer.addTunnelBuffer( 20, "img/tun_4.png" );// 20

	// drawer.addBuffer<PlasmaFX>( 20 );// 20
	// drawer.addTunnelBuffer( 20, "img/tun_6.png" );// 20

	// drawer.addBuffer<MoireFX>( 24 ); // 24
	// drawer.addBuffer<MoireTimedFX>( 24 ); // 24
	// drawer.addBuffer<MoireExtendFX>( 24 ); // 24
	// drawer.addTunnelBuffer( 20, "img/tun_8.png" ); // 20
	
	// drawer.addBuffer<BlobsFX>( 30 );//30

	//? [Windows?]

	engine.Draw();


}
