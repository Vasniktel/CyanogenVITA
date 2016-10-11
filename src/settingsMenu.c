#include "appDrawer.h"
#include "clock.h"
#include "fs.h"
#include "homeMenu.h"
#include "include/keyboard.h"
#include "settingsMenu.h"
#include "utils.h"

int aboutMenu()
{
	if (darkThemeMode == 0)
	{
		aboutBg = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/aboutBg.png");
		highlight = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/highlight.png");
		fontColor = black;
	}
	else
	{
		aboutBg = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/dark/aboutBg.png");
		highlight = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/dark/highlight.png");
		fontColor = lightGray;
	}
	
	SceSystemSwVersionParam param;
	param.size = sizeof(SceSystemSwVersionParam);
	sceKernelGetSystemSwVersion(&param);
	
	char henkakuVersion[10];
	
	SceNetEtherAddr mac;
	sceNetGetMacAddress(&mac, 0);
	
	while(1)
	{
		vita2d_start_drawing();
		vita2d_clear_screen();
	
		vita2d_draw_texture(aboutBg, 0, 0);
		
		if (cursor(0, 900, 117, 230))
			vita2d_draw_texture(highlight, 0, 117);
		else if (cursor(0, 900, 231, 343))
			vita2d_draw_texture(highlight, 0, 232);
		else if (cursor(0, 900, 344, 456))
			vita2d_draw_texture(highlight, 0, 347);
		
		vita2d_pgf_draw_textf(Roboto, 30, 162, fontColor, 1.0f, "CyanogenVITA updates");
		vita2d_pgf_draw_textf(Roboto, 30, 192, fontColor, 1.0f, "Click for, view or install available updates");
		vita2d_pgf_draw_textf(Roboto, 30, 270, fontColor, 1.0f, "CyanogenVITA version: %s-%d%02d%02d-OFFICIAL", VERSION, YEAR, MONTH + 1, DAY);
		vita2d_pgf_draw_textf(Roboto, 30, 300, fontColor, 1.0f, "Model: PS Vita");
		vita2d_pgf_draw_textf(Roboto, 30, 330, fontColor, 1.0f, "Mac Address: %02X:%02X:%02X:%02X:%02X:%02X", mac.data[0], mac.data[1], mac.data[2], mac.data[3], mac.data[4], mac.data[5]);
		vita2d_pgf_draw_textf(Roboto, 30, 385, fontColor, 1.0f, "Kernel Version: %.4s", param.version_string);
		strcpy(henkakuVersion, (char *) param.version_string);
		vita2d_pgf_draw_textf(Roboto, 30, 415, fontColor, 1.0f, "Henkaku Version: %c", henkakuVersion[(strlen(henkakuVersion) - 1)]);
		vita2d_pgf_draw_textf(Roboto, 30, 445, fontColor, 1.0f, "Developer: Joel16");
		
		controls();
		wifiStatus(612, 6);
		batteryStatus(667, 8, 0);
		digitaltime(773, 30, 0, 1.0f, hrTime);
		navbarControls(1);
		vita2d_draw_texture(cursor, cursorX, cursorY);
		
		endDrawing();
		
		if (returnToMenu2)
		{
			vita2d_free_texture(aboutBg);
			vita2d_free_texture(highlight);
			settingsMenu();
		}	
	
		else if(pressed & SCE_CTRL_CIRCLE)
		{
			vita2d_free_texture(aboutBg);
			vita2d_free_texture(highlight);
			settingsMenu();
		}	
	}
	
	return 0;
}

