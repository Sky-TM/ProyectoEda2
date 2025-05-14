#include <iostream>
#include "func.h"
#include <vector>
#include "class_socio.h"
#include <unordered_map>

using namespace std;

string a_minusculas(string text){
    for( size_t i = 0;i<text.size(); i++){//size() devuelve un unsigned long, o size_t y size_t segun el entorno de ejecucion puede ser uns long, uns int, uns long long
        text[i] = tolower(text[i]);//la pos 0 ej:C va a ser =  c
    }
    return text ;
}
string borrar_comillas(string texto){
string salida = "";
for(char c : texto){//recorre el texto c por c(char)
    if(c != '"'){//si c es distinto de "
       salida += c;//le vamos ingresando c por c a la salida
    }
}
return salida;//devolvemos el text sin "
}
string borrar_ceros(string fecha){
string salida = "";
for(unsigned long i = 0;i < fecha.length(); i++){//recorre el texto c por c(char) xx/xx/xxxx
    if((i == 0 || i ==3) && fecha[i] == '0'){ // si en las posiciones 0 o 3 hay un 0, no se almacena
      //si la fecha es ej:02/02/1966 se borran los 0 en las posiciones 0 y 3
    }else{
        salida += fecha[i];
    }
}
return salida;
}
bool fecha_valida(string fecha){
    int longitud = fecha.length();
    if(longitud >= 10 && fecha[2] == '/' && fecha[5] == '/'){//si  es xx/xx/xxxx
        return true;        
    }else if(longitud >= 8 && fecha[1] == '/' && fecha[3] == '/'){//si es x/x/xxxx
        return true;
    }else if(longitud >= 9 && fecha[1] == '/' && fecha[4] == '/'){// x/xx/xxxx
        return true;
    }else if(longitud >= 9 && fecha[2] == '/' && fecha[4] == '/'){// xx/x/xxxx
        return true;
    }else if(longitud >= 6){// x/x/xx
        return true;
    }
    else{
        return false;
    }
}
string normalizar_anio(string fecha){
int len = fecha.length();
if(len>=6 && fecha[len -3 ] == '/' ){//si es xx/xx/xx - 3 me da / o si es x/x/xx tambien
   string ult_dos = fecha.substr(len - 2, 2); // substr saca una parte del string, desde donde(len-2) y cuantos caracteres queremos(2)
   int an_ingresado = stoi(ult_dos);//stoi = string to int
   string insertar = (an_ingresado>=26) ? "19" : "20";//si es 26 = 1926 si es 25 = 2025
    fecha.insert(len - 2, insertar); //xx/xx/"insertar(19/20)"xx
}
return fecha;
}
string borrar_espacios(string texto){
string salida = "";
for(unsigned long i = 0; i< texto.length(); i++){//recorre el texto c por c(char)    
    if(texto[i] != ' '){//si  es distinto de un espacio
       salida += texto[i];//le vamos ingresando c por c a la salida
    }
}
return salida;
}
string quitar_tildes(string texto) {
    unordered_map<string, char> reemplazos = {//las tildes van con string porque ocupan mas de un char
        {"á", 'a'}, {"é", 'e'}, {"í", 'i'}, {"ó", 'o'}, {"ú", 'u'},//clave = á , valor = a;
        {"Á", 'A'}, {"É", 'E'}, {"Í", 'I'}, {"Ó", 'O'}, {"Ú", 'U'},
        {"ñ", 'n'}, {"Ñ", 'N'}, {"ü", 'u'}, {"Ü", 'U'}
    };
    string resultado = "";
    for (size_t i = 0; i < texto.length();) { //recorremos el texto char por char
        if ((unsigned char)texto[i] >= 194) {//si es mas de 194 ; las letras con acento empiezan en 0xc2(194) o mas.
            //se castea unsigned char porque un char normal nunca va a ser mayor a 127 y ademas puede ser negativo entonces 127>194 no tiene sentido(unsigned char va de 0 a 255)
            string letra = texto.substr(i, 2);//le sacamos los 2 bytes si es un acento y lo guardamos en letra(desde i, 2 posiciones);
            if (reemplazos.count(letra)) { //devuelve true si letra existe o false si no existe en el mapa
                //si la letra(clave) encontrada y sacada con substr esta en el mapa se cambia por el valor del mapa
                resultado += reemplazos[letra]; //reemplazos[letra] devuelve el valor asociado a la clave, ej á = a ;
            } else {
                resultado += letra;//si no esta en el map, se guarda como esta
            }
            i += 2; //como es tilde avanzamos 2 bytes
        } else {
            resultado += texto[i]; //le sumamos la letra normal en la posicion
            i++; //letra normal, de 1 en 1
        }
    }

    return resultado;
}


