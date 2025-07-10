
#include "main_frame.h"
#include <wx/toolbar.h>
#include <wx/artprov.h>
#include "map.h"
#include "editor.h" // ✅ Include the global editor

Editor editor;

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_TOOL(TOOLBAR_WORLDGENERATOR, MainFrame::OnWorldGenerator)
END_EVENT_TABLE()

MainFrame::MainFrame()
	: wxFrame(nullptr, wxID_ANY, "Remere's Map Editor - Enhanced")
{
	wxToolBar* toolBar = CreateToolBar();
	wxBitmap icon = wxArtProvider::GetBitmap(wxART_NEW, wxART_TOOLBAR, wxSize(16,16));
	toolBar->AddTool(TOOLBAR_WORLDGENERATOR, "WorldGen", icon, "Generate a new map");
	toolBar->Realize();
}

MainFrame::~MainFrame() {}

void MainFrame::OnWorldGenerator(wxCommandEvent& event) {
	WorldGeneratorDialog dialog(this);
	if (dialog.ShowModal() == wxID_OK) {
		int width = dialog.GetMapWidth();
		int height = dialog.GetMapHeight();
		WorldGenerator generator;

		Map* map = editor.getCurrentMap(); // ✅ Correct way to get the current map
		if (map) {
			generator.Generate(map, width, height);
			Refresh(); // Redraw canvas
		}
	}
}
