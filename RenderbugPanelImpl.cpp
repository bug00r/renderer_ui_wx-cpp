#include "RenderbugPanelImpl.h"

RenderPanel::RenderPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	texture = NULL;
	this->SetBackgroundStyle(wxBG_STYLE_PAINT);
	this->Connect( wxEVT_PAINT, wxPaintEventHandler( RenderPanel::canvas_paint ), NULL, this );
}

RenderPanel::~RenderPanel()
{
	if(texture!=NULL) {
		texture_free(texture);
	}
}

void RenderPanel::canvas_paint( wxPaintEvent& event ) { 
	std::cout << "call paint event" << std::endl;
	if(this->texture!=NULL) {
		wxAutoBufferedPaintDC dc(this);
		render(dc);
	}
}

void RenderPanel::setTexture(texture_t * newtexture) {
	if(this->texture!=NULL) {
		texture_free(this->texture);
	}
	this->texture = newtexture;
}

texture_t * RenderPanel::getTexture() {
	return this->texture;
}

void RenderPanel::render(wxAutoBufferedPaintDC& dc) {
	std::cout << "render render" << std::endl;

	cRGB_t * cref;
	array_error_t array_res;
	
	for (unsigned int h = 0; h < texture->height; ++h){
	  for (unsigned int w = 0; w < texture->width; ++w){
			array_res = crgb_array2D_get_ref(texture->buffer, w, h, &cref);
			if(array_res==ARRAY_ERR_OK){
				dc.SetPen( wxPen( wxColor((unsigned char)cref->r, (unsigned char)cref->g, (unsigned char)cref->b), 1 ));
				dc.DrawPoint(w, h);
			}
	    }
	};
}

