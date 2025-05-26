#ifndef func_h //si no esta definido
#define func_h //definimos

#include <string>
#include <unordered_map>

using namespace std;

string a_minusculas(string text);
string borrar_comillas(string texto);
string borrar_ceros(string fecha);
bool fecha_valida(string fecha);
string normalizar_anio(string fecha);
string borrar_espacios(string texto);
string quitar_tildes(string texto);
bool es_entero_valido(string s);

#endif //cierra condicion del ifndef
