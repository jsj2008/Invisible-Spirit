/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MENU_OPTION_H__
#define __IS06_MENU_OPTION_H__

class MenuOption : public Hud {
  public:
    MenuOption(MenuIcon icon, const core::stringw& title);
    virtual ~MenuOption();

    virtual void render();

    void setVisible(bool isVisible);
    void setHover(bool isHover);
    void setEnabled(bool isEnabled);
    void setSelectable(bool isSelectable);

  protected:
    core::stringw currentTitle;
    MenuIcon currentIcon;

    bool hover;
    bool enabled;
    bool visible;
    bool selectable;
};

#endif