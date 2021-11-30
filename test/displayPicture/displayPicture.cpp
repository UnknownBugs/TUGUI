#include <tugui.hpp>


#define IMG_WIDTH 100
#define IMG_HEIGHT 75

unsigned char img[] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                       0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

int tuguiMain() {
    TUGUI::Graphics g;
    // 偏移为(100,300)
    // 此处由于文件过大，所以使用假数据，假设图片宽度为100，高75，
    // img存放图片的raw数据，将img替换为RGB即可查看效果
    // 如果想查看具体图片效果，可将https://raw.githubusercontent.com/cupnes/bare_metal_uefi/master/043_graphic_image_blt/BOOTX64.c
    // 网站中的unsinged char img[]数据复制到上方img中
    g.tuguiblt(img, IMG_WIDTH, IMG_HEIGHT, 100, 300);

    while (true)
        ;
    return 0;
}