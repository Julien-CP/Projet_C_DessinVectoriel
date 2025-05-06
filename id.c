//
// Created by Adrien Assouad on 14/04/2023.
//
#include "id.h"

unsigned int global_id = 0;

unsigned int get_next_id()
{
    return ++ global_id;
}