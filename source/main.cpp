#include "keylog.h"
#include <ncurses.h>

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE); // Enable keypad for special keys like backspace
    refresh();

    keylog M;
    while (true) {
        int ch = getch();

        if (ch == 27) // Exit when Escape key is pressed
            break;
        else if (ch == KEY_BACKSPACE || ch == 127) { // Handle backspace
            M.Input('\b'); // '\b' represents the backspace character
            M.Input(' '); // Overwrite the character on the screen with a space
            refresh();
            move(getcury(stdscr), getcurx(stdscr) - 1); // Move cursor back one position
        } else {
            M.Input(ch); // Input other characters as usual
            refresh();
        }
    }
    endwin();

    M.Output();

    return 0;
}
