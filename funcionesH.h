#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include<iostream>
#include<string>
#include<fstream>
#include<vector>

#include "socioH.h"
#include "libroH.h"

using namespace std;

fstream archivo_IO(vector <socio>&, int);///FUNCION PARA ABRIR EL ARCHIVO EN MODO ESCRITURA O LECTURA
void mostrar(vector<socio>&);
void lecturaLinea(vector <socio>&, fstream&);///TOMA EL ARCHIVO Y LE EXTRAE LOS DATOS LINEA X LINEA Y LO ENSAMBLA EN UN VECTOR
void modificar_Socio(vector <socio>&);///MODIFICA EL VECTOR
void subirCambios(vector <socio>&, int);///TOMA EL VECTOR Y LO COPIA EN EL ARCHIVO
void eliminarSocio(vector <socio>&);

#endif // FUNCIONES_H_INCLUDED
