// clrTest.cpp : main project file.

#include "stdafx.h"
#include "TestForm.h"

using namespace System;
using namespace clrTest;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
    //Console::WriteLine(L"Hello World");
	//TestForm form;
	//form.Show();
	//Console::ReadKey();

	//Application::EnableVisualStyles();
	//Application::SetCompatibleTextRenderingDefault(true); 
	Application::Run(gcnew TestForm());

    return 0;
}
