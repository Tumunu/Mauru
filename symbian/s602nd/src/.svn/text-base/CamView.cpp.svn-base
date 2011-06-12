/*
 *  Name:     CCamView from CamView.cpp
 *  Author:   Cleave Pokotea
 *  Www:      www.tumunu.com
 *  Project:  mauru
 */


// includes
#include <aknviewappui.h>
#include <avkon.hrh>
#include "CamView.h"
#include "CamContainer.h"
#include <Mauru.rsg>
#include <Mauru.hrh>

// member functions
void CCamView::ConstructL()
{
  BaseConstructL(R_MAURU_CAM);
}

CCamView::~CCamView()
{
  if (iContainer)
  {
    AppUi()->RemoveFromViewStack(*this, iContainer);
  }

  delete iContainer;
}

CCamView *CCamView::NewL()
{
  CCamView *self = CCamView::NewLC();
  CleanupStack::Pop(self);
  return self;
}

CCamView *CCamView::NewLC()
{
  CCamView *self = new(ELeave)CCamView();
  CleanupStack::PushL(self);
  self->ConstructL();
  return self;
}

TUid CCamView::Id()const
{
  return KCamViewId;
}

void CCamView::HandleCommandL(TInt aCommand)
{
  switch (aCommand)
  {
    case EAknSoftkeyBack:
      {
        AppUi()->HandleCommandL(EEikCmdExit);
        break;
      }
    case ESamCmdSnap:
      {
        if (iContainer)
        {
          iContainer->CamCaptureL();
        }
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

void CCamView::HandleClientRectChange()
{
  if (iContainer)
  {
    iContainer->SetRect(ClientRect());
  }
}

void CCamView::DoActivateL(const TVwsViewId & /*aPrevViewId*/, TUid
  /*aCustomMessageId*/, const TDesC8 & /*aCustomMessage*/)
{
  if (!iContainer)
  {
    iContainer = new(ELeave)CCamContainer;
    iContainer->SetMopParent(this);
    iContainer->ConstructL(ClientRect());
    AppUi()->AddToStackL(*this, iContainer);
  }
}

void CCamView::DoDeactivate()
{
  if (iContainer)
  {
    AppUi()->RemoveFromViewStack(*this, iContainer);
  }

  delete iContainer;
  iContainer = NULL;
}
