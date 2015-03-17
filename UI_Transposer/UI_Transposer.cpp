#include "UI_Transposer.h"
#include <Songlist.h>
#include <Transposer.h>
using namespace System;
using namespace::Windows::Forms;
[STAThread]
void main(array<String^>^ args){
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	UI_Transposer::UI_Transposer mainWindow;
	Application::Run(%mainWindow); //Run is a continuous loop. Any code following that will be executed after the window is closed
}