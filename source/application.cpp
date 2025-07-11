#include "application.h"

#include "main_frame.h"
#include "gui.h"
#include "editor.h"
#include "materials.h"
#include "graphics.h"
#include "settings.h"
#include "version.h"

IMPLEMENT_APP(Application)

Application::~Application() {}

bool Application::OnInit() {
	wxInitAllImageHandlers();

	g_settings.load();

	// Launch Main Window
	MainFrame* frame = newd MainFrame(wxT("Remere's Map Editor"),
		wxPoint(0, 0), wxSize(800, 600));

	SetTopWindow(frame);
	frame->Show(true);

	// Load Resources
	Editor::getInstance()->loadMap(nullptr);
	return true;
}

void Application::OnEventLoopEnter(wxEventLoopBase* loop) {
	wxApp::OnEventLoopEnter(loop);
}

int Application::OnExit() {
	g_settings.save();
	return wxApp::OnExit();
}

void Application::Unload() {
	if (GetTopWindow()) {
		GetTopWindow()->Close();
	}
}

void Application::FixVersionDiscrapencies() {
	// Any migration code if needed
}

bool Application::ParseCommandLineMap(wxString& fileName) {
	return false; // Not yet implemented
}

void Application::OnFatalException() {
	wxMessageBox(wxT("A fatal error has occurred. RME will now close."), wxT("Fatal Error"), wxICON_ERROR);
}
