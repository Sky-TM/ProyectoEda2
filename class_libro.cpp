#include "class_libro.h"
//constructor
libro::libro(string n, string a , string s, string aut, string edi, string ani){
nombre = n;
area = a;
sub_area = s;
autores = aut;
editorial = edi;
anio_P = ani;
}
//getters
string libro::get_nombre() { 
    return nombre; 
}
string libro::get_area() { 
return area;
}
string libro::get_sub_area() { 
    return sub_area; 
}
string libro::get_autores()  { 
    return autores; 
}
string libro::get_editorial()  { 
    return editorial; 
}
string libro::get_anio_P()  { 
    return anio_P; 
}
//setters
 void libro::set_estado(string estado_){
 estado = estado_;
 }
void libro:: set_ubicacion(char ubicacion_){
ubicacion[2] = ubicacion_;
}
void libro:: set_estadoPD(bool estadoPD_){
estadoPD  = estadoPD_;
}
string libro::generar_barras(){

    ///ubicacion > 4 _ 3
    //estadoPD
    //estado

   int columna=0, fila=0, es_bool=0, es_L=0, i=0, salir = 0;

        int indice = 0;
        string estado = "regular";
        string barras;
        char ubicacion[2] = {9,2};//columna - fila
        bool estadob = 1;/// 0 no - 1 si

///FILA Y COLUMNA
    for(int i=0; i<=1 ; i++){

        for(int j = ubicacion[i]; j>0; j--){
            barras.append("|");
            cout<< '|';
        }
        barras.append( "/");
        cout<< '/';

    }
///ESTADO DISPONIBLE O NO -- 0 NO // 1 SI
    if(estadob){
        barras.append( "||");
        cout<< "||";
    }else{
        barras.append( "|");
        cout<< '|';
    }
    barras.append( "/");
    cout<< '/';

    if(estado.front() == 'b'){
        barras.append( "|");
        cout<< '|';

    }else if(estado.front() == 'r'){
        barras.append( "||");
        cout<< "||";

    }else if(estado.front() == 'm'){
        barras.append( "|||");
        cout<< "|||";

    }else if(estado.front() == 'd'){
        barras.append( "||||");
        cout<< "||||";
    }
     barras.append( "/");
    cout<<  endl;

    cout<< "string barras : "<< barras<< endl;

    ///LEEEMOS LA BARRA PARA DECODIFICARLO

    while(!salir){

        if(barras[i] == '/'){
            indice++;
            i++;
        }

        if(indice == 0){
            columna++;

        }else if(indice == 1){
            fila++;
        }else if(indice == 2){
            es_bool++;

        }else if(indice == 3){
            es_L++;
        }else{
            salir = 1;
        }
        i++;
    }

    cout<< "el libro se escuentra :"<< endl
        << "columna: "<<columna<< " en la fila: "<< fila<< endl;

        if(es_bool){
            cout<<"estado : disponible"<<endl;
        }else{
            cout<<"estado : no disponible"<<endl;
        }

    cout<< "estado: ";
        if(es_L == 1){
            cout<< "bueno"<< endl;

        }else if(es_L == 2){
            cout<< "regular"<< endl;

        }else if(es_L == 3){
            cout<< "malo"<< endl;

        }else if(es_L == 4){
            cout<< "destruido"<< endl;

        }
        return barras;
}