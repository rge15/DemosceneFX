extern "C"
{
	#include <tinyptc.h>
}

int main()
{
	ptc_open("window", 720,480);

	for(;;);

	ptc_close();

	return 0;
}