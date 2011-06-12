/*
*   Name:     CCamView from CamView.h
 *  Author:   Cleave Pokotea
 *  Www:      www.tumunu.com
 *  Project:  mauru
 */

 
#ifndef CAM_VIEW_H
#define CAM_VIEW_H

// includes
#include <aknview.h>

// constants
const TUid KCamViewId = {2};

// declarations
class CCamContainer;

// Cam View
class CCamView : public CAknView
  {
    public:
      static CCamView*  NewL();
      static CCamView*  NewLC();

      ~CCamView();

    public:
      // from CAknView
      TUid Id() const;

      // from MEikMenuObserver
      void HandleCommandL(TInt aCommand);

      // from CAknView
      void HandleClientRectChange();

    private:
      void ConstructL();

      // from CAknView
      void DoActivateL(const TVwsViewId& aPrevViewId,TUid aCustomMessageId, const TDesC8& aCustomMessage);

      // from CAknView
      void DoDeactivate();

    private:
      CCamContainer*  iContainer;
  };

#endif
