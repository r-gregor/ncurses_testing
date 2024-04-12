/*
 * ncrs_win_test_v01.c
 */

#include <stdio.h>
#include <string.h>
#include <ncurses.h>


int main(void) {

	/* NCURSES start */
	initscr();
	cbreak();
	// raw();
	noecho();

	/* window dims */
	int height   = 15;
	int width    = 60;
	int start_y  = 10;
	int start_x  = 10;
	int startl   =  1;

	/* create window */
	WINDOW *win1 = newwin(height, width, start_y, start_x);
	refresh();

	/* display window */
	box(win1, 0, 0); // first: char for left and right; second: char for top and bottom
	// wprintw(win1, "This is my box");
	mvwprintw(win1, 0, 1, "[ This is my box ]");
	mvwprintw(win1, startl, 1, "Trying to print 20 lines ...");

	for (int i = 1; i < 20; ++i) {
		if (startl + i == height - 1) break;
		mvwprintw(win1, startl + i, 1, "This is line %02d", i);
		wrefresh(win1);
	}
	wrefresh(win1);






	int c = getch();

	/* NCURSES stop */
	endwin();
	return 0;
}
