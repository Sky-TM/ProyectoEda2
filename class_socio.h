#include <iostream>
#ifndef class_socio_h
#define class_socio_h
using namespace std;
class socio{
///atributos archivos
private:
    string apellido;
    string dni;// xx.xxx.xxx
    string sexo;
    string direccion;
    string num_telefonico;
    string edad;
    string fechaN;//xx_xx_xxx
    string mail;

public :
    socio(string, string, string, string, string, string, string, string);
   // ~socio();
    void alta_baja();
    void modificacion();
    string getapll();
    string getdni();
    string getsex();
    string getdir();
    string getnum();
    string getedad();
    string getfechaN();
    string getmail();

};

#endif