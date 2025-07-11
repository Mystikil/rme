#include "main_frame.h"  // ✅ Ensures full definition of MainFrame
#include "application.h"
#include "main_toolbar.h"
#include "gui.h"
#include "settings.h"

IMPLEMENT_APP(Application)

Application::~Application() {}

bool Application::OnInit() {
    m_startup = true;
    m_file_to_open.clear();

#ifdef _USE_PROCESS_COM
    m_proc_server = nullptr;
    m_single_instance_checker = nullptr;
#endif

    SetAppName("rme");
    SetVendorName("Remere");

    wxInitAllImageHandlers();
    g_settings.Load();

    if (!m_file_to_open.empty()) {
        g_gui.LoadMap(FileName(m_file_to_open));
    } else {
        g_gui.ShowWelcomeDialog();
    }

    m_startup = false;
    return true;
}

void Application::OnEventLoopEnter(wxEventLoopBase* loop) {
    wxApp::OnEventLoopEnter(loop);
}

void Application::MacOpenFiles(const wxArrayString& fileNames) {
    if (!fileNames.IsEmpty()) {
        m_file_to_open = fileNames[0];
    }
}

int Application::OnExit() {
    g_settings.Save();
    return wxApp::OnExit();
}

void Application::Unload() {
    g_gui.Close();
}

void Application::FixVersionDiscrapencies() {
    // Stub for future compatibility handling
}

bool Application::ParseCommandLineMap(wxString& fileName) {
    return false;
}

void Application::OnFatalException() {
    wxMessageBox("Fatal error occurred.", "Error", wxOK | wxICON_ERROR);
}
