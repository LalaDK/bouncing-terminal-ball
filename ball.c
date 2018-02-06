#include <stdio.h>
#include<stdlib.h>
#include <ncurses.h>
#include <unistd.h>

typedef struct Vectors {
  float x;
  float y;
} PVector;

void exitProgram();
void initializeScreen();
void initVector(PVector *target, float x, float y);
void addVector(PVector *target, PVector *vector);

int screenX, screenY;
PVector location, oldLocation, velocity, gravity;

int main() {
  initializeScreen();

  getmaxyx(stdscr, screenY, screenX);
  initVector(&location, screenX / 2, screenY / 5);
  initVector(&oldLocation, location.x, location.y);
  initVector(&velocity, 0.15, 0.0);
  initVector(&gravity, 0.0, 0.0003);
  addVector(&location, &velocity);

  /* Display title */
  attron(A_BOLD);
  mvprintw(5, (screenX / 2) - 7, "Mads' hoppebold");
  attroff(A_BOLD);

  while(true) {
    //clear();
    mvprintw(oldLocation.y, oldLocation.x, ".");
    oldLocation.y = location.y;
    oldLocation.x = location.x;
    attron(A_BOLD);
    mvprintw(location.y, location.x, "@");
    attroff(A_BOLD);
    refresh();
    usleep(3 * 1000);

    addVector(&location, &velocity);
    addVector(&location, &gravity);
    addVector(&velocity, &gravity);
    if(location.x > screenX || location.x < 0) {
      velocity.x = velocity.x * -1.0;
    }
    if(location.y > screenY) {
      velocity.y = velocity.y * -0.95;
    }

  }

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

void initVector(PVector *target, float x, float y) {
  (*target).x = x;
  (*target).y = y;
};

void addVector(PVector *target, PVector *vector) {
  (*target).x = (*target).x + (*vector).x;
  (*target).y = (*target).y + (*vector).y;
}
