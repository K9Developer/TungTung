#include "sahur.h"
#include "tung.h"
#include "constants.h"
#include <stdio.h>
#include <windows.h>
#include <process.h>
#include <time.h>
#include <unistd.h>
static Sahur SAHUR_p = {
    .tungs = {},
    .tungCount = 0,
    .isRunning = true
};
Sahur* const SAHUR = &SAHUR_p;

void renderTungs(Sahur* const* sahur) {
    for (int i = 0; i < (*sahur)->tungCount; i++) {
        Tung* tung = &SAHUR->tungs[i];
        glfwMakeContextCurrent(tung->window);
        if (!glfwWindowShouldClose(tung->window)) {
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(tung->window);
            glfwPollEvents();
        } else {
            glfwDestroyWindow(tung->window);
            tung->shouldClose = true;
        }
    }

    for (int i = 0; i < (*sahur)->tungCount; i++) {
        if ((*sahur)->tungs[i].shouldClose) {
            (*sahur)->tungs[i] = (*sahur)->tungs[--(*sahur)->tungCount];
            i--;
        }
    }
}

void sahurLoop(Sahur* const* sahur) {
    const double frameTime = 1.0 / SAHUR_FPS;

    while ((*sahur)->isRunning) {
        double start = glfwGetTime();

        renderTungs(sahur);

        double elapsed = glfwGetTime() - start;

        if (elapsed < frameTime) {
            usleep((useconds_t)((frameTime - elapsed) * 1000000.0));
        }
    }
}

int initSahur() {
    if (!glfwInit())
        return -1;

    return 0;
}

void patapimLoop() {
    HANDLE hThread;
    unsigned int threadID;
    //hThread = (HANDLE)_beginthreadex(NULL, 0, sahurLoop, &SAHUR, 0, &threadID);
    sahurLoop(&SAHUR);
}
