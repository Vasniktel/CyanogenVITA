#include "clock.h"
#include "homeMenu.h"

void digitaltime(int x, int y, int color, int hr) //color == 0 is white, color == 0 is black
{					
	SceDateTime time;
	sceRtcGetCurrentClockLocalTime(&time);
		
	if (hr == 0)
	{
		if(time.hour >= 12) 
			vita2d_pgf_draw_textf(Roboto, x + 75, y, RGBA8(255, 255, 255, 255), 1.0f, "PM"); 
		else 
			vita2d_pgf_draw_textf(Roboto, x + 75, y, RGBA8(255, 255, 255, 255), 1.0f, "AM");   
		
		if (time.hour > 12)
			time.hour -= 12;
	
		if (time.hour == 00)
			time.hour = 12;
			
		vita2d_pgf_draw_textf(Roboto, x, y, RGBA8(255, 255, 255, 255), 1.0f, "%2d:%02d", time.hour, time.minute);
	}
	
	else if (hr == 1)
	{
		vita2d_pgf_draw_textf(Roboto, x + 40, y, RGBA8(255, 255, 255, 255), 1.0f, "%2d:%02d", time.hour, time.minute);
	}
}

void getDayOfWeek(int x, int y, int n)
{
	SceDateTime time;
	sceRtcGetCurrentClockLocalTime(&time);

	int day = sceRtcGetDayOfWeek(time.year, time.month, time.day);

    static const char days[7][16] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    
    char buffer[16];
	sprintf(buffer, "%s", days[day]);
    
    if(n == 2)
        buffer[3] = 0;
        
    vita2d_pgf_draw_textf(Roboto, x, y, RGBA8(255, 255, 255, 255), 1.0f, "%s", buffer);
}
	
void getMonthOfYear(int x, int y)
{
	static const char months[12][16] =
	{
		"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
	};
       
    SceDateTime time;
	sceRtcGetCurrentClockLocalTime(&time);
    vita2d_pgf_draw_textf(Roboto, x, y, RGBA8(255, 255, 255, 255), 1.0f, "%d %s", time.day, months[time.month - 1]);
}