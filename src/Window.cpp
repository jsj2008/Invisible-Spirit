/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/core.h"

using namespace irr;
using namespace std;

Window::Window(f32 w, f32 h, f32 x, f32 y, f32 borderWidth, WindowStyle style) : Hud() {
  pos = core::position2df(x, y);
  size = core::dimension2df(w, h);

  f32 sideW = w - borderWidth;
  f32 sideH = h - borderWidth;
  f32 sideWMin = x + (w / 2) * -1;
  f32 sideWMax = x + (w / 2);
  f32 sideHMin = y + (h / 2) * -1;
  f32 sideHMax = y + (h / 2);

  cornerTL = new Picture(borderWidth, borderWidth, sideWMin, sideHMin, "resource/hud/menu/window1.bmp");
  cornerTR = new Picture(borderWidth, borderWidth, sideWMax, sideHMin, "resource/hud/menu/window1.bmp");
  cornerBL = new Picture(borderWidth, borderWidth, sideWMin, sideHMax, "resource/hud/menu/window1.bmp");
  cornerBR = new Picture(borderWidth, borderWidth, sideWMax, sideHMax, "resource/hud/menu/window1.bmp");

  cornerBL->setTextureOffset(core::vector2df(0.0f, 0.0f), core::vector2df(0.0625f, 0.0625f));
  cornerBR->setTextureOffset(core::vector2df(0.9375f, 0.0f), core::vector2df(1.0f, 0.0625f));
  cornerTL->setTextureOffset(core::vector2df(0.0f, 0.9375f), core::vector2df(0.0625f, 1.0f));
  cornerTR->setTextureOffset(core::vector2df(0.9375f, 0.9375f), core::vector2df(1.0f, 1.0f));

  sideTop = new Picture(sideW, borderWidth, x, sideHMax, "resource/hud/menu/window1.bmp");
  sideLeft = new Picture(borderWidth, sideH, sideWMin, y, "resource/hud/menu/window1.bmp");
  sideRight = new Picture(borderWidth, sideH, sideWMax, y, "resource/hud/menu/window1.bmp");
  sideBottom = new Picture(sideW, borderWidth, x, sideHMin, "resource/hud/menu/window1.bmp");

  sideTop->setTextureOffset(core::vector2df(0.0625f, 0.0f), core::vector2df(0.9375f, 0.0625f));
  sideLeft->setTextureOffset(core::vector2df(0.0f, 0.0625f), core::vector2df(0.0625f, 0.9375f));
  sideRight->setTextureOffset(core::vector2df(0.9375f, 0.0625f), core::vector2df(1.0f, 0.9375f));
  sideBottom->setTextureOffset(core::vector2df(0.0625f, 0.9375f), core::vector2df(0.9375f, 1.0f));

  center = new Picture(sideW, sideH, x, y, "resource/hud/menu/window1.bmp");
  center->setTextureOffset(core::vector2df(0.0625f, 0.0625f), core::vector2df(0.9375f, 0.9375f));
}

void Window::render() { Hud::render();
  cornerTL->render();
  cornerTR->render();
  cornerBL->render();
  cornerBR->render();
  sideTop->render();
  sideLeft->render();
  sideRight->render();
  sideBottom->render();
  center->render();
}

Window::~Window() {
  delete cornerTL;
  delete cornerTR;
  delete cornerBL;
  delete cornerBR;
  delete sideTop;
  delete sideLeft;
  delete sideRight;
  delete sideBottom;
  delete center;
}
