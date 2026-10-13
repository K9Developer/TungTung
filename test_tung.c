#include <stdio.h>

#include "Sahur.h"

void onCappuccina(CappuccinaEvent event) {
    if (event.action == PRESS) {
        printf("On window named \"%s\" a key (%i) was pressed!\n", glfwGetWindowTitle(event.src_tung->window), event.key);
        if (event.key == CAP_SPACE) {
            newTung("Tung Tung", 50, 50);
        }
    }
}

int main() {
    if (initSahur()) return -1;
    ReturnTung tung = newTung("Tung Tung1", 400, 600);
    if (tung.isValid == false) {
        printf("Failed to create tung.\n");
        return -1;
    }

    setCappuccinaListener(onCappuccina);
    patapimLoop();
    return 0;
}