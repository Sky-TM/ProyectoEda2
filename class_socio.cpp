#include "class_socio.h"

// constructor
socio::socio(string apellido_, string dni_, string sexo_, string direccion_, string num_telefonico_, string edad_, string fechaN_, string mail_) {
    apellido = apellido_;
    dni = dni_;
    sexo = sexo_;
    direccion = direccion_;
    num_telefonico = num_telefonico_;
    edad = edad_;
    fechaN = fechaN_;
    mail = mail_;
}

// getters
string socio::getapll() { 
    return apellido;
 }
string socio::getdni() { 
    return dni; 
}
string socio::getsex() { 
    return sexo; 
}
string socio::getdir() {
     return direccion;
     }
string socio::getnum() {
     return num_telefonico;
     }
string socio::getedad() {
     return edad; 
    }
string socio::getfechaN() {
     return fechaN;
     }
string socio::getmail() { 
    return mail; 
}

