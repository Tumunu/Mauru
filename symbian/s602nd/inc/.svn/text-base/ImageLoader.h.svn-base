/*
 *  Name:     CImageLoader from ImageLoader.h
 *  Author:   Cleave Pokotea
 *  Www:      www.tumunu.com
 *  Project:  mauru
 */

 
#ifndef IMAGE_LOADER_H
#define IMAGE_LOADER_H

// includes
#include <MdaImageConverter.h>

// declarations
class CFbsBitmap;
class CSamDiaryContainer;

// Image Loader
class CImageLoader : public CActive, public MMdaImageUtilObserver
  {
    public:
      enum TTextureLoadingError { KBadImageWidth = 1666001 };
      static CFbsBitmap*  LoadImageL(const TDesC &aFilename);

      // from MMdaImageUtilObserver
      virtual void MiuoOpenComplete(TInt aError);
      virtual void MiuoConvertComplete(TInt aError);
      virtual void MiuoCreateComplete(TInt aError);

      // from CActive
      void RunL();
      void DoCancel();

    private:
      CImageLoader(const TDesC *aFilename);
      ~CImageLoader();
      void ReadImageL();
      void CreateTexture();

      TDesC*  iFilename;
      CMdaImageFileToBitmapUtility*  iConverter;
      RTimer*  iTimer;
      CFbsBitmap*  iBitmap;
      TInt  iErrorCode;
  };

#endif
