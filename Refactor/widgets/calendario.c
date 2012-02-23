

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
