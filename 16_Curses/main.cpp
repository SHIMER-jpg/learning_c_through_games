#include <iostream>
#include <curses.h>
#include <string>

using namespace std;

int main()
{
    // INIT AND OUTPUT
    initscr();       // init terminal in curses
    curs_set(false); // makes cursor invisble
    noecho();
    nodelay(stdscr, true); // removes freeze on get ch
    keypad(stdscr, true);
    // move(15, 10); first y then x
    // for (int x = 0; x < 10; x++)
    // {
    //     // move(x, x);
    //     // printw("x");
    //     const char *l = x + "a";
    //     mvprintw(x, x, l);
    // }
    int windowMaxY;
    int windowMaxX;
    getmaxyx(stdscr, windowMaxY, windowMaxX);
    mvprintw(windowMaxY / 2, windowMaxX / 2, "Hello World !!!"); // writes to a hidden window
    mvaddch('*', windowMaxY, windowMaxX);
    refresh();

    // input
    int fetched;
    while (fetched != KEY_DOWN)
    {
        fetched = getch();
        if (fetched)
        {
            printw("fetched something");
        }
        refresh();
    }
    endwin();

    return 0;
}