RenderbugPanelImpl::RenderbugPanelImpl( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) 
: RenderbugPanel( parent, id, pos, size, style ), cur_algorithm(0), cur_filter(0), cur_manipulation(0), cur_selected_filter(0) 
{
	wxSizer * sizer = this->noise_image_panel->GetSizer();
	this->canvas = new RenderPanel(this->noise_image_panel, wxID_ANY, wxDefaultPosition, wxSize(512,512));
	sizer->Add(canvas, 1, wxALIGN_CENTER|wxALL|wxEXPAND, 5);
	
	this->cur_algo_func = &this->process_ds;
	this->cur_filtertype_func = &this->process_filter_standard;
	this->cur_manipulator_func = &this->process_brigthness_contrast;
	this->texture = NULL;

	this->average_ds->Append("arithmetic",	(void*)middle_arithmetic);
	this->average_ds->Append("hoelder",		(void*)middle_hoelder);
	this->average_ds->Append("geometric",	(void*)middle_geometric);
	this->average_ds->Append("cubic", 		(void*)middle_cubic);
	this->average_ds->Append("quad", 		(void*)middle_quad);
	this->average_ds->Append("median", 		(void*)middle_median);
	this->average_ds->Append("quantil",		(void*)middle_quantil);
	this->average_ds->Append("harmonic", 	(void*)middle_harmonic);
	
	this->average_ds->SetSelection(0);
	
	this->average_md->Append("arithmetic",	(void*)middle_arithmetic);
	this->average_md->Append("hoelder",		(void*)middle_hoelder);
	this->average_md->Append("geometric",	(void*)middle_geometric);
	this->average_md->Append("cubic", 		(void*)middle_cubic);
	this->average_md->Append("quad", 		(void*)middle_quad);
	this->average_md->Append("median", 		(void*)middle_median);
	this->average_md->Append("quantil", 	(void*)middle_quantil);
	this->average_md->Append("harmonic", 	(void*)middle_harmonic);
	
	this->average_md->SetSelection(0);
	
	this->average2_md->Append("arithmetic", (void*)middle_arithmetic2);
	this->average2_md->Append("hoelder", 	(void*)middle_hoelder2);
	this->average2_md->Append("geometric", 	(void*)middle_geometric2);
	this->average2_md->Append("cubic", 		(void*)middle_cubic2);
	this->average2_md->Append("quad", 		(void*)middle_quad2);
	this->average2_md->Append("harmonic", 	(void*)middle_harmonic2);
	
	this->average2_md->SetSelection(0);
	
	this->reduction_type_md->Append("seed * reduction", (void*)seed_reduction_mul);
	this->reduction_type_md->Append("seed / reduction",	(void*)seed_reduction_div);
	this->reduction_type_md->Append("seed + reduction", (void*)seed_reduction_add);
	this->reduction_type_md->Append("seed - reduction", (void*)seed_reduction_sub);
	this->reduction_type_md->Append("seed * sqrt(reduction)", (void*)seed_reduction_mul_sqrt);
	this->reduction_type_md->Append("seed / sqrt(reduction)", (void*)seed_reduction_div_sqrt);
	this->reduction_type_md->Append("seed + sqrt(reduction)", (void*)seed_reduction_add_sqrt);
	this->reduction_type_md->Append("seed - sqrt(reduction)", (void*)seed_reduction_sub_sqrt);
	this->reduction_type_md->Append("s * (s**2+r)/(s**2)-r",  (void*)seed_reduction_pow2_p_r_div_pow2_m_r);
	this->reduction_type_md->Append("s * (s**2-r)/(s**2)+r",  (void*)seed_reduction_pow2_m_r_div_pow2_p_r);
	this->reduction_type_md->Append("s + arithmetic(s,r)",  (void*)seed_reduction_arithmetic_add);
	this->reduction_type_md->Append("s - arithmetic(s,r)",  (void*)seed_reduction_arithmetic_sub);
	this->reduction_type_md->Append("s * arithmetic(s,r)",  (void*)seed_reduction_arithmetic_mul);
	this->reduction_type_md->Append("s / arithmetic(s,r)",  (void*)seed_reduction_arithmetic_div);
	this->reduction_type_md->Append("s + hoelder(s,r)",  (void*)seed_reduction_hoelder_add);
	this->reduction_type_md->Append("s - hoelder(s,r)",  (void*)seed_reduction_hoelder_sub);
	this->reduction_type_md->Append("s * hoelder(s,r)",  (void*)seed_reduction_hoelder_mul);
	this->reduction_type_md->Append("s / hoelder(s,r)",  (void*)seed_reduction_hoelder_div);
	this->reduction_type_md->Append("s + geometric(s,r)",  (void*)seed_reduction_geometric_add);
	this->reduction_type_md->Append("s - geometric(s,r)",  (void*)seed_reduction_geometric_sub);
	this->reduction_type_md->Append("s * geometric(s,r)",  (void*)seed_reduction_geometric_mul);
	this->reduction_type_md->Append("s / geometric(s,r)",  (void*)seed_reduction_geometric_div);
	this->reduction_type_md->Append("s + cubic(s,r)",  (void*)seed_reduction_cubic_add);
	this->reduction_type_md->Append("s - cubic(s,r)",  (void*)seed_reduction_cubic_sub);
	this->reduction_type_md->Append("s * cubic(s,r)",  (void*)seed_reduction_cubic_mul);
	this->reduction_type_md->Append("s / cubic(s,r)",  (void*)seed_reduction_cubic_div);
	this->reduction_type_md->Append("s + quad(s,r)",  (void*)seed_reduction_quad_add);
	this->reduction_type_md->Append("s - quad(s,r)",  (void*)seed_reduction_quad_sub);
	this->reduction_type_md->Append("s * quad(s,r)",  (void*)seed_reduction_quad_mul);
	this->reduction_type_md->Append("s / quad(s,r)",  (void*)seed_reduction_quad_div);
	this->reduction_type_md->Append("s + harmonic(s,r)",  (void*)seed_reduction_harmonic_add);
	this->reduction_type_md->Append("s - harmonic(s,r)",  (void*)seed_reduction_harmonic_sub);
	this->reduction_type_md->Append("s * harmonic(s,r)",  (void*)seed_reduction_harmonic_mul);
	this->reduction_type_md->Append("s / harmonic(s,r)",  (void*)seed_reduction_harmonic_div);
	
	this->reduction_type_md->SetSelection(0);
	
	this->reduction_type_ds->Append("seed * reduction", (void*)seed_reduction_mul);
	this->reduction_type_ds->Append("seed / reduction", (void*)seed_reduction_div);
	this->reduction_type_ds->Append("seed + reduction", (void*)seed_reduction_add);
	this->reduction_type_ds->Append("seed - reduction", (void*)seed_reduction_sub);
	this->reduction_type_ds->Append("seed * sqrt(reduction)", (void*)seed_reduction_mul_sqrt);
	this->reduction_type_ds->Append("seed / sqrt(reduction)", (void*)seed_reduction_div_sqrt);
	this->reduction_type_ds->Append("seed + sqrt(reduction)", (void*)seed_reduction_add_sqrt);
	this->reduction_type_ds->Append("seed - sqrt(reduction)", (void*)seed_reduction_sub_sqrt);
	this->reduction_type_ds->Append("s * (s**2+r)/(s**2)-r",  (void*)seed_reduction_pow2_p_r_div_pow2_m_r);
	this->reduction_type_ds->Append("s * (s**2-r)/(s**2)+r",  (void*)seed_reduction_pow2_m_r_div_pow2_p_r);
	this->reduction_type_ds->Append("s + arithmetic(s,r)",  (void*)seed_reduction_arithmetic_add);
	this->reduction_type_ds->Append("s - arithmetic(s,r)",  (void*)seed_reduction_arithmetic_sub);
	this->reduction_type_ds->Append("s * arithmetic(s,r)",  (void*)seed_reduction_arithmetic_mul);
	this->reduction_type_ds->Append("s / arithmetic(s,r)",  (void*)seed_reduction_arithmetic_div);
	this->reduction_type_ds->Append("s + hoelder(s,r)",  (void*)seed_reduction_hoelder_add);
	this->reduction_type_ds->Append("s - hoelder(s,r)",  (void*)seed_reduction_hoelder_sub);
	this->reduction_type_ds->Append("s * hoelder(s,r)",  (void*)seed_reduction_hoelder_mul);
	this->reduction_type_ds->Append("s / hoelder(s,r)",  (void*)seed_reduction_hoelder_div);
	this->reduction_type_ds->Append("s + geometric(s,r)",  (void*)seed_reduction_geometric_add);
	this->reduction_type_ds->Append("s - geometric(s,r)",  (void*)seed_reduction_geometric_sub);
	this->reduction_type_ds->Append("s * geometric(s,r)",  (void*)seed_reduction_geometric_mul);
	this->reduction_type_ds->Append("s / geometric(s,r)",  (void*)seed_reduction_geometric_div);
	this->reduction_type_ds->Append("s + cubic(s,r)",  (void*)seed_reduction_cubic_add);
	this->reduction_type_ds->Append("s - cubic(s,r)",  (void*)seed_reduction_cubic_sub);
	this->reduction_type_ds->Append("s * cubic(s,r)",  (void*)seed_reduction_cubic_mul);
	this->reduction_type_ds->Append("s / cubic(s,r)",  (void*)seed_reduction_cubic_div);
	this->reduction_type_ds->Append("s + quad(s,r)",  (void*)seed_reduction_quad_add);
	this->reduction_type_ds->Append("s - quad(s,r)",  (void*)seed_reduction_quad_sub);
	this->reduction_type_ds->Append("s * quad(s,r)",  (void*)seed_reduction_quad_mul);
	this->reduction_type_ds->Append("s / quad(s,r)",  (void*)seed_reduction_quad_div);
	this->reduction_type_ds->Append("s + harmonic(s,r)",  (void*)seed_reduction_harmonic_add);
	this->reduction_type_ds->Append("s - harmonic(s,r)",  (void*)seed_reduction_harmonic_sub);
	this->reduction_type_ds->Append("s * harmonic(s,r)",  (void*)seed_reduction_harmonic_mul);
	this->reduction_type_ds->Append("s / harmonic(s,r)",  (void*)seed_reduction_harmonic_div);
	
	this->reduction_type_ds->SetSelection(0);
	
	this->mb_color_model->Append("normal", 				 (void*)mandelbrot_color_normal_8Bit);
	this->mb_color_model->Append("linear interpolation", (void*)mandelbrot_color_line_int_8Bit);
	
	this->mb_color_model->SetSelection(0);

	this->julia_color_model->Append("normal", 				 (void*)julia_color_normal_8Bit);
	this->julia_color_model->Append("linear interpolation",  (void*)julia_color_line_int_8Bit);
	
	this->julia_color_model->SetSelection(0);
	
	this->julia_poly_func->Append("i**2 + c", 				 		(void*)julia_pfunc_quad_plus_c);
	this->julia_poly_func->Append("i**3 + c", 				 		(void*)julia_pfunc_third_plus_c);
	this->julia_poly_func->Append("i**4 + c", 				 		(void*)julia_pfunc_fourth_plus_c);
	this->julia_poly_func->Append("i**10 + c", 				 		(void*)julia_pfunc_ten_plus_c);
	this->julia_poly_func->Append("(i**2 + c) / (i**2 - c)",		(void*)julia_pfunc_quad_plus_c_2);
	this->julia_poly_func->Append("(sqrt(i) + c)",					(void*)julia_pfunc_sqrt_plus_c);
	this->julia_poly_func->Append("(sqrt(i) - c)",					(void*)julia_pfunc_sqrt_minus_c);
	this->julia_poly_func->Append("(i**2 - c) / (i**2 + c)", 		(void*)julia_pfunc_quad_plus_c_1_2);
	this->julia_poly_func->Append("(i**3 + c) / (i**3 - c)", 		(void*)julia_pfunc_quad_plus_c_3);
	this->julia_poly_func->Append("e**(i**3 - c)", 			 		(void*)julia_pfunc_exp_plus_c);
	this->julia_poly_func->Append("((1-i**3/6) / (i - i**2/2)) + c",(void*)julia_pfunc_3_2_div_pc);
	this->julia_poly_func->Append("i**3 + i**2 + i + c",			(void*)julia_pfunc_pow_3_p_2_p_1_p_c);
	this->julia_poly_func->Append("random", 			 	 		(void*)julia_pfunc_px_random);
	
	this->julia_poly_func->SetSelection(0);
	
	this->julia_constants[0] = 0.7f + 0.fi;	
	this->julia_constants[1] = -0.8f + 0.2fi;	
	this->julia_constants[2] = -1.f + 0.fi;
	this->julia_constants[3] = 0.f + 1.fi;
	this->julia_constants[4] = -.2f + 1.fi;		
	this->julia_constants[5] = 0.f + 1.0fi;
	this->julia_constants[6] = -.2f + .8fi;	
	this->julia_constants[7] = 0.f + .8fi;		
	this->julia_constants[8] = .39f + .6fi;
	this->julia_constants[9] = -0.75f+0.11fi;	
	this->julia_constants[10] = -0.1f+0.651fi;		
	this->julia_constants[11] = -0.74543f+0.11301fi;
	
	this->julia_constant->Append("0.7f + 0.f*I",   		(void*)&this->julia_constants[0]);
	this->julia_constant->Append("-0.8f + 0.2f*I", 		(void*)&this->julia_constants[1]);
	this->julia_constant->Append("-1.f + 0.f*I", 		(void*)&this->julia_constants[2]);
	this->julia_constant->Append("0.f + 1.f*I", 		(void*)&this->julia_constants[3]);
	this->julia_constant->Append("-.2f + 1.f*I", 		(void*)&this->julia_constants[4]);
	this->julia_constant->Append("0.f + 1.0f*I", 		(void*)&this->julia_constants[5]);
	this->julia_constant->Append("-.2f + .8f*I", 		(void*)&this->julia_constants[6]);
	this->julia_constant->Append("0.f + .8f*I", 		(void*)&this->julia_constants[7]);
	this->julia_constant->Append(".39f + .6f*I", 		(void*)&this->julia_constants[9]);
	this->julia_constant->Append("-0.75f+0.11f*I", 		(void*)&this->julia_constants[10]);
	this->julia_constant->Append("-0.1f+0.651f*I", 		(void*)&this->julia_constants[11]);
	this->julia_constant->Append("-0.74543f+0.11301f*I",(void*)&this->julia_constants[12]);
	
	this->julia_constant->SetSelection(0);
	
	this->selected_filter->Append("Arithmetic", (void*)filter_middle_arith);
	this->selected_filter->Append("Median(Box)", (void*)filter_middle_median_box);
	this->selected_filter->Append("Median(Cross)", (void*)filter_middle_median_cross);
	this->selected_filter->Append("Median(DiagCross)", (void*)filter_middle_median_diag_cross);
	this->selected_filter->Append("Cubic(Box)", (void*)filter_middle_cubic_box);
	this->selected_filter->Append("Gaussian", (void*)filter_gaussian);
	this->selected_filter->Append("invert", (void*)filter_invert);
	
	this->selected_filter->SetSelection(0);
	
}

