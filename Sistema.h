#ifndef POO_PRACTICA_12_SISTEMA_H
#define POO_PRACTICA_12_SISTEMA_H

#include <string>
#include "Persona.h"
#include "Documento.h"
#include "Prestamo.h"

class Sistema {
protected:
  Alumno *listaAlumno[100];
  Profesor *listaProfesor[100];
  Libros *listaLibros[100];
  Tesis *listaTesis[100];
  Revistas *listaRevistas[100];
  Prestamo *listaPrestamos[100];
  int actualAlumno,actualProfesor,actualLibros,actualTesis,actualRevistas,actualprestamo;
public:
  Sistema();
  void ingresar(int);
  void listar(int);
  void buscar(int);
  void eliminar(int);
  bool validar(char*, char*);
};

Sistema::Sistema() {
  for (int i=0;i<100;i++) {
    listaAlumno[i]= new Alumno;
    listaProfesor[i]= new Profesor;
    listaLibros[i]=new Libros;
    listaTesis[i]=new Tesis;
    listaRevistas[i]=new Revistas;
    listaPrestamos[i]=new Prestamo;
  }
  actualAlumno=actualProfesor=actualLibros=actualTesis=actualRevistas=actualprestamo=0;
}

void Sistema::ingresar(int tipo) {
  switch(tipo) {
    case 1:
      listaAlumno[actualAlumno]->llenarAlumno();
      actualAlumno++;
      break;
    case 2:
      listaProfesor[actualProfesor++]->llenarProfesor();
      break;
    case 3:
      listaLibros[actualLibros++]->llenarLibros();
      break;
    case 4:
      listaTesis[actualTesis++]->llenarTesis();
      break;
    case 5:
      listaRevistas[actualRevistas++]->llenarRevistas();
      break;
    case 6:
      //listaPrestamos[actualprestamo++]->traerPersonas(listaAlumno, listaProfesor);
      //listaPrestamos[actualprestamo++]->traerDocumentos(listaLibros,listaTesis, listaRevistas);
      listaPrestamos[actualprestamo++]->llenarPrestamo(listaAlumno, listaProfesor, listaLibros, listaTesis, listaRevistas);

      break;
    default:
      cout << "Error!" << endl;
      break;
  }
}

void Sistema::listar(int tipo) {
  switch(tipo) {
    case 1:
      for (int i = 0; i < actualAlumno; i++)
        listaAlumno[i]->mostrarAlumno();
      break;
    case 2:
      for (int i = 0; i < actualProfesor; i++)
        listaProfesor[i]->mostrarProfesor();
      break;
    case 3:
      for (int i = 0; i < actualLibros; i++)
        listaLibros[i]->mostrarLibros();
      break;
    case 4:
      for (int i = 0; i < actualTesis; i++)
        listaTesis[i]->mostrarTesis();
      break;
    case 5:
      for (int i = 0; i < actualRevistas; i++)
        listaRevistas[i]->mostrarRevistas();
      break;
    case 6:
      for (int i = 0; i < actualprestamo; i++)
        listaPrestamos[i]->mostrarPrestamo();
      break;
    default:
      cout << "Error!" << endl;
      break;
  }
}

