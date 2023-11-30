#include <ncurses.h>

int main()
{

	initscr();
	raw();
	int mynum = 22;
	printw("This is bog standard string output %d", mynum);
	addch('a');
	move(12, 13);
	mvprintw(15, 20, "Movement");
	mvaddch(12, 50, '@');
	getch();
	endwin();


	return 0;
}

