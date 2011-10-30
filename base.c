#include<sqlite3.h>
#include<stdio.h>

int main(int argc, const char *argv[])
{
		char* res;
	sqlite3 *cone;
	int error;
error=	sqlite3_open("hol.db",&cone);	
sqlite3_exec(cone,"CREATE TABLE tablita(id int,nombre text,apellido text,dni integer",&res);
printf("%d",error);

	return 0;
}
