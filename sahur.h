#ifndef TUNGTUNG_LIBRARY_H
#define TUNGTUNG_LIBRARY_H
#include "constants.h"
#include "tung.h"
#include "cappuccina.h"

typedef struct Sahur {
    bool isRunning;

    Tung tungs[MAX_TUNG_COUNT];
    int tungCount;

    void (*cappuccinaListeners[MAX_CAPPUCCINA_LISTENERS])(CappuccinaEvent);
    int cappuccinaListenerCount;
} Sahur;

extern Sahur* const SAHUR;

#include "tung.h"

int initSahur();
void patapimLoop();

#endif //TUNGTUNG_LIBRARY_H
