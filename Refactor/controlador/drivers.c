
#include "drivers.h"
int prueba_binding(EObjectType cdkType GCC_UNUSED, void *object, void *clientData GCC_UNUSED, chtype input)
{

    CDKMATRIX *mat=(CDKMATRIX*)object;
    char *aa[]={"asd","asdf"};
    if(input=='g')
    {
        popupLabel(ScreenOf(mat),aa,2);

       // getch();
    }

    return 1;

}


int prueba_preprocess(EObjectType cdkType GCC_UNUSED, void *object, void *clientData GCC_UNUSED, chtype input)
{





}