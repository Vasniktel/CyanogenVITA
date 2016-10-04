#include <psp2/apputil.h>
#include <psp2/appmgr.h>
#include <psp2/display.h>
#include <psp2/net/net.h>
#include <psp2/net/netctl.h>
#include <psp2/sysmodule.h>

#include <stdio.h>
#include <string.h>

#include <vita2d.h>

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