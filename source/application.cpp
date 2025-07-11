#include "application.h"

#include "main_frame.h"
#include "gui.h"
#include "editor.h"
#include "materials.h"
#include "graphics.h"

IMPLEMENT_APP(Application)

Application::~Application() {}

bool Application::OnInit() {
    wxInitAllImageHandlers();

    g_settings.load();

    g_gui.LoadMainWindow();

    wxBitmap icon(wxArtProvider::GetBitmap(wxART_INFORMATION, wxART_OTHER, wxSize(32, 32)));
    g_gui.ShowWelcomeDialog(icon);

    return true;
}

void Application::OnEventLoopEnter(wxEventLoopBase* loop) {
    wxApp::OnEventLoopEnter(loop);
}

void Application::MacOpenFiles(const wxArrayString& fileNames) {
    // Mac-specific file open logic if needed
}

int Application::OnExit() {
    g_settings.save();
    return wxApp::OnExit();
}

void Application::Unload() {
    if (g_gui.main_frame) {
        g_gui.main_frame->Close();
    }
}

void Application::FixVersionDiscrapencies() {
    // Fix logic here
}

bool Application::ParseCommandLineMap(wxString& fileName) {
    return false;
}

void Application::OnFatalException() {
    wxMessageBox(wxT("A fatal error has occurred. RME will now close."), wxT("Fatal Error"), wxICON_ERROR);
}
