cmake_minimum_required(VERSION 3.23)
project(POO_PRACTICA_12)

set(CMAKE_CXX_STANDARD 17)

add_executable(POO_PRACTICA_12 main.cpp)

add_executable(sistemaBiblioteca sistemaBiblioteca.cpp Persona.h Prestamo.h Documento.h Sistema.h)