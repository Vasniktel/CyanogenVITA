#include "clock.h"
#include "fs.h"
#include "homeMenu.h"
#include "include/keyboard.h"
#include "lockScreen.h"
#include "settingsMenu.h"
#include "utils.h"

int lockScreen()
{
	lockscreenBg = loadPngWithFilter("ux0:/data/CyanogenVITA/system/home/menu/lockscreenBg.png");
	
	FILE * password;
	FILE * pin;
	char passwordData[20] = "";
	char pinData[5] = "";
	int passProtect = 0;
	
	if (fileExists("ux0:/data/CyanogenVITA/system/app/settings/password.bin"))
		passProtect = 1;	
	else if (fileExists("ux0:/data/CyanogenVITA/system/app/settings/pin.bin"))
		passProtect = 2;
	else if ((!(fileExists("ux0:/data/CyanogenVITA/system/app/settings/password.bin"))) || (!(fileExists("ux0:/data/CyanogenVITA/system/app/settings/pin.bin"))))
		passProtect = 0;
	
	while (1)
	{
		vita2d_start_drawing();
        vita2d_clear_screen();
	
		vita2d_draw_texture(background, 0, 0);
		vita2d_draw_texture(lockscreenBg, 0, 0);
		
		if (hrTime == 0)
			digitaltime(350, 170, 0, 4.0f, hrTime);
		else 
			digitaltime(310, 170, 0, 4.0f, hrTime);
		getDayOfWeek(360, 220, 0, 1.1f);
		getMonthOfYear(500, 220, 1.1f);

		controls();
		wifiStatus(675, 6);
		batteryStatus(730, 8, 0);
		digitaltime(835, 30, 0, 1.0f, hrTime);
		vita2d_draw_texture(cursor, cursorX, cursorY);
		
		endDrawing();
		
		if (passProtect == 1)
		{
			if(pressed & SCE_CTRL_CIRCLE)
			{
				initKeyboard("Enter Password", "", 20);
				password = fopen("ux0:/data/CyanogenVITA/system/app/settings/password.bin", "r");
				fscanf(password, "%s", passwordData);
				fclose(password);

				if (strcmp(tempMessage, passwordData) == 0)
				{
					vita2d_free_texture(lockscreenBg);
					home();
				}
				else if ((strcmp(tempMessage, passwordData) != 0))
				{
					vita2d_free_texture(lockscreenBg);
					lockScreen();
				}	
			}
		}
		
		else if (passProtect == 2)
		{
			if(pressed & SCE_CTRL_CIRCLE)
			{
				initKeyboard("Enter Pin", "", 5);
				pin = fopen("ux0:/data/CyanogenVITA/system/app/settings/pin.bin", "r");
				fscanf(pin, "%s", pinData);
				fclose(pin);

				if (strcmp(tempPin, pinData) == 0)
				{
					vita2d_free_texture(lockscreenBg);
					home();
				}
				else if ((strcmp(tempPin, pinData) != 0))
				{
					vita2d_free_texture(lockscreenBg);
					lockScreen();
				}
			}
		}
		
		else if (passProtect == 0)
		{
			if(pressed & SCE_CTRL_CIRCLE)
			{
				vita2d_free_texture(lockscreenBg);
				home();
			}
		}
	}
	
	return 0;
}