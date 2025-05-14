#ifndef LIBRO_H_INCLUDED
#define LIBRO_H_INCLUDED

#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

class libro{
    string nombre;
    string area;
    string sub_area;
    string autores;
    string editorial;
    string anio_P;
    string estado;//leer en la funcion generar_barra el primer byte > segun el byte le asignamos un numero

///atributos agregados
    char ubicacionL[2];// 4( columna )  _  3( fila )
    bool estadoSN;//1 ( DISPONIBLE ) / 0 ( NO DISPONIBLE )

public :
    libro(string, string, string, string, string, string);
    //~libro();
    void generar_barras();
    void mostrarLibro();
        //getters
    string get_nombre();
    string get_area() ;
    string get_sub_area();
    string get_autores() ;
    string get_editorial(); 
    string get_anio_P();


};

#endif // LIBRO_H_INCLUDED
