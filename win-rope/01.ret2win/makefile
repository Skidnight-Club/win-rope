PROJECT  := ret2win

PREFIX   := x86_64-w64-mingw32

CC       := $(PREFIX)-gcc
CFLAGS   := -O0 -fno-PIE -fno-stack-protector -U_FORTIFY_SOURCE -masm=intel -Wl,--disable-dynamicbase,--disable-nxcompat

all: $(PROJECT).exe

$(PROJECT).exe: ret2win.c
	$(CC) $(CFLAGS) $^ -o ret2win.exe

clean: ret2win.exe
	rm ret2win.exe
