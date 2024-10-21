//--------------------------------------------------------------------
// C++ code generated with wxFormBuilder (version 3.9.0 Jun 14 2020)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
//--------------------------------------------------------------------

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/button.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/treelist.h>
#include <wx/sizer.h>
#include <wx/panel.h>

#include <wx/filedlg.h>
#include <wx/wfstream.h>
#include <wx/textfile.h>
#include <wx/msgdlg.h>
#include "api/json/json/json.h"

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainPanel
///////////////////////////////////////////////////////////////////////////////
class MainPanel : public wxPanel
{
	private:

	protected:
		wxButton* loadData;
		wxTreeListCtrl* treeListCtrl;
		wxButton* m_button2;
		wxButton* m_button3;

		// Virtual event handlers,overide them in your derived class
		//virtual void loadData2Table(wxCommandEvent& event) { event.Skip(); }
		virtual void treeListCtrlOnTreelistColumnSorted(wxTreeListEvent& event) { event.Skip(); }
		virtual void treeListCtrlOnTreelistItemActivated(wxTreeListEvent& event) { event.Skip(); }
		//virtual void treeListCtrlOnTreelistItemChecked(wxTreeListEvent& event) { event.Skip(); }
		virtual void treeListCtrlOnTreelistItemContextMenu(wxTreeListEvent& event) { event.Skip(); }
		virtual void treeListCtrlOnTreelistItemExpanded(wxTreeListEvent& event) { event.Skip(); }
		virtual void treeListCtrlOnTreelistItemExpanding(wxTreeListEvent& event) { event.Skip(); }
		virtual void treeListCtrlOnTreelistSelectionChanged(wxTreeListEvent& event) { event.Skip(); }


	public:

		MainPanel(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(800,466), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString);
		~MainPanel();
		void loadData2Table(wxCommandEvent& event);
		void treeListCtrlOnTreelistItemChecked(wxTreeListEvent& event);
};

