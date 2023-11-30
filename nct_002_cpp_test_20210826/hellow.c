#include <curses.h>

int main(int argc, char **argv) {
	initscr();

	int height, width, start_x, start_y;
	height = 10;
	width = 20;
	start_x = start_y = 10;

	printw("Hello World!\n");
	printw("Another line ...\n");

	// window
	WINDOW *win = newwin(height, width, start_y, start_x);
	refresh();

	box(win, 0, 0);
	mvwprintw(win, 1, 1, "I'm in the WIN!");
	wrefresh(win);

	refresh();
	int c = getchar();

	endwin();

	return 0;
}

