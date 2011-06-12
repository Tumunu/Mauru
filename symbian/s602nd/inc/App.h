/*
 *  Name:     CApp from App.h
 *  Author:   Cleave Pokotea
 *  Www:      www.tumunu.com
 *  Project:  mauru
 */

 
#ifndef APP_H
#define APP_H

// includes
#include <aknapp.h>

// constants
const TUid KUidMauru = { 0x1020E545 }; // this is the unique mauru UID

// App
class CApp : public CAknApplication
  {
    private:
      // from CApaApplication
      CApaDocument* CreateDocumentL();

      // from CApaApplication
      TUid AppDllUid() const;
  };

#endif
