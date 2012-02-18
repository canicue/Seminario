

#include "archivos.h"



CDKFSELECT *
seleccionar_archivo ()
{
  initscr ();
  CDKSCREEN *pantalla = initCDKScreen (stdscr);
  selector = newCDKFselect (pantalla,
			    CENTER,
			    CENTER,
			    20,
			    65,
			    title,
			    "",
			    A_NORMAL, '_', A_REVERSE,
			    "</5>", "</48>", "</N>", "</N>", TRUE, FALSE);
  setCDKFselectDirectory (selector, "../../documentos/");

  activateCDKFselect (selector, 0);

  return selector;
}

CDKVIEWER *
ver_archivo ()
{
  initscr ();
  CDKSCREEN *pantalla = initCDKScreen (stdscr);
  visor_archivo = newCDKViewer (pantalla, CENTER, CENTER, 20, -2,
				button, 2, A_REVERSE, TRUE, FALSE);
}
