#include <psp2/display.h>
#include <psp2/net/net.h>
#include <psp2/net/netctl.h>
#include <psp2/sysmodule.h>

#include <vita2d.h>

void setBilinearFilter(int enabled, vita2d_texture *texture);
vita2d_texture * loadPngWithFilter(const char * path);
void endDrawing();
void initNet();
void termNet();