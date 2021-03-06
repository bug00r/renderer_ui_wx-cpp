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

INCLUDEDIR=-I. -I./../_third/wxw/include -I./../_third/wxw/lib/wx/include/msw-unicode-static-3.0 \
			-I./../../c/collections/array/ -I./../../c/math/statistics/ -I./../../c/math/vec/ -I./../../c/math/mat/ -I./../../c/math/utils/ \
			-I./../../c/math/algorithm/noise/ -I./../../c/math/algorithm/fractals/ -I./../../c/color -I./../../c/texture

SRC=renderer_ui_wx.cpp renderer_ui_app.h renderer_ui_app.cpp renderer_ui_main_frame.h renderer_ui_main_frame.cpp RenderbugPanel.h RenderbugPanel.cpp RenderbugPanelImpl.h RenderbugPanelImpl.cpp

BIN=renderer_ui_wx.exe
LIBS=-lwx_mswu_html-3.0  -lwx_mswu_core-3.0 -lwx_baseu-3.0 -lwxtiff-3.0 -lwxjpeg-3.0 -lwxpng-3.0 -lwxregexu-3.0 \
	-lpng -lz -lrpcrt4 -loleaut32 -lole32 -luuid -lwinspool -lwinmm -lshell32 -lcomctl32 -lcomdlg32 -ladvapi32 -lwsock32 \
	-lgdi32 -static -lstdc++ -ltexture -lfractals -lnoise -lcrgb_array -lfarray -larray -lcolor -lstatistics -lutilsmath -lmat -lvec
LIBDIR= -L./../_third/wxw/lib \
		-L./../../c/collections/array/$(BUILDDIR_C) \
		-L./../../c/math/statistics/$(BUILDDIR_C) \
		-L./../../c/math/utils/$(BUILDDIR_C) \
		-L./../../c/math/mat/$(BUILDDIR_C) \
		-L./../../c/math/vec/$(BUILDDIR_C) \
		-L./../../c/math/algorithm/noise/$(BUILDDIR_C) \
		-L./../../c/math/algorithm/fractals/$(BUILDDIR_C) \
		-L./../../c/color/$(BUILDDIR_C) \
		-L./../../c/texture/$(BUILDDIR_C) \
		-L$(BUILDDIR)

all: createdir $(BUILDPATH)$(BIN)

$(BUILDPATH)$(BIN): $(SRC)
	$(CXX) $(CFLAGS) $(SRC) -o $(BUILDPATH)$(BIN) $(INCLUDEDIR) $(LIBDIR) $(LIBS)
	
.PHONY: clean createdir

createdir:
	mkdir -p $(BUILDDIR)

clean:
	-rm -dr $(BUILDROOT)
