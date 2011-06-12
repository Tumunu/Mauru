/*
 *  Name:     CRecorderAdapter from RecorderAdapter.h
 *  Author:   Cleave Pokotea
 *  Www:      www.tumunu.com
 *  Project:  mauru
 */


// includes
#include <eikenv.h>
#include <stringloader.h>
#include <barsread.h>
#include <aknutils.h>
#include <MdaAudioSampleEditor.h>
#include <aknquerydialog.h>
#include <aknnotewrappers.h>
#include <aknmessagequerydialog.h>
#include "RecorderAdapter.h"
#include <Mauru.rsg>
#include "Mauru.loc"

// member functions
CRecorderAdapter::CRecorderAdapter(){}

CRecorderAdapter::~CRecorderAdapter()
{
  delete iMdaAudioRecorderUtility;
  iMdaAudioRecorderUtility = NULL;
}

CRecorderAdapter *CRecorderAdapter::NewL()
{
  CRecorderAdapter *self = new(ELeave)CRecorderAdapter();
  CleanupStack::PushL(self);
  self->ConstructL();
  CleanupStack::Pop(self);
  return self;
}

void CRecorderAdapter::ConstructL()
{
  iMdaAudioRecorderUtility = CMdaAudioRecorderUtility::NewL(*this, NULL, 80,
    EMdaPriorityPreferenceTime);
  iRecPhase = TNone;
  iTelyMode = 3;
}

void CRecorderAdapter::PlayL(const TDesC &aFileName)
{
  if (iRecPhase == TPlayingGoingPhase)
  {
    iMdaAudioRecorderUtility->Stop();
    iMdaAudioRecorderUtility->Close();
  }

  iRecPhase = TBeginPlayingPhase;
  TInt err;

  TRAP(err, iMdaAudioRecorderUtility->OpenFileL(aFileName));
}

void CRecorderAdapter::PlayFinallyL()
{
  iRecPhase = TPlayingGoingPhase;

  switch (iTelyMode)
  {
    case 0:
      {
        iMdaAudioRecorderUtility->SetAudioDeviceMode(CMdaAudioRecorderUtility
          ::EDefault);
        break;
      }
    case 1:
      {
        iMdaAudioRecorderUtility->SetAudioDeviceMode(CMdaAudioRecorderUtility
          ::ETelephonyOrLocal);
        break;
      }
    case 2:
      {
        iMdaAudioRecorderUtility->SetAudioDeviceMode(CMdaAudioRecorderUtility
          ::ETelephonyMixed);
        break;
      }
    case 3:
      {
        iMdaAudioRecorderUtility->SetAudioDeviceMode(CMdaAudioRecorderUtility
          ::ETelephonyNonMixed);
        break;
      }
    case 4:
      {
        iMdaAudioRecorderUtility->SetAudioDeviceMode(CMdaAudioRecorderUtility
          ::ELocal);
        break;
      }
  }

  iMdaAudioRecorderUtility->SetVolume(iMdaAudioRecorderUtility->MaxVolume());
  iMdaAudioRecorderUtility->SetPosition(TTimeIntervalMicroSeconds(0));
  iMdaAudioRecorderUtility->PlayL();
}

void CRecorderAdapter::StopL()
{
  iMdaAudioRecorderUtility->Stop();
  iMdaAudioRecorderUtility->Close();

  iRecPhase = TPlayingStoppedPhase;
}

void CRecorderAdapter::MoscoStateChangeEvent(CBase * /*aObject*/, TInt
  aPreviousState, TInt aCurrentState, TInt aErrorCode)
{
  switch (iMdaAudioRecorderUtility->State())
  {
    case CMdaAudioRecorderUtility::EOpen: 
    {
      switch (iRecPhase)
      {
        case TBeginPlayingPhase:
          {
            PlayFinallyL();
            break;
          }
        case TPlayingGoingPhase:
          {
            break;
          }
        default:
          break;
        }
        break;
      }
      case CMdaAudioRecorderUtility::EPlaying: 
      {
        break;
      }
      case CMdaAudioRecorderUtility::ENotReady: break;
    default:
      break;
  }
}

void CRecorderAdapter::setVolumeLevel(TInt sMode)
{
  iVolumeLevel = sMode;
}

void CRecorderAdapter::setTelyMode(TInt tMode)
{
  iTelyMode = tMode;
}