int developerMenu()
{
	if (darkThemeMode == 0)
	{
		developerBg = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/developerBg.png");
		highlight = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/highlight.png");
		fontColor = black;
	}
	else
	{
		developerBg = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/dark/developerBg.png");
		highlight = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/dark/highlight.png");
		fontColor = lightGray;
	}
	
	toggleOn = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/toggleOn.png");
	toggleOff = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/toggleOff.png");
	
	while(1)
	{
		vita2d_start_drawing();
		vita2d_clear_screen();
	
		vita2d_draw_texture(developerBg, 0, 0);
		
		if (cursor(0, 900, 117, 230))
		{
			vita2d_draw_texture(highlight, 0, 117);
		}
			
		else if (cursor(0, 900, 231, 343))
			vita2d_draw_texture(highlight, 0, 232);
		else if (cursor(0, 900, 344, 456))
			vita2d_draw_texture(highlight, 0, 347);
		
		vita2d_pgf_draw_textf(Roboto, 30, 192, fontColor, 1.0f, "Dark theme");
		
		controls();
		wifiStatus(612, 6);
		batteryStatus(667, 8, 0);
		digitaltime(773, 30, 0, 1.0f, hrTime);
		navbarControls(1);
		vita2d_draw_texture(cursor, cursorX, cursorY);
		
		if (darkThemeMode == 0)
			vita2d_draw_texture(toggleOff, 790, 147);
		else if (darkThemeMode == 1)
			vita2d_draw_texture(toggleOn, 790, 147);
		
		endDrawing();
		
		if (darkThemeMode == 0)
		{
			if (pressed & SCE_CTRL_CROSS)
			{
				darkThemeMode = 1;
				FILE * darkTheme = fopen("ux0:/data/CyanogenVITA/system/app/settings/darkTheme.bin", "w");
				fprintf(darkTheme, "%d", darkThemeMode);
				fclose(darkTheme);
				vita2d_free_texture(developerBg);
				vita2d_free_texture(highlight);
				vita2d_free_texture(toggleOn);
				vita2d_free_texture(toggleOff);
				developerMenu();
			}
		}	
		else if (darkThemeMode == 1)
		{
			if (pressed & SCE_CTRL_CROSS)
			{
				darkThemeMode = 0;
				FILE * darkTheme = fopen("ux0:/data/CyanogenVITA/system/app/settings/darkTheme.bin", "w");
				fprintf(darkTheme, "%d", darkThemeMode);
				fclose(darkTheme);
				vita2d_free_texture(developerBg);
				vita2d_free_texture(highlight);
				vita2d_free_texture(toggleOn);
				vita2d_free_texture(toggleOff);
				developerMenu();
			}
		}
		
		if (returnToMenu2)
		{
			vita2d_free_texture(developerBg);
			vita2d_free_texture(highlight);
			vita2d_free_texture(toggleOn);
			vita2d_free_texture(toggleOff);
			settingsMenu();
		}	
	
		else if(pressed & SCE_CTRL_CIRCLE)
		{
			vita2d_free_texture(developerBg);
			vita2d_free_texture(highlight);
			vita2d_free_texture(toggleOn);
			vita2d_free_texture(toggleOff);
			settingsMenu();
		}	
	}
	
	return 0;
}

int displayMenu()
{
	if (darkThemeMode == 0)
	{
		displayBg = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/displayBg.png");
		highlight = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/highlight.png");
		fontColor = black;
	}
	else
	{
		displayBg = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/dark/displayBg.png");
		highlight = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/dark/highlight.png");
		fontColor = lightGray;
	}

	while(1)
	{
		vita2d_start_drawing();
		vita2d_clear_screen();
	
		vita2d_draw_texture(displayBg, 0, 0);
		
		if (cursor(0, 900, 117, 230))
			vita2d_draw_texture(highlight, 0, 117);
		else if (cursor(0, 900, 231, 343))
			vita2d_draw_texture(highlight, 0, 232);
		else if (cursor(0, 900, 344, 456))
			vita2d_draw_texture(highlight, 0, 347);
		
		vita2d_pgf_draw_textf(Roboto, 30, 186, fontColor, 1.0f, "Themes");
		vita2d_pgf_draw_textf(Roboto, 30, 300, fontColor, 1.0f, "Time");
		vita2d_pgf_draw_textf(Roboto, 30, 415, fontColor, 1.0f, "Miscellaneous");
		
		controls();
		wifiStatus(612, 6);
		batteryStatus(667, 8, 0);
		digitaltime(773, 30, 0, 1.0f, hrTime);
		navbarControls(1);
		vita2d_draw_texture(cursor, cursorX, cursorY);
		
		endDrawing();
		
		if ((cursor(0, 900, 231, 343)) && (pressed & SCE_CTRL_CROSS)) 
		{
			vita2d_free_texture(displayBg);
			vita2d_free_texture(highlight);
			displayTime();
		}
		
		if (returnToMenu2)
		{
			vita2d_free_texture(displayBg);
			vita2d_free_texture(highlight);
			settingsMenu();
		}	
	
		else if(pressed & SCE_CTRL_CIRCLE)
		{
			vita2d_free_texture(displayBg);
			vita2d_free_texture(highlight);
			settingsMenu();
		}	
	}
	
	return 0;
}

