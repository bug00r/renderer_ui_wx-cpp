///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 27 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "RenderbugPanel.h"

///////////////////////////////////////////////////////////////////////////

RenderbugPanel::RenderbugPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	m_listbook1 = new wxListbook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLB_DEFAULT );
	m_panel4 = new wxPanel( m_listbook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxVERTICAL );
	
	algorithm = new wxChoicebook( m_panel4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxCHB_DEFAULT );
	average_panel = new wxPanel( algorithm, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer1121;
	bSizer1121 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText122 = new wxStaticText( average_panel, wxID_ANY, wxT("Average"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText122->Wrap( -1 );
	bSizer1121->Add( m_staticText122, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	average_ds = new wxComboBox( average_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer1121->Add( average_ds, 1, wxALIGN_CENTER, 5 );
	
	
	bSizer27->Add( bSizer1121, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer172;
	bSizer172 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText52 = new wxStaticText( average_panel, wxID_ANY, wxT("Start-Seed:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText52->Wrap( -1 );
	bSizer172->Add( m_staticText52, 1, wxALIGN_CENTER, 5 );
	
	start_seed_ds = new wxTextCtrl( average_panel, wxID_ANY, wxT("1.0"), wxDefaultPosition, wxDefaultSize, 0 );
	#ifdef __WXGTK__
	if ( !start_seed_ds->HasFlag( wxTE_MULTILINE ) )
	{
	start_seed_ds->SetMaxLength( 10 );
	}
	#else
	start_seed_ds->SetMaxLength( 10 );
	#endif
	bSizer172->Add( start_seed_ds, 1, wxALIGN_CENTER, 5 );
	
	
	bSizer27->Add( bSizer172, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer1712;
	bSizer1712 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText512 = new wxStaticText( average_panel, wxID_ANY, wxT("Seed:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText512->Wrap( -1 );
	bSizer1712->Add( m_staticText512, 1, wxALIGN_CENTER, 5 );
	
	seed_ds = new wxTextCtrl( average_panel, wxID_ANY, wxT("1.0"), wxDefaultPosition, wxDefaultSize, 0 );
	#ifdef __WXGTK__
	if ( !seed_ds->HasFlag( wxTE_MULTILINE ) )
	{
	seed_ds->SetMaxLength( 10 );
	}
	#else
	seed_ds->SetMaxLength( 10 );
	#endif
	bSizer1712->Add( seed_ds, 1, wxALIGN_CENTER, 5 );
	
	
	bSizer27->Add( bSizer1712, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer17111;
	bSizer17111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText5111 = new wxStaticText( average_panel, wxID_ANY, wxT("Reduction:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5111->Wrap( -1 );
	bSizer17111->Add( m_staticText5111, 1, wxALIGN_CENTER, 5 );
	
	reduction_ds = new wxTextCtrl( average_panel, wxID_ANY, wxT("0.5"), wxDefaultPosition, wxDefaultSize, 0 );
	#ifdef __WXGTK__
	if ( !reduction_ds->HasFlag( wxTE_MULTILINE ) )
	{
	reduction_ds->SetMaxLength( 10 );
	}
	#else
	reduction_ds->SetMaxLength( 10 );
	#endif
	bSizer17111->Add( reduction_ds, 1, wxALIGN_CENTER, 5 );
	
	
	bSizer27->Add( bSizer17111, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer93;
	bSizer93 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText71 = new wxStaticText( average_panel, wxID_ANY, wxT("Reduction Type:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText71->Wrap( -1 );
	bSizer93->Add( m_staticText71, 1, wxALIGN_CENTER, 5 );
	
	reduction_type_ds = new wxComboBox( average_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer93->Add( reduction_type_ds, 1, wxALIGN_CENTER, 5 );
	
	
	bSizer27->Add( bSizer93, 0, wxALL|wxEXPAND, 5 );
	
	
	average_panel->SetSizer( bSizer27 );
	average_panel->Layout();
	bSizer27->Fit( average_panel );
	algorithm->AddPage( average_panel, wxT("Diamond Square"), true );
	m_panel6 = new wxPanel( algorithm, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer271;
	bSizer271 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer11211;
	bSizer11211 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1221 = new wxStaticText( m_panel6, wxID_ANY, wxT("Average-1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1221->Wrap( -1 );
	bSizer11211->Add( m_staticText1221, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	average_md = new wxComboBox( m_panel6, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer11211->Add( average_md, 1, wxALIGN_CENTER, 5 );
	
	
	bSizer271->Add( bSizer11211, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer11221;
	bSizer11221 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1231 = new wxStaticText( m_panel6, wxID_ANY, wxT("Average-2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1231->Wrap( -1 );
	bSizer11221->Add( m_staticText1231, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	average2_md = new wxComboBox( m_panel6, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer11221->Add( average2_md, 1, wxALIGN_CENTER, 5 );
	
	
	bSizer271->Add( bSizer11221, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer1721;
	bSizer1721 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText521 = new wxStaticText( m_panel6, wxID_ANY, wxT("Start-Seed:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText521->Wrap( -1 );
	bSizer1721->Add( m_staticText521, 1, wxALIGN_CENTER, 5 );
	
	start_seed_md = new wxTextCtrl( m_panel6, wxID_ANY, wxT("1.0"), wxDefaultPosition, wxDefaultSize, 0 );
	#ifdef __WXGTK__
	if ( !start_seed_md->HasFlag( wxTE_MULTILINE ) )
	{
	start_seed_md->SetMaxLength( 10 );
	}
	#else
	start_seed_md->SetMaxLength( 10 );
	#endif
	bSizer1721->Add( start_seed_md, 1, wxALIGN_CENTER, 5 );
	
	
	bSizer271->Add( bSizer1721, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer17121;
	bSizer17121 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText5121 = new wxStaticText( m_panel6, wxID_ANY, wxT("Seed:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5121->Wrap( -1 );
	bSizer17121->Add( m_staticText5121, 1, wxALIGN_CENTER, 5 );
	
	seed_md = new wxTextCtrl( m_panel6, wxID_ANY, wxT("1.0"), wxDefaultPosition, wxDefaultSize, 0 );
	#ifdef __WXGTK__
	if ( !seed_md->HasFlag( wxTE_MULTILINE ) )
	{
	seed_md->SetMaxLength( 10 );
	}
	#else
	seed_md->SetMaxLength( 10 );
	#endif
	bSizer17121->Add( seed_md, 1, wxALIGN_CENTER, 5 );
	
	
	bSizer271->Add( bSizer17121, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer171111;
	bSizer171111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText51111 = new wxStaticText( m_panel6, wxID_ANY, wxT("Reduction:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText51111->Wrap( -1 );
	bSizer171111->Add( m_staticText51111, 1, wxALIGN_CENTER, 5 );
	
	reduction_md = new wxTextCtrl( m_panel6, wxID_ANY, wxT("0.5"), wxDefaultPosition, wxDefaultSize, 0 );
	#ifdef __WXGTK__
	if ( !reduction_md->HasFlag( wxTE_MULTILINE ) )
	{
	reduction_md->SetMaxLength( 10 );
	}
	#else
	reduction_md->SetMaxLength( 10 );
	#endif
	bSizer171111->Add( reduction_md, 1, wxALIGN_CENTER, 5 );
	
	
	bSizer271->Add( bSizer171111, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer931;
	bSizer931 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText711 = new wxStaticText( m_panel6, wxID_ANY, wxT("Reduction Type:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText711->Wrap( -1 );
	bSizer931->Add( m_staticText711, 1, wxALIGN_CENTER, 5 );
	
	reduction_type_md = new wxComboBox( m_panel6, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer931->Add( reduction_type_md, 1, wxALIGN_CENTER, 5 );
	
	
	bSizer271->Add( bSizer931, 0, wxEXPAND, 5 );
	
	
	m_panel6->SetSizer( bSizer271 );
	m_panel6->Layout();
	bSizer271->Fit( m_panel6 );
	algorithm->AddPage( m_panel6, wxT("Midpoint Displacement"), false );
	m_panel7 = new wxPanel( algorithm, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer75;
	bSizer75 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer8;
	sbSizer8 = new wxStaticBoxSizer( new wxStaticBox( m_panel7, wxID_ANY, wxT("Complex Boundary") ), wxVERTICAL );
	
	wxBoxSizer* bSizer76;
	bSizer76 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText35 = new wxStaticText( sbSizer8->GetStaticBox(), wxID_ANY, wxT("Min:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText35->Wrap( -1 );
	bSizer76->Add( m_staticText35, 0, wxALIGN_CENTER|wxALL, 5 );
	
	mb_min_real = new wxTextCtrl( sbSizer8->GetStaticBox(), wxID_ANY, wxT("-2.0"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer76->Add( mb_min_real, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_staticText36 = new wxStaticText( sbSizer8->GetStaticBox(), wxID_ANY, wxT("+"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText36->Wrap( -1 );
	bSizer76->Add( m_staticText36, 0, wxALIGN_CENTER|wxALL, 5 );
	
	mb_min_imag = new wxTextCtrl( sbSizer8->GetStaticBox(), wxID_ANY, wxT("-1.0"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer76->Add( mb_min_imag, 0, wxALL, 5 );
	
	m_staticText41 = new wxStaticText( sbSizer8->GetStaticBox(), wxID_ANY, wxT("*I"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText41->Wrap( -1 );
	bSizer76->Add( m_staticText41, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	sbSizer8->Add( bSizer76, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer761;
	bSizer761 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText351 = new wxStaticText( sbSizer8->GetStaticBox(), wxID_ANY, wxT("Max:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText351->Wrap( -1 );
	bSizer761->Add( m_staticText351, 0, wxALIGN_CENTER|wxALL, 5 );
	
	mb_max_real = new wxTextCtrl( sbSizer8->GetStaticBox(), wxID_ANY, wxT("0.5"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer761->Add( mb_max_real, 0, wxALL, 5 );
	
	m_staticText361 = new wxStaticText( sbSizer8->GetStaticBox(), wxID_ANY, wxT("+"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText361->Wrap( -1 );
	bSizer761->Add( m_staticText361, 0, wxALIGN_CENTER|wxALL, 5 );
	
	mb_max_imag = new wxTextCtrl( sbSizer8->GetStaticBox(), wxID_ANY, wxT("1.0"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer761->Add( mb_max_imag, 0, wxALL, 5 );
	
	m_staticText411 = new wxStaticText( sbSizer8->GetStaticBox(), wxID_ANY, wxT("*I"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText411->Wrap( -1 );
	bSizer761->Add( m_staticText411, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	sbSizer8->Add( bSizer761, 0, wxEXPAND, 5 );
	
	
	bSizer75->Add( sbSizer8, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer9;
	sbSizer9 = new wxStaticBoxSizer( new wxStaticBox( m_panel7, wxID_ANY, wxT("Iterations") ), wxVERTICAL );
	
	mb_iterations = new wxSlider( sbSizer9->GetStaticBox(), wxID_ANY, 20, 1, 1000, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS );
	sbSizer9->Add( mb_iterations, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer75->Add( sbSizer9, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer10;
	sbSizer10 = new wxStaticBoxSizer( new wxStaticBox( m_panel7, wxID_ANY, wxT("Coloring Model") ), wxVERTICAL );
	
	mb_color_model = new wxComboBox( sbSizer10->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	sbSizer10->Add( mb_color_model, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer75->Add( sbSizer10, 0, wxEXPAND, 5 );
	
	
	m_panel7->SetSizer( bSizer75 );
	m_panel7->Layout();
	bSizer75->Fit( m_panel7 );
	algorithm->AddPage( m_panel7, wxT("Mandelbrot"), false );
	m_panel8 = new wxPanel( algorithm, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer751;
	bSizer751 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer81;
	sbSizer81 = new wxStaticBoxSizer( new wxStaticBox( m_panel8, wxID_ANY, wxT("Complex Boundary") ), wxVERTICAL );
	
	wxBoxSizer* bSizer762;
	bSizer762 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText352 = new wxStaticText( sbSizer81->GetStaticBox(), wxID_ANY, wxT("Min:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText352->Wrap( -1 );
	bSizer762->Add( m_staticText352, 0, wxALIGN_CENTER|wxALL, 5 );
	
	julia_min_real = new wxTextCtrl( sbSizer81->GetStaticBox(), wxID_ANY, wxT("-2.1"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer762->Add( julia_min_real, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_staticText362 = new wxStaticText( sbSizer81->GetStaticBox(), wxID_ANY, wxT("+"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText362->Wrap( -1 );
	bSizer762->Add( m_staticText362, 0, wxALIGN_CENTER|wxALL, 5 );
	
	julia_min_imag = new wxTextCtrl( sbSizer81->GetStaticBox(), wxID_ANY, wxT("-2.1"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer762->Add( julia_min_imag, 0, wxALL, 5 );
	
	m_staticText412 = new wxStaticText( sbSizer81->GetStaticBox(), wxID_ANY, wxT("*I"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText412->Wrap( -1 );
	bSizer762->Add( m_staticText412, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	sbSizer81->Add( bSizer762, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer7611;
	bSizer7611 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText3511 = new wxStaticText( sbSizer81->GetStaticBox(), wxID_ANY, wxT("Max:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3511->Wrap( -1 );
	bSizer7611->Add( m_staticText3511, 0, wxALIGN_CENTER|wxALL, 5 );
	
	julia_max_real = new wxTextCtrl( sbSizer81->GetStaticBox(), wxID_ANY, wxT("2.1"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7611->Add( julia_max_real, 0, wxALL, 5 );
	
	m_staticText3611 = new wxStaticText( sbSizer81->GetStaticBox(), wxID_ANY, wxT("+"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3611->Wrap( -1 );
	bSizer7611->Add( m_staticText3611, 0, wxALIGN_CENTER|wxALL, 5 );
	
	julia_max_imag = new wxTextCtrl( sbSizer81->GetStaticBox(), wxID_ANY, wxT("2.1"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7611->Add( julia_max_imag, 0, wxALL, 5 );
	
	m_staticText4111 = new wxStaticText( sbSizer81->GetStaticBox(), wxID_ANY, wxT("*I"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4111->Wrap( -1 );
	bSizer7611->Add( m_staticText4111, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	sbSizer81->Add( bSizer7611, 0, wxEXPAND, 5 );
	
	
	bSizer751->Add( sbSizer81, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer91;
	sbSizer91 = new wxStaticBoxSizer( new wxStaticBox( m_panel8, wxID_ANY, wxT("Iterations") ), wxVERTICAL );
	
	julia_iterations = new wxSlider( sbSizer91->GetStaticBox(), wxID_ANY, 200, 1, 1000, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS );
	sbSizer91->Add( julia_iterations, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer751->Add( sbSizer91, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer101;
	sbSizer101 = new wxStaticBoxSizer( new wxStaticBox( m_panel8, wxID_ANY, wxT("Coloring Model") ), wxVERTICAL );
	
	julia_color_model = new wxComboBox( sbSizer101->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	sbSizer101->Add( julia_color_model, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer751->Add( sbSizer101, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer1011;
	sbSizer1011 = new wxStaticBoxSizer( new wxStaticBox( m_panel8, wxID_ANY, wxT("Polynom Function") ), wxVERTICAL );
	
	julia_poly_func = new wxComboBox( sbSizer1011->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	sbSizer1011->Add( julia_poly_func, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer751->Add( sbSizer1011, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer811;
	sbSizer811 = new wxStaticBoxSizer( new wxStaticBox( m_panel8, wxID_ANY, wxT("Complex Target Constant") ), wxVERTICAL );
	
	wxBoxSizer* bSizer76111;
	bSizer76111 = new wxBoxSizer( wxHORIZONTAL );
	
	julia_constant = new wxComboBox( sbSizer811->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer76111->Add( julia_constant, 1, wxALL, 5 );
	
	
	sbSizer811->Add( bSizer76111, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer92;
	bSizer92 = new wxBoxSizer( wxHORIZONTAL );
	
	julia_use_input = new wxCheckBox( sbSizer811->GetStaticBox(), wxID_ANY, wxT("Use manual Input"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer92->Add( julia_use_input, 0, wxALL, 5 );
	
	
	sbSizer811->Add( bSizer92, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer7621;
	bSizer7621 = new wxBoxSizer( wxHORIZONTAL );
	
	julia_const_real = new wxTextCtrl( sbSizer811->GetStaticBox(), wxID_ANY, wxT("0.7"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7621->Add( julia_const_real, 1, wxALIGN_CENTER|wxALL, 5 );
	
	m_staticText3621 = new wxStaticText( sbSizer811->GetStaticBox(), wxID_ANY, wxT("+"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3621->Wrap( -1 );
	bSizer7621->Add( m_staticText3621, 0, wxALIGN_CENTER|wxALL, 5 );
	
	julia_const_imag = new wxTextCtrl( sbSizer811->GetStaticBox(), wxID_ANY, wxT("0.0"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7621->Add( julia_const_imag, 1, wxALL, 5 );
	
	m_staticText4121 = new wxStaticText( sbSizer811->GetStaticBox(), wxID_ANY, wxT("*I"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4121->Wrap( -1 );
	bSizer7621->Add( m_staticText4121, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	sbSizer811->Add( bSizer7621, 0, wxEXPAND, 5 );
	
	
	bSizer751->Add( sbSizer811, 0, wxEXPAND, 5 );
	
	
	m_panel8->SetSizer( bSizer751 );
	m_panel8->Layout();
	bSizer751->Fit( m_panel8 );
	algorithm->AddPage( m_panel8, wxT("Julia"), false );
	m_panel24 = new wxPanel( algorithm, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	algorithm->AddPage( m_panel24, wxT("Evolution"), false );
	bSizer23->Add( algorithm, 1, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer69;
	bSizer69 = new wxBoxSizer( wxHORIZONTAL );
	
	generate_algorithm = new wxButton( m_panel4, wxID_ANY, wxT("generate"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer69->Add( generate_algorithm, 1, wxALL, 5 );
	
	
	bSizer23->Add( bSizer69, 0, wxEXPAND, 5 );
	
	
	m_panel4->SetSizer( bSizer23 );
	m_panel4->Layout();
	bSizer23->Fit( m_panel4 );
	m_listbook1->AddPage( m_panel4, wxT("Algorithm"), true );
	m_panel9 = new wxPanel( m_listbook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxVERTICAL );
	
	filter = new wxChoicebook( m_panel9, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxCHB_DEFAULT );
	m_panel10 = new wxPanel( filter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer7;
	sbSizer7 = new wxStaticBoxSizer( new wxStaticBox( m_panel10, wxID_ANY, wxT("Select Filter") ), wxVERTICAL );
	
	selected_filter = new wxComboBox( sbSizer7->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	selected_filter->SetSelection( 0 );
	sbSizer7->Add( selected_filter, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer25->Add( sbSizer7, 0, wxEXPAND, 5 );
	
	wxString kernel_typeChoices[] = { wxT("Box"), wxT("Cross"), wxT("Cross(Diagonal)") };
	int kernel_typeNChoices = sizeof( kernel_typeChoices ) / sizeof( wxString );
	kernel_type = new wxRadioBox( m_panel10, wxID_ANY, wxT("Kernel Type"), wxDefaultPosition, wxDefaultSize, kernel_typeNChoices, kernel_typeChoices, 1, wxRA_SPECIFY_COLS );
	kernel_type->SetSelection( 0 );
	kernel_type->Enable( false );
	
	bSizer25->Add( kernel_type, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( m_panel10, wxID_ANY, wxT("Kernel Size (Pixel)") ), wxVERTICAL );
	
	kernel_size = new wxSpinCtrl( sbSizer5->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 10, 2 );
	sbSizer5->Add( kernel_size, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer25->Add( sbSizer5, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer6;
	sbSizer6 = new wxStaticBoxSizer( new wxStaticBox( m_panel10, wxID_ANY, wxT("Pixelfactor(%)") ), wxHORIZONTAL );
	
	pixel_factor = new wxSlider( sbSizer6->GetStaticBox(), wxID_ANY, 100, 1, 500, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS );
	sbSizer6->Add( pixel_factor, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer25->Add( sbSizer6, 0, wxEXPAND, 5 );
	
	
	m_panel10->SetSizer( bSizer25 );
	m_panel10->Layout();
	bSizer25->Fit( m_panel10 );
	filter->AddPage( m_panel10, wxT("Standard"), true );
	m_panel16 = new wxPanel( filter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	filter->AddPage( m_panel16, wxT("Advanced"), false );
	bSizer24->Add( filter, 1, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer68;
	bSizer68 = new wxBoxSizer( wxHORIZONTAL );
	
	filter_set = new wxButton( m_panel9, wxID_ANY, wxT("set"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer68->Add( filter_set, 0, wxALL, 5 );
	
	filter_add = new wxButton( m_panel9, wxID_ANY, wxT("add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer68->Add( filter_add, 0, wxALL, 5 );
	
	
	bSizer24->Add( bSizer68, 0, wxEXPAND, 5 );
	
	
	m_panel9->SetSizer( bSizer24 );
	m_panel9->Layout();
	bSizer24->Fit( m_panel9 );
	m_listbook1->AddPage( m_panel9, wxT("Filter"), false );
	m_panel18 = new wxPanel( m_listbook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer60;
	bSizer60 = new wxBoxSizer( wxVERTICAL );
	
	manipulation = new wxChoicebook( m_panel18, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxCHB_DEFAULT );
	m_panel19 = new wxPanel( manipulation, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer63;
	bSizer63 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText69 = new wxStaticText( m_panel19, wxID_ANY, wxT("Brightness:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText69->Wrap( -1 );
	bSizer63->Add( m_staticText69, 0, wxALL, 5 );
	
	brightness = new wxSlider( m_panel19, wxID_ANY, 0, -100, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS );
	bSizer63->Add( brightness, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText70 = new wxStaticText( m_panel19, wxID_ANY, wxT("Contrast:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText70->Wrap( -1 );
	bSizer63->Add( m_staticText70, 0, wxALL, 5 );
	
	contrast = new wxSlider( m_panel19, wxID_ANY, 0, -100, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS );
	bSizer63->Add( contrast, 1, wxALL|wxEXPAND, 5 );
	
	
	m_panel19->SetSizer( bSizer63 );
	m_panel19->Layout();
	bSizer63->Fit( m_panel19 );
	manipulation->AddPage( m_panel19, wxT("Brightness/Contrast"), false );
	bSizer60->Add( manipulation, 1, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer62;
	bSizer62 = new wxBoxSizer( wxHORIZONTAL );
	
	manipulator_set = new wxButton( m_panel18, wxID_ANY, wxT("set"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer62->Add( manipulator_set, 0, wxALIGN_LEFT|wxALL, 5 );
	
	manipulator_add = new wxButton( m_panel18, wxID_ANY, wxT("add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer62->Add( manipulator_add, 0, wxALIGN_LEFT|wxALL, 5 );
	
	
	bSizer60->Add( bSizer62, 0, wxEXPAND, 5 );
	
	
	m_panel18->SetSizer( bSizer60 );
	m_panel18->Layout();
	bSizer60->Fit( m_panel18 );
	m_listbook1->AddPage( m_panel18, wxT("Manipulation"), false );
	#ifdef __WXGTK__ // Small icon style not supported in GTK
	wxListView* m_listbook1ListView = m_listbook1->GetListView();
	long m_listbook1Flags = m_listbook1ListView->GetWindowStyleFlag();
	if( m_listbook1Flags & wxLC_SMALL_ICON )
	{
		m_listbook1Flags = ( m_listbook1Flags & ~wxLC_SMALL_ICON ) | wxLC_ICON;
	}
	m_listbook1ListView->SetWindowStyleFlag( m_listbook1Flags );
	#endif
	
	bSizer6->Add( m_listbook1, 1, wxEXPAND | wxALL, 5 );
	
	
	bSizer1->Add( bSizer6, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer181;
	bSizer181 = new wxBoxSizer( wxVERTICAL );
	
	noise_image_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* noise_image_container;
	noise_image_container = new wxBoxSizer( wxVERTICAL );
	
	
	noise_image_panel->SetSizer( noise_image_container );
	noise_image_panel->Layout();
	noise_image_container->Fit( noise_image_panel );
	bSizer181->Add( noise_image_panel, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer1->Add( bSizer181, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	// Connect Events
	algorithm->Connect( wxEVT_COMMAND_CHOICEBOOK_PAGE_CHANGED, wxChoicebookEventHandler( RenderbugPanel::on_algorithm_changed ), NULL, this );
	generate_algorithm->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RenderbugPanel::generateNoise ), NULL, this );
	filter->Connect( wxEVT_COMMAND_CHOICEBOOK_PAGE_CHANGED, wxChoicebookEventHandler( RenderbugPanel::on_filter_changed ), NULL, this );
	filter_set->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RenderbugPanel::on_filter_set ), NULL, this );
	filter_add->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RenderbugPanel::on_filter_add ), NULL, this );
	manipulation->Connect( wxEVT_COMMAND_CHOICEBOOK_PAGE_CHANGED, wxChoicebookEventHandler( RenderbugPanel::on_manipulation_changed ), NULL, this );
	manipulator_set->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RenderbugPanel::on_manipulator_set ), NULL, this );
	manipulator_add->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RenderbugPanel::on_manipulator_add ), NULL, this );
}

RenderbugPanel::~RenderbugPanel()
{
	// Disconnect Events
	algorithm->Disconnect( wxEVT_COMMAND_CHOICEBOOK_PAGE_CHANGED, wxChoicebookEventHandler( RenderbugPanel::on_algorithm_changed ), NULL, this );
	generate_algorithm->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RenderbugPanel::generateNoise ), NULL, this );
	filter->Disconnect( wxEVT_COMMAND_CHOICEBOOK_PAGE_CHANGED, wxChoicebookEventHandler( RenderbugPanel::on_filter_changed ), NULL, this );
	filter_set->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RenderbugPanel::on_filter_set ), NULL, this );
	filter_add->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RenderbugPanel::on_filter_add ), NULL, this );
	manipulation->Disconnect( wxEVT_COMMAND_CHOICEBOOK_PAGE_CHANGED, wxChoicebookEventHandler( RenderbugPanel::on_manipulation_changed ), NULL, this );
	manipulator_set->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RenderbugPanel::on_manipulator_set ), NULL, this );
	manipulator_add->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RenderbugPanel::on_manipulator_add ), NULL, this );
	
}
