/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_PLAYABLE_CHARACTER_H__
#define __IS06_PLAYABLE_CHARACTER_H__

#include "../../include/3d/Character.h"

class PlayableCharacter : public Character
{
  public:
    PlayableCharacter(Camera* cam);

    void render();

    // Player moves
    void goLeft(f32 speed);
    void goRight(f32 speed);
    void goForward(f32 speed);
    void goBackward(f32 speed);

    // Gravity
    void fall(f32 factor);
    void raise();
    void jump();
    void setJumpDelta(f32 value);
    f32 getJumpDelta();
    f32 getJumpStrength();

    // Wall collisions
    void moveOpposite(const core::vector3df& normal);

    // Player control
    void toggleControl();
    bool hasControl();

  private:
    void updateCoords(f32 deltaU, f32 speed);

    Camera* linkedCam;

    bool controlable;
    f32 jumpDelta;
    f32 fallDelta;
    f32 gravity;
    f32 jumpStrength;
};

#endif