int displayTime()
{
	if (darkThemeMode == 0)
	{
		displayBg = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/displayBg.png");
		highlight = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/highlight.png");
		fontColor = black;
	}
	else
	{
		displayBg = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/dark/displayBg.png");
		highlight = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/dark/highlight.png");
		fontColor = lightGray;
	}
	
	toggleOn = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/toggleOn.png");
	toggleOff = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/toggleOff.png");

	while(1)
	{
		vita2d_start_drawing();
		vita2d_clear_screen();
	
		vita2d_draw_texture(displayBg, 0, 0);
		
		if (cursor(0, 900, 117, 230))
		{
			vita2d_draw_texture(highlight, 0, 117);
			
			if (hrTime == 0)
			{
				if (pressed & SCE_CTRL_CROSS)
				{
					hrTime = 1;
					FILE * timeSetTxt = fopen("ux0:/data/CyanogenVITA/system/app/clock/timeSet.bin", "w");
					fprintf(timeSetTxt, "%d", hrTime);
					fclose(timeSetTxt);
				}
			}
			
			else if (hrTime == 1)
			{
				if (pressed & SCE_CTRL_CROSS)
				{
					hrTime = 0;
					FILE * timeSetTxt = fopen("ux0:/data/CyanogenVITA/system/app/clock/timeSet.bin", "w");
					fprintf(timeSetTxt, "%d", hrTime);
					fclose(timeSetTxt);
				}
			}
		}
			
		else if (cursor(0, 900, 231, 343))
			vita2d_draw_texture(highlight, 0, 232);
		else if (cursor(0, 900, 344, 456))
			vita2d_draw_texture(highlight, 0, 347);
		
		vita2d_pgf_draw_textf(Roboto, 30, 192, fontColor, 1.0f, "Use 24-hour format");
		
		controls();
		wifiStatus(612, 6);
		batteryStatus(667, 8, 0);
		digitaltime(773, 30, 0, 1.0f, hrTime);
		navbarControls(1);
		vita2d_draw_texture(cursor, cursorX, cursorY);
		
		if (hrTime == 0)
			vita2d_draw_texture(toggleOff, 790, 147);
		else if (hrTime == 1)
			vita2d_draw_texture(toggleOn, 790, 147);
		
		endDrawing();
		
		if (returnToMenu2)
		{
			vita2d_free_texture(displayBg);
			vita2d_free_texture(highlight);
			vita2d_free_texture(toggleOn);
			vita2d_free_texture(toggleOff);
			displayMenu();
		}	
	
		else if(pressed & SCE_CTRL_CIRCLE)
		{
			vita2d_free_texture(displayBg);
			vita2d_free_texture(highlight);
			vita2d_free_texture(toggleOn);
			vita2d_free_texture(toggleOff);
			displayMenu();
		}	
	}
	
	return 0;
}

