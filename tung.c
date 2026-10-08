#include "tung.h"
#include <GLFW/glfw3.h>
#include "sahur.h"
#include "cappuccina.h"

ReturnTung newTung(char* tungTitle, int width, int height) {
    if (SAHUR->tungCount >= MAX_TUNG_COUNT)
        return (ReturnTung){.tung = {}, .isValid = false};

    GLFWwindow* window = glfwCreateWindow(width, height, tungTitle, NULL, NULL);
    if (!window) {
        glfwTerminate();
        return (ReturnTung){.tung = {}, .isValid = false};
    }

    SAHUR->tungs[SAHUR->tungCount++] = (Tung){
        .window = window
    };
    glfwSetKeyCallback(window, _sahurCappuccinaListener);
};

void destoryTung(Tung* tung) {
    tung->shouldClose = true;
};

Tung* getTungByGLFWWindow(GLFWwindow const* win) {
    for (int i = 0; i < SAHUR->tungCount; i++) {
        Tung* tung = &SAHUR->tungs[i];
        if (tung->window == win) {
            return tung;
        }
    }
    return NULL;
}