#ifndef POO_PRACTICA_12_PERSONA_H
#define POO_PRACTICA_12_PERSONA_H

#include <iostream>
#include <string>
using namespace std;

class Persona {
protected:
  char *cod = new char [100];
  char *nombre = new char[100];
public:
  Persona();
  Persona(char*, char*);

  void llenar_data();
  void mostrar_data();
};

Persona::Persona() {
  *cod = ' ';
  *nombre = ' ';
}

Persona::Persona(char *c, char *n) {
  cod = c;
  nombre = n;
}

void Persona::llenar_data() {
  fflush(stdin);
  cout << "Nombre: "; cin.getline(nombre,101,'\n');
  cout << "Codigo: "; cin.getline(cod,101,'\n');
}

void Persona::mostrar_data() {
  cout<<"Nombre : "<<nombre<<endl;
  cout<<"Codigo : "<<cod<<endl;
}

// ------------- CLASE ALUMNO ---------------

class Alumno : public Persona {
protected:
  char *creditos=new char [100];
  int limite;
public:
  Alumno();
  Alumno(char*, char*, char*, int);
  void llenarAlumno();
  void mostrarAlumno();
  char* getCod();
  char* getNombre();
  int getLimite();
  void setLimite(int);
};

Alumno::Alumno(){
  *creditos = ' ';
  limite = 0;
}

Alumno::Alumno(char *c, char *n, char *cred, int lim): Persona(c, n){
  creditos = cred;
  limite = lim;
}

void Alumno::llenarAlumno() {
  fflush(stdin);
  cin.ignore();
  Persona::llenar_data();
  cout<<"Creditos: ";cin.getline(creditos,101,'\n');
  limite = 2;
}

void Alumno::mostrarAlumno() {
  Persona::mostrar_data();
  cout<<"Creditos: "<<creditos<<endl;
  cout<<"----------------------------------------------------"<<endl;
}

char *Alumno::getCod() {
  return cod;
}

char *Alumno::getNombre() {
    return nombre;
}

int Alumno::getLimite() {
  return limite;
}

void Alumno::setLimite(int l) {
  limite = l;
}


/* ------------------ CLASE PROFESOR ------------------- */

class Profesor : public Persona {
protected:
  char *cursos = new char [100];
  int limite;
public:
  Profesor();
  Profesor(char*, char*, char*, int);
  void llenarProfesor();
  void mostrarProfesor();
  char* getCod();
  char* getNombre();
  int getLimite();
  void setLimite(int);
};

Profesor::Profesor(){
  *cursos = ' ';
  limite = 0;
}

Profesor::Profesor(char *c, char *n, char *cred, int lim): Persona(c, n){
  cursos = cred;
  limite = lim;
}

void Profesor::llenarProfesor() {
  fflush(stdin);
  cin.ignore();
  Persona::llenar_data();
  cout<<"Cursos: ";cin.getline(cursos,101,'\n');
  limite = 3;
}

void Profesor::mostrarProfesor() {
  Persona::mostrar_data();
  cout<<"Cursos: "<<cursos<<endl;
  cout<<"--------------------------------------------"<<endl;
}

char *Profesor::getCod() {
  return cod;
}

char *Profesor::getNombre() {
  return nombre;
}

int Profesor::getLimite() {
  return limite;
}

void Profesor::setLimite(int l) {
  limite = l;
}

#endif //POO_PRACTICA_13_PERSONA_H
