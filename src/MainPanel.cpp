//--------------------------------------------------------------------
// C++ code generated with wxFormBuilder (version 3.9.0 Jun 14 2020)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
//--------------------------------------------------------------------

#include "MainPanel.h"
#include <fstream>
#include <sstream>
#include <iostream>

///////////////////////////////////////////////////////////////////////////

// class MainPanelSub : public MainPanel
// {
// public:

//     void treeListCtrlOnTreelistItemChecked(wxTreeListEvent& event)
//     {
//         // 如果基类中的实现不应该做任何事情，可以省略 event.Skip();
//         // event.Skip(); // 如果有需要，可以取消注释

// 		wxTreeListItem item = event.GetItem();

//  		wxString itemstring = item.IsOk() ? treeListCtrl->GetItemText(item) : wxString("NONE");


// 		wxMessageBox(wxString::FromUTF8(itemstring));
//     }


// 	MainPanelSub(wxWindow* parent);
// 	~MainPanelSub();

// };

// // MainPanelSub::MainPanelSub(wxWindow* parent)
// // {
	
// // }

// MainPanelSub::~MainPanelSub()
// {
	
// }


MainPanel::MainPanel(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) : wxPanel(parent, id, pos, size, style, name)
{
	wxBoxSizer* bSizer_main;
	bSizer_main = new wxBoxSizer(wxVERTICAL);

	loadData = new wxButton(this, wxID_ANY, wxString::FromUTF8("加载数据"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer_main->Add(loadData, 0, wxALL, 5);

	treeListCtrl = new wxTreeListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTL_CHECKBOX);

	bSizer_main->Add(treeListCtrl, 1, wxEXPAND | wxALL, 5);

	wxBoxSizer* bSizer_bottom;
	bSizer_bottom = new wxBoxSizer(wxHORIZONTAL);

	m_button2 = new wxButton(this, wxID_ANY, wxString::FromUTF8("加载数据1"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer_bottom->Add(m_button2, 0, wxALL, 5);

	m_button3 = new wxButton(this, wxID_ANY, wxString::FromUTF8("加载数据2"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer_bottom->Add(m_button3, 0, wxALL, 5);


	bSizer_main->Add(bSizer_bottom, 1, wxEXPAND, 5);


	this->SetSizer(bSizer_main);
	this->Layout();



	// Connect Events
	loadData->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainPanel::loadData2Table), NULL, this);
	treeListCtrl->Connect(wxEVT_TREELIST_COLUMN_SORTED, wxTreeListEventHandler(MainPanel::treeListCtrlOnTreelistColumnSorted), NULL, this);
	treeListCtrl->Connect(wxEVT_TREELIST_ITEM_ACTIVATED, wxTreeListEventHandler(MainPanel::treeListCtrlOnTreelistItemActivated), NULL, this);
	treeListCtrl->Connect(wxEVT_TREELIST_ITEM_CHECKED, wxTreeListEventHandler(MainPanel::treeListCtrlOnTreelistItemChecked), NULL, this);
	treeListCtrl->Connect(wxEVT_TREELIST_ITEM_CONTEXT_MENU, wxTreeListEventHandler(MainPanel::treeListCtrlOnTreelistItemContextMenu), NULL, this);
	treeListCtrl->Connect(wxEVT_TREELIST_ITEM_EXPANDED, wxTreeListEventHandler(MainPanel::treeListCtrlOnTreelistItemExpanded), NULL, this);
	treeListCtrl->Connect(wxEVT_TREELIST_ITEM_EXPANDING, wxTreeListEventHandler(MainPanel::treeListCtrlOnTreelistItemExpanding), NULL, this);
	treeListCtrl->Connect(wxEVT_TREELIST_SELECTION_CHANGED, wxTreeListEventHandler(MainPanel::treeListCtrlOnTreelistSelectionChanged), NULL, this);
}

MainPanel::~MainPanel()
{
	// Disconnect Events
	loadData->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MainPanel::loadData2Table), NULL, this);
	treeListCtrl->Disconnect(wxEVT_TREELIST_COLUMN_SORTED, wxTreeListEventHandler(MainPanel::treeListCtrlOnTreelistColumnSorted), NULL, this);
	treeListCtrl->Disconnect(wxEVT_TREELIST_ITEM_ACTIVATED, wxTreeListEventHandler(MainPanel::treeListCtrlOnTreelistItemActivated), NULL, this);
	treeListCtrl->Disconnect(wxEVT_TREELIST_ITEM_CHECKED, wxTreeListEventHandler(MainPanel::treeListCtrlOnTreelistItemChecked), NULL, this);
	treeListCtrl->Disconnect(wxEVT_TREELIST_ITEM_CONTEXT_MENU, wxTreeListEventHandler(MainPanel::treeListCtrlOnTreelistItemContextMenu), NULL, this);
	treeListCtrl->Disconnect(wxEVT_TREELIST_ITEM_EXPANDED, wxTreeListEventHandler(MainPanel::treeListCtrlOnTreelistItemExpanded), NULL, this);
	treeListCtrl->Disconnect(wxEVT_TREELIST_ITEM_EXPANDING, wxTreeListEventHandler(MainPanel::treeListCtrlOnTreelistItemExpanding), NULL, this);
	treeListCtrl->Disconnect(wxEVT_TREELIST_SELECTION_CHANGED, wxTreeListEventHandler(MainPanel::treeListCtrlOnTreelistSelectionChanged), NULL, this);

}


void MainPanel::loadData2Table(wxCommandEvent& event) {
    // 加载json 到 表格


	wxString jsonFilePath = wxFileSelector(wxString::FromUTF8("选择json文件"), "", "", "", "json files (*.json)|*.json", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if (jsonFilePath.empty()) {
		return;
	}

  // 将 wxString 转换为 std::string，以便使用标准 C++ 文件流
    std::string jsonFileStdString = jsonFilePath.ToStdString();

    // 打开文件并读取内容
    std::ifstream file(jsonFileStdString);
    std::stringstream buffer;
    buffer << file.rdbuf(); // 读取文件内容到 buffer

    // 关闭文件
    file.close();

	std::string stlstring = buffer.str();

	Json::Reader reader;
    Json::Value value;
    if (reader.parse(stlstring, value))            // json字符串转为json对象
    {   
		// wxMessageBox(wxString::FromUTF8(value.toStyledString()));


    //   wxTreeListCtrl* treeList = new wxTreeListCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(200, 150),
    //         wxTR_HAS_BUTTONS | wxTR_HAS_VARIABLE_ROW_HEIGHT | wxTR_ROW_LINES | wxTR_DEFAULT_STYLE);
 	// 	treeListCtrl->style

    // 	treeListCtrl->ToggleWindowStyle(1);

		treeListCtrl->AppendColumn("#id",
						wxCOL_WIDTH_AUTOSIZE,
						wxALIGN_LEFT,
						wxCOL_RESIZABLE | wxCOL_SORTABLE);
		treeListCtrl->AppendColumn("#name",
						treeListCtrl->WidthFor("1,000,000"),
						wxALIGN_RIGHT,
						wxCOL_RESIZABLE | wxCOL_SORTABLE);
		treeListCtrl->AppendColumn("#mobile",
						treeListCtrl->WidthFor("1,000,000 KiB"),
						wxALIGN_RIGHT,
						wxCOL_RESIZABLE | wxCOL_SORTABLE);
        wxTreeListItem root = treeListCtrl->GetRootItem();


		if (value.isMember("RECORDS") && value["RECORDS"].isArray()) {
			// 遍历RECORDS数组
			for (int i = 0; i < value["RECORDS"].size(); ++i) {
				const Json::Value& record = value["RECORDS"][i];
				// 假设我们想打印id, user_name, 和 mobile
				if (record.isMember("id") && record.isMember("user_name") && record.isMember("mobile")) {
					int id = record["id"].asInt();
					std::string userName = record["user_name"].asString();
					std::string mobile = record["mobile"].asString();
					//std::cout << "ID: " << id << ", User Name: " << userName << ", Mobile: " << mobile << std::endl;
					wxString wxUserName(userName.c_str(), wxConvUTF8);
					wxTreeListItem item = treeListCtrl->AppendItem(root , wxUserName); 

					wxString wxMobile(mobile.c_str(), wxConvUTF8);
					wxTreeListItem item1 = treeListCtrl->AppendItem(item , wxMobile); 	
				}
			}
		} else {
			std::cerr << "JSON does not contain a RECORDS array" << std::endl;
		}










	}


   
}

void MainPanel::treeListCtrlOnTreelistItemChecked(wxTreeListEvent& event)
{
	// 如果基类中的实现不应该做任何事情，可以省略 event.Skip();
	// event.Skip(); // 如果有需要，可以取消注释

	wxTreeListItem item = event.GetItem();

	wxString itemstring = item.IsOk() ? treeListCtrl->GetItemText(item) : wxString("NONE");


	wxMessageBox(wxString::FromUTF8(itemstring));
}