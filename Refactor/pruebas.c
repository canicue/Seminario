#include "pruebas.h"

void
ventanita_info (CDKSCREEN * pantalla, char **msg)
{
  endCDK ();
  char *mesg[] = { "asdfadsf", "asdfads" };
  char **copia = copyCharList (msg);

  printf ("--------->%d\n", lenCharList (copia));

  char **tmp = copyCharList (msg);
  int longitud = sizeof (msg) / sizeof (msg[0]);
  printf ("msg=%d    msg[0]=%d      tmp=%d\n", longitud, sizeof (char),
	  sizeof (tmp));

  printf ("---%d\n", longitud);
  // int longitud=lenCharList(msg)/2-1;//sizeof(msg[0]);

  //  char* oso[]={"asdfasdf","d","dddddddddddddddddddddddd"};//,"d"};
  // printf("----%d\n",sizeof(oso)/sizeof(oso[0]));
//int longitud=(sizeof(msg)/sizeof(msg[0]));
  //   printf("%d\n",longitud);
  //popupLabel(pantalla,msg,longitud);
}
