/*
 *  Name:     CImageLoader from ImageLoader.cpp
 *  Author:   Cleave Pokotea
 *  Www:      www.tumunu.com
 *  Project:  mauru
 */


// includes
#include <e32base.h>
#include <aknapp.h>
#include <akndoc.h>
#include <aknviewappui.h>
#include <aknview.h>
#include <eikenv.h>
#include <mdaimageconverter.h>
#include <f32file.h>
#include "ImageLoader.h"
#include "Mauru.hrh"
#include <Mauru.rsg> 

// constants
#define IMAGEREAD_TIMEOUT 5 * 1000 * 1000

// member functions
void CImageLoader::DoCancel()
{
  // cancel the timer    
  iTimer->Cancel();
  iTimer->Close();

  // end blocking in ReadTextureL()
  CActiveScheduler::Stop();
}

void CImageLoader::RunL()
{
  // timer timeout - loading failed
  Cancel();
  iTimer->Close();
}

CFbsBitmap *CImageLoader::LoadImageL(const TDesC &aFilename)
{
  // construct new loader instance
  CImageLoader *loader = new(ELeave)CImageLoader(&aFilename);
  CleanupStack::PushL(loader);

  // add the loader to active scheduler
  CActiveScheduler::Add(loader);

  // perform operations for reading and converting the image
  loader->ReadImageL();

  // start a nested scheduling; blocks until CActiveScheduler::Stop()
  // is called in DoCancel()
  CActiveScheduler::Start();

  // if error, leave with correct error code
  if (loader->iBitmap == NULL)
  {
    // instance will be destroyed by the cleanupstack
    User::Leave(loader->iErrorCode);
  }

  // get a local copy of the instance's created texture
  // if error(s) in process, this will be NULL
  CFbsBitmap *bitmap = loader->iBitmap;
  //  CTexture *texture = loader->iTexture;

  // deallocate the instance
  CleanupStack::PopAndDestroy();

  // return the created texture
  return bitmap;
}

CImageLoader::CImageLoader(const TDesC *aFilename): CActive(CActive
  ::EPriorityStandard)
{
  // make a local copy of the filename
  iFilename = aFilename->Alloc();
}

CImageLoader::~CImageLoader()
{
  // deallocate all data
  delete iFilename;
  delete iTimer;
  delete iConverter;
  //  delete iBitmap;
}

// performs the actual reading and conversion of the image
void CImageLoader::ReadImageL()
{
  // reset the texture
  //  iTexture = NULL;

  // create + initialize operation timeout timer
  iTimer = new RTimer();
  iTimer->CreateLocal();

  // set timeout for the image read + conversion process
  iTimer->After(iStatus, IMAGEREAD_TIMEOUT);
  SetActive();

  // start loading the image
  iConverter = CMdaImageFileToBitmapUtility::NewL(*this);
  iConverter->OpenL(*iFilename);
}

// called when OpenL() finishes
void CImageLoader::MiuoOpenComplete(TInt aError)
{
  if (aError != KErrNone)
  {
    iErrorCode = aError;
    Cancel();
    return ;
  }

  TFrameInfo info;
  iConverter->FrameInfo(0, info);

  // create a bitmap to write into
  iBitmap = new(ELeave)CFbsBitmap();
  TInt rc = iBitmap->Create(info.iOverallSizeInPixels, EColor16M); //EGray256);
  if (rc != KErrNone)
  {
    iErrorCode = rc;
    Cancel();
    return ;
  }

  // convert the gif into a bitmap
  TRAPD(error, iConverter->ConvertL(*iBitmap));

  // handle the error
  if (error != KErrNone)
  {
    iErrorCode = error;
    Cancel();
    return ;
  }
}

// called when ConvertL() finishes
void CImageLoader::MiuoConvertComplete(TInt aError)
{
  if (aError != KErrNone)
  {
    iErrorCode = aError;
    Cancel();
    return ;
  }
  Cancel();
}

void CImageLoader::MiuoCreateComplete(TInt /*aError*/){}
