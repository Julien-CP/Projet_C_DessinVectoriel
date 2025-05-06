//
// Created by Adrien Assouad on 23/05/2023.
//
#include "pixels.h"
#include <stdlib.h>
#include <stdio.h>

Pixel* create_pixel(int px, int py)
{
    Pixel* new_pixel = (Pixel*) malloc(sizeof(Pixel));
    new_pixel->px = px;
    new_pixel->py = py;
    return new_pixel;
}

void delete_pixel(Pixel* pixel)
{
    free(pixel);
}


void pixel_point(Point* point, Pixel*** pixel, int* nb_pixels)
{
    *nb_pixels   = 1;
    *pixel = (Pixel**) malloc (*nb_pixels*sizeof (Pixel*));
    (*pixel)[0] = create_pixel(point->pos_x, point->pos_y);
}


void pixel_line(Line* line, Pixel*** pixel, int* nb_pixels)
{
    int x0 = line->p1->pos_x;
    int y0 = line->p1->pos_y;
    int x1 = line->p2->pos_x;
    int y1 = line->p2->pos_y;

    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int erreur_acc = dx - dy;
    int erreur_2;

    int max_pixels = 400;  // Maximum de pixels à allouer
    *nb_pixels = 0;  // Initialisation du nombre de pixels à 0
    *pixel = (Pixel**) malloc(max_pixels * sizeof(Pixel*));  // Allocation de l'espace mémoire pour le tableau de pixels

    while (1) {
        if (*nb_pixels >= max_pixels) {
            break;  // Si on atteint le maximum de pixels, on sort de la boucle
        }

        (*pixel)[*nb_pixels] = create_pixel(x0, y0);  // Ajout du pixel à la liste
        (*nb_pixels)++;  // Mise à jour du nombre de pixels

        if (x0 == x1 && y0 == y1) {
            break;  // Si on est arrivé au point d'arrivée, on sort de la boucle
        }

        erreur_2 = 2 * erreur_acc;
        if (erreur_2 > -dy) {
            erreur_acc -= dy;
            x0 += sx;
        }
        if (erreur_2 < dx) {
            erreur_acc += dx;
            y0 += sy;
        }
    }
}


void pixel_circle(Circle* circle, Pixel*** pixel, int *nb_pixels)
{

    *nb_pixels = 8 * circle->radius;  // Estimation du nombre de pixels à allouer
    *pixel = (Pixel**) malloc(*nb_pixels * sizeof(Pixel*));
    Pixel* px = NULL;


    int x = 0;
    int y = circle->radius;
    int d = circle->radius - 1;
    int k = 0;

    //  x = k = 0;
    //  y = circle->radius;
    //  d = circle->radius - 1;
    while (y >= x)
    {
        // Ajouter le point pour le premier octant
        px = create_pixel(circle->p1->pos_x + x, circle->p1->pos_y + y);
        (*pixel)[k++] = px;

        // Ajouter le point pour l'octant d'en face
        px = create_pixel(circle->p1->pos_x + y, circle->p1->pos_y + x);
        (*pixel)[k++] = px;

        // Ajouter la même chose pour les six octants restants
        // Octant 2
        px = create_pixel(circle->p1->pos_x + y, circle->p1->pos_y - x);
        (*pixel)[k++] = px;

        // Octant 3
        px = create_pixel(circle->p1->pos_x + x, circle->p1->pos_y - y);
        (*pixel)[k++] = px;

        // Octant 4
        px = create_pixel(circle->p1->pos_x - x, circle->p1->pos_y - y);
        (*pixel)[k++] = px;

        // Octant 5
        px = create_pixel(circle->p1->pos_x - y, circle->p1->pos_y - x);
        (*pixel)[k++] = px;

        // Octant 6
        px = create_pixel(circle->p1->pos_x - y, circle->p1->pos_x + x);
        (*pixel)[k++] = px;

        // Octant 7
        px = create_pixel(circle->p1->pos_x - x, circle->p1->pos_x + y);
        (*pixel)[k++] = px;

        if (d >= 2 * x)
        {
            d -= 2 * x + 1;
            x++;
        }
        else if (d < 2 * (circle->radius - y))
        {
            d += 2 * y - 1;
            y--;
        }
        else
        {
            d += 2 * (y - x - 1);
            y--;
            x++;
        }
    }
}

