/*
 *  Name:     CDocument from Document.h
 *  Author:   Cleave Pokotea
 *  Www:      www.tumunu.com
 *  Project:  mauru
 */

 
#ifndef DOCUMENT_H
#define DOCUMENT_H

// includes
#include <akndoc.h>

// declarations
class  CEikAppUi;

// Document
class CDocument : public CAknDocument
  {
    public:
      static CDocument*  NewL(CEikApplication& aApp);

      virtual ~CDocument();

    private:
      CDocument(CEikApplication& aApp);
      void ConstructL();

    private:
      // from CEikDocument
      CEikAppUi*  CreateAppUiL();
  };

#endif
