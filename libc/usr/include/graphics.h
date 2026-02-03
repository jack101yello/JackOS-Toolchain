#ifndef __graphics_H
#define __graphics_H

#include <sys/syscall_codes.h>
#include <stdbool.h>

enum COLOR_CODE {
    BLACK = 0x00,
    BLUE = 0x01,
    GREEN = 0x02,
    CYAN = 0x03,
    RED = 0x04,
    WHITE = 0x3F
};

#ifdef __cplusplus
extern "C" {
#endif

void enter_graphics_mode();
void exit_graphics_mode();
void put_pixel(int, int, enum COLOR_CODE color);
void draw_frame();
bool is_pressed(char);

#ifdef __cplusplus
}
#endif

#endif