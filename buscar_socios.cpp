#include "buscar_socios.h"
#include "func.h"
void busqueda_socios(vector<socio> &socios){
string eleccion;
do{
cout<<"Seleccione una opcion de busqueda y filtrado de socios: "<<endl;
cout<<" 1.Apellido\n 2.Dni\n 3.Sexo\n 4.Direccion\n 5.Numero de Telefono\n 6.Edad\n 7.Fecha de Nacimiento\n 8.Mail"<<endl;
cin>>eleccion;
}while(eleccion != "1" && eleccion != "2" && eleccion != "3" && eleccion != "4" && eleccion != "5"&& eleccion != "6"&& eleccion != "7"&& eleccion != "8");
int opcion = stoi(eleccion); //evitamos overflow de int, hacemos string to int
switch(opcion){
    case 1:{
bool existe;
do{
    existe = false;
    string apellido_busc ;
    cout<<"Ingrese el Apellido a Buscar: "<<endl;
    cin>>apellido_busc;
    apellido_busc = a_minusculas(apellido_busc);
    for(size_t i = 0; i<socios.size();i++){
    if(apellido_busc == a_minusculas(socios[i].getapll())){ //aparecen todas las personas que coincidan con el apellido
//size_t es un unsigned int o long
cout<<"--------------------"<<endl;
cout<<"Apellido: "<<socios[i].getapll()<<endl;
cout<<"DNI: "<<socios[i].getdni()<<endl;
cout<<"Sexo: "<<socios[i].getsex()<<endl;
cout<<"Direccion: "<<socios[i].getdir()<<endl;
cout<<"Numero: "<<socios[i].getnum()<<endl;
cout<<"Edad: "<<socios[i].getedad()<<endl;
cout<<"Fecha de Nacimiento: "<<socios[i].getfechaN()<<endl;
cout<<"Email: "<<socios[i].getmail()<<endl;
existe = true;

    }
    }
    if(!existe){
        cout<<"El apellido indicado no existe."<<endl;
    }
}while(!existe);
}break;

    case 2:{
bool existe ;
do{
existe = false;
string dni_ ;
cout<<"Ingrese el Dni a Buscar: "<<endl;
cin>>dni_;
    for(size_t i = 0; i<socios.size();i++){
        if(dni_ == socios[i].getdni()){ 
        cout<<"--------------------"<<endl;
        cout<<"Apellido: "<<socios[i].getapll()<<endl;
        cout<<"DNI: "<<socios[i].getdni()<<endl;
        cout<<"Sexo: "<<socios[i].getsex()<<endl;
        cout<<"Direccion: "<<socios[i].getdir()<<endl;
        cout<<"Numero: "<<socios[i].getnum()<<endl;
        cout<<"Edad: "<<socios[i].getedad()<<endl;
        cout<<"Fecha de Nacimiento: "<<socios[i].getfechaN()<<endl;
        cout<<"Email: "<<socios[i].getmail()<<endl;
        existe = true;
    }
}
            if(!existe){
                cout<<"El Dni no existe."<<endl;
            }
    }while(!existe);
}
    break;
    case 3:{
string sexo_busc;
cout<<"Ingrese el sexo a buscar(female, male): "<<endl;
cin>>sexo_busc;
sexo_busc = a_minusculas(sexo_busc);
while(sexo_busc !="male" && sexo_busc != "female"){//no tiene q ser ninguna de las 2 opciones para seguir pidiendo el ingreso
cout<<"El sexo ingresado no existe."<<endl;
cout<<"Ingrese el sexo a buscar(female, male): "<<endl;
cin>>sexo_busc;
sexo_busc = a_minusculas(sexo_busc);
}
    for(size_t i = 0; i<socios.size();i++ ){
        if(sexo_busc == socios[i].getsex()){
        cout<<"--------------------"<<endl;
        cout<<"Apellido: "<<socios[i].getapll()<<endl;
        cout<<"DNI: "<<socios[i].getdni()<<endl;
        cout<<"Sexo: "<<socios[i].getsex()<<endl;
        cout<<"Direccion: "<<socios[i].getdir()<<endl;
        cout<<"Numero: "<<socios[i].getnum()<<endl;
        cout<<"Edad: "<<socios[i].getedad()<<endl;
        cout<<"Fecha de Nacimiento: "<<socios[i].getfechaN()<<endl;
        cout<<"Email: "<<socios[i].getmail()<<endl;
        }
    }
    }
    break;
    case 4:{
bool bandera;
cin.ignore();
do{
bandera = false;
cout<<"Ingrese la Direccion a buscar: "<<endl;
string direccion_busc;
//ignora el salto de linea(que queda en el buffer despues de leer) para que getline funcione correctamente
getline(cin, direccion_busc);
direccion_busc = a_minusculas(borrar_comillas(direccion_busc));
    for(size_t i = 0; i<socios.size();i++ ){
        if(direccion_busc == a_minusculas(borrar_comillas(socios[i].getdir()))){
        cout<<"--------------------"<<endl;
        cout<<"Apellido: "<<socios[i].getapll()<<endl;
        cout<<"DNI: "<<socios[i].getdni()<<endl;
        cout<<"Sexo: "<<socios[i].getsex()<<endl;
        cout<<"Direccion: "<<socios[i].getdir()<<endl;
        cout<<"Numero: "<<socios[i].getnum()<<endl;
        cout<<"Edad: "<<socios[i].getedad()<<endl;
        cout<<"Fecha de Nacimiento: "<<socios[i].getfechaN()<<endl;
        cout<<"Email: "<<socios[i].getmail()<<endl;
        bandera = true;
        }
    }
            if(!bandera){
                cout<<"La direccion ingresada no existe."<<endl;
            }

    }while(!bandera);
}
    break;
    case 5:{
bool existe;
do{
string num_busc;
cout<<"Ingrese el numero a buscar: "<<endl;
cin>>num_busc;
existe = false;
num_busc = borrar_comillas(num_busc);
    for(unsigned long i = 0; i< socios.size();i++){//.Size devuelve un unsigned long
        if(num_busc == socios[i].getnum()){
            cout<<"--------------------"<<endl;
            cout<<"Apellido: "<<socios[i].getapll()<<endl;
            cout<<"DNI: "<<socios[i].getdni()<<endl;
            cout<<"Sexo: "<<socios[i].getsex()<<endl;
            cout<<"Direccion: "<<socios[i].getdir()<<endl;
            cout<<"Numero: "<<socios[i].getnum()<<endl;
            cout<<"Edad: "<<socios[i].getedad()<<endl;
            cout<<"Fecha de Nacimiento: "<<socios[i].getfechaN()<<endl;
            cout<<"Email: "<<socios[i].getmail()<<endl;
            existe = true;
        }
}
            if(!existe){
                cout<<"El numero ingresado no existe."<<endl;
            }

    }while(!existe);
}
    break;
    case 6:{
string entrada;
do{
cout<<"Ingrese una opcion de busqueda de edad: "<<endl;
cout<<"1.Mayores a 18.\t 2.Mayores a 30.\t 3.Mayores a 60.\t 4.Edad Especifica.\n"<<endl;
cin>>entrada; //almacenamos un string para evitar overflow si fuera un int
}while(entrada != "1" && entrada != "2" && entrada != "3" && entrada != "4"); //mientras no sea la correcta
//int opcion  = entrada[0] - '0'; //en ASCII cuando restamos el caracter '0' a numeros de un digito nos da su version numerica
int opcion = stoi(entrada);//o simplemente hacemos un string to int de la cadena 
    switch(opcion){
        case 1:{//+18
              cout<<"Socios Mayores a 18."<<endl;
        for(size_t i = 0; i<socios.size(); i++){
            if(stoi(socios[i].getedad()) >= 18){//string to int de edad
            cout<<"--------------------"<<endl;
            cout<<"Apellido: "<<socios[i].getapll()<<endl;
            cout<<"DNI: "<<socios[i].getdni()<<endl;
            cout<<"Sexo: "<<socios[i].getsex()<<endl;
            cout<<"Direccion: "<<socios[i].getdir()<<endl;
            cout<<"Numero: "<<socios[i].getnum()<<endl;
            cout<<"Edad: "<<socios[i].getedad()<<endl;
            cout<<"Fecha de Nacimiento: "<<socios[i].getfechaN()<<endl;
            cout<<"Email: "<<socios[i].getmail()<<endl;
            }
        }
            break;
        }
        case 2:{//+30
              cout<<"Socios Mayores a 30."<<endl;
            for(unsigned long i = 0; i<socios.size(); i++){
            if(stoi(socios[i].getedad()) >= 30){//string to int de edad
            cout<<"--------------------"<<endl;
            cout<<"Apellido: "<<socios[i].getapll()<<endl;
            cout<<"DNI: "<<socios[i].getdni()<<endl;
            cout<<"Sexo: "<<socios[i].getsex()<<endl;
            cout<<"Direccion: "<<socios[i].getdir()<<endl;
            cout<<"Numero: "<<socios[i].getnum()<<endl;
            cout<<"Edad: "<<socios[i].getedad()<<endl;
            cout<<"Fecha de Nacimiento: "<<socios[i].getfechaN()<<endl;
            cout<<"Email: "<<socios[i].getmail()<<endl;
            }
        }
        break;
    }
        case 3:{//+60
              cout<<"Socios Mayores a 60."<<endl;
            for(unsigned long i = 0; i<socios.size(); i++){
            if(stoi(socios[i].getedad()) >= 60){//string to int de edad
            cout<<"--------------------"<<endl;
            cout<<"Apellido: "<<socios[i].getapll()<<endl;
            cout<<"DNI: "<<socios[i].getdni()<<endl;
            cout<<"Sexo: "<<socios[i].getsex()<<endl;
            cout<<"Direccion: "<<socios[i].getdir()<<endl;
            cout<<"Numero: "<<socios[i].getnum()<<endl;
            cout<<"Edad: "<<socios[i].getedad()<<endl;
            cout<<"Fecha de Nacimiento: "<<socios[i].getfechaN()<<endl;
            cout<<"Email: "<<socios[i].getmail()<<endl;
            }
        }
         break;
    }
        case 4:{//edad especifica
            bool existe;
            do{
            string edad_busc;
            existe  = false;
            cout<<"Ingrese la edad a buscar: "<<endl;
            cin>>edad_busc;
            cout<<"Socios con "<<edad_busc<<" anios."<<endl;
            for(size_t i = 0; i < socios.size(); i++){
                if(socios[i].getedad()  == edad_busc){
            cout<<"--------------------"<<endl;
            cout<<"Apellido: "<<socios[i].getapll()<<endl;
            cout<<"DNI: "<<socios[i].getdni()<<endl;
            cout<<"Sexo: "<<socios[i].getsex()<<endl;
            cout<<"Direccion: "<<socios[i].getdir()<<endl;
            cout<<"Numero: "<<socios[i].getnum()<<endl;
            cout<<"Edad: "<<socios[i].getedad()<<endl;
            cout<<"Fecha de Nacimiento: "<<socios[i].getfechaN()<<endl;
            cout<<"Email: "<<socios[i].getmail()<<endl;
            existe  = true;
                }
            }
        }while(!existe);
            break;
        }
        default:{ 
            cout<<"Opcion ingresada invalida."<<endl;
        }
         break;
    }
}
    break;
    case 7:{
string fechaNaci_busc;
bool existe = false;
cout<<"Ingrese la Fecha de Nacimiento a buscar(mes/dia/anio(xx/xx/xxxx)): "<<endl;
cin>>fechaNaci_busc;//xx/xx/xxxx
fechaNaci_busc = borrar_ceros(fechaNaci_busc);
fechaNaci_busc = normalizar_anio(fechaNaci_busc);
    while(!fecha_valida(fechaNaci_busc)){// el formato es x/x/xxxx entonces [1] = / y [3] = / ya que usamos la funcion borrar_ceros
    cout<<"Formato incorrecto o fecha inexistente."<<endl;
    cout<<"Ingrese la Fecha de Nacimiento a buscar(mes/dia/anio(xx/xx/xxxx)): "<<endl;
    cin>>fechaNaci_busc;
    fechaNaci_busc = borrar_ceros(fechaNaci_busc);
    }
    for(unsigned long i = 0; i< socios.size();i++){//.Size devuelve un unsigned long
        if(fechaNaci_busc == socios[i].getfechaN()){
            cout<<"--------------------"<<endl;
            cout<<"Apellido: "<<socios[i].getapll()<<endl;
            cout<<"DNI: "<<socios[i].getdni()<<endl;
            cout<<"Sexo: "<<socios[i].getsex()<<endl;
            cout<<"Direccion: "<<socios[i].getdir()<<endl;
            cout<<"Numero: "<<socios[i].getnum()<<endl;
            cout<<"Edad: "<<socios[i].getedad()<<endl;
            cout<<"Fecha de Nacimiento: "<<socios[i].getfechaN()<<endl;
            cout<<"Email: "<<socios[i].getmail()<<endl;
            existe = true;
        }
}
            if(!existe){
                cout<<"La fecha ingresada no existe."<<endl;
            }
    }
    break;
    case 8:{
bool band;
do{
string mail_busc;
band = false;
cout<<"Ingrese el Mail a Buscar: "<<endl;
cin>>mail_busc;
mail_busc = a_minusculas(mail_busc);
    for(unsigned long i = 0; i<socios.size(); i++){ 
        if(a_minusculas(socios[i].getmail()) == mail_busc){
            cout<<"--------------------"<<endl;
            cout<<"Apellido: "<<socios[i].getapll()<<endl;
            cout<<"DNI: "<<socios[i].getdni()<<endl;
            cout<<"Sexo: "<<socios[i].getsex()<<endl;
            cout<<"Direccion: "<<socios[i].getdir()<<endl;
            cout<<"Numero: "<<socios[i].getnum()<<endl;
            cout<<"Edad: "<<socios[i].getedad()<<endl;
            cout<<"Fecha de Nacimiento: "<<socios[i].getfechaN()<<endl;
            cout<<"Email: "<<socios[i].getmail()<<endl;
            band = true;
}
}
if(!band){
    cout<<"El email "<<mail_busc<<" no existe."<<endl;
        }
    }while(!band);
}
    break;
    default:{
        cout<<"Error."<<endl;break;
    }
}
}
