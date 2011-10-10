#include <curses.h>
#include <string.h>
WIN *win;
int main() {    int length, x, y;                                                                            
    float temp;                                                                                   
                                                                                                  
    if(win == NULL)                                                                               
        win = stdscr;                                                                             
    getyx(win, y, x);                                                                             
    if(startx != 0)                                                                               
        x = startx;                                                                               
    if(starty != 0)                                                                               
        y = starty;                                                                               
    if(width == 0)                                                                                
        width = 80;                                                                               
                                                                                                  
    length = strlen(string);                                                                      
    temp = (width - length)/ 2;                                                                   
    x = startx + (int)temp;                                                                       
    wattron(win, color);                                                                          
    mvwprintw(win, y, x, "%s", string);                                                           
    wattroff(win, color);                                                                         
    refresh();                                                                                    
}                                                                                                 
