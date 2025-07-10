#pragma once

#include <wx/wx.h>

class WorldGeneratorDialog : public wxDialog {
public:
	WorldGeneratorDialog(wxWindow* parent);
	int GetMapWidth() const;
	int GetMapHeight() const;

private:
	wxTextCtrl* widthCtrl;
	wxTextCtrl* heightCtrl;
};