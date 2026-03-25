#ifndef __VIZDOOM_CONSTS_H__
#define __VIZDOOM_CONSTS_H__

namespace vizdoom{

    const unsigned int SLOT_COUNT = 10;
    const unsigned int MAX_PLAYERS = 16;
    const unsigned int MAX_NAME_LENGTH = 128;
    const unsigned int MAX_PLAYER_NAME_LENGTH = MAX_NAME_LENGTH;
    const unsigned int USER_VARIABLE_COUNT = 60;
    const unsigned int DEFAULT_TICRATE = 35;
    const unsigned int DEFAULT_FPS = DEFAULT_TICRATE;
    const double DEFAULT_FRAMETIME_S = 1.0 / DEFAULT_TICRATE;
    const double DEFAULT_FRAMETIME_MS = DEFAULT_FRAMETIME_S * 1000;

    const unsigned int BINARY_BUTTON_COUNT = 38;
    const unsigned int DELTA_BUTTON_COUNT = 5;
    const unsigned int BUTTON_COUNT = 43;

    const int DEFAULT_SOUND_FREQ = 44100;
    const int DEFAULT_SAMPLES_TIC = DEFAULT_SOUND_FREQ / DEFAULT_TICRATE;
    const int SOUND_NUM_CHANNELS = 2;  // it is stereo by default

}
#endif
