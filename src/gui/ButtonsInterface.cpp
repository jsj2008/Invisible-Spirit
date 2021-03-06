/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/gui/ButtonsInterface.h"
#include "../../include/Game.h"
#include "../../include/gui/TextButton.h"
#include "../../include/gui/IconButton.h"
#include "../../include/gui/IconTextButton.h"

using namespace std;

ButtonsInterface::ButtonsInterface() : Hud()
{
  menu = new TextButton(Game::screenPos.left + 70, Game::screenPos.bottom + 110);
  defense = new IconButton(Game::screenPos.left + 30, Game::screenPos.bottom + 70);
  jump = new IconButton(Game::screenPos.left + 110, Game::screenPos.bottom + 70);
  command = new IconTextButton(Game::screenPos.left + 70, Game::screenPos.bottom + 30);
}

void ButtonsInterface::render()
{
  Hud::render();
  menu->render();
  defense->render();
  jump->render();
  command->render();
}

void ButtonsInterface::hide()
{
  menu->hide();
  defense->hide();
  jump->hide();
  command->hide();
}

void ButtonsInterface::show()
{
  menu->show();
  defense->show();
  jump->show();
  command->show();
}

void ButtonsInterface::setOpacity(u8 value)
{
  menu->setOpacity(value);
  defense->setOpacity(value);
  jump->setOpacity(value);
  command->setOpacity(value);
}

ButtonsInterface::~ButtonsInterface()
{
  delete menu;
  delete defense;
  delete jump;
  delete command;
}
