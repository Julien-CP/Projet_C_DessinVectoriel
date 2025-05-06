//
// Created by Adrien Assouad on 22/04/2023.
//
#include "area.h"
#include "shapes.h"
#include <stdlib.h>
#include <stdio.h>
#include "pixels.h"


Area* create_area(unsigned int width, unsigned int height)
{
    Area* area = (Area*) malloc(sizeof(Area));
    area->width = width;
    area->height = height;
    area->mat = (BOOL**) malloc(width * sizeof(BOOL*));    // allouer de la mémoire pour la matrice des pixels
    for (int i =0; i<height; i++)
    {
        area->mat[i] = (BOOL**) malloc(height*sizeof(BOOL*));
    }
    return area;
}



void add_shape_to_area(Area* area, Shape* shape)
{
    area->shapes[area->nb_shape++] = shape;
}


void clear_area(Area* area)
{
    for (int i = 0; i < area->width; i++)
    {
        for (int j = 0; j < area-> height; j++)
        {
            area->mat[i][j] = 0;
        }
    }
}


void erase_area(Area* area)
{
    for (int i = 0; i < area->nb_shape; i++)
    {
        free(area->shapes[i]);
    }
    area->nb_shape = 0;
}

void delete_area(Area* area)
{
    erase_area(area);
    for (int i = 0; i < area->width; i++)
    {
        free(area->mat[i]);
    }
    free(area->mat);
    free(area);
}



void draw_area(Area* area) {
    int nb;
    for (int i = 0; i < area->nb_shape; i++) {
        Pixel **list_pixel = create_shape_to_pixel(area->shapes[i],&nb); // Récupération de la liste des pixels à colorier pour chaque forme
        for (int j = 0; j < nb; j++) {
            Pixel *pixel = list_pixel[j];
            area->mat[pixel->py - 1][pixel->px - 1] = 1;
            }
        }
    }




void print_area(Area* area)
{
    for (int x = 0; x < area->width; x++)
    {
        for (int y = 0; y < area->height; y++)
        {
            if (area->mat[x][y]==0)
            {
                printf(" . "); // affiche un pixel vide
            }
            if (area->mat[x][y]==1)
            {
                printf(" # "); // affiche un pixel rempli
            }
        }
        printf("\n"); // passe à la ligne suivante
    }
}




void afficher_formes(Area*area)
{
    for(int i = 0; i<area->nb_shape; i++)
    {
    printf("%d\t",i+1);
    print_shape(area->shapes[i]);
    printf("\n");
    }
}