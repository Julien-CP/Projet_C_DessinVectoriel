//
// Created by Adrien Assouad on 11/05/2023.
//
#include "commandes.h"
#include "area.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

Command* create_commande()
{
    Command* cmd = (Command*)malloc(sizeof(Command)); // allocation dynamique de mémoire pour une structure de type Command
    if (cmd != NULL) { // vérification si la mémoire a bien été allouée
        // Initialisation des champs de la structure à des valeurs par défaut
        strcpy(cmd->name, "");
        cmd->int_size = 0;
        cmd->str_size = 0;
        for (int i = 0; i < 10; i++) {
            cmd->int_params[i] = 0;
            cmd->str_params[i] = NULL;
        }
    }
    return cmd; // renvoie le pointeur vers la structure nouvellement créée
}

void add_str_param(Command* cmd, char* p) {
    if (cmd != NULL && p != NULL && cmd->str_size < 10) { // vérification des paramètres d'entrée
        cmd->str_params[cmd->str_size] = strdup(p); // duplique la chaîne de caractère donnée en paramètre et l'insère dans le tableau
        cmd->str_size++; // incrémente str_size
    }
}

void add_int_param(Command* cmd, int p) {
    if (cmd != NULL && cmd->int_size < 10) { // vérification des paramètres d'entrée
        cmd->int_params[cmd->int_size] = p; // insère l'entier donné en paramètre dans le tableau
        cmd->int_size++; // incrémente int_size
    }
}

void free_cmd(Command* cmd) {
    if (cmd != NULL) { // vérification du paramètre d'entrée
        // libère l'espace occupé par les chaînes de caractères dans le tableau str_params
        for (int i = 0; i < cmd->str_size; i++) {
            free(cmd->str_params[i]);
            cmd->str_params[i]=NULL;
        }
        // libère la mémoire allouée pour la commande
        free(cmd);
        cmd = NULL;
    }
}

int read_exec_command(Command* cmd, Area* area) {
    if (strcmp(cmd->name, "clear") == 0) {
        system("clear"); // cls si windows
    } else if (strcmp(cmd->name, "exit") == 0) {
        delete_area(area);
        return 1; // Sortir du programme
    } else if (strcmp(cmd->name, "point") == 0) {
        Shape *pt = create_point_shape(cmd->int_params[0], cmd->int_params[1]);
        add_shape_to_area(area, pt);
        draw_area(area);
    } else if (strcmp(cmd->name, "line") == 0) {
        Shape *line = create_line_shape(cmd->int_params[0], cmd->int_params[1], cmd->int_params[2], cmd->int_params[3]);
        add_shape_to_area(area, line);
        draw_area(area);
    } else if (strcmp(cmd->name, "circle") == 0) {
        Shape *circle = create_circle_shape(cmd->int_params[0], cmd->int_params[1], cmd->int_params[2]);
        add_shape_to_area(area, circle);
        draw_area(area);
    } else if (strcmp(cmd->name, "square") == 0) {
        Shape *square = create_square_shape(cmd->int_params[0], cmd->int_params[1], cmd->int_params[2]);
        add_shape_to_area(area, square);
        draw_area(area);
    } else if (strcmp(cmd->name, "rectangle") == 0) {
        Shape *rectangle = create_rectangle_shape(cmd->int_params[0], cmd->int_params[1], cmd->int_params[2], cmd->int_params[3]);
        add_shape_to_area(area, rectangle);
        draw_area(area);
    } else if (strcmp(cmd->name, "polygon") == 0) {
        int i = 0;
        int list[100];
        while(cmd->int_params[i] != NULL)
        {
            list[i]=cmd->int_params[i];
            i++;
        }
        Shape *polygon = create_polygon_shape(list, (i/2)+1);
        add_shape_to_area(area, polygon);
        draw_area(area);
    } else if (strcmp(cmd->name, "plot") == 0) {
        print_area(area);
    } else if (strcmp(cmd->name, "list") == 0) {
        afficher_formes(area);
    } else if (strcmp(cmd->name, "delete") == 0) {
        delete_shape(area->shapes[cmd->int_params[0]-1]);
        clear_area(area);
        for(int i = cmd->int_params[0]-1; i<(area->nb_shape); i++)
        {
            area->shapes[i]= area->shapes[i+1];
        }
        area->nb_shape--;
        draw_area(area);
    } else if (strcmp(cmd->name, "erase") == 0) {
        erase_area(area);
        clear_area(area);
        draw_area(area);
    } else if (strcmp(cmd->name, "help") == 0) {
        printf("— clear : effacer l’écran\n"
               "— exit : quitter le programme\n"
               "— point x y : ajouter un point\n"
               "— line x1 y1 x2 y2 : ajouter un segment reliant deux points (x1, y1) et (x2, y2)\n"
               "— circle x y radius : ajouter un cercle de centre (x, y) et de rayon radius\n"
               "— square x y length : ajouter un carré dont le coin supérieur gauche est (x, y) et de côté length.\n"
               "— rectangle x y width height : ajouter un rectangle dont le coin supérieur gauche est (x, y), de largeur width et de longueur height\n"
               "— polygon x1 y1 x2 y2 x3 y3 ... ... : ajouter un polygone avec la liste des points donnés\n"
               "— plot : rafraîchir l’écran pour afficher toutes les formes géométriques de l’image (en fonction des\n"
               "règles d’affichage)\n"
               "— list : afficher la liste de l’ensemble des formes géométriques qui composent l’image ainsi que toutes leurs informations\n"
               "— delete id : supprimer une forme à partir de son identifiant id.\n"
               "— erase : supprimer toutes les formes d’une image.\n"
               "— help : afficher la liste des commandes ainsi qu’un mini mode d’emploi permettant à l’utilisateur d’utiliser les commandes correctement.\n");
    }
    return 0
    ;
}


void read_from_stdin(Command* cmd) {
    char *p = (char*) malloc(100 * sizeof(char));
    int p_len = 0,max_len=0;

    printf(">>>");
    fgets(p, 100, stdin);

    // Supprimer le caractère de retour à la ligne à la fin de la saisie
    while (p[max_len] != '\0') {
        max_len++;
    }

    while (p[p_len]!=' ' && p[p_len]!='\n') {
        cmd->name[p_len] = p[p_len];
        p_len++;
    }

    cmd->name[p_len] = '\0';

    int i =p_len;

    while (i < max_len) {

        // Si le caractère suivant est un espace, passer au paramètre suivant
        if (p[i] == ' ') {
            i++;
            continue;
        }

        // Si le caractère suivant est un chiffre, récupérer l'entier suivant
        if (isdigit(p[i])) {
            int tmp = i;
            while (isdigit(p[tmp])) {
                tmp++;
            }
            char entier[tmp - i + 1];
            strncpy(entier, p + i, tmp - i);
            entier[tmp - i] = '\0';
            add_int_param(cmd, strtol(entier, NULL, 10));
            i = tmp;
        }
            // Sinon, récupérer la chaîne de caractères suivante
        else {
            int tmp = i;
            while (p[tmp] != ' ' && p[tmp] != '\0') {
                tmp++;
            }
            char* chaine = (char*) malloc(tmp - i + 1);
            strncpy(chaine, p + i, tmp - i);
            chaine[tmp - i] = '\0';
            add_str_param(cmd, chaine);
            i = tmp;
        }
    }

}