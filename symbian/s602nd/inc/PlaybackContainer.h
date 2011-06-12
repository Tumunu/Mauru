/*
 *  Name:     CPlaybackContainer from PlaybackContainer.h
 *  Author:   Cleave Pokotea
 *  Www:      www.tumunu.com
 *  Project:  mauru
*/


#ifndef PLAYBACK_CONTAINER_H
#define PLAYBACK_CONTAINER_H

// includes
#include <coecntrl.h>
#include "RecorderAdapter.h"

// declarations
class CRecorderAdatper;
class CFbsBitmap;
class CAppUi;

// Playback Container
class CPlaybackyContainer : public CCoeControl, public MRecorderObserver
  {
    public:
      static CPlaybackContainer*  NewL(const TRect& aRect);
      static CPlaybackContainer*  NewLC(const TRect& aRect);
      void ConstructL(const TRect& aRect);

      ~CPlaybackContainer();

    public:
      void PlayL();
      void StopL();

      enum TContainerState
      {
        ENotReady = 0,
        EPlaying,
        EPaused,
        EStopped,
        EOpen
      };

      TKeyResponse OfferKeyEventL(const TKeyEvent& aKeyEvent,TEventCode aType);

    public:
      // MAudioPlayerEngineObserver
      virtual void HandlePlayingStoppedL();

    private:
      // from CCoeControl,Draw
      void Draw(const TRect& aRect) const;

    private:
      void DisplayMessage(const TDesC& aMessage, CWindowGc& aGc) const;
      void LoadImgFromFileL() const;

    private:
      TContainerState  iContainerState;
      CRecorderAdapter*  iEngine;
      CFbsBitmap*  iLogoBitmap;
      CFbsBitmap*  iBitmap;
      CFbsBitmap*  iBirdBitmap;
      HBufC*  iStoppedText;
      HBufC*  iPlayingText;
      HBufC*  iPausedText;
      HBufC*  iOpenText;
  };

#endif
