


#include <cdk/cdk.h>
#include <cdk/matrix.h>

#include "callbacks.h"

int
call_alta (void *nombre, int argc, char **argv, char **azColName)
{
  char tmp[255];
  char *formato = "<L></B>%s";
  char *coltitle[argc], *rowtitle[argc];
  //  char *mesg[10];
  int colwidth[argc], colvalue[argc];
  colvalue[3] = vUCHAR;

  int i = 0;
  //char *titulo="<L></B/5>%s";
  char titulo[255];
  //sprintf(&titulo,nombre);
  CDKSCREEN *pantalla;
  initscr ();
  pantalla = initCDKScreen (stdscr);
  // CDKMATRIX *matriz;
  sprintf (titulo, formato, nombre);
  // armar_prefijo(nombre,argv[0]);

  for (i = 0; i < argc; i++)
    {
      sprintf (tmp, formato, azColName[i]);
      rowtitle[i + 1] = (char *) copyChar (tmp);

      //        printf(tmp);
      //      set_row(i+1,azColName[i]);
    }


  //setCDKMatrixCell (matriz,1,1,argv[0]);
  set_col (1, 44, titulo);	// habia un 77 pero no anda en netbook
  // set_readonly(1,44,titulo);

  matriz = newCDKMatrix (pantalla,
			 CENTER,
			 CENTER,
			 argc,
			 1,
			 argc,
			 1,
			 "",
			 rowtitle,
			 coltitle,
			 colwidth,
			 colvalue, -1, -1, '.', COL, TRUE, FALSE, FALSE);
  //activateCDKMatrix(matriz, 0);
  //          for(i=0;i<argc;i++)
  //        {
  //                printf("->%s: %s\n",azColName[i],argv[i]);
  //       }
  //        printf("%s",(char*)nombre);


  return 0;


}


int
call_modificacion (void *nombre, int argc, char **argv, char **azColName)
{


  int i;



  call_alta (nombre, argc, argv, azColName);

//  char **copia=copyCharList(argv);

  for (i = 0; i < argc; i++)
    {
      // i==0?armar_prefijo(nombre,argv[0]):
      //  printf("%s= %s\n",azColName[i],argv[i]) ;
      //setCDKMatrixCell (matriz, i + 1, 1, copia[i]);
      setCDKMatrixCell (matriz, i + 1, 1, argv[i]);

    }



  //  activateCDKMatrix(matriz,0);

  //  popupLabel(ScreenOf(matriz),argv,argc);



  return 0;


}

int
call_lista (void *nombre, int argc, char **argv, char **azColName)
{

  // insertCDKScrollItem(lista_scroll,argv[0]);
  addCDKScrollItem (lista_scroll, argv[0]);

  return 0;

}

int
call_borrado (void *nombre, int argc, char **argv, char **azColName)
{
  char *BORRAR_CANCELAR[] = { "BORRAR", "CANCELAR" };
  initscr ();
  curs_set (0);
  CDKSCREEN *pantalla = initCDKScreen (stdscr);

  dialogo = newCDKDialog (pantalla,
			  CENTER,
			  CENTER,
			  argv, argc, BORRAR_CANCELAR, 2,
			  COLOR_PAIR (2) | A_REVERSE, TRUE, TRUE, FALSE);




}

int
call_id (void *ultimo, int argc, char **argv, char **azColName)
{

  strcpy (ultimo, argv[0]);
  // printf(ultimo);
  return 0;


}
