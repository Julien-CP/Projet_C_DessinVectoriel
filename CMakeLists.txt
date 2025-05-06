cmake_minimum_required(VERSION 3.24)
project(ProjetC C)

set(CMAKE_C_STANDARD 11)

add_executable(ProjetC main.c shapes.c shapes.h id.c id.h formes.c formes.h area.c area.h commandes.c commandes.h pixels.c pixels.h)
