/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SAVE_H__
#define __IS06_SAVE_H__

using namespace irr;
using namespace std;

class Save {
  public:
    Save();
    ~Save();

    void load();
    void write();
    void createNewFile();

    // General information
    u8 slot;

    // Map information
    SceneIdentifier currentMap;

    // Player information
    PlayerData playerData;
    PowerData powerData;
};

#endif
