#include <sqlite3.h>
#include <stdio.h>
#include <cdk/cdk.h>
#define set_col(n, width, string)  coltitle[n] = string;   colwidth[n] = width ; colvalue[n] = vUMIXED
#define set_row(n, string)  rowtitle[n] = "</B/6>" string

sqlite3  *conectar()
{
	sqlite3 *db;
	char *base="base.sqlite";
	sqlite3_open(base,&db);

return db;
}
int call_tabla(void *nombre, int argc, char **argv, char **azColName)
{
		char tmp[255];
		char *formato="<L></B/5>%s";
		char *coltitle[10], *rowtitle[10], *mesg[10];
		int colwidth[10], colvalue[10];
		int i=0;
	    //char *titulo="<L></B/5>%s";
	    char *titulo[255];
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
set_col(1,17,titulo);
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
void ver_tabla(char *nombre)
{
char *error;
sqlite3 *db=conectar();
char *plantilla="SELECT * FROM '%s' limit 1";
char consulta[255];
sprintf(consulta,plantilla,nombre);
//printf(consulta);
sqlite3_exec(db,consulta,call_tabla,nombre,&error);
}

void formulario(char *tabla)
{

ver_tabla(tabla);


}

int call_columnas(void *NotUsed, int argc, char **argv, char **azColName)
{
		printf("%d,%d",sizeof(&azColName),sizeof(azColName[0]));
	int i=0;
	//for(i=0;i<sizeof(azColName)/sizeof(azColName[0]);i++)
	for(i=0;i<argc;i++)
	{
//		printf("%s",argv[i]);
		printf("\n%s",azColName[i]);	
	}


}
void columnas(char *tabla)
{
	char *error;
	int res;
	sqlite3 *db;
	char plantilla[]="PRAGMA table_info(%s)";
	char consulta[255];
//	sprintf(consulta,plantilla,tabla);
	sprintf(consulta,"select * from '%s' limit 1",tabla);
	db=conectar();
	res=sqlite3_exec(db,consulta,call_columnas,tabla,&error);

}		
int main(int argc, const char *argv[])
{
//		ver_tabla("cliente");
//		columnas("cliente");
formulario("cliente");
formulario("proveedor");
formulario("RMP");
		return 0;
}
