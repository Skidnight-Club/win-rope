PROJECT  := ret2win

PREFIX   := x86_64-w64-mingw32

CC       := $(PREFIX)-gcc
CFLAGS   := -O2 -fno-PIE -fno-stack-protector -U_FORTIFY_SOURCE

all:
	$(CC) $(CFLAGS) ret2win.c -o ret2win.exe
