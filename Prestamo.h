#ifndef POO_PRACTICA_12_PRESTAMO_H
#define POO_PRACTICA_12_PRESTAMO_H

#include <iostream>
using namespace std;


class Prestamo {
protected:  
  int codigo;
  char *fecha = new char[100];
  char *usuario = new char[100];
  char *prestamo = new char[100];
  int limiteFinal; // para almacenar el limite final de lo que le queda
  //Persona *totalPersonas = new Persona[100];
  //Documento *totalDocumentos = new Documento[100];
public:
  Prestamo();
  //void traerPersonas(Alumno*, Profesor*);
  //void traerDocumentos(Libros*, Tesis*, Revistas*);
  void llenarPrestamo(Alumno*[], Profesor*[], Libros*[], Tesis*[], Revistas*[]);
  bool validar(char*, char*);
  void mostrarPrestamo();
};

Prestamo::Prestamo() {
  codigo = 0;
  *fecha = ' ';
  *usuario = ' ';
  *prestamo = ' ';
  limiteFinal = 0;
  /*for (int i = 0; i < 100; i++) {
    totalPersonas[i] = *new Persona;
    totalDocumentos[i] = *new Documento;
  }*/
}

// Esta funcion trae toda la lista de los datos ya asi poder comprobar
// que existe lo que se busca
void Prestamo::llenarPrestamo(Alumno* alumn[], Profesor* profe[], Libros* lib[], Tesis* tes[], Revistas* rev[]) {
  char *validar_persona = new char[100];
  char *validar_documento = new char[100];
  bool validador;
  // Primero se validaran los datos
  fflush(stdin);
  cout << "Codigo: "; cin >> codigo;
  cin.ignore();
  cout << "Fecha: "; cin.getline(fecha,101,'\n');
  cout << "Usuario: "; cin.getline(validar_persona,101,'\n');
  cout << "Docuemnto a prestar: "; cin.getline(validar_documento,101,'\n');

  /* --------- VALIDADOR DE PERSONA ---------
  Aqui uso el for para recorrer la lista verifico si existe lo que busco y
  si esta disponible, esto mediante el limite que se ha establecido
  a medida que la persona se presta un libro su limite diminuye hasta llegar a 0
  */
  for (int i = 0; i < 20; i++) {
    if (validar(validar_persona, alumn[i]->getNombre()) && alumn[i]->getLimite() != 0) {
      usuario = alumn[i]->getNombre();
      limiteFinal = alumn[i]->getLimite() - 1;
      alumn[i]->setLimite(limiteFinal);
      validador = true;
    } else if (validar(validar_persona, profe[i]->getNombre()) && profe[i]->getLimite() != 0){
      usuario = profe[i]->getNombre();
      limiteFinal = profe[i]->getLimite() - 1;
      profe[i]->setLimite(limiteFinal);
      validador = true;
    }
  }
  if (!validador)
    cout << "La persona no esta registrada o excedio el limite" << endl;
  validador = false; // El validador vuelve a ser falso para pasar a los documentos

  /* Validador de documentos
   * Hace lo mmismo que el validador de personas pero ahora con documentos
   * tambien disminuye el stock cuando alguien pide el libro prestado
   */
  for (int i = 0; i < 20; i++) {
    if (validar(validar_documento, lib[i]->getNombre()) && lib[i]->getStock() != 0) {
      prestamo = lib[i]->getNombre();
      limiteFinal = lib[i]->getStock() - 1;
      lib[i]->setStock(limiteFinal);
      validador = true;
    } else if (validar(validar_documento, tes[i]->getNombre()) && tes[i]->getStock() != 0) {
      prestamo = tes[i]->getNombre();
      limiteFinal = tes[i]->getStock() - 1;
      tes[i]->setStock(limiteFinal);
      validador = true;
    } else if (validar(validar_documento, rev[i]->getNombre()) && rev[i]->getStock() != 0) {
      prestamo = rev[i]->getNombre();
      limiteFinal = rev[i]->getStock() - 1;
      rev[i]->setStock(limiteFinal);
      validador = true;
    }
  }
  if (!validador)
    cout << "El documento no esta registrado o ya no esta disponible" << endl;
}

bool Prestamo::validar(char* cadena1, char* cadena2) {
  int i=0;
  for( ; cadena1[i]!='\0' && cadena2[i]!='\0'  ; i++){
    if(cadena1[i]!=cadena2[i])
      return false;
  }
  if( cadena1[i]=='\0' && cadena2[i]=='\0')
    return true;
  return false;
}

void Prestamo::mostrarPrestamo() {
  cout << "Codigo: " << codigo << endl;
  cout << "Fecha: " << fecha << endl;
  cout << "Usuario: " << usuario << endl;
  cout << "Documento: " << prestamo << endl;
  cout  << "-------------------------------------------" << endl;
}

#endif //POO_PRACTICA_12_PRESTAMO_H
