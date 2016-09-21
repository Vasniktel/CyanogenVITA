TARGET   = CyanogenVita
TITLE_ID = CYAN0GENV
SOURCES := src

VERSION	= '"6.0.1"'

PREFIX   = arm-vita-eabi
CC       = $(PREFIX)-gcc
CXX      = $(PREFIX)-g++
CFLAGS   = -Wl,-q -Wall -Werror -O3 -DVERSION=$(VERSION)
CXXFLAGS = $(CFLAGS) -std=c++11 -fno-rtti -fno-exceptions
ASFLAGS  = $(CFLAGS)

OBJS     = appDrawer.o clock.o main.o homeMenu.o settingsMenu.o utils.o

LIBS	 = 	-lvita2d -lSceKernel_stub -lSceDisplay_stub -lSceGxm_stub \
			-lSceSysmodule_stub -lSceCtrl_stub -lScePgf_stub \
			-lScePower_stub \
			-lSceCommonDialog_stub -lfreetype -lpng -ljpeg -lz -lm -lc

all: $(TARGET).vpk

%.vpk: eboot.bin
	vita-mksfoex -d PARENTAL_LEVEL=1 -s APP_VER=06.01 -s TITLE_ID=$(TITLE_ID) "$(TARGET)" param.sfo
	vita-pack-vpk -s param.sfo -b eboot.bin \
		--add ../sce_sys/icon0.png=sce_sys/icon0.png \
		--add ../sce_sys/livearea/contents/bg.png=sce_sys/livearea/contents/bg.png \
		--add ../sce_sys/livearea/contents/startup.png=sce_sys/livearea/contents/startup.png \
		--add ../sce_sys/livearea/contents/template.xml=sce_sys/livearea/contents/template.xml \
	$(TARGET).vpk
	
eboot.bin: $(TARGET).velf
	vita-make-fself $< $@

%.velf: %.elf
	$(PREFIX)-strip -g $<
	vita-elf-create $< $@

$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

%.o: %.png
	$(PREFIX)-ld -r -b binary -o $@ $^
%.o: %.txt
	$(PREFIX)-ld -r -b binary -o $@ $^

clean:
	@rm -rf $(TARGET).vpk $(TARGET).velf $(TARGET).elf $(TARGET).unstripped.elf $(OBJS) \
		eboot.bin param.sfo