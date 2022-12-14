#include <Engine/DemoEngine.hpp>
#include <Engine/FX/IncludeFX.hpp>

//#define MINIAUDIO_IMPLEMENTATION
//#include "../miniaudio.h"


extern "C"
{
	#define MINIAUDIO_IMPLEMENTATION
	#include "includes/miniaudio.h"
}

int main()
{
	// MEMORIA
	// 1º. Desarrollo : Inicio de iteración, desde la primera reunión, objetivos, y pasos
	// 2º. Marco Teórico : Teoria relativa al proyecto
	// 2.1º. TEORIA : Demo, intros, historia, mates, FX
	// 2.2º. ESTADO DEL ARTE : Ver el desarrollo de los puntos teóricos comentados. Como hace la gente hoy lo mismo

	ma_result result;
    ma_engine mEngine;

    result = ma_engine_init(NULL, &mEngine);
    
	if (result != MA_SUCCESS) {
        printf("Failed to initialize audio engine.");
        return -1;
    }

    ma_engine_play_sound(&mEngine, "img/MK1_Demo.mp3", NULL);


	// TODO : SEE AWESOME CPP REPO y BUSCAR MINIAUDIO-MINIMP3
	auto demoEngine = std::make_unique<DemoEngine>();
	auto& engine = *demoEngine.get();
	auto& drawer = engine.getDrawer();

	auto& sprBuffer = drawer.addBuffer<SpriteFX>( 13 );
	auto& B1 = sprBuffer.addSprite("img/B.png");
	auto& B2 = sprBuffer.addSprite("img/B.png");
	auto& Y = sprBuffer.addSprite("img/Y.png");
	auto& O = sprBuffer.addSprite("img/O.png");
	auto& I = sprBuffer.addSprite("img/I.png");
	auto& T = sprBuffer.addSprite("img/T.png");

	auto& M = sprBuffer.addSprite("img/M.png");
	auto& K = sprBuffer.addSprite("img/K.png");
	auto& ONE = sprBuffer.addSprite("img/1.png");

	B1.setPos( 720,100 );
	B1.setSpeed( -2, 0 );
	I.setPos( 810,120 );
	I.setSpeed( -2, 0 );
	T.setPos( 860,120 );
	T.setSpeed( -2, 0 );

	B2.setPos( -201, 195 );
	B2.setSpeed( 2, 0 );
	O.setPos( -121, 225 );
	O.setSpeed( 2, 0 );
	Y.setPos( -70, 210 );
	Y.setSpeed( 2, 0 );

	M.setPos( 1680, 90 );
	M.setSpeed( -2, 0 );
	K.setPos( 1801, 100 );
	K.setSpeed( -2, 0 );
	ONE.setPos( 1905, 110 );
	ONE.setSpeed( -2, 0 );

	sprBuffer.setBufferFX( std::make_unique<FireFX>( 10, *(drawer._src.get()) ) );
	
	drawer.addBuffer<FireUpDownFX>( 16 );
	drawer.addBuffer<PlasmaUpFX>( 21 );// 20
	drawer.addTunnelBuffer( 21, "img/tun_4.png" );// 20

	drawer.addBuffer<PlasmaFX>( 21 );// 20
	drawer.addTunnelBuffer( 21, "img/tun_6.png" );// 20

	drawer.addBuffer<MoireFX>( 24 ); // 24
	drawer.addBuffer<MoireTimedFX>( 24 ); // 24
	drawer.addBuffer<MoireExtendFX>( 24 ); // 24
	drawer.addTunnelBuffer( 20, "img/tun_8.png" ); // 20
	
	drawer.addBuffer<BlobsFX>( 20 );//30

	// ? [Windows?]

	engine.Draw();

    ma_engine_uninit(&mEngine);

}
