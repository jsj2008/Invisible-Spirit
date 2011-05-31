/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"

using namespace irr;

// 0 = No Menu
// 1 = Main Menu
// 2 = Sub menu...

MapEditor::MapEditor() {
  active = false;
}

void MapEditor::events() {
  if(active) {

  }
}

void MapEditor::toggle() {
  if(active) {
    active = false;
  } else {
    active = true;
  }
}

bool MapEditor::isRunning() {
  return active;
}

MapEditor::~MapEditor() {

}
