#include "FaceRecognition.h"
#include "stdafx.h"


using namespace System::Windows::Forms;

[System::STAThread]


int main(array<System::String^>^ args) {
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	FaceDetection::FaceRecognition form;
	Application::Run(%form);
	
}