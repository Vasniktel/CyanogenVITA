#include "clock.h"
#include "homeMenu.h"
#include "lockScreen.h"
#include "settingsMenu.h"
#include "utils.h"

int lockScreen()
{
	lockscreenBg = loadPngWithFilter("ux0:/data/CyanogenVITA/system/home/menu/lockscreenBg.png");
	
	while (1)
	{
		vita2d_start_drawing();
        vita2d_clear_screen();
	
		vita2d_draw_texture(background, 0, 0);
		vita2d_draw_texture(lockscreenBg, 0, 0);

		controls();
		wifiStatus(675, 6);
		batteryStatus(730, 8, 0);
		digitaltime(835, 30, 0, hrTime);
		vita2d_draw_texture(cursor, cursorX, cursorY);
		
		endDrawing();
		
		if(padPressed & SCE_CTRL_CIRCLE)
		{
			vita2d_free_texture(lockscreenBg);
			home();
		}
	}
	
	return 0;
}