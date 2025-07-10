#ifndef RME_MAINTOOLBAR_H_
#define RME_MAINTOOLBAR_H_

#include <wx/wx.h>
#include <wx/aui/aui.h>
#include <wx/aui/auibar.h>

#include "gui_ids.h"
#include "numbertextctrl.h"

#define TOOLBAR_WORLDGENERATOR 6001

class MainToolBar : public wxEvtHandler
{
public:
	MainToolBar(wxWindow* parent, wxAuiManager* manager);
	~MainToolBar();

	wxAuiPaneInfo& GetPane(ToolBarID id);
	void UpdateButtons();
	void UpdateBrushButtons();
	void UpdateBrushSize(BrushShape shape, int size);
	void UpdateIndicators();
	void Show(ToolBarID id, bool show);
	void HideAll(bool update = true);
	void LoadPerspective();
	void SavePerspective();

	void OnStandardButtonClick(wxCommandEvent& event);
	void OnBrushesButtonClick(wxCommandEvent& event);
	void OnPositionButtonClick(wxCommandEvent& event);
	void OnPositionKeyUp(wxKeyEvent& event);
	void OnPastePositionText(wxClipboardTextEvent& event);
	void OnSizesButtonClick(wxCommandEvent& event);
	void OnIndicatorsButtonClick(wxCommandEvent& event);

private:
	static const wxString STANDARD_BAR_NAME;
	static const wxString BRUSHES_BAR_NAME;
	static const wxString POSITION_BAR_NAME;
	static const wxString SIZES_BAR_NAME;
	static const wxString INDICATORS_BAR_NAME;

	wxAuiToolBar* standard_toolbar;
	wxAuiToolBar* brushes_toolbar;
	wxAuiToolBar* position_toolbar;
	NumberTextCtrl* x_control;
	NumberTextCtrl* y_control;
	NumberTextCtrl* z_control;
	wxButton* go_button;
	wxAuiToolBar* sizes_toolbar;
	wxAuiToolBar* indicators_toolbar;
};

#endif // RME_MAINTOOLBAR_H_