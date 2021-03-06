/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SCENE_GAMEPLAY_H__
#define __IS06_SCENE_GAMEPLAY_H__

#include "../../include/scene/Scene.h"

using namespace irr;
using namespace std;

class SceneGameplay : public Scene
{
  public:
    SceneGameplay();
    virtual ~SceneGameplay();

    virtual void events();
    virtual void postRender();

  protected:
    PlayableCharacter* ayron;
    LevelMesh* level;

    GameplayInterface* gpInterface;
    EnergyInterface* enInterface;
    GameplayMenu* gpMenu;

  private:
    void manageCameraControl();
    void manageCharacterJumps();
    void manageCharacterMovements();
    void manageCharacterCollisions();
    void manageMenuControl();
};

#endif
