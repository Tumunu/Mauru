/*
 *  Name:     CPlaybackView from PlaybackView.h
 *  Author:   Cleave Pokotea
 *  Www:      www.tumunu.com
 *  Project:  mauru
 */


// includes
#include <aknviewappui.h>
#include <avkon.hrh>
#include "SplashView.h"
#include "CamView.h"
#include "PlaybackView.h"
#include "PlaybackContainer.h"
#include <Mauru.rsg>
#include <Mauru.hrh>

// member functions
void CPlaybackView::ConstructL()
{
  BaseConstructL(R_MAURU_PLAYBACK);
}

CPlaybackView::~CPlaybackView()
{
  if (iContainer)
  {
    AppUi()->RemoveFromViewStack(*this, iContainer);
  }

  delete iContainer;
}

CPlaybackView *CPlaybackView::NewL()
{
  CPlaybackView *self = CPlaybackView::NewLC();
  CleanupStack::Pop(self);
  return self;
}

CPlaybackView *CPlaybackView::NewLC()
{
  CPlaybackView *self = new(ELeave)CPlaybackView();
  CleanupStack::PushL(self);
  self->ConstructL();
  return self;
}

TUid CPlaybackView::Id()const
{
  return KPlaybackViewId;
}

void CPlaybackView::HandleCommandL(TInt aCommand)
{
  switch (aCommand)
  {
    case EAknSoftkeyBack:
      {
        AppUi()->HandleCommandL(EEikCmdExit);
        break;
      }
    case EAknSoftkeyOk:
    default:
      {
        AppUi()->HandleCommandL(aCommand);
        break;
      }
  }
}

void CPlaybackView::HandleClientRectChange()
{
  if (iContainer)
  {
    iContainer->SetRect(ClientRect());
  }
}

void CPlaybackView::DoActivateL(const TVwsViewId & /*aPrevViewId*/, TUid
  /*aCustomMessageId*/, const TDesC8 & /*aCustomMessage*/)
{
  if (!iContainer)
  {
    iContainer = new(ELeave)CPlaybackContainer;
    iContainer->SetMopParent(this);
    iContainer->ConstructL(ClientRect());
    AppUi()->AddToStackL(*this, iContainer);
  }
}

void CPlaybackView::DoDeactivate()
{
  if (iContainer)
  {
    AppUi()->RemoveFromViewStack(*this, iContainer);
  }

  delete iContainer;
  iContainer = NULL;
}
