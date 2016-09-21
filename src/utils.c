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