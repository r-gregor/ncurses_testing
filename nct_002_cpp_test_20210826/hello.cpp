#include <curses.h>
using namespace std;

int main(int argc, char **argv) {
	initscr();
	printw("Hello World!\n");
	printw("Another line ...\n");

	refresh();
	getchar();

	endwin();

	return 0;
}

