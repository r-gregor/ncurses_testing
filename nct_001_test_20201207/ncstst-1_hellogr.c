#include <curses.h>

int main() {
	
	initscr();
	raw();
	printw("Hello World -- from Gregec!\n");
	getch();
	endwin();
	




	return 0;
}
