

#ifndef __VIZDOOM_UTILITIES_H__
#define __VIZDOOM_UTILITIES_H__

#include "ViZDoomConsts.h"
#include "ViZDoomTypes.h"
#include <vector>
#include <string>

namespace vizdoom {


    /* Time helpers */
    /*----------------------------------------------------------------------------------------------------------------*/

    double doomTicsToMs(double tics, unsigned int ticrate = DEFAULT_TICRATE);
    double msToDoomTics(double ms, unsigned int ticrate = DEFAULT_TICRATE);
    double doomTicsToSec(double tics, unsigned int ticrate = DEFAULT_TICRATE);
    double secToDoomTics(double sec, unsigned int ticrate = DEFAULT_TICRATE);


    /* DoomFixed helpers */
    /*----------------------------------------------------------------------------------------------------------------*/

    template<typename T>
    inline T doomFixedToReal(int fixed){
        return static_cast<T>(fixed) / 65536.0;
    }
    template<typename T, typename U>
    inline T doomFixedToReal(U fixed){
        return static_cast<T>(fixed) / 65536.0;
    }
    float doomFixedToFloat(int doomFixed);
    float doomFixedToFloat(float doomFixed);
    double doomFixedToDouble(int doomFixed);
    double doomFixedToDouble(double doomFixed);


    /* Types helpers */
    /*----------------------------------------------------------------------------------------------------------------*/

    std::string modeToString(Mode mode);
    std::string screenToString(ScreenFormat screenFormat);
    std::string automapModeToString(AutomapMode mode);
    std::string gameVariableToString(GameVariable gameVariable);
    std::string buttonToString(Button button);

    bool isBinaryButton(Button button);
    bool isDeltaButton(Button button);

    /* Category helpers */
    /*----------------------------------------------------------------------------------------------------------------*/

    std::vector<std::string> getDefaultCategories();

}

#endif