RenderbugPanelImpl::~RenderbugPanelImpl()
{
	if (this->texture!=NULL) {
		texture_free(this->texture);
	}
}

double RenderbugPanelImpl::txtctrl_to_double_errormsg(wxTextCtrl* control, double default_value, bool shomsg, 
													  const wxString &message, const wxString &caption) {
	double result;
	if(!control->GetValue().ToDouble(&result)) {
		if (shomsg) {
			wxMessageDialog(this, message, caption).ShowModal(); 
		}
		result = default_value;
	}
	return result;
}

void RenderbugPanelImpl::generateNoise( wxCommandEvent& event ) {
	((this)->*(this->cur_algo_func))(); //easier way => #include <functional>  ... std::invoke(this->cur_algo_func, this);
	std::cout << "generate some noise" << std::endl;
}

void RenderbugPanelImpl::on_algorithm_changed( wxChoicebookEvent& event ) {
	this->cur_algorithm = event.GetSelection();	
	
	switch(this->cur_algorithm) {
		case 0:	this->cur_algo_func = &this->process_ds; break;
		case 1:	this->cur_algo_func = &this->process_md; break;
		case 2:	this->cur_algo_func = &this->process_mandelbrot;break;
		case 3:	this->cur_algo_func = &this->process_julia; break;
		case 4: this->cur_algo_func = &this->process_evolution; break;
		default:
			this->cur_algo_func = &this->process_ds;
	}
	
	std::cout << "algorithm changed to: " << this->cur_algorithm << std::endl;
}
void RenderbugPanelImpl::on_filter_changed( wxChoicebookEvent& event ) {
	this->cur_filter = event.GetSelection();	
	
	switch(this->cur_filter) {
		case 0:	this->cur_filtertype_func = &this->process_filter_standard; break;
		case 1:	this->cur_filtertype_func = &this->process_filter_advanced; break;
		default:
			this->cur_filtertype_func = &this->process_filter_standard;
	}
	
	std::cout << "filter changed to: " << this->cur_filter << std::endl;
}

