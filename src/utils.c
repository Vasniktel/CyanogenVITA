#include "utils.h"

void setBilinearFilter(int enabled, vita2d_texture * texture)
{
	if (enabled == 1)
	{
		vita2d_texture_set_filters(texture, SCE_GXM_TEXTURE_FILTER_LINEAR, SCE_GXM_TEXTURE_FILTER_LINEAR);
	}
}

vita2d_texture * loadPngWithFilter(const char * path)
{
	vita2d_texture *texture = vita2d_load_PNG_file(path);
	setBilinearFilter(1, texture);
	
	return texture;
}

void endDrawing() 
{
	vita2d_end_drawing();
	vita2d_swap_buffers();
	sceDisplayWaitVblankStart();
}

void initNet()
{
	if (sceSysmoduleIsLoaded(SCE_SYSMODULE_NET) != SCE_SYSMODULE_LOADED)
		sceSysmoduleLoadModule(SCE_SYSMODULE_NET);
	
	static char memory[16 * 1024];

	SceNetInitParam param;
	param.memory = memory;
	param.size = sizeof(memory);
	param.flags = 0;

	sceNetInit(&param);
	sceNetCtlInit();
}

void termNet()
{
	sceNetCtlTerm();
	sceNetTerm();
}
