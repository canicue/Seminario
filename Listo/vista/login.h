/* 
 * File:   login.h
 * Author: canicue
 *
 * Created on 14 de octubre de 2011, 18:29
 */

#ifndef _LOGIN_H
#define	_LOGIN_H
void error_login();
char* pedir_datos(char* tipo);
static BINDFN_PROTO (entryCB);
boolean validar_usuario(char* usuario,char* password);
int login();
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* _LOGIN_H */

