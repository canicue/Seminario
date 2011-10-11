/*

El segundo ejemplo muestra en el centro de la pantalla una
serie de cadenas en varios colores distintos.

LINES tomara el valor del número de líneas de nuestro terminal
y COLS el número de columnas.

Ninguno de los cambios en la ventana de ncurses se hace efectivo
hasta que no se use la función refresh() momento en el que todos
se hacen visibles a la vez. Este diseño se hace para no ralentizar
demasiado las aplicaciones que usen ncurses.

ncurses supondrá que nuestro terminal es el que figura en la variable
TERM. Un valor de TERM que no corresponda a nuestro terminal provocará
seguramente un caos en la pantalla. En linux se usa TER='linux' derivado
y muy similar a 'vt100'.

*/

/****************************************************************
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#define NORMAL       0
#define BRILLO       1
#define SEMIBRILLO   2
#define INTERMITENTE 5
#define INVERSO      7
#define NEGRO       30
#define ROJO        31
#define VERDE       32
#define MARRON      33
#define AZUL        34
#define ROSA        35
#define CELESTE     36
#define BLANCO      37

#define MAXLINEAS 15
#define MAXCAD 70

WINDOW *win; /** manejaremos una única ventana de pantalla completa **/

/*********************************************************************/
void IniVideo(){
    win=initscr();
    clear();
    refresh();
    noecho();
    cbreak();
    keypad(win, TRUE);
    if(has_colors()) {
             start_color();
             init_pair(1, COLOR_YELLOW, COLOR_BLUE);
             init_pair(2, COLOR_BLACK, COLOR_RED);
             init_pair(3, COLOR_BLACK, COLOR_GREEN);
             init_pair(4, COLOR_WHITE, COLOR_RED);
             init_pair(5, COLOR_WHITE, COLOR_GREEN);
        }
}

/*************************/
Exit(){
        clear();
        refresh();
        endwin();
        exit(1);
}

/**************************************/
void Disp(){
  int posY, posX, i;

  posY=(LINES/2)-((2+MAXLINEAS)/2);
  posX=(COLS/2)-4;
  for (i=0; i<MAXLINEAS; i++){
    attrset(COLOR_PAIR(1+(i%5)));
    move(posY+i, posX);
    printw("%03d %03d %03d", i, i, i);
  }
  refresh();
}

/*****************************************************************/
main () {
    IniVideo();
    Disp();
    getch();
    Exit();
}