void RenderbugPanelImpl::on_manipulation_changed( wxChoicebookEvent& event ) {
	this->cur_manipulation = event.GetSelection();	
	std::cout << "manipulation changed to: " << this->cur_manipulation << std::endl;
	
	switch(this->cur_manipulation) {
		case 0:	this->cur_manipulator_func = &this->process_brigthness_contrast; break;
		default:
			this->cur_manipulator_func = &this->process_brigthness_contrast;
	}
	
}

void RenderbugPanelImpl::refresh_texture(texture_t *texture, int width, int height, bool setAsNew) {
	if (setAsNew) {
		canvas->setTexture(texture_copy(texture));
		canvas->SetSize(wxSize(width,height));
	}
	canvas->Refresh();
}

texture_t * RenderbugPanelImpl::create_new_texture(int width, int height) {
	if (this->texture!=NULL) {
		texture_free(this->texture);
	}
	this->texture = texture_new(width, height);
	return this->texture;
}

void RenderbugPanelImpl::process_ds() {
	std::cout << "process DS" << std::endl;
	
	int w = 513;
	int h = w;
	
	texture_t * texture = this->create_new_texture(w,h);
	noise_t * noise = noise_new(w, h);
	
	diamond_square_t ds_param;
	ds_param.noise = noise;
	ds_param.length = w-1;
	
	ds_param.startseed = txtctrl_to_double_errormsg(this->start_seed_ds, 1.0, true, "Invalid will set to value: 1.0", "Error start seed");
	ds_param.seed = txtctrl_to_double_errormsg(this->seed_ds, 1.0, true, "Invalid will set to value: 1.0", "Error seed");
	ds_param.reduction = txtctrl_to_double_errormsg(this->reduction_ds, 0.5, true, "Invalid, will set to value: 0.5", "Error reduction");
	ds_param.middlefunc = (Average4Func)this->average_ds->GetClientData(this->average_ds->GetCurrentSelection());//middle_arithmetic;
	ds_param.seedreducefunc = (SeedReductionFunc)this->reduction_type_ds->GetClientData(this->reduction_type_ds->GetCurrentSelection());//seed_reduction_mul;
	create_diamond_square(&ds_param);
	
	filter_noise_gauss(noise, 100.f);
	
	noise_to_texture( noise, texture);
	
	this->refresh_texture(texture, w, h);
	
	noise_free(noise);
}
void RenderbugPanelImpl::process_md() {
	std::cout << "process MD" << std::endl;
	int w = 513;
	int h = w;
	
	texture_t * texture = this->create_new_texture(w,h);
	noise_t * noise = noise_new(w, h);
	
	midpoint_displacement_t md_param;
	md_param.noise = noise;
	md_param.length = w-1;
	
	md_param.startseed  = txtctrl_to_double_errormsg(this->start_seed_md, 1.0, true, "Invalid will set to value: 1.0", "Error start seed");
	md_param.seed  = txtctrl_to_double_errormsg(this->seed_md, 1.0, true, "Invalid will set to value: 1.0", "Error seed");
	md_param.reduction  = txtctrl_to_double_errormsg(this->reduction_md, 0.5, true, "Invalid will set to value: 0.5", "Error reduction");
	md_param.middlefunc = (Average4Func)this->average_md->GetClientData(this->average_md->GetCurrentSelection());//middle_arithmetic;
	md_param.middlefunc2 = (Average2Func)this->average2_md->GetClientData(this->average2_md->GetCurrentSelection());//middle_arithmetic2;
	md_param.seedreducefunc = (SeedReductionFunc)this->reduction_type_md->GetClientData(this->reduction_type_md->GetCurrentSelection());//seed_reduction_mul;;
	create_midpoint_displacement(&md_param);
	
	filter_noise_circle(noise, 0.9f);
	
	noise_to_texture( noise, texture);
	
	this->refresh_texture(texture, w, h);
	
	noise_free(noise);
}

