
#include "drivers.h"
int
prueba_binding (EObjectType cdkType GCC_UNUSED, void *object,
		void *clientData GCC_UNUSED, chtype input)
{

  CDKMATRIX *mat = (CDKMATRIX *) object;
  char *aa[] = { "asd", "asdf" };
  if (input == 'g')
    {
      popupLabel (ScreenOf (mat), aa, 2);

      // getch();
    }

  return 1;

}


int
prueba_preprocess (EObjectType cdkType GCC_UNUSED, void *object,
		   void *clientData GCC_UNUSED, chtype input)
{





}


int
driver_borrado (EObjectType cdktype GCC_UNUSED,
		void *object GCC_UNUSED, void *clientData, chtype key)
{

  char *mierda[] = { "MIERDA ", "CARAJO" };



  CDKBUTTONBOX *buttonbox = (CDKBUTTONBOX *) clientData;
  popupLabel (ScreenOf (buttonbox), mierda, 2);
  injectCDKButtonbox (buttonbox, key);
  return (TRUE);
}
