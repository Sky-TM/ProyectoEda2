#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED

#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

class socio{
    string apellido;
    string dni;
    string sexo;
    string direccion;
    string num_telefonico;
    string edad;
    string fechaN;
    string mail;
    int posicionDato; /// ELIMINAR

public :
    socio();
    socio(string, string, string, string, string, string, string, string, int);
    ~socio();

    void setDato(string, int);///MODIFICA ALGUN ATRIBUTO DEL OBJETO
    int validar(string);///SIRVE PARA LA BUSQUEDA DEL SOCIO
    string stringFile();///CONVIERTE LOS ATRIBUTOS A UN STRING
    void mostrar();
    void mostrarSocio();
    //getters
    string getapll();
    string getdni();
    string getsex();
    string getdir();
    string getnum();
    string getedad();
    string getfechaN();
    string getmail();

};

#endif // SOCIO_H_INCLUDED