int storageMenu()
{
	if (darkThemeMode == 0)
	{
		storageBg = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/storageBg.png");
		fontColor = black;
	}
	else
	{
		storageBg = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/dark/storageBg.png");
		fontColor = lightGray;
	}
	
	double usedStorage = (getStorageInfoDouble(0) - getStorageInfoDouble(1));
	double totalStorage = getStorageInfoDouble(0);
	double fill = ((usedStorage / totalStorage) * 860.0);
	
	while(1)
	{
		vita2d_start_drawing();
        vita2d_clear_screen();
	
		vita2d_draw_texture(storageBg, 0, 0);
		
		vita2d_pgf_draw_textf(Roboto, 20, 168, RGBA8(58, 159, 150, 255), 1.6f, "%.2f GB", usedStorage);
		
		vita2d_pgf_draw_textf(Roboto, 20, 208, RGBA8(96, 125, 139, 255), 1.0f, "Total used of %.2f GB", totalStorage);
		
		vita2d_pgf_draw_textf(Roboto, 20, 292, RGBA8(96, 125, 139, 255), 1.0f, "Storage:"); 
		vita2d_pgf_draw_textf(Roboto, 20, 322, RGBA8(96, 125, 139, 255), 1.0f, "Total used of %.2f GB", totalStorage); 
		
		vita2d_draw_rectangle(20, 352, 860, 10, RGBA8(206, 215, 219, 255));
		vita2d_draw_rectangle(20, 352, fill, 10, RGBA8(0, 149, 135, 255));
		
		controls();
		wifiStatus(612, 6);
		batteryStatus(667, 8, 0);
		digitaltime(773, 30, 0, 1.0f, hrTime);
		navbarControls(1);
		vita2d_draw_texture(cursor, cursorX, cursorY);
		
		endDrawing();
	
		if (returnToMenu2)
		{
			vita2d_free_texture(storageBg);
			settingsMenu();
		}	
	
		else if(pressed & SCE_CTRL_CIRCLE)
		{
			vita2d_free_texture(storageBg);
			settingsMenu();
		}	
	}
	
	return 0;
}

int securityMenu()
{
	if (darkThemeMode == 0)
	{
		securityBg = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/securityBg.png");
		highlight = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/highlight.png");
		fontColor = black;
	}
	else
	{
		securityBg = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/dark/securityBg.png");
		highlight = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/dark/highlight.png");
		fontColor = lightGray;
	}
	
	while(1)
	{
		vita2d_start_drawing();
        vita2d_clear_screen();
		
		vita2d_draw_texture(securityBg, 0, 0);
		
		if (cursor(0, 900, 117, 230))
		{
			vita2d_draw_texture(highlight, 0, 117);
			if(pressed & SCE_CTRL_CROSS)
			{
				if (fileExists("ux0:/data/CyanogenVITA/system/app/settings/password.bin"))
					sceIoRemove("ux0:/data/CyanogenVITA/system/app/settings/password.bin");
				else if (fileExists("ux0:/data/CyanogenVITA/system/app/settings/pin.bin"))
					sceIoRemove("ux0:/data/CyanogenVITA/system/app/settings/pin.bin");
				initKeyboard("Enter Password", tempMessage, 20);
				FILE * password = fopen("ux0:/data/CyanogenVITA/system/app/settings/password.bin", "w");
				fprintf(password, "%s", tempMessage);
				fclose(password);
			}
		}
		else if (cursor(0, 900, 231, 343))
		{
			vita2d_draw_texture(highlight, 0, 232);
			if(pressed & SCE_CTRL_CROSS)
			{
				if (fileExists("ux0:/data/CyanogenVITA/system/app/settings/password.bin"))
					sceIoRemove("ux0:/data/CyanogenVITA/system/app/settings/password.bin");
				else if (fileExists("ux0:/data/CyanogenVITA/system/app/settings/pin.bin"))
					sceIoRemove("ux0:/data/CyanogenVITA/system/app/settings/pin.bin");
				initKeyboard("Enter Pin", tempPin, 5);
				FILE * pin = fopen("ux0:/data/CyanogenVITA/system/app/settings/password.bin", "w");
				fprintf(pin, "%s", tempPin);
				fclose(pin);
			}
		}
		else if (cursor(0, 900, 344, 456))
		{
			vita2d_draw_texture(highlight, 0, 347);
			if(pressed & SCE_CTRL_CROSS)
			{
				if (fileExists("ux0:/data/CyanogenVITA/system/app/settings/password.bin"))
					sceIoRemove("ux0:/data/CyanogenVITA/system/app/settings/password.bin");
				else if (fileExists("ux0:/data/CyanogenVITA/system/app/settings/pin.bin"))
					sceIoRemove("ux0:/data/CyanogenVITA/system/app/settings/pin.bin");
			}
		}
		
		vita2d_pgf_draw_textf(Roboto, 30, 186, fontColor, 1.0f, "Password lock");
		vita2d_pgf_draw_textf(Roboto, 30, 300, fontColor, 1.0f, "Pin lock");
		vita2d_pgf_draw_textf(Roboto, 30, 415, fontColor, 1.0f, "Swipe");
		
		controls();
		wifiStatus(612, 6);
		batteryStatus(667, 8, 0);
		digitaltime(773, 30, 0, 1.0f, hrTime);
		navbarControls(1);
		vita2d_draw_texture(cursor, cursorX, cursorY);
		
		endDrawing();
	
		if (returnToMenu2)
		{
			vita2d_free_texture(highlight);
			vita2d_free_texture(securityBg);
			settingsMenu();
		}	
	
		else if(pressed & SCE_CTRL_CIRCLE)
		{
			vita2d_free_texture(highlight);
			vita2d_free_texture(securityBg);
			settingsMenu();
		}	
	}
	
	return 0;
}

