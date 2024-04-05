#include "keylog.cpp"
#include <ncurses.h>

int main() {
    initscr();
    cbreak();
    noecho();
    refresh();
    
    keylog M;
    while (true) {
        int ch = getch();

        if (ch == 27)
            break;

        M.Input(ch);
        refresh();
    }
    endwin();

    M.Output();

    return 0;
}
