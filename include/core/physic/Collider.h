#ifndef INCLUDE_COLLISION_H
#define INCLUDE_COLLISION_H

#include "Vector.h"

enum ColliderType { SPHERE, BOX, CAPSUALE};

typedef struct Collider
{
    ColliderType type;

    Vector3 offset;
    Vector3 size;

    double radius;
    double height;
}Collider;

#endif