#include "Sahur.h"

void onCappuccina() {

}

int main() {
    if (initSahur()) return -1;
    newTung("Tung Tung1", 400, 600);
    newTung("Tung Tung2", 500, 600);
    newTung("Tung Tung3", 600, 600);
    setCappuccinaListener(onCappuccina);
    patapimLoop();
    return 0;
}