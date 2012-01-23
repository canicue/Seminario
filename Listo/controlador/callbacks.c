#include "callbacks.h"
int callback_reg(void *NotUsed, int argc, char **argv, char **azColName)
{
    
    return 0;

}
int call_tabla(void *nombre, int argc, char **argv, char **azColName)
{
		char tmp[255];
		char *formato="<L></B/5>%s";
		char *coltitle[10], *rowtitle[10], *mesg[10];
		int colwidth[10], colvalue[10];
		int i=0;
	    //char *titulo="<L></B/5>%s";
	    char titulo[255];
	    //sprintf(&titulo,nombre);
		CDKSCREEN *pantalla;
		initscr();
		pantalla=initCDKScreen(stdscr);
	CDKMATRIX *matriz;
	sprintf(titulo,formato,nombre);
	for(i=0;i<argc;i++)
	{
	sprintf(tmp,formato,azColName[i]);
	rowtitle[i+1]=copyChar(tmp);

	printf(tmp);
	//	set_row(i+1,azColName[i]);
	}
set_col(1,57,titulo);
	matriz=newCDKMatrix(
						pantalla,
						CENTER,CENTER,
						argc,1,argc,1,
						"",rowtitle,coltitle,colwidth,colvalue,-1,-1,'.',COL,TRUE,FALSE,FALSE

					);
	activateCDKMatrix(matriz,0);
/* 	for(i=0;i<argc;i++)
	{
		printf("->%s: %s\n",azColName[i],argv[i]);
	}
	printf("%s",(char*)nombre);*/
return 0;
}



int call_columnas(void *NotUsed, int argc, char **argv, char **azColName)
{
	//	printf("%d,%d",sizeof(&azColName),sizeof(azColName[0]));
	int i=0;
	//for(i=0;i<sizeof(azColName)/sizeof(azColName[0]);i++)
	for(i=0;i<argc;i++)
	{
//		printf("%s",argv[i]);
	//	printf("\n%s",azColName[i]);
	}


}