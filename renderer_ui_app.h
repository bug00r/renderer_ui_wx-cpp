#ifndef RENDERER_UI_APP_H
#define RENDERER_UI_APP_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "renderer_ui_main_frame.h"

class MyApp: public wxApp
{
public:
    virtual bool OnInit();
};

#endif