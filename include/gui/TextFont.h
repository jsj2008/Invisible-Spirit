/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_TEXT_FONT_H__
#define __IS06_TEXT_FONT_H__

#include "../enums/styles/FontStyle.h"

using namespace std;
using namespace irr;

class TextFont
{
  public:
    TextFont(FontStyle style);
    ~TextFont();

    video::SMaterial& getMaterial();
    u8& getCharOffset(u8 code);

  private:
    void readFontData(const core::stringc& dataFilePath);

    video::ITexture* fontTexture;
    video::SMaterial fontMaterial;
    u8 offset[256];
};

#endif
