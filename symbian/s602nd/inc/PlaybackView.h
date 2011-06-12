/*
 *  Name:     CPlaybackView from PlaybackView.h
 *  Author:   Cleave Pokotea
 *  Www:      www.tumunu.com
 *  Project:  mauru
 */


#ifndef PLAYBACK_VIEW_H
#define PLAYBACK_VIEW_H

// includes
#include <aknview.h>

// constants
const TUid KPlaybackViewId = {3};

// declarations
class CSamDiaryContainer;

// Playback View
class CPlaybackView : public CAknView
  {
    public:
      static CPlaybackView*  NewL();
      static CPlaybackView*  NewLC();

      ~CPlaybackView();

    public:
      // from CAknView returns Uid of View
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
      CPlaybackContainer*  iContainer;
  };

#endif
