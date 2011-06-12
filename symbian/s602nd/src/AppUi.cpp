/*
 *  Name:     CAppUi from AppUi.cpp
 *  Author:   Cleave Pokotea
 *  Www:      www.tumunu.com
 *  Project:  mauru
 */


// includes
#include <aknmessagequerydialog.h>
#include "Appui.h"
#include "SplashView.h"
#include "CamView.h"
#include "PlaybackView.h"
#include <Mauru.rsg>
#include "Mauru.hrh"
#include <avkon.hrh>

// literals
_LIT(KPassword, "mauru");

// member functions
void CAppUi::ConstructL()
{
  BaseConstructL();
  CSplashView *splashView = CSplashView::NewLC();
  AddViewL(splashView);
  CleanupStack::Pop(splashView);

  CCamView *camView = CCamView::NewLC();
  AddViewL(camView);
  CleanupStack::Pop(camView);

  CPlaybackView *playbackView = CPlaybackView::NewLC();
  AddViewL(playbackView);
  CleanupStack::Pop(playbackView);

  SetDefaultViewL(*splashView);
}

CAppUi::~CAppUi()
{
  if (iURL)
  {
    iURL = NULL;
    delete iURL;
  }
}

void CAppUi::DynInitMenuPaneL(TInt /*aResourceId*/, CEikMenuPane *
  /*aMenuPane*/){}

TKeyResponse CAppUi::HandleKeyEventL(const TKeyEvent &aKeyEvent, TEventCode
  aType)
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
        ActivateLocalViewL(KCamViewId);
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

void CAppUi::HandleCommandL(TInt aCommand)
{
  switch (aCommand)
  {
    case EEikCmdExit:
      {
        TBuf < 15 > password;
        CAknTextQueryDialog *Dialog = CAknTextQueryDialog::NewL(password,
          CAknQueryDialog::ENoTone);
        Dialog->PrepareLC(R_ASK_PWD);
        Dialog->RunLD();

        TBuf < 20 > buf;
        buf.Copy(KPassword);

        if (password == buf)
        {
          Exit();
        }
        break;
      }
    case ESamCmdAbout:
      {
        TBuf < 1024 > msgAbout = _L(
          "mauru ~ a www.tumunu.com project\r\nBy Cleave Pokotea");

        CAknMessageQueryDialog *dlgAbout = CAknMessageQueryDialog::NewL
          (msgAbout);
        dlgAbout->PrepareLC(R_MAURU_ABOUT);
        dlgAbout->QueryHeading()->SetTextL(_L("About mauru"));
        dlgAbout->RunLD();
        break;
      }
    default:
      break;
  }
}
