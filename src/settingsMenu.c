#include "appDrawer.h"
#include "clock.h"
#include "homeMenu.h"
#include "settingsMenu.h"
#include "utils.h"

int aboutMenu()
{
	settingsBg = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/aboutBg.png");
	highlight = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/highlight.png");
	
	SceSystemSwVersionParam param;
	param.size = sizeof(SceSystemSwVersionParam);
	sceKernelGetSystemSwVersion(&param);
	
	while(1)
	{
		vita2d_start_drawing();
		vita2d_clear_screen();
	
		vita2d_draw_texture(aboutBg, 0, 0);
		
		if (cursor(0, 900, 117, 231))
			vita2d_draw_texture(highlight, 0, 117);
		
		vita2d_pgf_draw_textf(Roboto, 30, 152, RGBA8(0, 0, 0, 255), 1.0f, "CyanogenVITA updates");
		vita2d_pgf_draw_textf(Roboto, 30, 182, RGBA8(0, 0, 0, 255), 1.0f, "Click for, view or install available updates");
		vita2d_pgf_draw_textf(Roboto, 30, 250, RGBA8(0, 0, 0, 255), 1.0f, "CyanogenVITA version: %s-%d%02d%02d-OFFICIAL", VERSION, YEAR, MONTH + 1, DAY);
		vita2d_pgf_draw_textf(Roboto, 30, 280, RGBA8(0, 0, 0, 255), 1.0f, "Model: PS Vita");
		vita2d_pgf_draw_textf(Roboto, 30, 310, RGBA8(0, 0, 0, 255), 1.0f, "Mac Address: 00:00:00:00:00:00");
		vita2d_pgf_draw_textf(Roboto, 30, 370, RGBA8(0, 0, 0, 255), 1.0f, "Kernel Version: %.4s", param.version_string);
		vita2d_pgf_draw_textf(Roboto, 30, 400, RGBA8(0, 0, 0, 255), 1.0f, "Henkaku Version: 5");
		vita2d_pgf_draw_textf(Roboto, 30, 430, RGBA8(0, 0, 0, 255), 1.0f, "Developer: Joel16");
		
		controls();
		wifiStatus(612, 6);
		batteryStatus(667, 8, 0);
		digitaltime(773, 30, 0, 0);
		navbarControls(1);
		vita2d_draw_texture(cursor, cursorX, cursorY);
	
		if(pad.buttons & SCE_CTRL_CIRCLE)
			appDrawer();
		
		vita2d_end_drawing();
		vita2d_swap_buffers();	
	}
	
	return 0;
}

int storageMenu()
{
	settingsBg = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/storageBg.png");
	
	while(1)
	{
		vita2d_start_drawing();
		vita2d_clear_screen();
	
		vita2d_draw_texture(storageBg, 0, 0);
		
		vita2d_pgf_draw_textf(Roboto, 20, 140, RGBA8(58, 159, 150, 255), 1.0f, "Device Storage");
		
		vita2d_pgf_draw_textf(Roboto, 20, 200, RGBA8(191, 191, 191, 255), 1.0f, "Device Storage");
		
		controls();
		wifiStatus(612, 6);
		batteryStatus(667, 8, 0);
		digitaltime(773, 30, 0, 0);
		navbarControls(1);
		vita2d_draw_texture(cursor, cursorX, cursorY);
	
		if(pad.buttons & SCE_CTRL_CIRCLE)
			appDrawer();
		
		vita2d_end_drawing();
		vita2d_swap_buffers();	
	}
	
	return 0;
}

int settingsMenu()
{
	settingsBg = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/settingsBg.png");
	hover = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/hover.png");
	
	while(1)
	{
		vita2d_start_drawing();
		vita2d_clear_screen();
		
		vita2d_draw_texture(settingsBg, 0, 0);
		
		if (cursor(0, 442, 118, 222))
			vita2d_draw_texture(hover, 3, 118);
		else if (cursor(0, 442, 223, 330))
			vita2d_draw_texture(hover, 3, 223);
		else if (cursor(0, 442, 331, 439))
			vita2d_draw_texture(hover, 3, 331);
		else if (cursor(0, 442, 440, 544))
			vita2d_draw_texture(hover, 3, 440);
		else if (cursor(450, 894, 118, 222))
			vita2d_draw_texture(hover, 456, 118);
		else if (cursor(450, 894, 223, 330))
			vita2d_draw_texture(hover, 456, 223);
		else if (cursor(450, 894, 331, 439))
			vita2d_draw_texture(hover, 456, 331);
		else if (cursor(450, 894, 440, 544))
			vita2d_draw_texture(hover, 456, 440);
		
		vita2d_pgf_draw_textf(Roboto, 100, 176, RGBA8(0, 0, 0, 255), 1.0f, "Wi-Fi");
		vita2d_pgf_draw_textf(Roboto, 100, 284, RGBA8(0, 0, 0, 255), 1.0f, "Language");
		vita2d_pgf_draw_textf(Roboto, 100, 394, RGBA8(0, 0, 0, 255), 1.0f, "Performance");
		vita2d_pgf_draw_textf(Roboto, 100, 505, RGBA8(0, 0, 0, 255), 1.0f, "Developer Options");
		vita2d_pgf_draw_textf(Roboto, 552, 176, RGBA8(0, 0, 0, 255), 1.0f, "Display");
		vita2d_pgf_draw_textf(Roboto, 552, 284, RGBA8(0, 0, 0, 255), 1.0f, "Storage");
		vita2d_pgf_draw_textf(Roboto, 552, 394, RGBA8(0, 0, 0, 255), 1.0f, "Security");
		vita2d_pgf_draw_textf(Roboto, 552, 505, RGBA8(0, 0, 0, 255), 1.0f, "About");
	
		controls();
		wifiStatus(612, 6);
		batteryStatus(667, 8, 0);
		digitaltime(773, 30, 0, 0);
		navbarControls(1);
		vita2d_draw_texture(cursor, cursorX, cursorY);
	
		if(pad.buttons & SCE_CTRL_CIRCLE)
			appDrawer();
		if(pad.buttons & SCE_CTRL_SQUARE)
			storageMenu();
		if(pad.buttons & SCE_CTRL_TRIANGLE)
			aboutMenu();	
		
		vita2d_end_drawing();
		vita2d_swap_buffers();
	}
	
	return 0;
}