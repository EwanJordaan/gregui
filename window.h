#ifndef WINDOW_H
#define WINDOW_H

#pragma once

#include "gregui.h"
#include <windows.h>

struct gregui_window {
    wchar_t *title;
    greg::vector2 size;
    greg::vector2 position;
    uint16_t id;
    uint8_t style;
    HWND hwnd;

    gregui_window() : title(nullptr), size(0, 0), position(0, 0), id(1), style(0), hwnd(nullptr) {}
};

#endif //WINDOW_H
