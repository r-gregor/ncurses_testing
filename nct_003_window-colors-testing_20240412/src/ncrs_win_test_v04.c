/*
 * ncrs_win_test_v04.c
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
	int start_y  = 5;
	int start_x  = 10;
	int startl   =  1;
	int offset = 2;

	/* create window */
	WINDOW *win1 = newwin(height, width, start_y, start_x);
	printw("\n[ ");
	attron(A_REVERSE);
	printw("ncrs_win_test_v04.c");
	printw(" -- (test)");
	attroff(A_REVERSE);
	printw(" ]\n");
	refresh();

	/* display window */
	box(win1, 0, 0); // first: char for left and right; second: char for top and bottom
	// wprintw(win1, "This is my box");
	attron(A_REVERSE);
	mvwprintw(win1, 0, offset, "[ This is my box ]");
	attroff(A_REVERSE);
	int lst = 20;
	mvwprintw(win1, startl, offset, "Trying to print %d lines ...", lst);
	int fst = lst - (height - 2) + 1;
	for (int i = startl; i < height - 2; ++i) {
		int pos = fst + i;
		if (pos <= 0) {
			mvwprintw(win1, startl + i, offset, "");
			wrefresh(win1);
		} else {
			mvwprintw(win1, startl + i, offset, "This is line %02d", fst + i);
			wrefresh(win1);
		}
	}

	int down = 0;
	mvprintw(start_y + height + down, start_x + 1, "[INFO] Window width:  %02d", width); down++;
	mvprintw(start_y + height + down, start_x + 1, "[INFO] Window height: %02d", height); down++;
	wrefresh(win1);






	int c = getch();

	/* NCURSES stop */
	endwin();
	return 0;
}
