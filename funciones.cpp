#include<iostream>
#include<string>
#include<fstream>
#include<vector>

#include "funcionesH.h"
#include "socioH.h"
#include "libroH.h"

using namespace std;

void mostrar(vector<socio>& vector_Socio){

    cout<< "SOCIOS"<<endl;

    for(size_t i = 0; i<vector_Socio.size(); i++){
        cout<< "---------------"<< endl;
        cout<< "- ";
        vector_Socio[i].mostrar();
    }
}


void eliminarSocio(vector <socio>& vector_Socio){

    string busquedaDNI;
    bool salir = 0;

    cout<< "INGRESAR EL DNI DEL SOCIO"<<endl << " >> ";
    getline(cin, busquedaDNI);

    for(size_t i=0; i<vector_Socio.size(); i++){

        ///VALIDAR RETORNA 1 SI SE ENCONTRO
        if(vector_Socio[i].validar(busquedaDNI)){

                cout<< "SOCIO ELIMINADO.."<< endl;
                vector_Socio.erase(vector_Socio.begin() + i);
                i = vector_Socio.size();
                salir = 1;
                cout<< "SUBIR LOS CAMBIOS PARA QUE SE ACTUALIZE"<< endl;
        }
    }
    if(!salir){
        cout<< "NO SE ENCONTRO EL DNI DEL SOCIO"<< endl;
    }
}


void subirCambios(vector <socio>& vector_Socio, int opcionMenu){

    string linea;
    fstream file;
    string aux;
    int cont = 0;

/**COMENTADO : AGREGA DNI A LOS SOCIOS */
/*
    for(size_t i=0; i<vector_Socio.size(); i++){

        if (i <= 50) {
            aux = "111" + std::to_string(cont);

        } else if (i > 50 && i <= 100) {
            aux = "222" + std::to_string(cont);

        } else if (i > 100 && i <= 150) {
            aux = "333" + std::to_string(cont);

        } else {
            aux = "444" + std::to_string(cont);

        }
        cont++;
        if(cont > 50){
            cont = 0;
        }
        vector_Socio[i].setDato(aux, 2);
    }
*/
    ///SOCIO
    if(opcionMenu == 1){

        ///OUT PARA ESCRIBIR Y TRUNC PARA ELIMINAR EL CONTENIDO ANTERIOIR DEL ARCHIVO
        file.open("lista de socios.csv", ios::out | ios::trunc);
        for(size_t i=0; i<vector_Socio.size(); i++){

            file << vector_Socio[i].stringFile()<<'\n';
        }

        file.close();

    }else{///LIBRO

    }

}


///MODIFICA EL VECTOR Y EN LA FUNCION < subirCambios > SOBREESCRIBIMOS EL ARCHIVO CON EL VECTOR
void modificar_Socio(vector <socio>& vector_Socio){

    string socioDNIB;///VARIABLE AUXILIAR PARA LA BUSQUEDA DEL SOCIO
    string nuevoValor;///ALMACENA EL NUEVO VALOR
    int posDato = 0;

    cout<< "INGRESE EL DNI DEL SOCIO A MODIFICAR : ";
    getline(cin, socioDNIB);

    ///RECORRE HASTA QUE I SE IGUAL AL TAMA�O DEL VECTOR
    for(size_t i=0; i<vector_Socio.size(); i++){

       ///VALIDA SI EL DNI COINCIDE CON ALGUN DNI DEL VECTOR
       if(vector_Socio[i].validar(socioDNIB)){

            cout<< "SOCIO ENCONTRADO.."<< endl<< ">> ";
            ///MOSTRAMOS AL SOCIO EN CUENSTION
            vector_Socio[i].mostrar();

            cout<< "QUE CAMPO QUIERE MODIFICAR : "
                << "1-APELLIDO  2-DNI   3-SEXO   4-DIRECCION    "
                << "5-TELEFONO  6-EDAD  7-FECHA NACIMIENTO  8-MAIL >> ";
            cin >> posDato;

            ///IGNORA EL ENTER PARA EVITAR LEERLO
            cin.ignore();

            switch(posDato){

            ///TOMA EL NUEVO VALOR Y LO PASAMOS AL METODO DEL OBJETO PARA MOFICARLO
            case 1 :
                cout<< "INGRESE EL NUEVO VALOR : ";
                getline(cin, nuevoValor);

                ///PARAMETROS : EL VALOR NUEVO, Y LA OPCION DEL DATO A CAMBIAR
                vector_Socio[i].setDato(nuevoValor, posDato);break;

            case 2 :
                cout<< "INGRESE EL NUEVO VALOR : ";
                getline(cin, nuevoValor);
                vector_Socio[i].setDato(nuevoValor, posDato);break;

            case 3 :
                cout<< "INGRESE EL NUEVO VALOR : ";
                getline(cin, nuevoValor);
                vector_Socio[i].setDato(nuevoValor, posDato);break;

            case 4:
                cout<< "INGRESE EL NUEVO VALOR : ";
                getline(cin, nuevoValor);
                vector_Socio[i].setDato(nuevoValor, posDato);break;

            case 5 :
                cout<< "INGRESE EL NUEVO VALOR : ";
                getline(cin, nuevoValor);
                vector_Socio[i].setDato(nuevoValor, posDato);break;

            case 6 :
                cout<< "INGRESE EL NUEVO VALOR : ";
                getline(cin, nuevoValor);
                vector_Socio[i].setDato(nuevoValor, posDato);break;

            case 7 :
                cout<< "INGRESE EL NUEVO VALOR : ";
                getline(cin, nuevoValor);
                vector_Socio[i].setDato(nuevoValor, posDato);break;

            case 8 :
                cout<< "INGRESE EL NUEVO VALOR : ";
                getline(cin, nuevoValor);
                vector_Socio[i].setDato(nuevoValor, posDato);break;

            default :
                cout<< "OPCIOP INCORRECTA"<< endl;
            }

            ///YA QUE SE ENCONTRO AL SOCIO TERMINAMOS EL BUCLE
            cout<< "SUBIR LOS CAMBIOS PARA QUE SE ACTUALIZE"<< endl;
             i = vector_Socio.size();
       }
    }
}

