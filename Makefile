CFLAGS=-std=c++17 -O1 -fext-numeric-literals
#-ggdb -Wpedantic -pedantic-errors -Wall -Wextra #Warnings caused build crash
#-pg for profiling 

CXX=g++
BUILDROOT?=build

ifeq ($(CLANG),1)
	export CXX=clang++
endif

BUILDROOT?=build
BUILDDIR?=$(BUILDROOT)/$(CXX)
BUILDDIR_C?=$(BUILDROOT)/gcc
BUILDPATH?=$(BUILDDIR)/

INCLUDEDIR=-I. -I/c/dev/include -I/c/dev/include/wx-3.2 -I/c/dev/lib/wx/include/msw-unicode-static-3.2 \

SRC=renderer_ui_wx.cpp renderer_ui_app.h renderer_ui_app.cpp renderer_ui_main_frame.h renderer_ui_main_frame.cpp RenderbugPanel.h RenderbugPanel.cpp RenderbugPanelImpl.h RenderbugPanelImpl.cpp

BIN=renderer_ui_wx.exe
#-lwxtiff-3.2 -lwxjpeg-3.2 -lwxpng-3.2 -lwxregexu-3.2
LIBS=-lwx_mswu_html-3.2 -lwx_mswu_core-3.2 -lwx_baseu-3.2 \
	-lpng -lz -lrpcrt4 -loleaut32 -lole32 -luuid -lwinspool -lwinmm -lshell32 -lcomctl32 -lcomdlg32 -ladvapi32 -lwsock32 \
	-luxtheme -loleacc -lshlwapi -lgdi32 -static -lstdc++ -lbatkit -lversion
LIBDIR= -L/c/dev/lib -L./$(BUILDDIR)

all: createdir $(BUILDPATH)$(BIN)

$(BUILDPATH)$(BIN): $(SRC)
	$(CXX) $(CFLAGS) $(SRC) -o $(BUILDPATH)$(BIN) $(INCLUDEDIR) $(LIBDIR) $(LIBS)
	
.PHONY: clean createdir

createdir:
	mkdir -p $(BUILDDIR)

clean:
	-rm -dr $(BUILDROOT)
