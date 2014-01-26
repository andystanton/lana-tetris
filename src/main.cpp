#include <cmath>
#include <ctime>
#include <queue>
#include <fstream>
#include <sstream>
#include <string>

#include <GLFW/glfw3.h>

#include "model/entity/tetris/World.h"

#include "drawing/foundation/Colour.h"
#include "drawing/foundation/Palette.h"
#include "drawing/GameplayDisplayer.h"
#include "drawing/UIDisplayer.h"

using namespace std;

enum GAME_STATE {
    MENU,
    PLAYING,
    PAUSED,
};

static GAME_STATE state = MENU;

static const GLint width = 660;
static const GLint height = 660;

World* world;

GameplayDisplayer* gameplayDisplayer;
UIDisplayer* uiDisplayer;

static void draw(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    switch(state) {
        case MENU: {
            uiDisplayer->drawStartScreen();
            break;
        }
        case PAUSED:
        case PLAYING: {
            uiDisplayer->drawGameplayScreen(world);
            gameplayDisplayer->drawWorld(world);
            break;
        }
    }
}

void key(GLFWwindow* window, int k, int scancode, int action, int mods) {
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        switch (k) {
            case GLFW_KEY_1:
                world->resetTet('I');
                break;
            case GLFW_KEY_2:
                world->resetTet('O');
                break;
            case GLFW_KEY_3:
                world->resetTet('T');
                break;
            case GLFW_KEY_4:
                world->resetTet('J');
                break;
            case GLFW_KEY_5:
                world->resetTet('L');
                break;
            case GLFW_KEY_6:
                world->resetTet('S');
                break;
            case GLFW_KEY_7:
                world->resetTet('Z');
                break;
            case GLFW_KEY_8:
                world->resetTet('D');
                break;
            case GLFW_KEY_Q:
                world->setMode(World::PlayMode::REGULAR_MODE);
                world->start();
                break;
            case GLFW_KEY_W:
                world->setMode(World::PlayMode::FROZEN_MODE);
                world->start();
                break;
            case GLFW_KEY_E:
                world->setMode(World::PlayMode::INFINITY_MODE);
                world->start();
                break;
            case GLFW_KEY_P:
                cout << *world->getActiveTet()->toString() << endl;
                break;
            case GLFW_KEY_A:
                world->rotateLeft();
                break;
            case GLFW_KEY_S:
                world->rotateRight();
                break;
            case GLFW_KEY_R:
                world->resetTet(nullptr);
                break;
            case GLFW_KEY_LEFT:
                world->moveLeft();
                break;
            case GLFW_KEY_RIGHT:
                world->moveRight();
                break;
            case GLFW_KEY_UP:
                world->moveUp();
                break;
            case GLFW_KEY_DOWN:
                world->moveDown();
                break;
            case GLFW_KEY_SPACE:
                if (state == MENU) {
                    state = PLAYING;
                } else if (state == PLAYING) {
                    state = PAUSED;
                } else if (state == PAUSED) {
                    state = PLAYING;
                }
                break;
            case GLFW_KEY_EQUAL:
                world->increaseSpeed();
                break;
            case GLFW_KEY_MINUS:
                world->decreaseSpeed();
                break;
            case GLFW_KEY_ESCAPE:
                break;
            default:
                return;
        }
    }
}

static void init(int argc, char *argv[]) {
    gameplayDisplayer = GameplayDisplayer::getInstance();
    uiDisplayer = UIDisplayer::getInstance(width, height);

    world = new World(new Vec2d(10, 20), World::PlayMode::REGULAR_MODE);
    world->start();

    Colour* bgColour = Palette::getInstance()->getColour(Palette::NAVY);
    
    glClearColor(bgColour->getR(), bgColour->getG(), bgColour->getB(), 0);
    glEnable(GL_BLEND);
    glDisable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    delete bgColour;
    bgColour = nullptr;
}


void reshape(GLFWwindow* window, int width, int height ) {
    int w, h;
    glfwGetFramebufferSize(window, &w, &h);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION );
    glLoadIdentity();
    glOrtho(0, width, height, 0, 0, 1);
    glMatrixMode(GL_MODELVIEW );
    glLoadIdentity();
}

void cleanup() {
    delete world;
    world = nullptr;
    
    delete uiDisplayer;
    uiDisplayer = nullptr;
    
    delete gameplayDisplayer;
    gameplayDisplayer = nullptr;
}

int main(int argc, char *argv[]) {
    srand((int) time(0));

    GLFWwindow* window;

    if(!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n" );
        exit(EXIT_FAILURE );
    }
    
    window = glfwCreateWindow(width, height, "lanaTetris", nullptr, nullptr);
    
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    if(!window) {
        fprintf(stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit(EXIT_FAILURE );
    }
    
    glfwMakeContextCurrent(window);
    reshape(window, width, height);
    
    init(argc, argv);
    
    glfwSetWindowSizeCallback(window, reshape);
    glfwSetKeyCallback(window, key);
    
    while (!glfwWindowShouldClose(window)) {
        draw();
        if (state == PLAYING) {
            if (!world->tick(glfwGetTime())) state = MENU;
        }
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    cleanup();
    
    glfwTerminate();
    
    exit(EXIT_SUCCESS);
}

