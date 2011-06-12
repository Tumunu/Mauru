/*
 *  Name:     CAppUi from AppUi.h
 *  Author:   Cleave Pokotea
 *  Www:      www.tumunu.com
 *  Project:  mauru
 */


#ifndef APP_UI_H
#define APP_UI_H

// includes
#include <aknviewappui.h>

// App Ui
class CAppUi : public CAknViewAppUi
  {
    public:
      void ConstructL();

      ~CAppUi();

    public:
      // from CEikAppUi
      void HandleCommandL(TInt aCommand);
      HBufC* iUri; // not ideal but it works for now

    private:
      // from MEikMenuObserver
      void DynInitMenuPaneL(TInt aResourceId,CEikMenuPane* aMenuPane);

    private:
      // from CEikAppUi
      virtual TKeyResponse HandleKeyEventL(const TKeyEvent& aKeyEvent,TEventCode aType);
  };

#endif
