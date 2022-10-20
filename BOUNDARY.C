#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void boundfill(int xc, int yc, int r, int b) {
    int cur;
    cur = getpixel(xc, yc);
    if (cur != b && cur != r) {
        putpixel(xc, yc, r);
        delay(1);

        boundfill(xc + 1, yc, r, b);
        boundfill(xc - 1, yc, r, b);
        boundfill(xc, yc + 1, r, b);
        boundfill(xc, yc - 1, r, b);
    }
}

void main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "..\\bgi");

	rectangle(50,50,100,100);
	boundfill(55,55,4,15);

    getch();
    closegraph();
}