#include <iostream>
#include "func.h"
#include <vector>
#include "class_socio.h"

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
    if((i == 0 || i ==3) && fecha[i] == '0'){//si c es distinto de "
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
    }else if(longitud >= 9 && fecha[1] == '/' && fecha[4] == '/'){//x/xx/xxxx
        return true;
    }else if(longitud >= 9 && fecha[2] == '/' && fecha[4] == '/'){//xx/x/xxxx
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

    