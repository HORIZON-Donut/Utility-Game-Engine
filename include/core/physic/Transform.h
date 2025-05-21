#ifndef INCLUDE_TRANSFORM_H
#define INCLUDE_TRANSFORM_H

#include "Vector.h"

typedef struct Transform
{
    Vector3 position;
    Vector3 localPosition;
    Vector3 rotation;
    Vector3 size;
    Vector3 scale;
}Transform;

#endif