#ifndef __RENDERBUGPANELIMPL_H__
#define __RENDERBUGPANELIMPL_H__

#include <iostream>
#include <wx/dcbuffer.h>
#include <wx/msgdlg.h>
#include "RenderbugPanel.h"

extern "C" {
	#include "noise.h"
	#include "fractals.h"
	#include "texture.h"
	#include <complex.h>
}

class RenderPanel: public wxPanel 
{
	private:
		texture_t * texture;

	protected:
		void canvas_paint( wxPaintEvent& event );
	public:
		void paintEvent(wxPaintEvent & evt);
        void paintNow();
 
		void setTexture(texture_t * newtexture);
		texture_t * getTexture();
		
        void render(wxAutoBufferedPaintDC& dc);
		
		RenderPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL ); 
		~RenderPanel();
};

class RenderbugPanelImpl : public RenderbugPanel 
{
	private:
		enum TriggerType { SET, ADD };
		RenderPanel * canvas;
		texture_t * texture;
		int cur_algorithm;
		int cur_filter;
		int cur_manipulation;
		int cur_selected_filter;
		typedef void (RenderbugPanelImpl::*AlgorithmMemberFunc)(void);
		typedef void (RenderbugPanelImpl::*FiltertypeMemberFunc)(TriggerType);
		typedef void (RenderbugPanelImpl::*ManipulatorMemberFunc)(TriggerType);
		typedef float (*Average4Func)(float,float,float,float);
		typedef float (*Average2Func)(float,float);
		typedef float (*SeedReductionFunc)(float,float);
		typedef void  (*mb_color_func)(const mandelbrot_t * mb, const mandelbrot_point_t * mbt, cRGB_t * col);
		typedef void (*jul_color_func)(const julia_t * julia, const julia_point_t * jbt, cRGB_t * col);
		typedef float _Complex (*juliapolyfunc)(const float _Complex *cp, const float _Complex *c);
		typedef void (*filter_func)(texture_t * texture, const unsigned int pxrange, const float factor);
		float _Complex julia_constants[12];
		
		AlgorithmMemberFunc cur_algo_func;
		FiltertypeMemberFunc cur_filtertype_func;
		ManipulatorMemberFunc cur_manipulator_func;
		
		void refresh_texture(texture_t *texture, int width, int height, bool setAsNew = true);
		double txtctrl_to_double_errormsg(wxTextCtrl* control, double default_value, bool shomsg, const wxString &message, const wxString &caption);
		texture_t * create_new_texture(int width, int height);
		
		void process_ds();
		void process_md();
		void process_evolution();
		void process_mandelbrot();
		void process_julia();
		
		void process_filter_standard(TriggerType filter_trigger_type);
		void process_filter_advanced(TriggerType filter_trigger_type);
		void process_brigthness_contrast(TriggerType filter_trigger_type);
		
	protected:
		
		// Virtual event handlers, overide them in your derived class
		void generateNoise( wxCommandEvent& event );
		void on_algorithm_changed( wxChoicebookEvent& event );
		void on_filter_changed( wxChoicebookEvent& event );
		void on_manipulation_changed( wxChoicebookEvent& event );
		void on_filter_set( wxCommandEvent& event );
		void on_filter_add( wxCommandEvent& event );
		void on_manipulator_set( wxCommandEvent& event );
		void on_manipulator_add( wxCommandEvent& event );
		
	public:
		
		RenderbugPanelImpl( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL ); 
		~RenderbugPanelImpl();
	
};

#endif
