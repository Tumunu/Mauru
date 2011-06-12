/*
 *  Name:     CPlaybackContainer from PlaybackContainer.cpp
 *  Author:   Cleave Pokotea
 *  Www:      www.tumunu.com
 *  Project:  mauru
 */


// includes
#include <AknAppUi.h>
#include <StringLoader.h>
#include <aknquerydialog.h>
#include <AknWaitDialog.h> 
#include <aknquerydialog.h>
#include <aknnotewrappers.h>
#include <aknmessagequerydialog.h>
#include <eiklabel.h>
#include <AknsDrawUtils.h>
#include <AknsBasicBackgroundControlContext.h>
#include "AppUi.h"
#include "RecorderAdapter.h"
#include "ImageLoader.h"
#include "SplashView.h"
#include "CamView.h"
#include "PlaybackView.h"
#include "PlaybackContainer.h"
#include <Mauru.rsg>
#include "Mauru.hrh"
#include <Mauru.mbg>

// literals
_LIT(KDrawBitmapPath, "\\system\\apps\\mauru\\mauru.mbm");
_LIT(KAudioFile, "e:\\Sounds\\%S.awb");
_LIT(KImgFile, "e:\\images\\%S.jpg");

// constants
const TInt KFractionOfFontSizeToLowerText = 3;
const TInt KBirdTopLeftX = 16;
const TInt KBirdTopLeftY = 40;
const TInt KTopLeftX = 0;
const TInt KTopLeftY = 0;
const TInt KSizeWidth = 176;
const TInt KSizeHeight = 208;

/* ---------------------------------------------------- 
NOTE: image size
145 width 
150 height
---------------------------------------------------- */

// member functions
void CPlaybackContainer::ConstructL(const TRect &aRect)
{
  iEngine = CRecorderAdapter::NewL(); //(*this);
  iBitmap = new(ELeave)CFbsBitmap();

  CreateWindowL();
  SetRect(aRect);

  SetExtentToWholeScreen();

  TFileName bitmapFile(KDrawBitmapPath);
  User::LeaveIfError(CompleteWithAppPath(bitmapFile));

  iLogoBitmap = new(ELeave)CFbsBitmap();
  User::LeaveIfError(iLogoBitmap->Load(bitmapFile, EMbmMivisSplash));

  ActivateL();

  /* ---------------------------------------------------- 
  Text strings
  ---------------------------------------------------- */
  iStoppedText = StringLoader::LoadL(R_AUDIO_STOPPED);
  iPlayingText = StringLoader::LoadL(R_AUDIO_PLAYING);
  iPausedText = StringLoader::LoadL(R_AUDIO_PAUSED);
  iOpenText = StringLoader::LoadL(R_AUDIO_OPENING);

  PlayL();
}

CPlaybackContainer::~CPlaybackContainer()
{
  delete iEngine;
  delete iLogoBitmap;
  delete iBitmap;
  delete iFocalBitmap;
}

TKeyResponse CPlaybackContainer::OfferKeyEventL(const TKeyEvent &aKeyEvent,
  TEventCode aType)
{
  TKeyResponse keyResponse = EKeyWasNotConsumed;

  if (aType != EEventKey)
  {
    return keyResponse;
  }

  switch (aKeyEvent.iCode)
  {
    case EKeyOK:
      {
        switch (iContainerState)
        {
        case EStopped:
          {
            ((CAppUi*)iEikonEnv->EikAppUi())->ActivateLocalViewL(KCamViewId);
            break;
          }
        case EPaused:
        case EPlaying:
          {
            StopL();
            break;
          }
        case EOpen:
        default:
          {
            break;
          }
        }
        keyResponse = EKeyWasConsumed;
        break;
      }
    case EKeyLeftArrow:
      {
        if (iContainerState == EStopped)
        {
          PlayL();
        }
        keyResponse = EKeyWasConsumed;
        break;
      }
    default:
      {
        keyResponse = EKeyWasNotConsumed;
        break;
      }
  }

  return keyResponse;
}

void CPlaybackContainer::DisplayMessage(const TDesC &aMessage, CWindowGc &aGc)
  const
{
  aGc.SetPenColor(KRgbYellow);
  const CFont *fontUsed = iEikonEnv->TitleFont();
  aGc.UseFont(fontUsed);

  // Set text position on screen
  TInt baseline = Rect().Height() - fontUsed->AscentInPixels()
    *KFractionOfFontSizeToLowerText;

  // Margin is zero so that the text will be centred
  TInt margin = 0;

  aGc.DrawText(aMessage, Rect(), baseline, CGraphicsContext::ECenter, margin);
}

void CPlaybackContainer::LoadImgFromFileL()const{}

void CPlaybackContainer::Draw(const TRect &aRect)const
{
  CWindowGc &gc = SystemGc();
  gc.Clear(aRect);

  TPoint topLeft(KTopLeftX, KTopLeftY);
  TSize bitmapSize(KSizeWidth, KSizeHeight);
  gc.DrawBitmap(TRect(topLeft, bitmapSize), iLogoBitmap);

  switch (iContainerState)
  {
    case EOpen:
      {
        DisplayMessage(*iOpenText, gc);
        break;
      }
    case EPaused:
      {
        DisplayMessage(*iPausedText, gc);
        break;
      }
    case EPlaying:
      {
        DisplayMessage(*iPlayingText, gc);
        break;
      }
    case EStopped:
    default:
      {
        DisplayMessage(*iStoppedText, gc);
        break;
      }
  }

  TBuf < 256 > gfxFile;

  HBufC *url = ((CAppUi*)iEikonEnv->EikAppUi())->iURL;
  TBuf < 256 > txt = url->Des();

  gfxFile.Format(KImgFile, &txt);
  CFbsBitmap *iFocalBitmap = CImageLoader::LoadImageL(gfxFile);

  if (iFocalBitmap)
  {
    TPoint pos(KBirdTopLeftX, KBirdTopLeftY);
    gc.BitBlt(pos, iFocalBitmap);
  }
}

void CPlaybackContainer::PlayL()
{
  iContainerState = EPlaying;
  DrawNow();

  TBuf < 256 > audioFile;
  HBufC *url = ((CAppUi*)iEikonEnv->EikAppUi())->iURL;
  TBuf < 256 > txt = url->Des();

  audioFile.Format(KAudioFile, &txt);
  iEngine->PlayL(audioFile);
}

void CPlaybackContainer::StopL()
{
  iEngine->StopL();

  iContainerState = EStopped;
  DrawNow();
}

void CPlaybackContainer::HandlePlayingStoppedL()
{
  iContainerState = EStopped;
  DrawNow();
}
