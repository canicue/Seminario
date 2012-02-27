
#include <matrix.h>
#include <cdk_util.h>
#include "utils.h"
#include "callbacks.h"
//#include <string.h>
char *tmp;
char *
generar_id (char *prefijo, char *tabla, char *columna)
{
  // char caca[12];              //="Asdfadsfasdfadsfadsfads";
  // strcpy(caca,prefijo);
  // int longitud;

  // tmp = buscar_ultimo (tabla, columna, call_id);
  printf ("prefijo %s\n", tmp);
//  longitud=strlen("caca");

  //longitud=strlen(prefijo);
  //printf("longitud  %d\n",(int)longitud);
  //printf(" prefijo %s\n",prefijo);
  // printf("%d--->\n",strlen(prefijo));
//  int long_pref=strlen(prefijo);
//  char *nro=tmp+long_pref;
  // printf("%s",nro);
// printf("str   %s\n",strstr("tmpC",prefijo));

  //  printf("------\n");
  // printf(tmp);
  // printf("------\n");
  /*  ultimo=strstr(prefijo,tmp);
     char *aguja="dios";
     char *pajar="diosito";
     char *d=strstr(aguja,pajar);
     char a[12];
     strcpy(a,d);
     printf("%s\n",a); */
  return tmp;
  // return "veremos";
}

void
setear_id (CDKMATRIX * matriz)
{
  //char *tmp=buscar_ultimo(matriz->)


  // printf("%s",matriz->rowtitle[0]);
  // endCDK();
  // char *algo=chtype2Char(matriz->rowtitle[0]);

  // eraseCDKMatrix(matriz);
  popupLabel (ScreenOf (matriz), (char **) matriz->coltitle, 3);

  setCDKMatrixCell (matriz, 1, 1, "dd");

}

void
armar_prefijo (char *nombre, char *destino)
{

  if (!strcasecmp (nombre, "proveedor"))
    {
      strcat (destino, "RMP00");
      //     sprintf(tmp,"P00%s",destino);
      //strcpy(destino,tmp);
      //   strcat(&destino,"P00");

    }
  else if (!strcasecmp (nombre, "RMP"))
    {
      strcat (destino, "RMP00");

    }
  else if (!strcasecmp (nombre, "cliente"))
    {
      strcat (destino, "C00");

    }
  else if (!strcasecmp (nombre, "tecnico"))
    {


    }
  else
    {
      strcat ("XXXX", destino);

    }






}
