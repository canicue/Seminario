#include <stdio.h>

struct st
{
		int i;
		char c;
		double d;
		char *dios;
};

int main()
{
		struct st estructura;
		char *pc;
		int i;

		/* una estructura de prueba */
		estructura.i = 2;
		estructura.c = 'a';
		estructura.d = 3.141593;
		estructura.dios="asdf";
		/* simplemente asignas la dirección de la estructura a un char* */
		pc = (char *) &estructura;

		/* pc ya es un array de bytes, y puedes recorrerlo con */
		for (i=0; i<sizeof(struct st); ++i)
				printf("[%2d] = %4d\n", i, pc[i]);

		/* ten en cuenta que, segun sistema/compilador, pueden existir bytes
		 * de padding entre los campos de la estrucutra, por ejemplo, con gcc
		 * y en maquinas x86 se dejan 3 bytes de padding después del char */

		return 0;
}
