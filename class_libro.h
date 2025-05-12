#include <iostream>
#ifndef class_libro_h
#define class_libro_h

using namespace std;
class libro{
private:
    string nombre;
    string area;
    string sub_area;
    string autores;
    string editorial;
    string anio_P;
    string estado;//leer en la funcion generar_barra el primer byte > segun el byte le asignamos un numero(1,2,3,4)(bien,regular,malo,destruido)
    char ubicacion[2];// 4( columna )  _  3( fila )
    bool estadoPD;//prestado / devuelto (0 prestado, 1 devuelto)
  

public :
libro( string, string, string, string, string, string);//constructor
    void alta_baja();
    void modificacion();
    //void busqueda_filtrado();
    string generar_barras();
    //getters
    string get_nombre();
    string get_area() ;
    string get_sub_area();
    string get_autores() ;
    string get_editorial(); 
    string get_anio_P();
    //setters
    void set_estado(string);
    void set_ubicacion(char);
    void set_estadoPD(bool);

};


#endif 

