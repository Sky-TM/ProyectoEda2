#include<iostream>
#include<string>
#include<fstream>
#include<vector>

#include "funcionesH.h"
#include "socioH.h"
#include "libroH.h"

using namespace std;

int main()
{
    short opcion_file;
    short opcionMenu = 0;
    short opcionMenu2 = 0;
    int salir = 0;
    int contRepe = 1;

    vector < socio > vector_Socio;/// VECTOR DINAMICO TIPOS SOCIO

    fstream file;///SIRVE PARA ACCEDER A LOS ARCHIVOS


    while(!salir){///ITERA HASTA QUE SALIR SEA 1

        cout<< endl<< endl;
        cout<< "<< MENU >>"<< endl;
        cout<< "1- SOCIOS   2-LIBRO    3-SALIR"<< endl<< ">> ";
        cin >> opcionMenu;

        switch(opcionMenu){

        case 1 :

            ///SOLO SE ABRE EL ARCHIVO 1 VEZ
            ///CUANDO LO VAMOS A PLASMAR EN VECTOR
            if(contRepe == 1){

                ///ABRIMOS EL ARCHIVO
                file = archivo_IO(vector_Socio, opcionMenu);

                ///VERIFICAMOS QUE SE ASIGNO
                if(file.fail()){
                        ///SI NO IMPRIMOS Y RETORNAMOS
                    cout<< "ERROR AL ABRIR EL ARCHIVO ( MAIN )"<< endl;
                    return 1;
                }

                ///TOMA LOS DATOS DEL ARCHIVO Y CIERRA ARCHIVO
                lecturaLinea(vector_Socio, file);
                contRepe++;
            }

            ///ABRIMOS EL ARCHIVO Y TOMAMOS SUS DATOS PARA VOLVARLO EN EL VECTOR
            cout<< "1-MODIFICAR SOCIO    2-ELIMINAR SOCIO ( BAJA ) "
                << "3-SUBIR CAMBIOS( ALTA )   4-VER SOCIOS  "<<endl
                << ">>  ";
            cin >> opcionMenu2;
            ///IGNORAMOS EL SALTO DE LINEA
            cin.ignore();

            if(opcionMenu2 == 1){
                modificar_Socio(vector_Socio);

            }else if(opcionMenu2 == 2){
                eliminarSocio(vector_Socio);

            }else if(opcionMenu2 == 3){
                subirCambios(vector_Socio, opcionMenu);
                cout<< " CAMBIOS GUARDADOS.."<< endl;

            }else if(opcionMenu2 == 4){
                mostrar(vector_Socio);

            }else{
                cout<< "OPCION INCORRECTE"<< endl;
            }

            break;

        case 2 :
            break;

        case 3 :
            cout<< "SALIENDO DEL MENU.."<<endl;
            salir = 1;
            break;

        default :
            cout<< "OPCION DEL MENU INVALIDO"<< endl;break;
        }

    }

    return 0;
}
