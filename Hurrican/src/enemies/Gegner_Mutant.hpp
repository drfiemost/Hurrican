#ifndef _GEGNER_MUTANT_H
#define _GEGNER_MUTANT_H

#include "GegnerClass.hpp"
#include "enemies/Gegner_Stuff.hpp"

class GegnerMutant : public GegnerClass {
  private:
    float zRot;
    float JumpDelay;

  public:
    GegnerMutant(int Wert1,
                 int Wert2,  // Konstruktor
                 bool Light);
    void GegnerExplode() override;  // Gegner explodiert
    void DoKI() override;           // Gegner individuell mit seiner eigenen kleinen KI bewegen
};

#endif
