#include <graphics.h>

int main()
{
    int i = 200;
    int wd = initwindow(1600, 900, "Chakka not ghuring");

    setcurrentwindow(wd);

    // Peaceful
    for (i = 0; i < 4; i += 5) {
        // Road
        line(0, 325, 1600, 325);

        // Body of the vehicle
        line(200 + i, 300, 225 + i, 300);
        line(275 + i, 300, 375 + i, 300);
        line(425 + i, 300, 450 + i, 300);
        line(200 + i, 200, 200 + i, 300);
        line(400 + i, 200, 400 + i, 275);
        line(200 + i, 200, 400 + i, 200);

        // Wheels
        circle(400 + i, 300, 25);
        circle(250 + i, 300, 25);
        circle(400 + i, 300, 5);
        circle(250 + i, 300, 5);

        // Windows
        rectangle(325 + i, 225, 375 + i, 250);
        rectangle(225 + i, 225, 275 + i, 250);

        // Head of the vehicle
        line(450 + i, 250, 400 + i, 200);
        line(450 + i, 250, 450 + i, 300);
        line(450 + i, 250, 400 + i, 250);

        // Trees
        line(900, 325, 900, 200);
        circle(900, 200, 50);

        delay(50);

        cleardevice();
    }

    // After accident
    //for (i = 450; i < 800; i += 5) {
        // Road
        line(0, 325, 1600, 325);

        // Body of the vehicle
        line(200 + i, 200 + 25, 225 + i, 200 + 25);
        line(275 + i, 200 + 25, 375 + i, 200 + 25);
        line(425 + i, 200 + 25, 450 + i, 200 + 25);
        line(200 + i, 200 + 25, 200 + i, 300 + 25);
        line(400 + i, 225 + 25, 400 + i, 300 + 25);
        line(200 + i, 300 + 25, 400 + i, 300 + 25);

        // Wheels
        circle(400 + i, 200 + 25, 25);
        circle(250 + i, 200 + 25, 25);
        circle(400 + i, 200 + 25, 5);
        circle(250 + i, 200 + 25, 5);

        // Windows
        rectangle(325 + i, 225 + 25, 375 + i, 250 + 25);
        rectangle(225 + i, 225 + 25, 275 + i, 250 + 25);

        // Head of the vehicle
        line(450 + i, 250 + 25, 400 + i, 300 + 25);
        line(450 + i, 200 + 25, 450 + i, 250 + 25);
        line(450 + i, 250 + 25, 400 + i, 250 + 25);

        // Trees
        line(900, 325, 900, 200);
        circle(900, 200, 50);

        delay(50);

        //cleardevice();
    //}

    // Driver
//    circle(500, 500, 300);
//    circle(400, 400, 50);
//    circle(600, 600, 50);
//    line(300, 500, 500, 700);
//    arc(500, 500, 180, 270, 200);
//
//    // Hello
//    line(800, 200, 800, 300);
//    line(875, 200, 875, 300);
//    line(800, 250, 875, 250);
//
//    line(900, 200, 900, 300);
//    line(900, 200, 975, 200);
//    line(900, 250, 975, 250);
//    line(900, 300, 975, 300);
//
//    line(1000, 200, 1000, 300);
//    line(1000, 300, 1075, 300);
//    line(1100, 200, 1100, 300);
//    line(1100, 300, 1175, 300);
//
//    circle(1250, 250, 50); // Hello finished

    getch();

    closegraph();

    return 0;
}
