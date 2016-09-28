#include "main.h"
#include "homeMenu.h"
#include "utils.h"

int main(int argc, char *argv[]) 
{
	memset(&pad, 0, sizeof(SceCtrlData));
	sceCtrlPeekBufferPositive(0, &pad, 1);
	
    vita2d_init();
	initNet();
	initAppUtil();
	
	vita2d_set_clear_color(RGBA8(0, 0, 0, 255));
	Roboto = vita2d_load_custom_pgf("ux0:/data/CyanogenVITA/system/fonts/Roboto.pgf");
	
	vita2d_texture * gekihen = loadPngWithFilter("ux0:/data/CyanogenVITA/system/misc/gekihen.png");
	background = loadPngWithFilter("ux0:/data/CyanogenVITA/system/framework/framework-res/res/ventana.png");
	cursor = loadPngWithFilter("ux0:/data/CyanogenVITA/system/cursor/cursor.png");
	ic_allapps = loadPngWithFilter("ux0:/data/CyanogenVITA/system/icons/default/allapps/ic_allapps.png");
	ic_allapps_pressed = loadPngWithFilter("ux0:/data/CyanogenVITA/system/icons/default/allapps/ic_allapps_pressed.png");
	ic_launcher_browser = loadPngWithFilter("ux0:/data/CyanogenVITA/system/icons/default/browser/ic_launcher_browser.png");
	ic_launcher_camera = loadPngWithFilter("ux0:/data/CyanogenVITA/system/icons/default/camera/ic_launcher_camera.png");
	ic_launcher_clock = loadPngWithFilter("ux0:/data/CyanogenVITA/system/icons/default/clock/ic_launcher_clock.png");
	ic_launcher_filemanager = loadPngWithFilter("ux0:/data/CyanogenVITA/system/icons/default/filemanager/ic_launcher_filemanager.png");
	ic_launcher_gallery = loadPngWithFilter("ux0:/data/CyanogenVITA/system/icons/default/gallery/ic_launcher_gallery.png");
	ic_launcher_game = loadPngWithFilter("ux0:/data/CyanogenVITA/system/icons/default/game/ic_launcher_game.png");
	ic_launcher_messenger = loadPngWithFilter("ux0:/data/CyanogenVITA/system/icons/default/messenger/ic_launcher_messenger.png");
	ic_launcher_music = loadPngWithFilter("ux0:/data/CyanogenVITA/system/icons/default/music/ic_launcher_eleven.png");
	ic_launcher_settings = loadPngWithFilter("ux0:/data/CyanogenVITA/system/icons/default/settings/ic_launcher_settings.png");
	navbar = loadPngWithFilter("ux0:/data/CyanogenVITA/system/home/menu/navbar.png");
	navbarHighlight = loadPngWithFilter("ux0:/data/CyanogenVITA/system/home/menu/navbarHighlight.png");
	navbar2 = loadPngWithFilter("ux0:/data/CyanogenVITA/system/home/menu/navbar2.png");
	navbarHighlight2 = loadPngWithFilter("ux0:/data/CyanogenVITA/system/home/menu/navbarHighlight2.png");
	
	stat_sys_wifi_signal_null = loadPngWithFilter("ux0:/data/CyanogenVITA/system/home/icons/stat_sys_wifi_signal_null.png");
	 _0 = loadPngWithFilter("ux0:/data/CyanogenVITA/system/home/icons/stat_sys_battery_0.png");
	 _15 = loadPngWithFilter("ux0:/data/CyanogenVITA/system/home/icons/stat_sys_battery_15.png");
	 _28 = loadPngWithFilter("ux0:/data/CyanogenVITA/system/home/icons/stat_sys_battery_28.png");
	 _43 = loadPngWithFilter("ux0:/data/CyanogenVITA/system/home/icons/stat_sys_battery_43.png");
	 _57 = loadPngWithFilter("ux0:/data/CyanogenVITA/system/home/icons/stat_sys_battery_57.png");
	 _71 = loadPngWithFilter("ux0:/data/CyanogenVITA/system/home/icons/stat_sys_battery_71.png");
	 _85 = loadPngWithFilter("ux0:/data/CyanogenVITA/system/home/icons/stat_sys_battery_85.png");
	 _100 = loadPngWithFilter("ux0:/data/CyanogenVITA/system/home/icons/stat_sys_battery_100.png");
	 _charge = loadPngWithFilter("ux0:/data/CyanogenVITA/system/home/icons/stat_sys_battery_charge.png");
	
	while(1)
	{
		vita2d_start_drawing();
		vita2d_clear_screen();
		vita2d_draw_texture(gekihen, 0, 0);
		endDrawing();
		//sceKernelDelayThread(5 * 1000 * 1000);//delay 5 seconds
        home();
	}
	
	vita2d_free_pgf(roboto);
	
	termAppUtil();
	termNet();
    vita2d_fini();
    
    sceKernelExitProcess(0);
    return 0;
}