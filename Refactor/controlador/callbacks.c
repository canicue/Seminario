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
//  colvalue[3] = vUCHAR;
//  int id=atoi(copyChar(argv[0]));
  // id++;
  //char *elid;
  //sprintf(elid,"%d",id);
/*  int j;
   for (j = 0; j < argc;j++)
   { printf("%s",argv[j]);}
   printf("%d",id);
  exit(0);*/
  int i = 0;
  //char *titulo="<L></B/5>%s";
  char titulo[255];
  //sprintf(&titulo,nombre);
  CDKSCREEN *pantalla;
  initscr ();
  pantalla = initCDKScreen (stdscr);
  // CDKMATRIX *matriz;
  sprintf (titulo, formato, ((char **) nombre)[0]);
  // armar_prefijo(nombre,argv[0]);

  for (i = 0; i < argc; i++)
    {
      sprintf (tmp, formato, azColName[i]);
      rowtitle[i + 1] = (char *) copyChar (tmp);

      //        printf(tmp);
      //      set_row(i+1,azColName[i]);
    }



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

  int algo = atoi (copyChar (argv[0]));
  char *temp = (char *) malloc (sizeof (char *));
  sprintf (temp, "%d", ++algo);
  setCDKMatrixCell (matriz, 1, 1, temp);
  //algo=atoi(algo);
  // No puedo castear a int !!

  // setCDKMatrixCell (matriz,1,1,argv[0]);//ver qu ehostias!!

  //activateCDKMatrix(matriz, 0);
  //          for(i=0;i<argc;i++)
  //        {
  //                printf("->%s: %s\n",azColName[i],argv[i]);
  //       }
  //        printf("%s",(char*)nombre);


//  int  ultimo=buscar_ultimo(nombre,azColName[0],call_id);
  // ultimo=ultimo+1;
  // setCDKMatrixCell(matriz,1,1,(char*)id);
  return 0;


}


int
call_modificacion (void *nombre, int argc, char **argv, char **azColName)
{
  ((char **) nombre)[1] = argv[0];
  int i;
  call_alta (nombre, argc, argv, azColName);
  for (i = 0; i < argc; i++)
    {
      // i==0?armar_prefijo(nombre,argv[0]):
      //  printf("%s= %s\n",azColName[i],argv[i]) ;
      //setCDKMatrixCell (matriz, i + 1, 1, copia[i]);
      setCDKMatrixCell (matriz, i + 1, 1, argv[i]);

    }
  return 0;
}

int
call_lista (void *nombre, int argc, char **argv, char **azColName)
{

  int tmp, i = 0;
  for (i = 0; i < argc; i++)
    {
      if (!strcmp (((char *) nombre), azColName[i]))
	{

	  //     endCDK();
	  //printf("nombre %s",azColName[i]);
	  //    exit(0);
	  tmp = i;

	}
    }


  addCDKScrollItem (lista_scroll, argv[tmp]);

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
