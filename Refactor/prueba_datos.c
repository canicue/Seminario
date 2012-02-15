#include <sqlite3.h>
#include <stdio.h>
#include <cdk/cdk.h>
#define set_col(n, width, string)  coltitle[n] = string;   colwidth[n] = width ; colvalue[n] = vUMIXED
#define set_row(n, string)  rowtitle[n] = "</B/6>" string
// HEADERS
sqlite3  *conectar();
int call_tabla(void *nombre, int argc, char **argv, char **azColName);
CDKMATRIX *formulario(char *tabla);
void ver_registro(char *tabla,char *campo,char *valor);
void ver_tabla(char *nombre);
//
CDKMATRIX *matriz;
/*
 *formulario(tabla) --> crea una matriz de ingreso para la tabla
 *
 *
 *
 *
 * */


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
        char titulo[255];
        //sprintf(&titulo,nombre);
        CDKSCREEN *pantalla;
        initscr();
        pantalla=initCDKScreen(stdscr);
    sprintf(titulo,formato,nombre);
    for(i=0;i<argc;i++)
    {
    sprintf(tmp,formato,azColName[i]);
    rowtitle[i+1]=copyChar(tmp);

    printf(tmp);
    //  set_row(i+1,azColName[i]);
    }
set_col(1,58,titulo);
    matriz=newCDKMatrix(
                        pantalla,
                        CENTER,CENTER,
                        argc,1,argc,1,
                        "",rowtitle,coltitle,colwidth,colvalue,-1,-1,'.',COL,TRUE,FALSE,FALSE

                    );
    activateCDKMatrix(matriz,0);
/*  for(i=0;i<argc;i++)
    {
        printf("->%s: %s\n",azColName[i],argv[i]);
    }
    printf("%s",(char*)nombre);*/
return 0;
}
int call_registro(void *nombre, int argc, char **argv, char **azColName)
{
int i;
//printf("%s\n",argv[1]);
int columnas[122];
matriz=formulario(nombre);
printf("longitud argv= %d  matriz->rows=%d",lenCharList(argv),matriz->rows);
for(i=0;i<argc;i++)
{
	printf("%s\n",argv[i]);

}
/*	for(i=0;i<matriz->rows;i++)
	{
		columnas[i]=90;
	}
		setCDKMatrixCells(matriz,argv,lenCharList(argv),1,columnas);
*/
//activateCDKMatrix(matriz,0);
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
//activateCDKMatrix(matriz,0);
}



CDKMATRIX *formulario(char *tabla)
{

ver_tabla(tabla);
return matriz;

}


void ver_registro(char *tabla,char *campo,char *valor)
{
        char *error;
    char consulta[255];
    char *plantilla="SELECT * FROM %s WHERE %s='%s'";
    sprintf(consulta,plantilla,tabla,campo,valor);
    printf(consulta);
    sqlite3 *db=conectar();
    sqlite3_exec(db,consulta,call_registro,tabla,&error);
	if(error!=SQLITE_OK)
	{
		printf("error");
	}
}



int call_columnas(void *NotUsed, int argc, char **argv, char **azColName)
{
        printf("%d,%d",sizeof(&azColName),sizeof(azColName[0]));
    int i=0;
    //for(i=0;i<sizeof(azColName)/sizeof(azColName[0]);i++)
    for(i=0;i<argc;i++)
    {
//      printf("%s",argv[i]);
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
//  sprintf(consulta,plantilla,tabla);
    sprintf(consulta,"select * from '%s' limit 1",tabla);
    db=conectar();
    res=sqlite3_exec(db,consulta,call_columnas,tabla,&error);

}
int main(int argc, const char *argv[])
{
//      ver_tabla("cliente");
//      columnas("cliente");
/*
        formulario("insumo");
formulario("cliente");
formulario("proveedor");
formulario("RMP");*/

formulario("cliente");
  //      ver_registro("tecnico","tecnico_id","T001");
		ver_registro("proveedor","proveedor_id","P001");
        return 0;
}