void pixel_square(Square* square, Pixel*** pixel, int* nb_pixels)
{
    *nb_pixels = 4 * (square->length-1);
    *pixel = (Pixel**)malloc(*nb_pixels * sizeof(Pixel*));

    int k = 0;
    int x = square->p1->pos_x;
    int y = square->p1->pos_y;

    for (int i = 1; i < square->length; i++) {
        Pixel* px = create_pixel(x, y);
        (*pixel)[k++] = px;
        x++;
    }

    for (int i = 1; i < square->length; i++) {
        Pixel* px = create_pixel(x, y);
        (*pixel)[k++] = px;
        y++;
    }

    for (int i = 1; i < square->length; i++) {
        Pixel* px = create_pixel(x, y);
        (*pixel)[k++] = px;
        x--;
    }

    for (int i = 1; i < square->length; i++) {
        Pixel* px = create_pixel(x, y);
        (*pixel)[k++] = px;
        y--;
    }
}

void pixel_rectangle(Rectangle* rectangle, Pixel*** pixel, int* nb_pixels)
{
    *nb_pixels = 2 * (rectangle->height - 1 + rectangle->width - 1 );
    *pixel = (Pixel**)malloc(*nb_pixels * sizeof(Pixel*));
    int k = 0;
    int x = rectangle->p1->pos_x;
    int y = rectangle->p1->pos_y;
    // Ligne supérieure
    for (int i = 1; i < rectangle->width; i++) {
        Pixel* px = create_pixel(x, y);
        (*pixel)[k++] = px;
        x++;
    }
    // Ligne de droite
    for (int i = 1; i < rectangle->height; i++) {
        Pixel* px = create_pixel(x, y);
        (*pixel)[k++] = px;
        y++;
    }
    // Ligne inférieure
    for (int i = 1; i < rectangle->width; i++) {
        Pixel* px = create_pixel(x, y);
        (*pixel)[k++] = px;
        x--;
    }
    // Ligne de gauche
    for (int i = 1; i < rectangle->height; i++) {
        Pixel* px = create_pixel(x, y);
        (*pixel)[k++] = px;
        y--;
    }
}


void pixel_polygon(Polygon * polygon, Pixel*** pixel, int* nb_pixels) {
    int k=0; // calcul de la mémoire
    for (int i = 0; i < polygon->n - 1; i++) {
        int x1 = polygon->points[i]->pos_x;
        int y1 = polygon->points[i]->pos_y;
        int x2 = polygon->points[i+1]->pos_x;
        int y2 = polygon->points[i+1]->pos_y;
        Pixel** line_pixels;
        int nb_line_pixels;
        Shape* l=create_line_shape(x1,y1,x2,y2);
        pixel_line(l->ptrShape,&line_pixels,&nb_line_pixels);
        for (int j = 0; j < nb_line_pixels; j++) {
            k++;
        }
        free(line_pixels);
        free(l);
    }
    *nb_pixels =k;
    *pixel = (Pixel**)malloc(*nb_pixels * sizeof(Pixel*));
    k = 0;
    for (int i = 0; i < polygon->n - 1; i++) {
        int x1 = polygon->points[i]->pos_x;
        int y1 = polygon->points[i]->pos_y;
        int x2 = polygon->points[i+1]->pos_x;
        int y2 = polygon->points[i+1]->pos_y;
        Pixel** line_pixels;
        int nb_line_pixels;
        Shape* l=create_line_shape(x1,y1,x2,y2);
        pixel_line(l->ptrShape,&line_pixels,&nb_line_pixels);
        for (int j = 0; j < nb_line_pixels; j++) {
            (*pixel)[k++] = (line_pixels)[j];
        }
        free(line_pixels);
        free(l);
    }
}



Pixel** create_shape_to_pixel(Shape * shape, int* nb_pixels)
{
    Pixel** pixel = NULL;
    switch(shape->shape_type){
        case POINT:
            pixel_point((Point*) shape->ptrShape , &pixel, nb_pixels);
            break;
        case LINE:
            pixel_line((Line*) shape->ptrShape , &pixel, nb_pixels);
            break;
        case CIRCLE:
            pixel_circle((Circle*) shape->ptrShape , &pixel, nb_pixels);
            break;
        case SQUARE:
            pixel_square((Square*) shape->ptrShape , &pixel, nb_pixels);
            break;
        case RECTANGLE:
            pixel_rectangle((Rectangle *) shape->ptrShape , &pixel, nb_pixels);
            break;
        case POLYGON:
            pixel_polygon((Polygon *) shape->ptrShape , &pixel, nb_pixels);
            break;
    }
    return pixel;
}


void delete_pixel_shape(Pixel** pixel, int nb_pixels)
{
    for(int i = 0; i<nb_pixels; i++)
    {
        free(pixel[i]);
    }
}