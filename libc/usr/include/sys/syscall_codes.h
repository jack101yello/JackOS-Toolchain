#ifndef __syscall_codes_H
#define __syscall_codes_H

enum syscall_label {
    PRINT = 0x0,
    ENTER_GRAPHICS_MODE = 0x1,
    EXIT_GRAPHICS_MODE = 0x2,
    CHECK_KEY = 0x3,
    PRINT_ADDR = 0x4,
    QUIT = 0x5,
    PUT_PIXEL = 0x6,
    DRAW_FRAME = 0x7
};

#endif