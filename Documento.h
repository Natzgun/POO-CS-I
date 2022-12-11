#ifndef POO_PRACTICA_12_DOCUMENTO_H
#define POO_PRACTICA_12_DOCUMENTO_H

#include <iostream>
#include <string>
using namespace std;

class Documento {
protected:
  char *nombre = new char[100];
  char *autor = new char[100];
public:
  Documento();
  Documento(char*, char*);

  void llenar_data();
  void mostrar_data();
};

Documento::Documento() {
  *nombre = ' ';
  *autor = ' ';
}

Documento::Documento(char *name, char *a) {
  nombre = name;
  autor = a;
}

void Documento::llenar_data() {
  fflush(stdin);
  cout << "Nombre: "; cin.getline(nombre,101,'\n');
  cout << "Autor: "; cin.getline(autor,101,'\n');
}

void Documento::mostrar_data() {
   cout << "Nombre: " << nombre << endl;
   cout << "Autor: " << autor << endl;
}

// -------------- CLASE TESIS -------------

class Tesis : public Documento {
protected:
  char *repositorio = new char[100];
  int stock;
public:
  Tesis();
  Tesis(char*,char*,char*, int);
  void llenarTesis();
  void mostrarTesis();
  char* getNombre();
  char* getAutor();
  int getStock();
  void setStock(int);
};

Tesis::Tesis() {
  *repositorio = ' ';
  stock = 0;
}

Tesis::Tesis(char *name, char *a, char *repo, int s): Documento (name, a) {
  repositorio = repo;
  stock = s;
}

void Tesis::llenarTesis() {
  fflush(stdin);
  cin.ignore();
  Documento::llenar_data();
  cout << "Repository: "; cin.getline(repositorio,101,'\n');
  cout << "Stock: "; cin >> stock;
}

void Tesis::mostrarTesis() {
  Documento::mostrar_data();
  cout << "Repository: " << repositorio << endl;
  cout << "Stock: " << stock << endl;
  cout<<"----------------------------------------------------"<<endl;
}

char *Tesis::getNombre() {
  return nombre;
}

char *Tesis::getAutor() {
  return autor;
}

int Tesis::getStock() {
  return stock;
}

void Tesis::setStock(int s) {
  stock = s;
}

// ---------------- CLASE LIBRO -------------

class Libros : public Documento {
protected:
  char *editorial = new char[100];
  int stock;
public:
  Libros();
  Libros(char*, char*, char*, int);
  void llenarLibros();
  void mostrarLibros();
  char* getNombre();
  char* getAutor();
  int getStock();
  void setStock(int);
};

Libros::Libros() {
  *editorial = ' ';
  stock = 0;
}

Libros::Libros(char *name, char *a, char *edito, int s): Documento (name, a) {
  editorial = edito;
  stock = s;
}

void Libros::llenarLibros() {
  fflush(stdin);
  cin.ignore();
  Documento::llenar_data();
  cout << "Editorial: "; cin.getline(editorial, 101, '\n');
  cout << "Stock: "; cin >> stock;
}

void Libros::mostrarLibros() {
  Documento::mostrar_data();
  cout << "Editorial: " << editorial << endl;
  cout << "Stock: " << stock << endl;
  cout<<"----------------------------------------------------"<<endl;
}

char *Libros::getNombre() {
  return nombre;
}

char *Libros::getAutor() {
  return autor;
}

int Libros::getStock() {
  return stock;
}

void Libros::setStock(int s) {
  stock = s;
}

// -------------- CLASE REVISTA ------------

class Revistas : public Documento {
protected:
  char *editorial = new char[100];
  int stock;
public:
  Revistas();
  Revistas(char*, char*, char*, int);
  void llenarRevistas();
  void mostrarRevistas();
  char* getNombre();
  char* getAutor();
  int getStock();
  void setStock(int);
};

Revistas::Revistas() {
  *editorial = ' ';
  stock = 0;
}

Revistas::Revistas(char *name, char *a, char *edito, int s): Documento (name, a) {
  editorial = edito;
  stock = s;
}

void Revistas::llenarRevistas() {
  fflush(stdin);
  cin.ignore();
  Documento::llenar_data();
  cout << "Editorial: "; cin.getline(editorial, 101, '\n');
  cout << "Stock: "; cin >> stock;
}

void Revistas::mostrarRevistas() {
  Documento::mostrar_data();
  cout << "Editorial: " << editorial << endl;
  cout << "Stock: " << stock << endl;
  cout<<"----------------------------------------------------"<<endl;
}

char *Revistas::getNombre() {
  return nombre;
}

char *Revistas::getAutor() {
  return autor;
}

int Revistas::getStock() {
  return stock;
}

void Revistas::setStock(int s) {
  stock = s;
}

#endif //POO_PRACTICA_12_DOCUMENTO_H
