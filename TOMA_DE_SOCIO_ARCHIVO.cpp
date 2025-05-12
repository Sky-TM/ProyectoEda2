#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

class socio{
///atributos archivos
    string apellido;
    string dni;
    string sexo;
    string direccion;
    string num_telefonico;
    string edad;
    string fechaN;
    string mail;

public :
    socio();
    socio(string, string, string, string, string, string, string, string);
    ~socio();
    void mostrar();

};

//----------->
class libro{
///atributos archivos
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
    libro(string, string, string, string, string, string, string);
    ~libro();
    void generar_barras();

};

//----------->
class gestion_p : public libro, public socio{

    string fecha_devoluciom;
    bool excedido; //0 > no || 1 > si
};
//----------->
void lectura_linea(string, vector <socio>&);///funcion que toma la linea ( Linea 68 ) y la desarma

int main(){

    string lineaDato;///es donde guardaremos los datos tomados del archivo

    vector < socio > vector_Socio;/// VECTOR DINAMICO TIPOS SOCIO

     ifstream file("lista de socios.csv");///abrimos el archivo en modo lectura ( input )

     if(!file){
        cout<< "error"<< endl;

     }else{

        while(!file.eof()){//pregunta si llega al final del archivo
            getline(file, lineaDato);//toma la linea de dato

            lectura_linea(lineaDato, vector_Socio);//le pasamos < linea > y el vector
        }

       for(int i=0; i< vector_Socio.size(); i++){///recorre el vector mostrando los datos

            vector_Socio[i].mostrar();
       }

     }


    return 0;
}
/**FUNCIONES MAIN*/
void lectura_linea(string lineaDato, vector <socio>& vector_Socio){

    int contDato = 1;///PARA IDENTIFICAR EN QUE TIPO DE DATO ESTAMOS
    int i = 0;
    string _apellido, _dni, _genero, _direccion, _numeroT, _edad, _fechaC, _mail;

    while(lineaDato[i] != '\0'){///ITERAMOS HASTA EL FINAL DEL STRING

        if(lineaDato[i] == ','){///SI ENCEUNTRA UNA < , > LO SALTEA
            i++;///PASAMOS AL SIGUIETE INDICE
        }else if(lineaDato[i] == '"'){///SALTEAMOS LAS COMILLAS
            i++;

        }else{

            ///RECORREMOS CADA DATO GUARDANDO CHAR X CHAR HASTA TERMINAR DE RECORRERLO
            if(contDato == 1){

                _apellido += lineaDato[i];
                i++;

            }else if(contDato == 2){
                _dni += lineaDato[i];
                i++;

            }else if(contDato == 3){
                _genero += lineaDato[i];
                i++;

            }else if(contDato == 4){
                _direccion += lineaDato[i];
                i++;

            }else if(contDato == 5){
                _numeroT += lineaDato[i];
                i++;

            }else if(contDato == 6){
                _edad += lineaDato[i];
                i++;

            }else if(contDato == 7){
                _fechaC += lineaDato[i];
                i++;

            }else if(contDato == 8){
                _mail += lineaDato[i];
                i++;
            }
        }

    }

    ///GUARDAMOS ESOS DATOS EN EL VECTOR DINAMICO PASADO POR REFERENCIA
    vector_Socio.push_back(socio(_apellido, _dni, _genero, _direccion, _numeroT, _edad, _fechaC, _mail));

    ///FIN
}

/**CLASE SOCIO - METODOS*/

socio::socio(string _apellido, string _dni, string _genero, string _direccion, string _numeroT, string _edad, string _fechaN, string _mail ){

    apellido = _apellido;
    dni = _dni;
    sexo = _genero;
    direccion = _direccion;
    num_telefonico = _numeroT;
    edad = _edad;
    fechaN = _fechaN;
    mail = _mail;
}

socio::socio(){
}

socio::~socio(){

    //cout<< "llamada a destructor"<< endl;
}

void socio::mostrar(){


    cout<< apellido<< "   "<< dni<< "   "<< sexo<< "   "
            << direccion<< "   "<< num_telefonico<< "   "<< edad<< "   "
            << fechaN<< "   "<< mail<< endl;

}
/**CLASE LIBRO - METODOS*/

void libro::generar_barras(){

    ///LOS DATOS SERAN REPRESENTADO POR  > |
    ///LOS SEPARAMOS CON > /
   int columna=0; //columna donde se encuentra el libro
   int fila=0; //fila donde se encuentra el libro
   int stateSN=0;
   int stateLibro=0;
   int i=0, salir = 0;

    int indice = 0;
    string cod_Barras;

///FILA Y COLUMNA
///LEE LA COLUMNA ( PRIMER DATO ) Y LUEGO LA FILA ( SEGUNDO DATO )

    for(int i=0; i<=1 ; i++){

        for(int j = ubicacionL[i]; j>0; j--){
            cod_Barras.append("|");
            cout<< '|';
        }
        cod_Barras.append( "/");///SEPARA COLUMNA DE FILA
        cout<< '/';
    }

///ESTADO DISPONIBLE O NO >> 1 SI // 0 NO
    if(estadoSN){//SI
        cod_Barras.append( "||");
        cout<< "||";

    }else{//NO
        cod_Barras.append( "|");
        cout<< '|';

    }

    cod_Barras.append( "/");///SEPARADOR
    cout<< '/';

///LEE EL PRIMER BYTES Y A VACE DE ESO LE ASIGNAMOS CIERTA LETRA
/// B > BUENO // R > REGULAR // M > MALO // D > DESTRUIDO
    if(estado.front() == 'b'){
        cod_Barras.append( "|");
        cout<< '|';

    }else if(estado.front() == 'r'){
        cod_Barras.append( "||");
        cout<< "||";

    }else if(estado.front() == 'm'){
        cod_Barras.append( "|||");
        cout<< "|||";

    }else if(estado.front() == 'd'){
        cod_Barras.append( "||||");
        cout<< "||||";
    }
     cod_Barras.append( "/");
    cout<<  endl;

///IMPRIME EL CODIGO DE BARRAS
    cout<< "string cod_Barras : "<< cod_Barras<< endl;


///LEEEMOS LA BARRA PARA DECODIFICARLO
    while(!salir){

        if(cod_Barras[i] == '/'){///SI ENCUENTRA UN SEPARADOR AUMENTA AL SIGUIENTE TIPO  Y AUMENTAMOS INDICE
            indice++;
            i++;
        }

        if(indice == 0){
            columna++;

        }else if(indice == 1){
            fila++;
        }else if(indice == 2){
            stateSN++;

        }else if(indice == 3){
            stateLibro++;

        }else{
            salir = 1;

        }
        i++;
    }

///IMPRIMIMOS EL CODIGO DE BARRAS
    cout<< "el libro se escuentra :"<< endl
        << "columna: "<<columna<< " en la fila: "<< fila<< endl;

        if(stateSN){
            cout<<"estado : disponible"<<endl;
        }else{
            cout<<"estado : no disponible"<<endl;
        }

    cout<< "estado: ";
        if(stateLibro == 1){
            cout<< "bueno"<< endl;

        }else if(stateLibro == 2){
            cout<< "regular"<< endl;

        }else if(stateLibro == 3){
            cout<< "malo"<< endl;

        }else if(stateLibro == 4){
            cout<< "destruido"<< endl;

        }

}
