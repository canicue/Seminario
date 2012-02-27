#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include "templates.h"


CDKTEMPLATE *
template_mail (CDKSCREEN * pantalla)
{
  char *plate = "MMMMM @ MMMMMMMMM.MMMM";
  template =
    newCDKTemplate (pantalla, CENTER, CENTER, "</5>Mail:<!5>", "mail", plate,
		    "_____  @  __________ .___ ", TRUE, FALSE);
  return template;
}

CDKTEMPLATE *
proveedor_id ()
{
  return NULL;
}
