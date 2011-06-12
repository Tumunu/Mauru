/*
 *  Name:     CApp from App.cpp
 *  Author:   Cleave Pokotea
 *  Www:      www.tumunu.com
 *  Project:  mauru
 */


// includes
#include "App.h"
#include "Document.h"

// member functions
TUid CApp::AppDllUid()const
{
  return KUidmivis;
}

CApaDocument *CApp::CreateDocumentL()
{
  return CDocument::NewL(*this);
}

EXPORT_C CApaApplication *NewApplication()
{
  return new CApp;
}

GLDEF_C TInt E32Dll(TDllReason)
{
  return KErrNone;
}
