/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/core.h"

using namespace irr;
using namespace std;

/**
 * Initialise la caméra TP et lui affecte des propriétés par défaut
 */
TPCamera::TPCamera() : Camera() {
  UAxis = (3 * core::PI) / 2;
  height = 1.8f;
  distance = 4.0f;
}

/**
 * Associe une entité Ayron à la caméra
 * @param Ayron* entity pointeur vers une entité Ayron
 * @todo Pouvoir associer n'importe quelle entité à une caméra
 */
void TPCamera::linkEntity(Ayron* entity) {
  linkedEntity = entity;
}

/**
 * Fonction de mise à jour et de rendu de la caméra TP
 * Elle permet de positionner la caméra par rapport au node associé en fonction
 * des propriétés variables par le joueur (déplacement le long du cercle trigonométrique)
 */
void TPCamera::render() { Camera::render();
  f32 x = linkedEntity->getNode()->getPosition().X + distance * cos(UAxis);
  f32 z = linkedEntity->getNode()->getPosition().Z + distance * sin(UAxis);

  irrCam->setTarget(core::vector3df(
    linkedEntity->getNode()->getPosition().X,
    linkedEntity->getNode()->getPosition().Y + 0.8,
    linkedEntity->getNode()->getPosition().Z
  ));
  irrCam->setPosition(core::vector3df(
    x,
    linkedEntity->getNode()->getPosition().Y + height,
    z
  ));

  cout << height << endl;
}

/**
 *
 */
void TPCamera::goLeft(s8 speed) {
  UAxis -= ((speed - 25) / 1500.0f);
  if(UAxis < 0) {
    UAxis = 2 * core::PI;
  }
}

/**
 *
 */
void TPCamera::goRight(s8 speed) {
  UAxis += ((speed - 25) / 1500.0f);
  if(UAxis > (2 * core::PI)) {
    UAxis = 0;
  }
}

/**
 *
 */
void TPCamera::goFar(s8 speed) {
  if(height < 3.3) {
    height += ((speed - 25) / 750.0f);
  }
  if(height > 3.3) {
    height = 3.3;
  }
  if(distance < 5.5) {
    distance += ((speed - 25) / 750.0f);
  } else {
    distance = 5.5;
  }
}

/**
 *
 */
void TPCamera::goNear(s8 speed) {
  if(height > 0.3) {
    height -= ((speed - 25) / 750.0f);
  }
  if(height < 0.3) {
    height = 0.3;
  }
  if(distance > 2.5) {
    distance -= ((speed - 25) / 750.0f);
  } else {
    distance = 2.5;
  }
}

/**
 *
 */
f32 TPCamera::getDistance() {
  return distance;
}
