//////////////////////////////////////////////////////////////////////
// This file is part of Remere's Map Editor
//////////////////////////////////////////////////////////////////////
// Remere's Map Editor is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Remere's Map Editor is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.
//////////////////////////////////////////////////////////////////////

#ifndef RME_APPLICATION_H_
#define RME_APPLICATION_H_

#include "gui.h"
#include "main_toolbar.h"
#include "action.h"
#include "settings.h"

#include "process_com.h"
#include "map_display.h"
#include "welcome_dialog.h"

class Item;
class Creature;

class MainFrame; // ✅ Forward declaration only
class MapWindow;
class wxEventLoopBase;
class wxSingleInstanceChecker;

class Application : public wxApp
{
public:
	~Application();
	virtual bool OnInit();
    virtual void OnEventLoopEnter(wxEventLoopBase* loop);
	virtual void MacOpenFiles(const wxArrayString& fileNames);
	virtual int OnExit();
	void Unload();

private:
    bool m_startup;
    wxString m_file_to_open;
	void FixVersionDiscrapencies();
	bool ParseCommandLineMap(wxString& fileName);

	virtual void OnFatalException();

#ifdef _USE_PROCESS_COM
	RMEProcessServer* m_proc_server;
	wxSingleInstanceChecker* m_single_instance_checker;
#endif
};

#endif // RME_APPLICATION_H_
