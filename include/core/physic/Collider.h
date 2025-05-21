#ifndef INCLUDE_COLLISION_H
#define INCLUDE_COLLISION_H

#include "Vector.h"

typedef enum ColliderType { SPHERE, BOX, CAPSUALE}ColliderType;

typedef struct Collider
{
    ColliderType type;

    Vector3 offset;
    Vector3 size;

    double radius;
    double height;
}Collider;

#endif