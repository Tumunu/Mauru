/*
 *  Name:     RecorderAdapter.h
 *  Author:   Cleave Pokotea
 *  Www:      www.tumunu.com
 *  Project:  mauru
 */


#ifndef RECORDER_ADAPTER_H
#define RECORDER_ADAPTER_H

#include <MdaAudioTonePlayer.h>
#include <MdaAudioSamplePlayer.h>
#include <MdaAudioOutputStream.h>
#include <MdaAudioSampleEditor.h>
#include <mda\common\audio.h>

class CMMFMdaAudioRecorderUtility;
class CMdaAudioClipUtility;
class CSamAppUi;

// Recorder Observer
class MRecorderObserver
  {
    public:
      virtual void HandlePlayingStoppedL() = 0;
  };

// Recorder Adapter
class CRecorderAdapter : public CBase, public MMdaObjectStateChangeObserver
  {
    public:
      static CRecorderAdapter*  NewL();
      ~CRecorderAdapter();

    public:
      virtual void MoscoStateChangeEvent(CBase* aObject, TInt aPreviousState, TInt aCurrentState, TInt aErrorCode);

    public:
      void PlayL(const TDesC &aFileName);
      void PlayFinallyL();
      void StopL();
      void setVolumeLevel(TInt);
      void setPlayerVolume();
      void setTelyMode(TInt);

    public:
      CRecorderAdapter();

    private:
      void ConstructL();
    
	private:
      CMdaAudioRecorderUtility*  iMdaAudioRecorderUtility;
      TInt  iVolumeLevel;
      TInt  iTelyMode;

      enum TRecordingPhases
      {
        TNone,
        TBeginPlayingPhase,
        TPlayingGoingPhase,
        TPlayingStoppedPhase
      };

      TRecordingPhases			iRecPhase;
  };

#endif
