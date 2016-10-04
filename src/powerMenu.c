#include "clock.h"
#include "homeMenu.h"
#include "powerMenu.h"
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
			
		vita2d_draw_texture(power, 340, 197);

		vita2d_pgf_draw_textf(Roboto, 767, 227, RGBA8(0, 0, 0, 255), 1.6f, "Power Off");
		vita2d_pgf_draw_textf(Roboto, 767, 292, RGBA8(0, 0, 0, 255), 1.6f, "Recovery");
		
		if (cursor(340, 620, 197, 271))
		{

			vita2d_draw_texture(powerSelection, 340, 196);
			vita2d_pgf_draw_textf(Roboto, 567, 227, RGBA8(0, 0, 0, 255), 1.6f, "Power Off");
			vita2d_pgf_draw_textf(Roboto, 567, 292, RGBA8(0, 0, 0, 255), 1.6f, "Recovery");
			if(padPressed & SCE_CTRL_CROSS)
				sceKernelExitProcess(0);
		}
		else if (cursor(340, 620, 272, 347))
		{
			vita2d_draw_texture(recoverySelection, 340, 197);
			vita2d_pgf_draw_textf(Roboto, 567, 227, RGBA8(0, 0, 0, 255), 1.6f, "Power Off");
			vita2d_pgf_draw_textf(Roboto, 567, 292, RGBA8(0, 0, 0, 255), 1.6f, "Recovery");
			if(padPressed & SCE_CTRL_CROSS)
				sceKernelExitProcess(0);
		}

		controls();
		appDrawerIcon();
		wifiStatus(675, 6);
		batteryStatus(730, 8, 0);
		digitaltime(835, 30, 0, 0);
		navbarControls(0);
		vita2d_draw_texture(cursor, cursorX, cursorY);
		
		endDrawing();

		if (returnToMenu2)
		{
			return 1;
		}	
	
		else if(padPressed & SCE_CTRL_CIRCLE)
		{
			home ();
		}
	}
	
	return 0;
}