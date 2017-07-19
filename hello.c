#include <stdio.h>
#include<stdlib.h>
#include <ncurses.h>
void exitProgram();
void initializeScreen();

int main() {
  initializeScreen();
  int screenX, screenY;
  getmaxyx(stdscr, screenX, screenY);
  int x, y;
  x = 0;
  y = 0;


  int i;
  for(i = 0; i < 100; i++) {
    clear();
    mvprintw(x, y, "Hello world! %i, %i", screenX, screenY);
    x = x + 2;
    y++;
    refresh();
    getch();
  }
  getch();
  exitProgram();
  return 0;
}

void initializeScreen() {
  initscr();
  cbreak();
  noecho();
  curs_set(0);
}

void exitProgram() {
  endwin();
}
