#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#include <psp2/ctrl.h>
#include <psp2/power.h>

#include <vita2d.h>

#define cursor(x1, x2, y1, y2)  (cursorX  >= (x1) && cursorX  <= (x2) && cursorY >= (y1) && cursorY <= (y2))
#define returnToMenu ((cursor(288, 384, 474, 544)) && (pad.buttons & SCE_CTRL_CROSS))
#define returnToMenu2 ((cursor(900, 960, 322, 437)) && (pad.buttons & SCE_CTRL_CROSS))

vita2d_texture 	*background, *cursor, *ic_allapps, *ic_allapps_pressed, *ic_launcher_browser, *ic_launcher_camera,
				*ic_launcher_clock, *ic_launcher_filemanager, *ic_launcher_gallery, *ic_launcher_game, *ic_launcher_messenger, 
				*ic_launcher_music, *ic_launcher_settings, *navbar, *navbarHighlight, *navbar2, *navbarHighlight2, 
				*stat_sys_wifi_signal_null, *_0, *_15, *_28, *_43, *_57, *_71, *_85, *_100, *_charge;

vita2d_pgf *Roboto;

SceCtrlData pad, old_pad;
unsigned int pressed;

int cursorX, cursorY;

int controls();
void batteryStatus(int x, int y, int style);
void wifiStatus(int x, int y);
void navbarControls(int type);
void appDrawerIcon();
int home();