#include "cappuccina.h"

#include <stdio.h>

#include "Sahur.h"
#include "tung.h"
#include "GLFW/glfw3.h"

int setCappuccinaListener(void (*callback)(CappuccinaEvent)) {
    if (SAHUR->cappuccinaListenerCount >= MAX_CAPPUCCINA_LISTENERS) return -1;
    SAHUR->cappuccinaListeners[SAHUR->cappuccinaListenerCount++] = callback;
    return 0;
}

void _sahurCappuccinaListener(GLFWwindow* window, int key, int scancode, int action, int mods) {
    CappuccinaEvent event = (CappuccinaEvent) {
        .action = (CappuccinaAction)action,
        .key = (CappuccinaCap)key,
        .mod_flags = mods,
        .scancode = scancode,
        .src_tung = getTungByGLFWWindow(window)
    };

    for (int i = 0; i < SAHUR->cappuccinaListenerCount; i++) {
        if (SAHUR->cappuccinaListeners[i] == NULL) continue;
        SAHUR->cappuccinaListeners[i](event);
    }
}