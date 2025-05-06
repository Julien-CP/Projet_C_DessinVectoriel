//
// Created by Adrien Assouad on 17/04/2023.
//

#ifndef PROJETC_FORMES_H
#define PROJETC_FORMES_H



typedef struct {
    int pos_x;
    int pos_y;
}Point;

Point *create_point(int px, int py);
void delete_point(Point * point);
void print_point(Point * p);


typedef struct line {
    Point *p1;
    Point *p2;
}Line;

Line *create_line(Point * p1, Point * p2);
void delete_line(Line * line);
void print_line(Line * line);


typedef struct Square {
    Point *p1;
    int length;
}Square;

Square *create_square(Point * point, int length);
void delete_square(Square * square);
void print_square(Square * square);

typedef struct Rectangle{
    Point *p1;
    int height;
    int width;
}Rectangle;


Rectangle *create_rectangle(Point * point, int width, int height);
void delete_rectangle(Rectangle * rectangle);
void print_rectangle(Rectangle * rectangle);


typedef struct Circle{
    Point *p1;
    int radius;
}Circle;


Circle *create_circle(Point * center, int radius);
void delete_circle(Circle * circle);
void print_circle(Circle * circle);


typedef struct polygon {
    int n;
    Point ** points; // tableau 1D dynamique de Point*
}Polygon;


Polygon *create_polygon(int n, Point**point);
void delete_polygon(Polygon * polygon);
void print_polygon(Polygon * polygon);


#endif //PROJETC_FORMES_H
