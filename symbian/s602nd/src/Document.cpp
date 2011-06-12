/*
 *  Name:     CDocument from Document.cpp
 *  Author:   Cleave Pokotea
 *  Www:      www.tumunu.com
 *  Project:  mauru
 */


// includes
#include "Document.h"
#include "Appui.h"

// member functions
CDocument::CDocument(CEikApplication &aApp): CAknDocument(aApp){}

CDocument::~CDocument(){}

void CDocument::ConstructL(){}

CDocument *CDocument::NewL(CEikApplication &aApp)
{
  CDocument *self = new(ELeave)CDocument(aApp);
  CleanupStack::PushL(self);
  self->ConstructL();
  CleanupStack::Pop();

  return self;
}

CEikAppUi *CDocument::CreateAppUiL()
{
  return new(ELeave)CAppUi;
}
