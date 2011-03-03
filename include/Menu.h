/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MENU_H__
#define __IS06_MENU_H__

using namespace std;
using namespace irr;

class Menu : public Hud {
  public:
    Menu(f32 x, f32 y, f32 width, u8 height);
    virtual ~Menu();

    virtual void render();

    void addOption(const MenuOption& option);
    void addOption(MenuIcon icon, const core::stringw& title);
    void removeOption(u16 index);
    MenuOption& getOption(u16 index);

    void nextOption();
    void prevOption();
    void firstOption();
    void lastOption();

  protected:
    map<u16, MenuOption> options;
    map<u16, MenuOption>::iterator optionsIt;
    u16 lastInsertedIndex;
    u16 defaultOption;
    u16 currentOption;

    core::position2df pos;
    f32 currentWidth;
    u8 currentHeight;

    bool loopMode;
};

#endif