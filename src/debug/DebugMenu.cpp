/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"

using namespace irr;
using namespace std;

DebugMenu::DebugMenu() {
  currentOption = 0;
  nextOptionID = 0;
  nextOptionY = 10;

  cout << "[DEBUG] New Menu" << endl;
}

void DebugMenu::events() {
  for(optionsIt = options.begin(); optionsIt != options.end(); optionsIt++) {
    optionsIt->second->events();
  }

  if(Game::getEventManager()->isKeyDownOnce(KEY_DOWN)) {
    nextOption();
  }
  if(Game::getEventManager()->isKeyDownOnce(KEY_UP)) {
    prevOption();
  }
  if(Game::getEventManager()->isKeyDownOnce(KEY_SPACE)) {
    enter();
  }
}

void DebugMenu::addOption(const core::stringc& text) {
  options[nextOptionID] = new DebugMenuOption(text, nextOptionY);
  if(nextOptionID == 0) {
    options[nextOptionID]->setSelected(true);
  }
  nextOptionID++;
  nextOptionY+= 12;
}

void DebugMenu::nextOption() {
  options[currentOption]->setSelected(false);
  currentOption++;
  if(currentOption >= options.size()) {
    currentOption = 0;
  }
  options[currentOption]->setSelected(true);
}

void DebugMenu::prevOption() {
  options[currentOption]->setSelected(false);
  currentOption--;
  if(currentOption <= -1) {
    currentOption = options.size() - 1;
  }
  options[currentOption]->setSelected(true);
}

void DebugMenu::enter() {

}

DebugMenu::~DebugMenu() {

}