#ifndef WINDOW_H
#define WINDOW_H

#include <memory>
#include <string>

#include "Log.h"

class IWindow
{
public:
    virtual ~IWindow() {}

    virtual bool init(int xPos, int yPos, int width, int height, bool isFullscreen) = 0;
    virtual void logGlParams() = 0;
    //virtual bool should_close() = 0;
    //virtual void handle_close() = 0;
    virtual void updateFpsCounter(float dt) = 0;
    virtual void clearBuffer() = 0;
    virtual void swapBuffer() = 0;
    virtual void clean() = 0;

    static std::unique_ptr<IWindow> create(const std::string& title);
};

#endif
