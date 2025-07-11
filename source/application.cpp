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

    g_settings.load();  // FIXED: Method name corrected

    // Setup main GUI frame
    GUI::GetInstance()->LoadMainWindow();

    // Show welcome dialog with icon (required by header)
    wxBitmap icon(wxArtProvider::GetBitmap(wxART_INFORMATION, wxART_OTHER, wxSize(32, 32)));
    g_gui.ShowWelcomeDialog(icon);  // FIXED: Pass required wxBitmap argument

    return true;
}

void Application::OnEventLoopEnter(wxEventLoopBase* loop) {
    wxApp::OnEventLoopEnter(loop);
}

void Application::MacOpenFiles(const wxArrayString& fileNames) {
    // Mac-specific file open logic here if needed
}

int Application::OnExit() {
    g_settings.save();  // FIXED: Method name corrected
    return wxApp::OnExit();
}

void Application::Unload() {
    g_gui.GetMainFrame()->Close();  // FIXED: GUI::Close() doesn't exist — use wxFrame::Close()
}

void Application::FixVersionDiscrapencies() {
    // Optional: fix logic
}

bool Application::ParseCommandLineMap(wxString& fileName) {
    // Optional: parse map logic
    return false;
}

void Application::OnFatalException() {
    wxMessageBox(wxT("A fatal error has occurred. RME will now close."), wxT("Fatal Error"), wxICON_ERROR);
}