void RenderbugPanelImpl::process_evolution() {
	std::cout << "process evolution" << std::endl;
	int w = 513;
	int h = w;
	
	texture_t * texture = this->create_new_texture(w,h);
	noise_t * noise = noise_new(w, h);
	
	evolution_t ev_param;
	ev_param.noise = noise;
	ev_param.min_value=-1.f;
	ev_param.max_value=2.f;
	ev_param.cnt_items=0;
	ev_param.max_evolution=30;

	create_evolution(&ev_param);
	
	noise_to_texture( noise, texture);
	
	this->refresh_texture(texture, w, h);
	
	noise_free(noise);
	
}

void RenderbugPanelImpl::process_mandelbrot() {
	std::cout << "process Mandelbrot" << std::endl;
	
	int w = 512;
	int h = w;
	
	mandelbrot_t *mb = mandelbrot_new(w, h);
	texture_t * texture = this->create_new_texture(w,h);
	
	mb->minreal  = txtctrl_to_double_errormsg(this->mb_min_real, -2.0, true, "Invalid will set to value: -2.0", "Error min real");
	mb->maxreal  = txtctrl_to_double_errormsg(this->mb_max_real, 0.5, true, "Invalid will set to value: 0.5", "Error max real");
	mb->minimag  = txtctrl_to_double_errormsg(this->mb_min_imag, -1.0, true, "Invalid will set to value: -1.0", "Error min imag");
	mb->maximag  = txtctrl_to_double_errormsg(this->mb_max_imag, 1.0, true, "Invalid will set to value: 1.0", "Error max imag");
	mb->cntiterations = this->mb_iterations->GetValue();
	
	create_mandelbrot(mb);
	
	mandelbrot_to_texture(mb, texture, (mb_color_func)this->mb_color_model->GetClientData(this->mb_color_model->GetCurrentSelection()));

	this->refresh_texture(texture, w, h);
	
	mandelbrot_free(mb);
}
void RenderbugPanelImpl::process_julia() {
	std::cout << "process Julia" << std::endl;
	int w = 512;
	int h = w;
	
	texture_t * texture = this->create_new_texture(w,h);
	
	julia_t *julia = julia_new(w, h);
	
	julia->minreal  = txtctrl_to_double_errormsg(this->julia_min_real, -2.1, true, "Invalid will set to value: -2.1", "Error min real");
	julia->maxreal  = txtctrl_to_double_errormsg(this->julia_max_real, 2.1, true, "Invalid will set to value: 2.1", "Error max real");	
	julia->minimag  = txtctrl_to_double_errormsg(this->julia_min_imag, -2.1, true, "Invalid will set to value: -2.1", "Error min imag");
	julia->maximag  = txtctrl_to_double_errormsg(this->julia_max_imag, 2.1, true, "Invalid will set to value: 2.1", "Error max imag");	
	julia->cntiterations = this->julia_iterations->GetValue();
	
	julia->polyfunc = (juliapolyfunc)this->julia_poly_func->GetClientData(this->julia_poly_func->GetCurrentSelection());
	
	if(this->julia_use_input->IsChecked()) {
		double wxValue =  txtctrl_to_double_errormsg(this->julia_const_real, 1.0, true, "Invalid will set to value: 1.0", "Error const real");
		double wxValue2 = txtctrl_to_double_errormsg(this->julia_const_imag, 1.0, true, "Invalid will set to value: 1.0", "Error const imag"); 

		julia->c = wxValue + (wxValue2 * 1.0fi);
	} else {
		julia->c = *((float _Complex*)this->julia_constant->GetClientData(this->julia_constant->GetCurrentSelection()));
	}

	create_julia(julia);

	julia_to_texture(julia, texture, (jul_color_func)this->julia_color_model->GetClientData(this->julia_color_model->GetCurrentSelection()));
	
	this->refresh_texture(texture, w, h);
	
	julia_free(julia);
}

