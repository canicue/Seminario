#include "preparadas.h"
int
main (int argc, const char *argv[])
{
  conectar (BASE);
  leer_registros (BASE, "persona");
  return 0;
}
