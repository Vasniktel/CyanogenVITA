#include <psp2/appmgr.h>
#include <psp2/apputil.h>
#include <psp2/message_dialog.h>
#include <psp2/ime_dialog.h>
#include <psp2/display.h>

#include <vita2d.h>

#define SCE_IME_DIALOG_MAX_TITLE_LENGTH	(128)
#define SCE_IME_DIALOG_MAX_TEXT_LENGTH	(512)

#define IME_DIALOG_RESULT_NONE 0
#define IME_DIALOG_RESULT_RUNNING 1
#define IME_DIALOG_RESULT_FINISHED 2
#define IME_DIALOG_RESULT_CANCELED 3

char tempMessage[20];
char tempPin[5];
char tempData[250];

void utf16_to_utf8(uint16_t *src, uint8_t *dst);
void utf8_to_utf16(uint8_t *src, uint16_t *dst);
void initImeDialog(char *title, char *initial_text, int max_text_length);
void getText(char *text);
void initKeyboard(char * initialMessage, char * message, int textLimit);