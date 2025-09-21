PROJECT  := split

PREFIX   := x86_64-w64-mingw32

BIN      := $(shell pwd)/../../bin
EXE      := $(BIN)/$(PROJECT).exe

CC       := $(PREFIX)-gcc
CFLAGS   := -O0 -fno-PIE -fno-stack-protector -U_FORTIFY_SOURCE -masm=intel -Wl,--disable-dynamicbase,--disable-nxcompat

all: $(EXE)

$(EXE): $(PROJECT).c
	$(CC) $(CFLAGS) $^ -o $(EXE)

clean: $(EXE)
	rm $(EXE)
