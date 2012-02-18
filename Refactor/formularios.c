#include <curses.h>
#include <form.h>
char ch;

void
respuesta (FORM * formulario)
{
  while ((ch = getch ()) != KEY_F (1))
    {
      switch (ch)
	{
	case KEY_DOWN:
	  /* Go to next field */
	  form_driver (formulario, REQ_NEXT_FIELD);
	  /* Go to the end of the present buffer */
	  /* Leaves nicely at the last character */
	  form_driver (formulario, REQ_END_LINE);
	  break;
	case KEY_UP:
	  /* Go to previous field */
	  form_driver (formulario, REQ_PREV_FIELD);
	  form_driver (formulario, REQ_END_LINE);
	  break;
	default:
	  /* If this is a normal character, it gets */
	  /*formulario Printed  */
	  form_driver (formulario, ch);
	  break;
	}
    }
}

void
colores ()
{
  init_pair (1, COLOR_WHITE, COLOR_BLUE);
  init_pair (2, COLOR_WHITE, COLOR_BLUE);


}

int
main (int argc, const char *argv[])
{
  initscr ();
  keypad (stdscr, TRUE);
  cbreak ();
  colores ();
  FIELD *campos[2];
  FIELD *campo = new_field (1, 15, 4, 18, 0, 0);
  FIELD *campo_dos = new_field (1, 10, 6, 18, 0, 0);

  campos[0] = campo;
  campos[1] = campo_dos;
  campos[2] = NULL;

  set_field_fore (campos[0], COLOR_PAIR (1));
  set_field_back (campos[0], COLOR_PAIR (2));
//      set_field_opts(campos[0],O_ACTIVE);
  set_field_back (campos[0], A_UNDERLINE);
//field_opts_off(campos[0],O_AUTOSKIP);
  set_field_back (campos[1], A_UNDERLINE);
//      field_opts_off(campos[1],O_AUTOSKIP);
  FORM *formulario = new_form (campos);

//      noecho();
  box (stdscr, 0, 0);
  set_form_win (formulario, stdscr);
  post_form (formulario);
  refresh ();
  mvprintw (4, 10, "Value 1:");
  mvprintw (6, 10, "Value 1:");
//------

  while ((ch = getch ()) != KEY_F (1))
    {
      switch (ch)
	{
	case KEY_DOWN:
	  /* Go to next field */
	  form_driver (formulario, REQ_NEXT_FIELD);
	  /* Go to the end of the present buffer */
	  /* Leaves nicely at the last character */
	  form_driver (formulario, REQ_END_LINE);
	  break;
	case KEY_UP:
	  /* Go to previous field */
	  form_driver (formulario, REQ_PREV_FIELD);
	  form_driver (formulario, REQ_END_LINE);
	  break;
	default:
	  /* If this is a normal character, it gets */
	  /* Printed                */
	  form_driver (formulario, ch);
	  break;
	}
    }









//------









//respuesta(formulario);
//getch();
  endwin ();
  return 0;
}