void RenderbugPanelImpl::on_filter_set( wxCommandEvent& event ) {
	if ( this->texture != NULL ) {
		((this)->*(this->cur_filtertype_func))(TriggerType::SET);
	} else {
		wxMessageDialog(this, "No texture available for filter", "Filter error").ShowModal();
	}
}
void RenderbugPanelImpl::on_filter_add( wxCommandEvent& event ) {
	if ( this->texture != NULL ) {
		((this)->*(this->cur_filtertype_func))(TriggerType::ADD);
	} else {
		wxMessageDialog(this, "No texture available for filter", "Filter error").ShowModal();
	}
}

void RenderbugPanelImpl::process_filter_standard(TriggerType filter_trigger_type) {
	std::cout << "filter standard: " <<  filter_trigger_type << std::endl;
	
	filter_func filter = (filter_func)this->selected_filter->GetClientData(this->selected_filter->GetCurrentSelection());
	
	texture_t * used_texture = NULL;
	
	switch(filter_trigger_type) {
		case SET: used_texture = texture_copy(this->texture);break;
		case ADD:
		default:
			used_texture = this->canvas->getTexture();
	}
	
	double pxrange = this->kernel_size->GetValue();
	double factor = this->pixel_factor->GetValue() / 100.0;
	
	filter(used_texture, pxrange, factor);
	
	bool newTexture = (filter_trigger_type == TriggerType::SET);
	this->refresh_texture(used_texture, texture->width, texture->height, newTexture);
}

