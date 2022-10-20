#include <Engine/DemoEngine.hpp>
#include <Engine/FX/IncludeFX.hpp>

int main()
{
	auto demoEngine = std::make_unique<DemoEngine>();
	auto& engine = *demoEngine.get();
	auto& drawer = engine.getDrawer();

	// auto& sprBuffer = drawer.addBuffer<SpriteFX>( 10 );
	// auto& spr1 = sprBuffer.addSprite("img/test-1.png", 10);

	// spr1.setPos( 100,100 );

	// sprBuffer.setBufferFX( std::make_unique<FireFX>( 10 ) );

	drawer.addBuffer<BlobsFX>( 24 );
	drawer.addBuffer<MoireFX>( 24 );
	drawer.addBuffer<MoireTimedFX>( 24 );
	drawer.addBuffer<MoireExtendFX>( 24 );
	// drawer.addBuffer<PlasmaUpFX>( 10 );
	// drawer.addTunnelBuffer( 10, "img/tunnel_1.png" );


	// TODO 19 OCTUBRE
	//? [1]	: Pasar los otros FX de los efectos y una vez checkear todos hacer otra TODO list de
	//?		todos los recursos(sprites/logos/música) y optimizaciones que hacer
	//?		- Sprites MK I
	//?		- Sprite 1 Tunnel
	//?		- Sprite 2 Tunnel
	//?		- Música ?
	//?		- Hacer un DemoEngineSrc [ Como DemoEngineConfig ] donde meter tablas de sinus y src compartidos
	//?		- Checkear pasar el tiempo del timer en vez de tener una variable _time en cada FX 
	//?
	//? [2.4]{SpriteFX} : Se pueden hacer variaciones de este buffer para que tenga un updatePos
	//?					que mueva los sprite en forma de sinusoidal o algo

	engine.Draw();
}
