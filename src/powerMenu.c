#include "clock.h"
#include "homeMenu.h"
#include "powerMenu.h"
#include "settingsMenu.h"
#include "utils.h"

void cleanUp()
{
	vita2d_free_pgf(Roboto);
	
	termAppUtil();
	termNet();
    vita2d_fini();
}

int powerMenu()
{
	while (1)
	{
		vita2d_start_drawing();
        vita2d_clear_screen();
	
		vita2d_draw_texture(background, 0, 0);
		
		vita2d_draw_texture(ic_launcher_music, 145, 360);
		vita2d_draw_texture(ic_launcher_messenger, 290, 360);
		vita2d_draw_texture(ic_launcher_browser, 575, 360);
		vita2d_draw_texture(ic_launcher_settings, 720, 360);
		
		controls();
		appDrawerIcon();
		wifiStatus(675, 6);
		batteryStatus(730, 8, 0);
		digitaltime(835, 30, 0, 1.0f, hrTime);
		navbarControls(0);
			
		vita2d_draw_texture(power, 173, 110);

		vita2d_pgf_draw_textf(Roboto, 320, 220, RGBA8(0, 0, 0, 255), 1.6f, "Power Off");
		vita2d_pgf_draw_textf(Roboto, 320, 345, RGBA8(0, 0, 0, 255), 1.6f, "Recovery");
		
		if (cursor(173, 786, 110, 216))
		{

			vita2d_draw_texture(powerSelection, 174, 110);
			vita2d_pgf_draw_textf(Roboto, 320, 220, RGBA8(0, 0, 0, 255), 1.6f, "Power Off");
			vita2d_pgf_draw_textf(Roboto, 320, 345, RGBA8(0, 0, 0, 255), 1.6f, "Recovery");
			if(pressed & SCE_CTRL_CROSS)
				sceKernelExitProcess(0);
		}
		else if (cursor(173, 786, 217, 434))
		{
			vita2d_draw_texture(recoverySelection, 173, 110);
			vita2d_pgf_draw_textf(Roboto, 320, 220, RGBA8(0, 0, 0, 255), 1.6f, "Power Off");
			vita2d_pgf_draw_textf(Roboto, 320, 345, RGBA8(0, 0, 0, 255), 1.6f, "Recovery");
			if(pressed & SCE_CTRL_CROSS)
				sceKernelExitProcess(0);
		}

		vita2d_draw_texture(cursor, cursorX, cursorY);
		
		endDrawing();

		if (returnToMenu2)
		{
			return 1;
		}	
	
		else if(pressed & SCE_CTRL_CIRCLE)
		{
			home();
		}
	}
	
	return 0;
}