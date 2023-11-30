#include <ncurses.h>

int main()
{
	initscr();
	raw();
	start_color();
	init_pair(1, COLOR_RED, COLOR_CYAN);
	attron(COLOR_PAIR(1));
	mvprintw(12, 40, "MY COLOURED NAME !!!");
	attroff(COLOR_PAIR(1));

	getch();
	endwin();

	return 0;
}
