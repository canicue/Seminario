#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cdk/cdk.h>
typedef struct t_cosa
{

  char nombre[50];
  int edad;


} COSA;
void
imprimir (COSA * cosa)
{
  printf ("nombre=%s\n", cosa->nombre);
  printf ("edad=%d\n", cosa->edad);

}

void
prueba (COSA cosa)
{

  char *linea = (char *) &cosa;
  printf ("%s", linea[0]);
}

int
main (int argc, const char *argv[])
{
  struct t_cosa cosita = { "nombre", 2 };
  imprimir (&cosita);
  char **conver = (char **) &cosita;
  printf ("%s", &conver[1]);
  initscr ();
  box (stdscr, 0, 0);
  CDKSCREEN *pantalla = initCDKScreen (stdscr);
  popupLabel (pantalla, (char **) &cosita, 2);
  getch ();
  /*
     COSA hola;
     //hola=(COSA*)malloc(sizeof(COSA));
     //hola->nombre="dios";
     strcpy(hola.nombre,"hola");
     hola.edad=19;
     //prueba(hola);
     char *buffer=(char*)&hola;
     printf("%s\n",*(buffer));
     imprimir(&hola); */
  return 0;
}
