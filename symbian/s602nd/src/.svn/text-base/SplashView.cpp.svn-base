/*
 *  Name:     CSplashView from SplashView.cpp
 *  Author:   Cleave Pokotea
 *  Www:      www.tumunu.com
 *  Project:  mauru
 */


// includes
#include <aknviewappui.h>
#include <avkon.hrh>
#include "SplashView.h"
#include "SplashContainer.h"
#include <Mauru.rsg>
#include <Mauru.hrh>

// member functions
void CSplashView::ConstructL()
{
  BaseConstructL(R_MAURU_SPLASH);
}

CSplashView::~CSplashView()
{
  if (iContainer)
  {
    AppUi()->RemoveFromViewStack(*this, iContainer);
  }

  delete iContainer;
}

CSplashView *CSplashView::NewL()
{
  CSplashView *self = CSplashView::NewLC();
  CleanupStack::Pop(self);
  return self;
}

CSplashView *CSplashView::NewLC()
{
  CSplashView *self = new(ELeave)CSplashView();
  CleanupStack::PushL(self);
  self->ConstructL();
  return self;
}

TUid CSplashView::Id()const
{
  return KSplashViewId;
}


void CSplashView::HandleCommandL(TInt aCommand)
{
  switch (aCommand)
  {
    case EAknSoftkeyBack:
      {
        AppUi()->HandleCommandL(EEikCmdExit);
        break;
      }
    case ESamCmdCamera:
      {
        TUid viewId;
        viewId.iUid = ECamView;
        AppUi()->ActivateLocalViewL(viewId);
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

void CSplashView::HandleClientRectChange()
{
  if (iContainer)
  {
    iContainer->SetRect(ClientRect());
  }
}

void CSplashView::DoActivateL(const TVwsViewId & /*aPrevViewId*/, TUid
  /*aCustomMessageId*/, const TDesC8 & /*aCustomMessage*/)
{
  if (!iContainer)
  {
    iContainer = new(ELeave)CSplashContainer;
    iContainer->SetMopParent(this);
    iContainer->ConstructL(ClientRect());
    AppUi()->AddToStackL(*this, iContainer);
  }
}

void CSplashView::DoDeactivate()
{
  if (iContainer)
  {
    AppUi()->RemoveFromViewStack(*this, iContainer);
  }

  delete iContainer;
  iContainer = NULL;
}
