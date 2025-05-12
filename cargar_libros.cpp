#include "cargar_libros.h"

vector <libro> cargarLibro(string nombre_archivo){
ifstream archivoLibros;
string linea;
char limitador = ',';
archivoLibros.open(nombre_archivo);
if(!archivoLibros.is_open()){
    cout<<"No se pudo abrir el archivo."<<endl;
}
//array dinamico 
vector<libro> libros;
getline(archivoLibros, linea);//primera linea(parametros)


while (getline(archivoLibros, linea)) //todas las lineas
{
stringstream stream(linea);

string nombre, area, subarea, autores, editorial, anio_de_publicacion;

getline(stream, nombre, limitador);
getline(stream, area, limitador);
getline(stream, subarea, limitador);
getline(stream, autores, limitador);
getline(stream, editorial, limitador);
getline(stream, anio_de_publicacion, limitador);
libro libroo(nombre, area, subarea, autores, editorial, anio_de_publicacion);

libros.push_back(libroo); 

}
archivoLibros.close();

return libros;
} 
