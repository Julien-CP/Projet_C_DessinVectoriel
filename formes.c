//
// Created by Adrien Assouad on 17/04/2023.
//

#include "formes.h"
#include <stdio.h>
#include <stdlib.h>

//POINT

Point *create_point(int px, int py)
{
    Point *p = malloc(sizeof(Point));
    p->pos_x = px;
    p->pos_y = py;
    return p;
}

void delete_point(Point * point)
{
    free(point);
    point = NULL;
}

void print_point(Point * p)
{
    printf("POINT %d %d", p->pos_x, p->pos_y);
}

//LINE

Line *create_line(Point * p1, Point * p2)
{
    Line* l = malloc(sizeof(Line));
    l->p1=p1;
    l->p2=p2;
    return l;
}

void delete_line(Line * line)
{
    free(line);
    line = NULL;
}

void print_line(Line * line)
{
    printf("LINE %d %d %d %d", line->p1->pos_x,line->p1->pos_y,line->p2->pos_x,line->p2->pos_y);
}

//SQUARE

Square *create_square(Point * point, int length)
{
    Square* s = malloc(sizeof(Square));
    s->p1=point;
    s->length = length;
    return s;
}

void delete_square(Square * square)
{
    free(square);
    square = NULL;
}

void print_square(Square * square)
{
    printf("SQUARE %d %d %d", square->p1->pos_x,square->p1->pos_y, square->length);
}


//RECTANGLE


Rectangle *create_rectangle(Point * point, int width, int height)
{
    Rectangle* r = malloc(sizeof(Rectangle));
    r->p1=point;
    r-> height = height;
    r-> width = width;
    return r;
}
void delete_rectangle(Rectangle * rectangle)
{
    free(rectangle);
    rectangle = NULL;
}
void print_rectangle(Rectangle * rectangle)
{
    printf("RECTANGLE %d %d %d %d", rectangle->p1->pos_x, rectangle->p1->pos_y, rectangle->height, rectangle->width);
}


//CIRCLE

Circle *create_circle(Point * center, int radius)
{
    Circle* c = malloc(sizeof(Circle));
    c->p1 = center;
    c->radius = radius;
    return c;
}
void delete_circle(Circle * circle)
{
    free(circle);
    circle = NULL;
}
void print_circle(Circle * circle)
{
    printf("CIRCLE %d %d %d", circle->p1->pos_x, circle->p1->pos_y, circle->radius);
}


//POLYGON


Polygon *create_polygon(int n, Point**point)
{
    Polygon* po = malloc(sizeof(Polygon));
    po->n = n;
    po->points = point;
    return po;
}
void delete_polygon(Polygon * polygon)
{
    free(polygon);
    polygon = NULL;
}

void print_polygon(Polygon * polygon)
{
    printf("POLYGON ");
    for(int i =0;i<polygon->n;i++)
    {
        printf("%d %d   ", polygon->points[i]->pos_x, polygon->points[i]->pos_y);
    }
}

