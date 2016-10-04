#include "appDrawer.h"
#include "clock.h"
#include "homeMenu.h"
#include "settingsMenu.h"
#include "utils.h"

int appDrawer()
{
	backdrop = vita2d_load_PNG_file("ux0:/data/CyanogenVITA/system/home/menu/backdrop.png");
	
	while(1)
	{
		vita2d_start_drawing();
		vita2d_clear_screen();
		
		vita2d_draw_texture(background, 0, 0);
		vita2d_draw_texture(backdrop, 10, 40);
		
		if (cursor(40, 140, 85, 185))
			vita2d_draw_texture_scale(ic_launcher_browser, 40, 85, 1.1, 1.1);
		else 
			vita2d_draw_texture(ic_launcher_browser, 45, 90);
		vita2d_pgf_draw_textf(Roboto, 50, 225, RGBA8(0, 0, 0, 255), 0.9f, "Browser");
		
		if (cursor(195, 295, 85, 185))
			vita2d_draw_texture_scale(ic_launcher_camera, 195, 85, 1.1, 1.1);
		else 
			vita2d_draw_texture(ic_launcher_camera, 200, 90);
		vita2d_pgf_draw_textf(Roboto, 203, 225, RGBA8(0, 0, 0, 255), 0.9f, "Camera");
		
		if (cursor(350, 450, 85, 185))
			vita2d_draw_texture_scale(ic_launcher_clock, 350, 85, 1.1, 1.1);
		else 
			vita2d_draw_texture(ic_launcher_clock, 355, 90);
		vita2d_pgf_draw_textf(Roboto, 370, 225, RGBA8(0, 0, 0, 255), 0.9f, "Clock");
		
		if (cursor(505, 605, 85, 185))
			vita2d_draw_texture_scale(ic_launcher_filemanager, 505, 85, 1.1, 1.1);
		else 
			vita2d_draw_texture(ic_launcher_filemanager, 510, 90);
		vita2d_pgf_draw_textf(Roboto, 510, 225, RGBA8(0, 0, 0, 255), 0.9f, "Manager");
		
		if (cursor(660, 760, 85, 185))
			vita2d_draw_texture_scale(ic_launcher_gallery, 660, 85, 1.1, 1.1);
		else 
			vita2d_draw_texture(ic_launcher_gallery, 665, 90);
		vita2d_pgf_draw_textf(Roboto, 670, 225, RGBA8(0, 0, 0, 255), 0.9f, "Gallery");
		
		if (cursor(815, 915, 85, 185))
			vita2d_draw_texture_scale(ic_launcher_game, 815, 85, 1.1, 1.1);
		else 
			vita2d_draw_texture(ic_launcher_game, 820, 90);
		vita2d_pgf_draw_textf(Roboto, 830, 225, RGBA8(0, 0, 0, 255), 0.9f, "Game");
		
		if (cursor(40, 140, 265, 365))
			vita2d_draw_texture_scale(ic_launcher_messenger, 40, 265, 1.1, 1.1);
		else 
			vita2d_draw_texture(ic_launcher_messenger, 45, 270);
		vita2d_pgf_draw_textf(Roboto, 39, 405, RGBA8(0, 0, 0, 255), 0.9f, "Messenger");
		
		if (cursor(195, 295, 265, 365))
			vita2d_draw_texture_scale(ic_launcher_music, 195, 265, 1.1, 1.1);
		else 
			vita2d_draw_texture(ic_launcher_music, 200, 270);
		vita2d_pgf_draw_textf(Roboto, 210, 405, RGBA8(0, 0, 0, 255), 0.9f, "Music");
		
		if (cursor(350, 450, 265, 365))
		{
			vita2d_draw_texture_scale(ic_launcher_settings, 350, 265, 1.1, 1.1);
			if(padPressed & SCE_CTRL_CROSS)
			{
				vita2d_free_texture(backdrop);
				settingsMenu();
			}	
		}
		else 
			vita2d_draw_texture(ic_launcher_settings, 355, 270);
		vita2d_pgf_draw_textf(Roboto, 355, 405, RGBA8(0, 0, 0, 255), 0.9f, "Settings");
		
		controls();
		wifiStatus(675, 6);
		batteryStatus(730, 8, 0);
		digitaltime(835, 30, 0, hrTime);
		navbarControls(0);
		vita2d_draw_texture(cursor, cursorX, cursorY);
		
		endDrawing();
		
		if (returnToMenu)
		{
			vita2d_free_texture(backdrop);
			home();
		}	
		
		else if(padPressed & SCE_CTRL_CIRCLE)
		{
			vita2d_free_texture(backdrop);
			home();
		}		
	}
		
	return 0;
}