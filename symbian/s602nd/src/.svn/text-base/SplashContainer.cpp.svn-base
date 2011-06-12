/*
 *  Name:     CSplashContainer from SplashContainer.cpp
 *  Author:   Cleave Pokotea
 *  Www:      www.tumunu.com
 *  Project:  mauru
 */


// includes
#include <aknquerydialog.h>
#include <aknnotewrappers.h>
#include <aknmessagequerydialog.h>
#include <eiklabel.h>
#include "SplashContainer.h"
#include <Mauru.rsg>
#include <Mauru.hrh>
#include <Mauru.mbg>

_LIT(KDrawBitmapPath, "\\system\\apps\\mauru\\mauru.mbm");
const TInt KTopLeftX = 0;
const TInt KTopLeftY = 0;
const TInt KSizeWidth = 176;
const TInt KSizeHeight = 208;

// member functions
void CSplashContainer::ConstructL(const TRect &aRect)
{
  iBitmap = new(ELeave)CFbsBitmap();

  CreateWindowL();

  SetRect(aRect);
  SetExtentToWholeScreen();

  TFileName bitmapFile(KDrawBitmapPath);
  User::LeaveIfError(CompleteWithAppPath(bitmapFile));

  iLogoBitmap = new(ELeave)CFbsBitmap();
  User::LeaveIfError(iLogoBitmap->Load(bitmapFile, EMbmMauruSplash));

  ActivateL();
}

CSplashContainer::~CSplashContainer()
{
  delete iLogoBitmap;
  delete iBitmap;
}

void CSplashContainer::Draw(const TRect & /*aRect*/)const
{
  CWindowGc &gc = SystemGc();

  gc.SetBrushStyle(CGraphicsContext::ENullBrush);
  gc.SetBrushColor(KRgbBlack);
  gc.DrawRect(Rect());

  TPoint topLeft(KTopLeftX, KTopLeftY);
  TSize bitmapSize(KSizeWidth, KSizeHeight);
  gc.DrawBitmap(TRect(topLeft, bitmapSize), iLogoBitmap);
}
