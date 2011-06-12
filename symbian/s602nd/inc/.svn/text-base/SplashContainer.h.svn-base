/*
 *  Name:     CSplashContainer from SplashContainer.h
 *  Author:   Cleave Pokotea
 *  Www:      www.tumunu.com
 *  Project:  mauru
 */


#ifndef SPLASH_CONTAINER_H
#define SPLASH_CONTAINER_H

// includes
#include <coecntrl.h>

// declarations
class CSplasView;
class CCamView;
class CPlaybackView;
class CFbsBitmap;

// splash container
class CSplashContainer : public CCoeControl
  {
    public:
      static CSplashContainer*  NewL(const TRect& aRect);
      static CSplashContainer*  NewLC(const TRect& aRect);
      void ConstructL(const TRect& aRect);

      ~CSplashContainer();

    private:
      // from CCoeControl, Draw
      void Draw(const TRect& aRect) const;

    private:
      CFbsBitmap*  iLogoBitmap;
      CFbsBitmap*  iBitmap;
  };

#endif
