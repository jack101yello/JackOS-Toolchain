#include <graphics.h>

void enter_graphics_mode() {
    asm volatile(
        "int $0x80"
        :
        : "a"(ENTER_GRAPHICS_MODE)
    );
}

void exit_graphics_mode() {
    asm volatile(
        "int $0x80"
        :
        : "a"(EXIT_GRAPHICS_MODE)
    );
}

void put_pixel(int x, int y, enum COLOR_CODE color) {
    asm volatile(
        "int $0x80"
        :
        : "a"(PUT_PIXEL), "b"(x), "c"(y), "d"(color)
    );
}

void draw_frame() {
    asm volatile(
        "int $0x80"
        :
        : "a"(DRAW_FRAME)
    );
}

bool is_pressed(char key) {
    bool status;
    asm volatile(
        "int $0x80"
        : "=c"(status)
        : "a"(CHECK_KEY), "b"(key)
    );
    return status;
}

void swap_framebuffer(int* new_framebuffer) {
	asm volatile(
		"int $0x80"
		:
		: "a"(SWAP_FRAMEBUFFER), "b"(new_framebuffer)
	);
}
