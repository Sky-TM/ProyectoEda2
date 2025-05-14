#ifndef func_h //si no esta definido
#define func_h //definimos
#include <vector>
#include "class_socio.h"
#include <string>
using namespace std;

string a_minusculas(string text);
string borrar_comillas(string texto);
string borrar_ceros(string fecha);
bool fecha_valida(string fecha);
string normalizar_anio(string fecha);
string borrar_espacios(string texto);
string quitar_tildes(string texto);

#endif //cierra condicion del ifndef