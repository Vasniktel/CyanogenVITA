#include "appDrawer.h"
#include "clock.h"
#include "homeMenu.h"
#include "settingsMenu.h"
#include "utils.h"

void controls() //Main controller function - allows cursor movement
{	
	//Intialize the limits
	int llimit = 0;
	int rlimit = 940;
	int ulimit = 0;
	int dlimit = 524;

	memset(&pad, 0, sizeof(SceCtrlData));
	sceCtrlPeekBufferPositive(0, &pad, 1);

	currPad = pad.buttons;
	padPressed = currPad & ~oldPad;
	holdPad = padPressed;
	releasedPad = ~currPad & oldPad;
		
	//Read keys
	sceCtrlPeekBufferPositive(0, &pad, 1);
		
	if (!(pad.buttons & SCE_CTRL_CROSS))	
	{	
		if(pad.buttons & SCE_CTRL_RIGHT)
			cursorX += 7;
		
		if(pad.buttons & SCE_CTRL_LEFT)
			cursorX -= 7;

		if(pad.buttons & SCE_CTRL_DOWN)
			cursorY += 7;
		
		if(pad.buttons & SCE_CTRL_UP)
			cursorY-= 7;
	}
	
	/* Prevents the cursor from going off screen */
	
	if (cursorX <= llimit)
	{
		cursorX = llimit;
	}
		
	else if (cursorX >= rlimit)
	{
		cursorX = rlimit;
	}
		
	if (cursorY <= ulimit)
	{	
		cursorY = ulimit;
	}
		
	else if (cursorY >= dlimit)
	{
		cursorY = dlimit;
	}
}

void batteryStatus(int x, int y, int style)
{
	int batt = scePowerGetBatteryLifePercent();
	
	if (style == 0)
	{
		if(batt == 0)
			vita2d_draw_texture(_0, x, y);	
		else if(batt > 0 && batt <= 15)
			vita2d_draw_texture(_15, x, y);
		else if(batt > 15 && batt <= 28)
			vita2d_draw_texture(_28, x, y);
		else if(batt > 28 && batt <= 43)
			vita2d_draw_texture(_43, x, y);
		else if(batt > 43 && batt <= 57)
			vita2d_draw_texture(_57, x, y);
		else if(batt > 57 && batt <= 71)
			vita2d_draw_texture(_71, x, y);
		else if(batt > 71 && batt <= 99)
			vita2d_draw_texture(_85, x, y);
		else if(batt == 100)
			vita2d_draw_texture(_100, x, y);
		
		if (scePowerIsBatteryCharging()) 
		{
			vita2d_draw_texture(_charge, x, y);
		}
		
		vita2d_pgf_draw_textf(Roboto, x + 41, y + 22, RGBA8(255, 255, 255, 255), 1.0f, "%d%%", batt);
	}
}

void wifiStatus(int x, int y)
{
	vita2d_draw_texture(stat_sys_wifi_signal_null, x, y);
}

void navbarControls(int type)
{
	if (type == 0)
	{		
		vita2d_draw_texture(navbar, 330, 488);
		
		if (cursor(288, 384, 474, 544))
			vita2d_draw_texture(navbarHighlight, 288, 474); //If the cursor is moved onto/near the back icon, it displays the highlighted back icon, else it just draws the navbar.
		else
			vita2d_draw_texture(navbar, 330, 488);
		
		if (cursor(385, 520, 474, 544))
		{
			vita2d_draw_texture(navbarHighlight, 415, 474); //If the cursor is moved onto/near the back icon, it displays the highlighted back icon, else it just draws the navbar.
			if(padPressed & SCE_CTRL_CROSS)
				home();
		}
		else
			vita2d_draw_texture(navbar, 330, 488);
		
		if (cursor(535, 620, 474, 544))
		{
			vita2d_draw_texture(navbarHighlight, 550, 474); //If the cursor is moved onto/near the back icon, it displays the highlighted back icon. else it just draws the navbar.
			vita2d_draw_texture(navbar, 330, 488);
		}
		else
			vita2d_draw_texture(navbar, 330, 488);
	}
	
	else if (type == 1)
	{		
		vita2d_draw_texture(navbar2, 910, 122);
		
		if (cursor(900, 960, 110, 220))
			vita2d_draw_texture(navbarHighlight2, 900, 92); //If the cursor is moved onto/near the back icon, it displays the highlighted back icon, else it just draws the navbar.
		else
			vita2d_draw_texture(navbar2, 910, 122);
		
		if (cursor(900, 960, 221, 321))
		{
			vita2d_draw_texture(navbarHighlight2, 900, 222); //If the cursor is moved onto/near the back icon, it displays the highlighted back icon, else it just draws the navbar.
			if(padPressed & SCE_CTRL_CROSS)
				home();
		}
		else
			vita2d_draw_texture(navbar2, 910, 122);
		
		if (cursor(900, 960, 322, 437))
		{
			vita2d_draw_texture(navbarHighlight2, 900, 345); //If the cursor is moved onto/near the back icon, it displays the highlighted back icon. else it just draws the navbar.
			vita2d_draw_texture(navbar2, 910, 122);
		}
		else
			vita2d_draw_texture(navbar2, 910, 122);
	}
}

void appDrawerIcon() //Draws the app drawer icon. Draws a different icon of the same size once hovered with the cursor.
{
	if (cursor(435, 525, 385, 475))
	{
		vita2d_draw_texture(ic_allapps_pressed, 435, 385);
		if(padPressed & SCE_CTRL_CROSS)
			appDrawer();
	}
	
	else
		vita2d_draw_texture(ic_allapps, 435, 385);
}

int home()
{
	while(1)
	{
		vita2d_start_drawing();
		vita2d_clear_screen();
		
		vita2d_draw_texture(background, 0, 0);
		
		if (cursor(140, 240, 355, 455))
			vita2d_draw_texture_scale(ic_launcher_music, 140, 355, 1.1, 1.1);
		else
			vita2d_draw_texture(ic_launcher_music, 145, 360);
		
		if (cursor(285, 385, 355, 455))
			vita2d_draw_texture_scale(ic_launcher_messenger, 285, 355, 1.1, 1.1);
		else
			vita2d_draw_texture(ic_launcher_messenger, 290, 360);
		
		
		if (cursor(570, 670, 355, 455))
			vita2d_draw_texture_scale(ic_launcher_browser, 570, 355, 1.1, 1.1);
		else
			vita2d_draw_texture(ic_launcher_browser, 575, 360);
		
		if (cursor(715, 815, 355, 455))
		{
			vita2d_draw_texture_scale(ic_launcher_settings, 715, 355, 1.1, 1.1);
			if(padPressed & SCE_CTRL_CROSS)
			{
				vita2d_free_texture(backdrop);
				settingsMenu();
			}	
		}
		else
			vita2d_draw_texture(ic_launcher_settings, 720, 360);
		
		controls();
		appDrawerIcon();
		wifiStatus(675, 6);
		batteryStatus(730, 8, 0);
		digitaltime(835, 30, 0, 0);
		navbarControls(0);
		vita2d_draw_texture(cursor, cursorX, cursorY);
		
		endDrawing();
	}
		
	return 0;
}