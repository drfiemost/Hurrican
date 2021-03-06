#ifndef _GEGNER_SMALLWESPE_HPP_
#define _GEGNER_SMALLWESPE_HPP_

#include "GegnerClass.hpp"
#include "enemies/Gegner_Stuff.hpp"

class GegnerSmallWespe : public GegnerClass {
  public:
    GegnerSmallWespe(int Wert1,
                     int Wert2,  // Konstruktor
                     bool Light);
    void GegnerExplode() override;  // Gegner explodiert
    void DoKI() override;           // Gegner individuell mit seiner eigenen kleinen KI bewegen
};

#endif