void RenderbugPanelImpl::process_filter_advanced(TriggerType filter_trigger_type) {
	std::cout << "filter advanced: " << filter_trigger_type << std::endl;
}


void RenderbugPanelImpl::on_manipulator_set( wxCommandEvent& event ) {
	if ( this->texture != NULL ) {
		((this)->*(this->cur_manipulator_func))(TriggerType::SET);
	} else {
		wxMessageDialog(this, "No texture available for filter", "Manipulator error").ShowModal();
	}
}
void RenderbugPanelImpl::on_manipulator_add( wxCommandEvent& event ) {
	if ( this->texture != NULL ) {
		((this)->*(this->cur_manipulator_func))(TriggerType::ADD);
	} else {
		wxMessageDialog(this, "No texture available for filter", "Manipulator error").ShowModal();
	}
}

void RenderbugPanelImpl::process_brigthness_contrast(TriggerType filter_trigger_type) {
	std::cout << "Brightness and contrast: " << filter_trigger_type << std::endl;
	
	texture_t * used_texture = NULL;
	
	switch(filter_trigger_type) {
		case SET: used_texture = texture_copy(this->texture);break;
		case ADD:
		default:
			used_texture = this->canvas->getTexture();
	}
	
	double contrast = this->contrast->GetValue();
	double brightness = this->brightness->GetValue();
	
	array_iterator_t * it = array_iterator_new(used_texture->buffer);
	cRGB_t * curcolor;
	cRGB_t temp;
	
	float contrast_factor = crgb_contrast_factor_255(contrast);

	while(array_iterator_has_next(it))
	{
		curcolor = (cRGB_t *)array_iterator_next(it);
		crgb_brightness_255_dest(&temp, curcolor, brightness);
		crgb_contrast_255_dest(curcolor, &temp, contrast_factor);
	}
	array_iterator_free(it);
	
	bool newTexture = (filter_trigger_type == TriggerType::SET);
	this->refresh_texture(used_texture, texture->width, texture->height, newTexture);
	
}

