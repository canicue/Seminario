/**
 * Coded by crodas,
 *
 * The author disclaims the copyright of this code.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int
table_exists (sqlite3 * dbh, const char *table)
{
  sqlite3_stmt *pStmtPrep;
  int rc, exists;
  /* preparamos el SQL a ejecutar, muy util para evitar SQL injections */
  rc =
    sqlite3_prepare (dbh,
		     "select * from sqlite_master where type='table' and name=?",
		     -1 /* null terminated str */ , &pStmtPrep, NULL);
  if (rc != SQLITE_OK)
    {
      printf ("This is an SQL bug %s", sqlite3_errmsg (dbh));
      exit (-1);
    }

  /* asignamos a la primera variabla (?) el valor de table */
  sqlite3_bind_text (pStmtPrep, 1, table, -1, 0);

  /* ejecutamos */
  rc = sqlite3_step (pStmtPrep);
  switch (rc)
    {
    case SQLITE_ERROR:
    case SQLITE_BUSY:
      printf ("Database locked or unknown error");
      fflush (stdout);
      exit (-1);
      break;
    case SQLITE_DONE:
      exists = -1;		/* no existe */
      break;
    case SQLITE_ROW:
      exists = 1;		/* existe */

    }

  /* a liberar memoria! */
  sqlite3_finalize (pStmtPrep);
  return exists;
}

int
main ()
{
  sqlite3 *dbh;
  int rc, i;
  sqlite3_stmt *pStmtPrep;

  if (sqlite3_open_v2
      ("test.db", &dbh, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE,
       0) != SQLITE_OK)
    {
      printf ("Can't  open db, please check permissions on this folder. %s\n",
	      sqlite3_errmsg (dbh));
      return -1;
    }

    /**
     *  Hice una pequenha funcion que ve si existe.
     *  lo bueno de la funcion es que muestra el primer ejemplo
     *  el SQLPrepare, y muestra como saber si la consulta
     *  tiene resultado o no
     */
  if (table_exists (dbh, "testing") == -1)
    {
      printf ("Table doesn't exists,execute\n");
      /* tabla sencilla, utilizo exec porque no espero resultado */
      sqlite3_exec (dbh, "create table testing (id int, text varchar(250))",
		    0, 0, 0);
      /* sql preparada para el insert */

      int data_id[] = { 5, 5, 5, 8, 0 };	/* el ID no es PK, en la vida real seria PK */
      const char *data_data[] =
	{ "Some text", "Another text", "foobar", "This is the 8 text", 0 };
      rc =
	sqlite3_prepare (dbh, "insert into testing values(?,?)", -1,
			 &pStmtPrep, NULL);
      /* no controlo nada porque ya mostre en la funcion anterior como controlar errores */
      for (i = 0;; i++)
	{
	  if (data_id[i] == 0)
	    break;
	  /* cambiamos ? ? por sus valores */
	  sqlite3_bind_int (pStmtPrep, 1, data_id[i]);
	  sqlite3_bind_text (pStmtPrep, 2, data_data[i], -1, 0);

	  /* ejecutamos */
	  rc = sqlite3_step (pStmtPrep);
	  /* se tendria que controlar la salida */

	  /* ya que no hay ciclos, para cambiar los parametros */
	  /* debemos reinicar al Statement */
	  sqlite3_reset (pStmtPrep);
	}

      sqlite3_finalize (pStmtPrep);
    }

  /* ahora queremos los datos con id 5,6,7,8 */
  int data[] = { 5, 6, 7, 8, 0 };
  char *text;
  rc =
    sqlite3_prepare (dbh, "select * from testing where id=?",
		     -1 /* null terminated str */ , &pStmtPrep, NULL);
  /* no controlo nada porque ya mostre en la funcion anterior como controlar errores */
  for (i = 0;; i++)
    {
      if (data[i] == 0)
	break;
      /* asignar valor a ? */
      sqlite3_bind_int (pStmtPrep, 1, data[i]);
      /* mientas haya resultado */
      while (sqlite3_step (pStmtPrep) == SQLITE_ROW)
	{
	  text = sqlite3_column_text (pStmtPrep, 1);	/* id = 0, text=1 */
	  printf ("%d: %s\n", data[i], text);
	}

      /* reinicar el stmt */
      sqlite3_reset (pStmtPrep);
    }

  /* */
  sqlite3_finalize (pStmtPrep);

  sqlite3_close (dbh);
}