void Sistema::buscar(int tipo) {
  char *valor_a_buscar = new char[100];
  // Lo que hace este switch es comparar valor_a_buscar con la lista que se ha escogido,
  // para iterar en cada valor de la lista se usa un for y se valida con la funcion
  // Sitema::validar que recibe dos parametro el valor a buscar y el elemento de la lista
  // Si devuelve TRUE en la comparacion significa que lo ha encontrado y lo muestra
  switch (tipo) {
    bool resultado;
    case 1:
      cin.ignore();
      cout << "Nombre a buscar: "; cin.getline(valor_a_buscar,101,'\n');
      for (int i = 0; i < actualAlumno; i++) {
        if  (Sistema::validar(valor_a_buscar, listaAlumno[i]->getNombre())) {
          cout << "------- Resultado obetenido --------- " << endl;
          listaAlumno[i]->mostrarAlumno();
          resultado = true;
        }
      }
      if (!resultado)
        cout << "No se ha encontrado al alumno..." << endl;
      break;
    case 2:
      cin.ignore();
      cout << "Nombre a buscar: "; cin.getline(valor_a_buscar,101,'\n');
      for (int i = 0; i < actualProfesor; i++) {
        if  (Sistema::validar(valor_a_buscar, listaProfesor[i]->getNombre())) {
          cout << "------- Resultado obetenido --------- " << endl;
          listaProfesor[i]->mostrarProfesor();
        }
      }
      break;
    case 3:
      cin.ignore();
      cout << "Nombre a buscar: "; cin.getline(valor_a_buscar,101,'\n');
      for (int i = 0; i < actualLibros; i++) {
        if (Sistema::validar(valor_a_buscar, listaLibros[i]->getNombre())) {
          cout << "------- Resultado obetenido --------- " << endl;
          listaLibros[i]->mostrarLibros();
        }
      }
      break;
    case 4:
      cin.ignore();
      cout << "Nombre a buscar: "; cin.getline(valor_a_buscar,101,'\n');
      for (int i = 0; i < actualTesis; i++) {
        if (Sistema::validar(valor_a_buscar, listaTesis[i]->getNombre())) {
          cout << "------- Resultado obetenido --------- " << endl;
          listaTesis[i]->mostrarTesis();
        }
      }
      break;
    case 5:
      cin.ignore();
      cout << "Nombre a buscar: "; cin.getline(valor_a_buscar,101,'\n');
      for (int i = 0; i < actualRevistas; i++) {
        if (Sistema::validar(valor_a_buscar, listaRevistas[i]->getNombre())) {
          cout << "------- Resultado obetenido --------- " << endl;
          listaRevistas[i]->mostrarRevistas();
        }
      }
      break;
    case 6:
      break;
    default:
      cout << "Error!!!!" << endl;
      break;
  }
}

bool Sistema::validar(char *cadena1, char *cadena2) {
  int i=0;
  for( ; cadena1[i]!='\0' && cadena2[i]!='\0'  ; i++){
    if(cadena1[i]!=cadena2[i])
      return false;
  }
  if( cadena1[i]=='\0' && cadena2[i]=='\0')
    return true;
  return false;
  /*
  // Mientras ambas cadenas no lleguen al final (carácter nulo)
  while (*cadena1 != '\0' && *cadena2 != '\0') {
    // Si los caracteres son diferentes, retorna falso
    if (*cadena1 != *cadena2)
      return false;
    cadena1++;
    cadena2++;
  }
  // Si ambas cadenas llegaron al final (carácter nulo) al mismo tiempo,
  // significa que son iguales, por lo que retorna verdadero
  return true;
  */
}

void Sistema::eliminar(int tipo) {
  int posicion_eliminar; // Se pide al usuario la psocicion a eliminar
  cout << "Posicion a liminar: "; cin >> posicion_eliminar;
  // Se muestra primero a quien se va a eliminar y mediante un for se recorre
  // las posciciones y reemplazan al valor eliminado, luego actualAlumno disminiuye
  switch(tipo) {
    case 1:
      cout << "Eliminado ---> " << listaAlumno[posicion_eliminar-1]->getNombre() << endl;
      for (int i = posicion_eliminar; i < actualAlumno; i++)
        listaAlumno[i-1] = listaAlumno[i];
      actualAlumno--;
      break;
    case 2:
      cout << "Eliminado ---> " << listaProfesor[posicion_eliminar-1]->getNombre() << endl;
      for (int i = posicion_eliminar; i < actualProfesor; i++)
        listaProfesor[i-1] = listaProfesor[i];
      actualProfesor--;
      break;
    case 3:
      cout << "Eliminado ---> " << listaLibros[posicion_eliminar-1]->getNombre() << endl;
      for (int i = posicion_eliminar; i < actualLibros; i++)
        listaLibros[i-1] = listaLibros[i];
      actualLibros--;
      break;
    case 4:
      cout << "Eliminado ---> " << listaTesis[posicion_eliminar-1]->getNombre() << endl;
      for (int i = posicion_eliminar; i < actualTesis; i++)
        listaTesis[i-1] = listaTesis[i];
      actualTesis--;
      break;
    case 5:
      cout << "Eliminado ---> " << listaRevistas[posicion_eliminar-1]->getNombre() << endl;
      for (int i = posicion_eliminar; i < actualRevistas; i++)
        listaRevistas[i-1] = listaRevistas[i];
      actualRevistas--;
      break;
    default:
      cout << "Error" << endl;
      break;
  }
}


#endif //POO_PRACTICA_12_SISTEMA_H