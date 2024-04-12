/*
 * ncrs_win_test_v05.c
 */

#include <stdio.h>
#include <string.h>
#include <ncurses.h>

#define COLOR_BROWN_BG 22
#define COLOR_SMOKE_FG 33

int make_nlrc(int RGB);
void init_new_colour(int COLOR_NAME, int R, int G, int B);

int main(void) {

	/* NCURSES start */
	initscr();
	cbreak();
	noecho();

	/* window dims */
	int height   = 16;
	int width    = 60;
	int start_y  = 4;
	int start_x  = 10;
	int offset   =  2;
	int lst      = 20;

	/* create window */
	WINDOW *win1 = newwin(height, width, start_y, start_x);

	/* v5 */
	if(!has_colors()) {
		printw("Terminal does NOT support colors\n");
		getch();
		return -1;
	} else {
		start_color();
	}

	init_new_colour(COLOR_SMOKE_FG, 38, 149, 235);
	init_new_colour(COLOR_BROWN_BG, 130, 46, 7);
	init_pair(1, COLOR_SMOKE_FG, COLOR_BROWN_BG);
	
	printw("[");
	attron(COLOR_PAIR(1));
	printw("ncrs_win_test_v04.c");
	printw(" -- (test)");
	attroff(COLOR_PAIR(1));
	printw("]\n");
	refresh();

	/* display window */
	printw("\n%10sTrying to print %d lines inside my_box ...\n"," ", lst);
	box(win1, 0, 0); // first: char for left and right; second: char for top and bottom
	mvwprintw(win1, 0, offset, "[");
	wattron(win1, A_REVERSE);
	wprintw(win1, "This is my_box");
	wattroff(win1, A_REVERSE);
	wprintw(win1, "]");
	int fst = lst - (height - 2) + 1;
	for (int i = 0; i < height - 2; ++i) {
		int pos = fst + i;
		if (pos <= 0) {
			continue;
			// mvwprintw(win1, startl + i, offset, "");
			// wrefresh(win1);
		} else {
			mvwprintw(win1, i + 1, offset, "This is line %02d", fst + i);
			wrefresh(win1);
		}
	}

	int down = 0;
	mvprintw(start_y + height + down, start_x + 1, "[INFO] Window width:  %02d", width); down++;
	mvprintw(start_y + height + down, start_x + 1, "[INFO] Window height: %02d", height); down++;
	wrefresh(win1);

	getch();

	/* NCURSES stop */
	endwin();
	return 0;
} // END MAIN


	/*
	 * have to convert R,G,B from 0-255 to 0-999
	 */
int make_nlrc(int RGB) {
	return (int)(RGB/255.0*999);
}

void init_new_colour(int COLOR_NAME, int R, int G, int B) {
	init_color(COLOR_NAME, make_nlrc(R), make_nlrc(G), make_nlrc(B));
}

