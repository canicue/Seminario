
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "calendario.h"

CDKCALENDAR *
calendario (CDKSCREEN * pantalla)
{
  struct tm *dateInfo;
  char *title = "Ingrese fecha";
  time_t clck;
  time (&clck);
  dateInfo = localtime (&clck);
  int dia = dateInfo->tm_mday;
  int mes = dateInfo->tm_mon + 1;
  int anio = dateInfo->tm_year + 1900;
  calendar = newCDKCalendar (pantalla,
			     CENTER,
			     CENTER,
			     title, dia, mes, anio,
			     COLOR_PAIR (16) | A_BOLD,
			     COLOR_PAIR (24) | A_BOLD,
			     COLOR_PAIR (32) | A_BOLD,
			     COLOR_PAIR (40) | A_REVERSE, TRUE, FALSE);
  //  activateCDKCalendar(calendar,0);
  return calendar;
}

void
mostrar_calendario (CDKMATRIX * matriz, CDKCALENDAR * calen)
{
  char tmp[128];

  calen = (CDKCALENDAR *) calendario (ScreenOf (matriz));
  activateCDKCalendar (calen, 0);
  if (calen->exitType == vNORMAL)
    {

      sprintf (tmp, "%02d/%02d/%d", calen->day, calen->month, calen->year);
      setCDKMatrixCell (matriz, matriz->crow, 1, tmp);
      destroyCDKCalendar (calen);
      drawCDKMatrix (matriz, TRUE);
    }

}
