#include <stdio.h>
#include <string.h>
#include "funciones.h"

void imprimirAlumnos(char alumnos[][2][20], double notas[][3]) {
    printf("Nombre\tApellido\tNota1\tNota2\tNota3\tPromedio\tAprobado\n");
    for (int i = 0; i < 6; i++) {
        double promedio = (notas[i][0] + notas[i][1] + notas[i][2]) / 3.0;
        printf("%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t\t%s\n", alumnos[i][0], alumnos[i][1], notas[i][0], notas[i][1], notas[i][2], promedio, (promedio >= 6.0) ? "Si" : "No");
    }
}

void buscarAlumnoXApellido(char alumnos[][2][20], double notas[][3]) {
    char apellido[20];
    printf("Ingrese el apellido del alumno: ");
    scanf("%s", apellido);

    int encontrado = 0;
    for (int i = 0; i < 6; i++) {
        if (strcmp(alumnos[i][1], apellido) == 0) {
            double promedio = (notas[i][0] + notas[i][1] + notas[i][2]) / 3.0;
            printf("Nombre: %s %s\nNotas: %.2f, %.2f, %.2f\nPromedio: %.2f\nAprobado: %s\n", alumnos[i][0], alumnos[i][1], notas[i][0], notas[i][1], notas[i][2], promedio, (promedio >= 6.0) ? "Si" : "No");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Alumno no encontrado.\n");
    }
}

void editarCalificaciones(char alumnos[][2][20], double notas[][3]) {
    char apellido[20];
    printf("Ingrese el apellido del alumno para editar sus calificaciones: ");
    scanf("%s", apellido);

    int encontrado = 0;
    for (int i = 0; i < 6; i++) {
        if (strcmp(alumnos[i][1], apellido) == 0) {
            printf("Ingrese las nuevas calificaciones para %s %s:\n", alumnos[i][0], alumnos[i][1]);
            printf("Nota 1: ");
            scanf("%lf", &notas[i][0]);
            printf("Nota 2: ");
            scanf("%lf", &notas[i][1]);
            printf("Nota 3: ");
            scanf("%lf", &notas[i][2]);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Alumno no encontrado.\n");
    }
}