int settingsMenu()
{
	if (darkThemeMode == 0)
	{
		settingsBg = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/settingsBg.png");
		fontColor = black;
	}
	else
	{
		settingsBg = loadPngWithFilter("ux0:/data/CyanogenVITA/system/app/settings/dark/settingsBg.png");
		fontColor = lightGray;
	}
	
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
				
		vita2d_pgf_draw_textf(Roboto, 100, 176, fontColor, 1.0f, "Wi-Fi");
		vita2d_pgf_draw_textf(Roboto, 100, 284, fontColor, 1.0f, "Language");
		vita2d_pgf_draw_textf(Roboto, 100, 394, fontColor, 1.0f, "Performance");
		vita2d_pgf_draw_textf(Roboto, 100, 505, fontColor, 1.0f, "Developer Options");
		vita2d_pgf_draw_textf(Roboto, 552, 176, fontColor, 1.0f, "Display");
		vita2d_pgf_draw_textf(Roboto, 552, 284, fontColor, 1.0f, "Storage");
		vita2d_pgf_draw_textf(Roboto, 552, 394, fontColor, 1.0f, "Security");
		vita2d_pgf_draw_textf(Roboto, 552, 505, fontColor, 1.0f, "About");
	
		controls();
		wifiStatus(612, 6);
		batteryStatus(667, 8, 0);
		digitaltime(773, 30, 0, 1.0f, hrTime);
		navbarControls(1);
		vita2d_draw_texture(cursor, cursorX, cursorY);
		
		endDrawing();
		
		if ((cursor(0, 442, 440, 544)) && (pressed & SCE_CTRL_CROSS))
		{
			vita2d_free_texture(settingsBg);
			vita2d_free_texture(hover);
			developerMenu();
		}
		else if ((cursor(450, 894, 118, 222)) && (pressed & SCE_CTRL_CROSS))
		{
			vita2d_free_texture(settingsBg);
			vita2d_free_texture(hover);
			displayMenu();
		}
		else if ((cursor(450, 894, 223, 330)) && (pressed & SCE_CTRL_CROSS))
		{
			vita2d_free_texture(settingsBg);
			vita2d_free_texture(hover);
			storageMenu();
		}
		else if ((cursor(450, 894, 331, 439)) && (pressed & SCE_CTRL_CROSS))
		{
			vita2d_free_texture(settingsBg);
			vita2d_free_texture(hover);
			securityMenu();
		}
		else if ((cursor(450, 894, 440, 544)) && (pressed & SCE_CTRL_CROSS))
		{
			vita2d_free_texture(settingsBg);
			vita2d_free_texture(hover);
			aboutMenu();
		}
		
		if (returnToMenu2)
		{
			vita2d_free_texture(settingsBg);
			vita2d_free_texture(hover);
			appDrawer();
		}	
	
		else if(pressed & SCE_CTRL_CIRCLE)
		{
			vita2d_free_texture(settingsBg);
			vita2d_free_texture(hover);
			appDrawer();
		}	
	}
	
	return 0;
}