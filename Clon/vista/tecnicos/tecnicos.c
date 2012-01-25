#include "../clientes/clientes.h"
#include "../tecnicos/tecnicos.h"
#include "../proveedores/proveedores.h"
#include "../../controlador/formularios.h"
#include "../../controlador/listados.h"

void tecnicos() {

    // endCDK();

    CDKSCREEN *pantalla_tecnicos;
    pantalla_tecnicos = initCDKScreen(stdscr);
    box(stdscr, 0, 0);
    refreshCDKWindow(stdscr);


    menu_tecnicos(pantalla_tecnicos);
    //  char *mensaje[]={"cli0entes","tecagas"};
    //  popupLabel(pantalla_clientes,mensaje,2);

    cdkScreen = pantalla_tecnicos;
    refresh();



}

void alta_tecnico(CDKSCREEN *pantalla) {
    char *mm = "asd";
    //      char *msg[]={"no","si"};
    WINDOW *subWindow;
    subWindow = newwin(LINES - 5, COLS - 10, 2, 5);

    waddstr(subWindow, mm);
    cdkScreen = initCDKScreen(subWindow);

    /* Box our window. */
    box(subWindow, ACS_VLINE, ACS_HLINE);
    //
    eraseCDKScreen(pantalla);
    // raiseCDKObject(vSWINDOW,(void*)subWindow);
    wrefresh(subWindow);
    refreshCDKScreen(cdkScreen);


    ///
    char elegido;
    do {



        elegido = getch();
        //refreshCDKScreen(cdkScreen);
        //
        //refresh();

        switch (elegido) {
            case 'a':
                proveedores();
                //produccion();
                break;
            case 1:
                waddstr(subWindow, "asdf");
                tecnicos();
                //administracion();
                break;
            case 2:
                //        mvwaddstr(cdkScreen->window,2,2,"dios");
                // wrefresh(cdkScreen->window);
                // getch();
                clientes();
                break;
            case 3:
                endCDK();

                exit(0);

        }


    } while (elegido != 'q');


    ///

    //  getch();










    //       char *mensaje[]={"ALTA","CLIENTE"};
    //   popupLabel(pantalla,mensaje,2);


}

void baja_tecnico(CDKSCREEN *pantalla) {
    char *mensaje[] = {"BAJA", "CLIENTE"};
    popupLabel(pantalla, mensaje, 2);
}

void menu_tecnicos(CDKSCREEN *pantalla)
 {

    /*    WINDOW *scrollwin;
        scrollwin=newwin(20,20,10,10);
        box(scrollwin,0,0);
        mvwaddstr(scrollwin,2,2,"dios");
        wrefresh
                (scrollwin);*/
    // refresh();
    char *opciones[] = {"Alta", "Baja", "Modificacion", "Volver"};
    CDKSCROLL *scroll;
    int elegido;
    do {

        scroll = newCDKScroll(pantalla, 2, 2, RIGHT, 10, 20,
                "<C></B>tecnicos",
                opciones
                ,
                4,

                TRUE,
                A_REVERSE,
                TRUE,
                FALSE);
        elegido = activateCDKScroll(scroll, 0);
        //refreshpantalla(cdkScreen);
        //
        //refresh();

        switch (elegido) {
            case 0:
                //  alta_tecnico(pantalla);

                destroyCDKScroll(scroll);
                //  alta_proveedor(pantalla);

                // cdkScreen=initCDKScreen(stdscr);


                CDKMATRIX *mat_tec = (CDKMATRIX*) formulario("tecnico");
                destroyCDKMatrix(mat_tec);


                break;
            case 1:
                destroyCDKScroll(scroll);
                //    listado_proveedores();
                CDKALPHALIST *lista_tec = (CDKALPHALIST*) listados("tecnico"); //Otra vez casteo cabron
                activateCDKAlphalist(lista_tec, 0);
                destroyCDKAlphalist(lista_tec);

                //  baja_tecnico(pantalla);
                break;

            case 2:
                destroyCDKScroll(scroll);
                //    listado_proveedores();
                CDKALPHALIST *lis_tec = (CDKALPHALIST*) listados("tecnico"); //Otra vez casteo cabron
                activateCDKAlphalist(lis_tec, 0);
                destroyCDKAlphalist(lis_tec);
                //tecnicos();
                break;
            case 3:
                cdkScreen = pantalla;
                //refresh();
                refreshCDKScreen(pantalla);

                //
        }








    } while (elegido != 3);
    //getch(); mierda!!!!
}