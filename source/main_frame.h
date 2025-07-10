#pragma once

#include <wx/frame.h>
#include "world_generator_dialog.h"
#include "world_generator.h"

#define TOOLBAR_WORLDGENERATOR 6001

class MainFrame : public wxFrame {
public:
	MainFrame();
	~MainFrame();

private:
	void OnWorldGenerator(wxCommandEvent& event);

	DECLARE_EVENT_TABLE()
};
