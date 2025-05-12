#include "buscar_libros.h"
#include "func.h"

void busqueda_libros(vector<libro> libros){
string eleccion;
do{
cout<<"Seleccione una opcion de busqueda y filtrado de libros: "<<endl;
cout<<" 1.Nombre\n 2.Area\n 3.Sub Area\n 4.Autores\n 5.Editorial\n 6.Anio de Publicacion\n 7.Estado\n 8.Ubicacion\n 9.Estado(Prestado, Devuelto)\n"<<endl;
cin>>eleccion;
}while(eleccion != "1" && eleccion != "2" && eleccion != "3" && eleccion != "4" && eleccion != "5" && eleccion != "6" && eleccion != "7" && eleccion != "8" && eleccion != "9" );
//todas tienen que ser falsas para seguir pidiendo el ingreso;
int opcion = 0;
opcion = stoi(eleccion);
switch(opcion){
case 1:{
bool band;
string nombre_busc; 
do{
band = 0;
cout<<"Ingrese el nombre del libro a buscar o E para salir: "<<endl;
cin.ignore();
getline(cin, nombre_busc);
nombre_busc = a_minusculas(nombre_busc);
for(unsigned long i = 0; i<libros.size(); i++){
    if(nombre_busc == a_minusculas(borrar_comillas(libros[i].get_nombre()))){
        cout<<"--------------------"<<endl;
        cout<<"Nombre: "<<libros[i].get_nombre()<<endl;
        cout<<"Area: "<<libros[i].get_area()<<endl;
        cout<<"Sub Area: "<<libros[i].get_sub_area()<<endl;
        cout<<"Autores: "<<libros[i].get_autores()<<endl;
        cout<<"Editorial:"<<libros[i].get_editorial()<<endl; 
        cout<<"Anio de Publicacion: "<<libros[i].get_anio_P()<<endl;
        band = 1;
    }
}
}while(!band && nombre_busc != "e");
    break;
}
case 2:{
bool exist;
cin.ignore();
do{
string area_busc;
exist = false;
cout<<"Ingrese el Area a buscar y filtrar o E para salir: "<<endl;
getline(cin, area_busc);
cout << "Leí exactamente: '" << area_busc << "'\n";
area_busc = a_minusculas(area_busc);
for(unsigned long i = 0; i < libros.size(); i++){
    if(area_busc == a_minusculas(libros[i].get_area())){
        cout<<"--------------------"<<endl;
        cout<<"Nombre: "<<libros[i].get_nombre()<<endl;
        cout<<"Area: "<<libros[i].get_area()<<endl;
        cout<<"Sub Area: "<<libros[i].get_sub_area()<<endl;
        cout<<"Autores: "<<libros[i].get_autores()<<endl;
        cout<<"Editorial:"<<libros[i].get_editorial()<<endl; 
        cout<<"Anio de Publicacion: "<<libros[i].get_anio_P()<<endl;
        exist = true;
    }
}
if(!exist){
    cout<<"El Area no existe."<<endl;
}
}while(!exist);
    break;
}
case 3:{
string subarea_busc;
bool encontrado;
do{
encontrado = 0;
cout<<"Ingrese el Sub Area a buscar y filtrar o E para salir: "<<endl;
cin.ignore();//limpiar buffer
getline(cin, subarea_busc);
subarea_busc = a_minusculas(subarea_busc);
for(unsigned long i = 0; i < libros.size(); i++){
    if(subarea_busc == a_minusculas(libros[i].get_sub_area())){
        cout<<"--------------------"<<endl;
        cout<<"Nombre: "<<libros[i].get_nombre()<<endl;
        cout<<"Area: "<<libros[i].get_area()<<endl;
        cout<<"Sub Area: "<<libros[i].get_sub_area()<<endl;
        cout<<"Autores: "<<libros[i].get_autores()<<endl;
        cout<<"Editorial:"<<libros[i].get_editorial()<<endl; 
        cout<<"Anio de Publicacion: "<<libros[i].get_anio_P()<<endl;
        encontrado = 1;
    }
}

}while(!encontrado && subarea_busc != "e");
    break;
}
case 4:{
string autor_busc;
bool band;
do{
band = 0;
cout<<"Ingrese el Autor a buscar o E para salir: "<<endl;
cin.ignore();
getline(cin, autor_busc);
autor_busc = a_minusculas(autor_busc);
for(unsigned long i = 0; i < libros.size(); i++){
    if(autor_busc == a_minusculas(libros[i].get_autores())){
        cout<<"--------------------"<<endl;
        cout<<"Nombre: "<<libros[i].get_nombre()<<endl;
        cout<<"Area: "<<libros[i].get_area()<<endl;
        cout<<"Sub Area: "<<libros[i].get_sub_area()<<endl;
        cout<<"Autores: "<<libros[i].get_autores()<<endl;
        cout<<"Editorial:"<<libros[i].get_editorial()<<endl; 
        cout<<"Anio de Publicacion: "<<libros[i].get_anio_P()<<endl;
        band = 1;
    }
}

}while(!band && autor_busc != "e");
    break;
}
case 5:{
bool band;
cin.ignore();
do{
band = false;
string edi_busc;
cout<<"Ingrese la Editorial a buscar y filtrar: "<<endl;
getline(cin, edi_busc);
edi_busc = a_minusculas(edi_busc);
for(unsigned long i = 0; i < libros.size(); i++){
    if(edi_busc == a_minusculas(libros[i].get_editorial())){
        cout<<"--------------------"<<endl;
        cout<<"Nombre: "<<libros[i].get_nombre()<<endl;
        cout<<"Area: "<<libros[i].get_area()<<endl;
        cout<<"Sub Area: "<<libros[i].get_sub_area()<<endl;
        cout<<"Autores: "<<libros[i].get_autores()<<endl;
        cout<<"Editorial:"<<libros[i].get_editorial()<<endl; 
        cout<<"Anio de Publicacion: "<<libros[i].get_anio_P()<<endl;
        band = true;
    }
}
    if(!band){
        cout<<"La editorial no existe."<<endl;
        
    }

}while(!band);
    break;
}
case 6:{
    break;
}
case 7:{

}
case 8:{
    break;
}
case 9:{
    break;
}
default:{
    break;
}
}
}