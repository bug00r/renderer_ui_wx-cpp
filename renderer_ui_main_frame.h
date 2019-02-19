#ifndef RENDERER_UI_MAIN_FRAME_H
#define RENDERER_UI_MAIN_FRAME_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "RenderbugPanelImpl.h"

class MyFrame: public wxFrame
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
	wxWindow * mainpanel;
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    //Old way better using bind !!!wxDECLARE_EVENT_TABLE();
};
enum
{
    ID_Hello = 1
};

#endif