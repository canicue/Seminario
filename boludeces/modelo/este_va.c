#include <panel.h>
#define NLINES 10
#define NCOLS 40
void init_wins (WINDOW ** wins, int n);
void mostrar_ventana (WINDOW * win, char *label, int label_color);
void imprimir_centrao (WINDOW * win, int starty, int startx, int width,
		       char *string, chtype color);
char *opciones[] = {

  "Choice 1",

  "Choice 2",

  "Choice 3",

  "Choice 4",

  "Exit",

};

int n_opciones = sizeof (opciones) / sizeof (char *);
int
main ()
{
  WINDOW *ventanas[3];
  PANEL *paneles[3];
  PANEL *top;
  int ch;
  int n_paneles=4444;
  /* Initialize curses */
  initscr ();
  start_color ();
  cbreak ();
  noecho ();
  keypad (stdscr, TRUE);
  /* Initialize all the colors */
  init_pair (1, COLOR_RED, COLOR_BLACK);
  init_pair (2, COLOR_GREEN, COLOR_BLACK);
  init_pair (3, COLOR_BLUE, COLOR_BLACK);
  init_pair (4, COLOR_CYAN, COLOR_BLACK);
  init_wins (ventanas, 6);
  /* Attach a panel to each window *//* Order is bottom up */
  paneles[0] = new_panel (ventanas[0]);	/* Push 0, order: stdscr-0 */
  paneles[1] = new_panel (ventanas[1]);	/* Push 1, order: stdscr-0-1 */
  paneles[2] = new_panel (ventanas[2]);	/* Push 2, order: stdscr-0-1-2 */
  /* Set up the user pointers to the next panel */
  set_panel_userptr (paneles[0], paneles[1]);
  set_panel_userptr (paneles[1], paneles[2]);
  set_panel_userptr (paneles[2], paneles[0]);
  /* Update the stacking order. 2nd panel will be on top */
  update_panels ();

  /* Show it on the screen */
  attron (COLOR_PAIR (4));
  mvprintw (LINES - 2, 0, "Q->Salir");
  attroff (COLOR_PAIR (4));
  doupdate ();

  top = paneles[2];		/* Store the top panel pointer */
  while ((ch = getch ()) != 'q')
    {
      switch (ch)
	{
	case 9:
	  top = (PANEL *) panel_userptr (top);	/* Find out the next panel in the cycle */
	  top_panel (top);	/* Make it as the top panel */
	  break;
	}
      update_panels ();
      doupdate ();
    }
  endwin ();
  return 0;
}

/* Put all the windows */
void
init_wins (WINDOW ** wins, int n)
{
  int x, y, i;
  char label[80];

  y = 2;
  x = 10;
  for (i = 0; i < n; ++i)
    {
      wins[i] = newwin (NLINES, NCOLS, y, x);
      sprintf (label, "Opcion Numero %d", i + 1);
      mostrar_ventana (wins[i], label, i + 1);
      y += 3;
      x += 7;
    }
}

/* Show the window with a border and a label */
void
mostrar_ventana (WINDOW * win, char *label, int label_color)
{
  int startx, starty, height, width;

  getbegyx (win, starty, startx);
  getmaxyx (win, height, width);

  box (win, 0, 0);
  mvwaddch (win, 2, 0, ACS_LTEE);
  mvwhline (win, 2, 1, ACS_HLINE, width - 2);
  mvwaddch (win, 2, width - 1, ACS_RTEE);

  imprimir_centrao (win, 1, 0, width, label, COLOR_PAIR (label_color));
}

void
imprimir_centrao (WINDOW * win, int starty, int startx, int width,
		  char *string, chtype color)
{
  int length, x, y;
  float temp;

  if (win == NULL)
    win = stdscr;
  getyx (win, y, x);
  if (startx != 0)
    x = startx;
  if (starty != 0)
    y = starty;
  if (width == 0)
    width = 80;
  length = strlen (string);
  temp = (width - length) / 2;
  x = startx + (int) temp;
  wattron (win, color);
  mvwprintw (win, y, x, "%s", string);
  wattroff (win, color);
  refresh ();
}
