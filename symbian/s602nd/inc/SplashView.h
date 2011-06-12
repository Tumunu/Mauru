/*
 *  Name:     CSplashView from SplashView.h
 *  Author:   Cleave Pokotea
 *  Www:      www.tumunu.com
 *  Project:  mauru
 */
 
 
#ifndef SPLASH_VIEW_H
#define SPLASH_VIEW_H

// includes
#include <aknview.h>

// constants

const TUid KSplashViewId = {1}; 

// declarations
class CSplashContainer; 

// splash view
class CSplashView: public CAknView
  {
    public:
      static CSplashView *NewL();
      static CSplashView *NewLC();
      ~CSplashView();
	  
    public:
      // from CAknView returns Uid of View
      TUid Id()const; // from MEikMenuObserver
      void HandleCommandL(TInt aCommand); // from CAknView
      void HandleClientRectChange();
	  
    private:
      void ConstructL();
      // from CAknView activate the view
      void DoActivateL(const TVwsViewId &aPrevViewId, TUid aCustomMessageId, const TDesC8 &aCustomMessage); // from CAknView
      void DoDeactivate();
	  
    private:
      CSplashContainer*  iContainer;
  };
  
#endif
