#include "keyboard.h"
#include "../utils.h"

static uint16_t ime_title_utf16[SCE_IME_DIALOG_MAX_TITLE_LENGTH];
static uint16_t ime_initial_text_utf16[SCE_IME_DIALOG_MAX_TEXT_LENGTH];
static uint16_t ime_input_text_utf16[SCE_IME_DIALOG_MAX_TEXT_LENGTH + 1];
static uint8_t ime_input_text_utf8[SCE_IME_DIALOG_MAX_TEXT_LENGTH + 1];

void utf16_to_utf8(uint16_t *src, uint8_t *dst) 
{
	int i;
	for (i = 0; src[i]; i++) 
	{
		if ((src[i] & 0xFF80) == 0) 
		{
			*(dst++) = src[i] & 0xFF;
		} 
		else if((src[i] & 0xF800) == 0)
		{
			*(dst++) = ((src[i] >> 6) & 0xFF) | 0xC0;
			*(dst++) = (src[i] & 0x3F) | 0x80;
		} 
		else if((src[i] & 0xFC00) == 0xD800 && (src[i + 1] & 0xFC00) == 0xDC00) 
		{
			*(dst++) = (((src[i] + 64) >> 8) & 0x3) | 0xF0;
			*(dst++) = (((src[i] >> 2) + 16) & 0x3F) | 0x80;
			*(dst++) = ((src[i] >> 4) & 0x30) | 0x80 | ((src[i + 1] << 2) & 0xF);
			*(dst++) = (src[i + 1] & 0x3F) | 0x80;
			i += 1;
		} 
		else 
		{
			*(dst++) = ((src[i] >> 12) & 0xF) | 0xE0;
			*(dst++) = ((src[i] >> 6) & 0x3F) | 0x80;
			*(dst++) = (src[i] & 0x3F) | 0x80;
		}
	}

	*dst = '\0';
}

void utf8_to_utf16(uint8_t *src, uint16_t *dst) 
{
	int i;
	for (i = 0; src[i];) 
	{
		if ((src[i] & 0xE0) == 0xE0) 
		{
			*(dst++) = ((src[i] & 0x0F) << 12) | ((src[i + 1] & 0x3F) << 6) | (src[i + 2] & 0x3F);
			i += 3;
		} 
		else if ((src[i] & 0xC0) == 0xC0) {
			*(dst++) = ((src[i] & 0x1F) << 6) | (src[i + 1] & 0x3F);
			i += 2;
		} 
		else 
		{
			*(dst++) = src[i];
			i += 1;
		}
	}

	*dst = '\0';
}
 
void initImeDialog(char *title, char *initial_text, int max_text_length) 
{
    // Convert UTF8 to UTF16
	utf8_to_utf16((uint8_t *)title, ime_title_utf16);
	utf8_to_utf16((uint8_t *)initial_text, ime_initial_text_utf16);
 
    SceImeDialogParam param;
	sceImeDialogParamInit(&param);

	param.sdkVersion = 0x03150021,
	param.supportedLanguages = 0x0001FFFF;
	param.languagesForced = SCE_TRUE;
	param.type = SCE_IME_TYPE_BASIC_LATIN;
	param.title = ime_title_utf16;
	param.maxTextLength = max_text_length;
	param.initialText = ime_initial_text_utf16;
	param.inputTextBuffer = ime_input_text_utf16;

	//int res = 
	sceImeDialogInit(&param);
	return ;
}

void getText(char *text)
{
	// Convert UTF16 to UTF8
	utf16_to_utf8(ime_input_text_utf16, ime_input_text_utf8);
	strcpy(text,(char*)ime_input_text_utf8);
}

void initKeyboard(char * initialMessage, char * message, int textLimit)
{
	sceCommonDialogSetConfigParam(&(SceCommonDialogConfigParam){});

    int keyboard = 0;
	
	while (1) 
	{
        if(!keyboard)
		{
            initImeDialog(initialMessage, message, textLimit);
			keyboard = 1;
        }
		
        vita2d_start_drawing();
        vita2d_clear_screen();
		
		SceCommonDialogStatus status = sceImeDialogGetStatus();
       
		if (status == IME_DIALOG_RESULT_FINISHED) 
		{
			SceImeDialogResult result;
			memset(&result, 0, sizeof(SceImeDialogResult));
			sceImeDialogGetResult(&result);

			if (result.button == SCE_IME_DIALOG_BUTTON_CLOSE) 
			{
				status = IME_DIALOG_RESULT_CANCELED;
				break;
			}
			else 
			{
				getText(message);
				sprintf(tempMessage, "%s", message);
				sprintf(tempPin, "%s", message);
				sprintf(tempData, "%s", message);
			}
			
			status = IME_DIALOG_RESULT_CANCELED;
			break;
			sceImeDialogTerm();
			keyboard = 0;
		}
		
		endDrawing();
	}
}