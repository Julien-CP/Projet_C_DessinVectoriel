//
// Created by Adrien Assouad on 23/03/2023.
//
#include "formes.h"
#include "shapes.h"
#include <stdio.h>
#include <stdlib.h>
#include "id.h"
//SHAPE

Shape *create_empty_shape(SHAPE_TYPE shape_type)
{
    Shape *shp = (Shape *) malloc(sizeof(Shape));
    shp->ptrShape = NULL;
    shp->id = get_next_id();
    shp->shape_type = shape_type;
    return shp;
}

//SHAPE POINT

Shape *create_point_shape(int px, int py)
{
    Shape *shp = create_empty_shape(POINT);
    Point *p = create_point(px, py);
    shp->ptrShape = p;
    shp->id = get_next_id();
    return shp;
}

//SHAPE LINE


Shape *create_line_shape(int px1, int py1, int px2, int py2)
{
    Shape *shp = create_empty_shape(LINE);
    Point *p1 = create_point(px1, py1);
    Point *p2 = create_point(px2, py2);
    Line *p = create_line(p1, p2);
    shp->ptrShape = p;
    shp->id = get_next_id();
    return shp;
}


//SHAPE SQUARE


Shape *create_square_shape(int px, int py, int length)
{
    Shape *shp = create_empty_shape(SQUARE);
    Point *p = create_point (px, py);
    Square *square = create_square(p, length);
    shp->ptrShape = square;
    shp->id = get_next_id();
    return shp;
}


//SHAPE RECTANGLE


Shape *create_rectangle_shape(int px, int py, int width, int height)
{
    Shape *shp = create_empty_shape(RECTANGLE);
    Point *p = create_point (px, py);
    Rectangle *rectangle = create_rectangle(p, width, height);
    shp->ptrShape = rectangle;
    shp->id = get_next_id();
    return shp;
}


//SHAPE CIRCLE


Shape *create_circle_shape(int px, int py, int radus)
{
    Shape *shp = create_empty_shape(CIRCLE);
    Point *p = create_point (px, py);
    Circle *circle = create_circle(p, radus);
    shp->ptrShape = circle;
    shp->id = get_next_id();
    return shp;
}


//SHAPE POLYGON


Shape *create_polygon_shape(int lst[], int n)
{
    Shape *shp = create_empty_shape(POLYGON);
    int k =0;
    Point ** tabpts = (Point**) malloc(sizeof (Point*) * n);
    for(int i=0;i<n*2;i+=2)
    {
        tabpts[k] = create_point(lst[i], lst[i+1]);
        k++;
    }
    Polygon *pol = create_polygon(n, tabpts);
    shp->ptrShape = pol;
    shp->id = get_next_id();
    return shp;
}




void delete_shape(Shape* shape) {
    switch (shape->shape_type) {
        case POINT:
            delete_point(shape->ptrShape);
            break;
        case LINE:
            delete_line(shape->ptrShape);
            break;
        case SQUARE:
            delete_square(shape->ptrShape);
            break;
        case RECTANGLE:
            delete_rectangle(shape->ptrShape);
            break;
        case CIRCLE:
            delete_circle(shape->ptrShape);
            break;
        case POLYGON:
            delete_polygon(shape->ptrShape);
            break;
    }
    free(shape);
    shape = NULL;
}

void print_shape(Shape * shape)
{
    switch (shape->shape_type) {
        case POINT:
            print_point(shape->ptrShape);
            break;
        case LINE:
            print_line(shape->ptrShape);
            break;
        case SQUARE:
            print_square(shape->ptrShape);
            break;
        case RECTANGLE:
            print_rectangle(shape->ptrShape);
            break;
        case CIRCLE:
            print_circle(shape->ptrShape);
            break;
        case POLYGON:
            print_polygon(shape->ptrShape);
            break;
    }
}

