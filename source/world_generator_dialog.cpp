#include "world_generator_dialog.h"

WorldGeneratorDialog::WorldGeneratorDialog(wxWindow* parent)
	: wxDialog(parent, wxID_ANY, "World Generator", wxDefaultPosition, wxSize(250, 150))
{
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

	mainSizer->Add(new wxStaticText(this, wxID_ANY, "Map Width:"), 0, wxALL, 5);
	widthCtrl = new wxTextCtrl(this, wxID_ANY, "100");
	mainSizer->Add(widthCtrl, 0, wxEXPAND | wxALL, 5);

	mainSizer->Add(new wxStaticText(this, wxID_ANY, "Map Height:"), 0, wxALL, 5);
	heightCtrl = new wxTextCtrl(this, wxID_ANY, "100");
	mainSizer->Add(heightCtrl, 0, wxEXPAND | wxALL, 5);

	mainSizer->Add(CreateButtonSizer(wxOK | wxCANCEL), 0, wxALIGN_CENTER | wxALL, 10);

	SetSizer(mainSizer);
	mainSizer->Fit(this);
}

int WorldGeneratorDialog::GetMapWidth() const {
	long val = 100;
	widthCtrl->GetValue().ToLong(&val);
	return static_cast<int>(val);
}

int WorldGeneratorDialog::GetMapHeight() const {
	long val = 100;
	heightCtrl->GetValue().ToLong(&val);
	return static_cast<int>(val);
}