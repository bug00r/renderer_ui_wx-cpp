///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 27 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

// WTF is this here

#ifndef __RENDERBUGPANEL_H__
#define __RENDERBUGPANEL_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/combobox.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/valtext.h>
#include <wx/statbox.h>
#include <wx/slider.h>
#include <wx/checkbox.h>
#include <wx/choicebk.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/radiobox.h>
#include <wx/spinctrl.h>
#include <wx/listbook.h>
#include <wx/listctrl.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class RenderbugPanel
///////////////////////////////////////////////////////////////////////////////
class RenderbugPanel : public wxPanel 
{
	private:
	
	protected:
		wxListbook* m_listbook1;
		wxPanel* m_panel4;
		wxChoicebook* algorithm;
		wxPanel* average_panel;
		wxStaticText* m_staticText122;
		wxComboBox* average_ds;
		wxStaticText* m_staticText52;
		wxTextCtrl* start_seed_ds;
		wxStaticText* m_staticText512;
		wxTextCtrl* seed_ds;
		wxStaticText* m_staticText5111;
		wxTextCtrl* reduction_ds;
		wxStaticText* m_staticText71;
		wxComboBox* reduction_type_ds;
		wxPanel* m_panel6;
		wxStaticText* m_staticText1221;
		wxComboBox* average_md;
		wxStaticText* m_staticText1231;
		wxComboBox* average2_md;
		wxStaticText* m_staticText521;
		wxTextCtrl* start_seed_md;
		wxStaticText* m_staticText5121;
		wxTextCtrl* seed_md;
		wxStaticText* m_staticText51111;
		wxTextCtrl* reduction_md;
		wxStaticText* m_staticText711;
		wxComboBox* reduction_type_md;
		wxPanel* m_panel7;
		wxStaticText* m_staticText35;
		wxTextCtrl* mb_min_real;
		wxStaticText* m_staticText36;
		wxTextCtrl* mb_min_imag;
		wxStaticText* m_staticText41;
		wxStaticText* m_staticText351;
		wxTextCtrl* mb_max_real;
		wxStaticText* m_staticText361;
		wxTextCtrl* mb_max_imag;
		wxStaticText* m_staticText411;
		wxSlider* mb_iterations;
		wxComboBox* mb_color_model;
		wxPanel* m_panel8;
		wxStaticText* m_staticText352;
		wxTextCtrl* julia_min_real;
		wxStaticText* m_staticText362;
		wxTextCtrl* julia_min_imag;
		wxStaticText* m_staticText412;
		wxStaticText* m_staticText3511;
		wxTextCtrl* julia_max_real;
		wxStaticText* m_staticText3611;
		wxTextCtrl* julia_max_imag;
		wxStaticText* m_staticText4111;
		wxSlider* julia_iterations;
		wxComboBox* julia_color_model;
		wxComboBox* julia_poly_func;
		wxComboBox* julia_constant;
		wxCheckBox* julia_use_input;
		wxTextCtrl* julia_const_real;
		wxStaticText* m_staticText3621;
		wxTextCtrl* julia_const_imag;
		wxStaticText* m_staticText4121;
		wxPanel* m_panel24;
		wxButton* generate_algorithm;
		wxPanel* m_panel9;
		wxChoicebook* filter;
		wxPanel* m_panel10;
		wxComboBox* selected_filter;
		wxRadioBox* kernel_type;
		wxSpinCtrl* kernel_size;
		wxSlider* pixel_factor;
		wxPanel* m_panel16;
		wxButton* filter_set;
		wxButton* filter_add;
		wxPanel* m_panel18;
		wxChoicebook* manipulation;
		wxPanel* m_panel19;
		wxStaticText* m_staticText69;
		wxSlider* brightness;
		wxStaticText* m_staticText70;
		wxSlider* contrast;
		wxButton* manipulator_set;
		wxButton* manipulator_add;
		wxPanel* noise_image_panel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void on_algorithm_changed( wxChoicebookEvent& event ) { event.Skip(); }
		virtual void generateNoise( wxCommandEvent& event ) { event.Skip(); }
		virtual void on_filter_changed( wxChoicebookEvent& event ) { event.Skip(); }
		virtual void on_filter_set( wxCommandEvent& event ) { event.Skip(); }
		virtual void on_filter_add( wxCommandEvent& event ) { event.Skip(); }
		virtual void on_manipulation_changed( wxChoicebookEvent& event ) { event.Skip(); }
		virtual void on_manipulator_set( wxCommandEvent& event ) { event.Skip(); }
		virtual void on_manipulator_add( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		RenderbugPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 819,-1 ), long style = wxTAB_TRAVERSAL ); 
		~RenderbugPanel();
	
};

#endif //__RENDERBUGPANEL_H__
