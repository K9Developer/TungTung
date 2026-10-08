#include "tung.h"
#include <GLFW/glfw3.h>
#include "sahur.h"

ReturnTung newTung(char* tungTitle, int width, int height) {
    if (SAHUR->tungCount >= MAX_WINDOW_COUNT)
        return (ReturnTung){.tung = {}, .isValid = false};

    GLFWwindow* window = glfwCreateWindow(width, height, tungTitle, NULL, NULL);
    if (!window) {
        glfwTerminate();
        return (ReturnTung){.tung = {}, .isValid = false};
    }

    SAHUR->tungs[SAHUR->tungCount++] = (Tung){
        .window = window
    };
};

void destoryTung(Tung* tung);