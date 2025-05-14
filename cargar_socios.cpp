#include "cargar_socios.h"

vector <socio> cargarSocio(string nombre_archivo){
ifstream archivoSocios;
string linea;
char limitador = ',';
archivoSocios.open(nombre_archivo);
if(!archivoSocios.is_open()){
    cout<<"No se pudo abrir el archivo."<<endl;
}
//array dinamico del objeto de la clase socio(<socio>) llamado socios
vector<socio> socios;
getline(archivoSocios, linea);//primera linea(parametros)


while (getline(archivoSocios, linea)) //todas las lineas
{
stringstream stream(linea);//operaciones de I/O en cadenas de text(stream), convierte la cadena(linea) a un stream
//ahora el stream contiene toda la info de la linea, despues la divido con los getline en cada parametro
//string nombre, area, subarea, autores, editorial, anio_de_publicacion; //almacenar lo leido
string apellido, dni, sexo, direccion, numero_telefono, mail, fechaN, edad;
int posicionA = 0;

getline(stream, apellido, limitador);
getline(stream, dni, limitador);
getline(stream, sexo, limitador);
getline(stream, direccion, limitador);
direccion = borrar_comillas(direccion);
getline(stream, numero_telefono, limitador);
numero_telefono = borrar_comillas(numero_telefono);
getline(stream, edad, limitador);
getline(stream, fechaN, limitador);
getline(stream, mail, limitador);
posicionA++;

socio socioo(apellido, dni, sexo, direccion, numero_telefono, edad, fechaN, mail, posicionA);//creamos el obj de la clase socio con esos atributos

socios.push_back(socioo); //lo mandamos al final de el vector socios
}
archivoSocios.close();

return socios;
} 
