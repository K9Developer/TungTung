#ifndef TUNG_H
#define TUNG_H
#include "GLFW/glfw3.h"

typedef struct {
    GLFWwindow* window;
    bool shouldClose;
} Tung;

typedef struct {
    Tung tung;
    bool isValid;
} ReturnTung;

ReturnTung newTung(char* tungTitle, int width, int height);
void destoryTung(Tung* tung);
Tung* getTungByGLFWWindow(GLFWwindow const* win);

#endif //TUNG_H