/// ABRE UN ARCHIVO VALIDO Y LO RETORNA
fstream archivo_IO(vector <socio>& vector_Socio, int opcionArchivo) {

    fstream file;///ALMACENAMOS LA DIRECCION DEL ARCHIVO

    ///OPCION 1 - SOCIOS   --   2 - LIBRO
    if(opcionArchivo == 1){
    ///SOCIOS

        file.open("lista de socios.csv", ios::in);

        if(file.fail()){

            cout<< "ERROR AL ABRIR EL ARCHIVO ( FUNCION )   ";
            cout<< "VERIFICAR QUE EL ARCHIVO EXISTA"<< endl;

            ///RETORNA EL ARCHIVO QUE ES NULL
            return file;
        }

    }else if(opcionArchivo == 2){
    ///LIBRO


    }else{
        cout<< "OPCION DE ARCHIVO INCORRECTA"<< endl;

    }

    ///SI TODO SALE BIEN RETORNAMOS LA DIRECCION DEL ARCHIVO
    return file;
}


///TOMA LA LINEA DEL ARCHIVO Y LO PLASMA EN VARIABLES
void lecturaLinea(vector <socio>& vector_Socio, fstream& file){

    int _posicionA = 0;///INDICA EN QUE POSICION ( LINEA ) DEL ARCHIVO SE ENCUENTRA
    int contDato = 1;///PARA IDENTIFICAR EN QUE TIPO DE DATO ESTAMOS
    int indice = 0;

    string lineaDato;///es donde guardaremos los datos tomados del archivo
    string _apellido, _dni, _genero, _direccion, _numeroT, _edad, _fechaC, _mail;

    ///TOMA LA LINEA DE DATOS HASTA QUE FINALIZA Y DEVULVE FALSE
     while(getline(file, lineaDato)){

        ///ITERAMOS HASTA EL FINAL DEL STRING ( LINEA )
        while(lineaDato[indice] != '\0'){

            ///SI ENCEUNTRA UNA < , > LO SALTEA
            if(lineaDato[indice] == ','){

                ///PASAMOS AL SIGUITE DATO
                contDato++;

                ///PASAMOS AL SIGUIETE INDICE
                indice++;

            ///SALTEAMOS LAS COMILLAS
            }else if(lineaDato[indice] == '"'){
                indice++;

            }else{

                ///RECORREMOS CADA DATO GUARDANDO CHAR X CHAR HASTA TERMINAR DE RECORRERLO
                if(contDato == 1){

                    _apellido += lineaDato[indice];
                    indice++;

                }else if(contDato == 2){
                    _dni += lineaDato[indice];
                    indice++;

                }else if(contDato == 3){
                    _genero += lineaDato[indice];
                    indice++;

                }else if(contDato == 4){
                    _direccion += lineaDato[indice];
                    indice++;

                }else if(contDato == 5){
                    _numeroT += lineaDato[indice];
                    indice++;

                }else if(contDato == 6){
                    _edad += lineaDato[indice];
                    indice++;

                }else if(contDato == 7){
                    _fechaC += lineaDato[indice];
                    indice++;

                }else if(contDato == 8){
                    _mail += lineaDato[indice];
                    indice++;
                }
            }

        }///FIN WHILE QUE RECORRE HASTA UN ' \0 '

        ///SE AGREGA DE FORMA DINAMICA UN NUEVO ESPACIO DE VECTOR CON LO QUE INICILIAZAMOS ESOS VALORES TOMADOS
        vector_Socio.push_back(socio(_apellido, _dni, _genero, _direccion, _numeroT, _edad, _fechaC, _mail, _posicionA));

        ///LIMPIAMOS LOS STRING PARA EVITAR SOBREESCRIBIR LOS DATOS UNOS SOBRE OTROS
        lineaDato.clear();
        _apellido.clear();
        _dni.clear();
        _genero.clear();
        _direccion.clear();
        _numeroT.clear();
        _edad.clear();
        _fechaC.clear();
        _mail.clear();

        ///MODIFICAMOS VARIABLES PARA CADA LINEA NUEVA
        indice=0;
        contDato = 1;
        _posicionA++;
     }

     ///CERRAMOS EL ARACHIVO
     file.close();
}
