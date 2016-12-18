#include <psp2/apputil.h>
#include <psp2/appmgr.h>
#include <psp2/display.h>
#include <psp2/net/net.h>
#include <psp2/net/netctl.h>
#include <psp2/sysmodule.h>

#include <stdio.h>
#include <string.h>

#include <vita2d.h>

#define black RGBA8(0, 0, 0, 255)
#define white RGBA8(255, 255, 255, 255)
#define lightGray RGBA8(245, 245, 245, 255)
#define teal RGBA8(58, 159, 150, 255)

#define abs(x) ((x) < 0 ? (-x) : (x))

vita2d_texture * loadPngWithFilter(const char * path);
void endDrawing();
void initNet();
void termNet();
void initAppUtil();
void termAppUtil();
char * getStorageInfoString(int type);
double getStorageInfoDouble(int type);
void getSizeString(char *string, uint64_t size); //Thanks TheOfficialFloW
void installDirectories();
int setFileDefaultsInt(char *path, int value, int var);
float setFileDefaultsFloat(char *path, float value, float var);
char * setFileDefaultsChar(char path[], char data[], char var[]);