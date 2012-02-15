#include  <cdk/cdk.h>

CDKMATRIX *matrix_prov;
char *titulo;
#define  filas 5
#define columnas 1
#define vrows 5
#define  vcols  1
#define  vcols  1
char *coltitle[10], *rowtitle[10], *mesg[10];
int colwidth[10], colvalue[10];
void form_prov(CDKSCREEN *pantalla);
void sacar_info(CDKSCREEN *pantalla,CDKMATRIX *matriz);

void ver_info(CDKMATRIX *matriz);
#define set_col(n, width, string) \
coltitle[n] = string;   colwidth[n] = width ; colvalue[n] = vUMIXED
#define set_row(n, string) \
   rowtitle[n] = "</B/6>" string
char *coltitle[10], *rowtitle[10], *mesg[10];
int colwidth[10], colvalue[10];
void form_prov(CDKSCREEN *pantalla)
{

  //  filas=5;
   // vrows=5;
    set_col(1, 17, "<L></B/5>Proveedor");
     //set_col(1, 7, "<C></B/5>Proveedor");
   // initCDKColor();

       set_row(1, "ID");
   set_row(2, "Nombre");
   set_row(3, "Apellido");
   set_row(4, "Correo");
   set_row(5, "Direccion");


   /* Create the title. */
   /* Create the matrix object. */
   matrix_prov = newCDKMatrix (pantalla,
                   CENTER,
                   CENTER,
                  filas, columnas, vrows, vcols,
                  titulo, rowtitle, coltitle,
                  colwidth, colvalue,
                  -1, -1, '.',
                  COL, TRUE,
                  FALSE,
                   FALSE);

activateCDKMatrix (matrix_prov, 0);

 if (matrix_prov->exitType == vESCAPE_HIT)
   {
      mesg[0] = "<C>You hit escape. No information passed back.";
      mesg[1] = "",
      mesg[2] = "<C>Press any key to continue.";
      popupLabel (pantalla, mesg, 3);
      destroyCDKMatrix(matrix_prov);
   }
   else if (matrix_prov->exitType == vNORMAL)
   {
		   ver_info(matrix_prov);
// sacar_info(pantalla,matrix_prov);
	 	   //info_matriz(matrix_prov,6,pantalla);

       //validar_matriz(matrix_prov,pantalla);

       destroyCDKMatrix(matrix_prov);
       refreshCDKScreen(pantalla);

       /*     char temp[80];

      sprintf(temp, "Current cell (%d,%d)", matrix_prov->crow, matrix_prov->ccol);
      mesg[0] = "<L>You exited the matrix normally.";
      mesg[1] = temp;
      mesg[2] = "<L>To get the contents of the matrix cell, you can";
      mesg[3] = "<L>use getCDKMatrixCell():";
      mesg[4] = getCDKMatrixCell(matrix_prov, matrix_prov->crow, matrix_prov->ccol);
      mesg[5] = "";
      mesg[6] = "<C>Press any key to continue.";
      popupLabel (pantalla, mesg, 7);*/
   }
}
int main(int argc, const char *argv[])
{ 

		initscr();
		CDKSCREEN *pantalla=initCDKScreen(stdscr);
		form_prov(pantalla);
	return 0;
}
void ver_info(CDKMATRIX *matriz)
{
		char *buttons[]={"ok","cancel"};
		char *title="titulo";
		char *info[]={"esta","es","la","info"};
int		buttonCount=2;
int size=4;
int rta=  viewInfo ( ScreenOf(matriz),title, info, size, buttons, buttonCount, FALSE);
if(rta==1)
{
	popupLabel(ScreenOf(matriz),info,4);
}

}
void sacar_info(CDKSCREEN *pantalla,CDKMATRIX *matriz)
{
		int i;
		printf("%s",chtype2String(matriz->coltitle[1]));
		char *tmp[matriz->rows];
	//	tmp[0]=matriz->coltitle[0];//"matriz->titles;";
		printf("%s",tmp[0]);
//		tmp =(char**)malloc(sizeof(char**));
		for(i=1;i<matriz->rows+1;i++)

		{
//	tmp[i]=(char*)malloc(sizeof("sdfdsfsdfdfdsdfdsf"));
tmp[i]=	getCDKMatrixCell(matriz,i,1);		
	//			printf("%d",i);
	//printf("\n %s",tmp[i]);	
	printf("\n %s",getCDKMatrixCell(matriz,i,1));	
		}

popupLabel(pantalla,tmp,4);
 char **buffer;
 buffer =(char**)malloc(sizeof(char*));
 buffer[0]="asdf";
 buffer[1]="dos";
 buffer[2]="dos";
 buffer[3]="cuatrpW";
 buffer[4]="asdfsdf";
 buffer[5]="asdfsdf";
 buffer[6]="asdfsdf";
 buffer[7]="asdfsdf";
 printf("%s,void=%d,char**=%d",buffer[4],sizeof(void*),sizeof(char**));
//char*buffer[]={"asdf","asdf"};
	   
		popupLabel(pantalla,buffer,7);

}
