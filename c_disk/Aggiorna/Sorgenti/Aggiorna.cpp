//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Main.cpp", FormMain);
USEFORM("GenModParam.cpp", FGenModParam);
USEFORM("TastieraNumerica.cpp", FormTastieraNumerica);
USEFORM("Tastiera.cpp", FormTastiera);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
  try
  {
     Application->Initialize();
     Application->Title = "Aggiorna";
     Application->CreateForm(__classid(TFormMain), &FormMain);
     Application->CreateForm(__classid(TFGenModParam), &FGenModParam);
     Application->CreateForm(__classid(TFormTastieraNumerica), &FormTastieraNumerica);
     Application->CreateForm(__classid(TFormTastiera), &FormTastiera);
     Application->Run();
  }
  catch (Exception &exception)
  {
     Application->ShowException(&exception);
  }
  catch (...)
  {
     try
     {
       throw Exception("");
     }
     catch (Exception &exception)
     {
       Application->ShowException(&exception);
     }
  }
  return 0;
}
//---------------------------------------------------------------------------




