#include "archivos.h"

CDKFSELECT *
seleccionar_archivo ()
{

  char *path = "../../documentos/";
  char *titulo = "Seleccione Archivo";
  initscr ();
  CDKSCREEN *pantalla = initCDKScreen (stdscr);
  selector = newCDKFselect (pantalla,
			    CENTER,
			    CENTER,
			    20, 65, titulo, "", A_NORMAL, '_', A_REVERSE,
//                          "</5>", "</48>", "</N>", "</N>", TRUE, FALSE);
			    "</5>", ".", NULL, NULL, TRUE, FALSE);
  setCDKFselectDirectory (selector, path);
//  activateCDKFselect (selector, 0);
  return selector;

}

CDKVIEWER *
ver_archivo (char *nombre)
{
  char *button[] = { "OK", "CANCEL" };
  initscr ();
  curs_set (0);
  CDKSCREEN *pantalla = initCDKScreen (stdscr);
  visor_archivo = newCDKViewer (pantalla, CENTER, CENTER, 20, -2,
				button, 2, A_REVERSE, TRUE, FALSE);
  lineas = CDKreadFile (nombre, &contenido);
  setCDKViewer (visor_archivo, titulo_archivo, contenido, lineas, A_REVERSE,
		TRUE, TRUE, TRUE);
  activateCDKViewer (visor_archivo, 0);
  return visor_archivo;
}

void
elegir_archivo (CDKMATRIX * matriz)
{
  CDKFSELECT *sele = seleccionar_archivo ();

  char *archivo = activateCDKFselect (sele, 0);
  if (sele->exitType == vNORMAL)
    {
      setCDKMatrixCell (matriz, matriz->crow, 1, archivo);

    }

  destroyCDKFselect (sele);
  drawCDKMatrix (matriz, TRUE);









}
