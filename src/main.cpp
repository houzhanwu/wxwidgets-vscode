// wxWidgets "Hello World" Program available on https://docs.wxwidgets.org/trunk/overview_helloworld.html

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif


#include "http/sion.h"
#define SION_DISABLE_SSL 1


#include <fstream>
#include "api/json/json/json.h"


class MyApp : public wxApp 
{
public:
    virtual bool OnInit(); 
}; 

class MyFrame : public wxFrame
{
public:
    MyFrame();
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);


    void LogToFile(const std::string& message);
};

enum
{
    ID_Hello = 1
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame();
    frame->Show(true);
    return true;
}

MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY, "Hello World")
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H", "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar( menuBar );

    CreateStatusBar();

    SetStatusText("Welcome to wxWidgets!");

    Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example", "About Hello World", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnHello(wxCommandEvent& event)
{
    //wxLogMessage("Hello world from wxWidgets!");

    auto resp = sion::Request()
                    .SetBody(R"({ "username": "admin", "password": "Admin@2024!#" })")
                    .SetHeader("Content-type", "application/json")
                    .SetUrl("http://127.0.0.1:8090/login")
                    .SetHttpMethod("POST")
                    .Send();
    std::cout << resp.StrBody() << std::endl;
    std::string stlstring = resp.StrBody();
    wxString mystring(stlstring.c_str(), wxConvUTF8);
    wxLogMessage(mystring);

 
    Json::Reader reader;
    Json::Value value;
    if (reader.parse(stlstring, value))            // json字符串转为json对象
    {   

        std::string name = value["user"]["username"].asString();
        std::string deptName = value["user"]["deptName"].asString();
        std::cout<<name<<" "<<name<<" "<<deptName<<std::endl;
        std::string out = "name:" + name + " deptName:" + deptName;
           // 示例日志
        LogToFile("Application started.");
        LogToFile(out);
        LogToFile("Application end.");
    }


    // stlstring 转 json 对象
   //std::string strValue = "{\"name\":\"json\",\"array\":[{\"cpp\":\"jsoncpp\"},{\"java\":\"jsoninjava\"},{\"php\":\"support\"}]}";    
    
    // // 构建json数组
    // Json::Value array;
    // Json::Value root;
    // Json::Value person;
    
    // Json::FastWriter writer;
 
 
    // person["name"] = "allen";
    // person["age"] = 10; 
    // person["sex"] = "male";
    // root.append(person);
 
    // person["name"] = "keiv";
    // person["age"] = 20; 
    // person["sex"] = "female";
    // root.append(person);
    
    // person["name"] = "lihua";
    // person["age"] = 10; 
    // person["sex"] = "female";
    // root.append(person);
 
    // // 添加数组格式
    // //array["array"].append(root);
    
    // // 子节点挂到根节点上
    // array["array"] = Json::Value(root);
 
    // std::string data = writer.write(array);
 
    // //cout<<data<<endl;  
    // //cout<<array.toStyledString()<<endl;
    
    
    // // 解析Json字符串
    // std::string strValue = array.toStyledString();      // json对象转变为json字符串
    // std::cout<< strValue << std::endl;
 
    // Json::Reader reader;
    // Json::Value value;
 
    // if (reader.parse(strValue, value))            // json字符串转为json对象
    // {   
    //     for (unsigned int i = 0; i < value["array"].size(); i++)
    //     {   
    //         std::string name = value["array"][i]["name"].asString();
    //         int     age = value["array"][i]["age"].asInt();
    //         std::string sex  = value["array"][i]["sex"].asString();
 
    //         std::cout<<name<<" "<<age<<" "<<sex<<std::endl;
    //     }
    // }


} 


void MyFrame::LogToFile(const std::string& message) {
    // 打开输出文件
    std::ofstream logFile("log.txt", std::ios_base::app); // 以追加方式打开文件
    if (logFile.is_open()) {
        logFile << message << std::endl; // 写入信息
        logFile.close(); // 关闭文件
    } else {
        wxMessageBox("Unable to open log file.", "Error", wxOK | wxICON_ERROR);
    }
}
