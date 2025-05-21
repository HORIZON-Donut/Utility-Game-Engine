#ifndef INCLUDE_RIGID_H
#define INCLUDE_RIGID_H

#include "Vector.h"

typedef struct RigidBody
{
    Vector3 Velocity;
    Vector3 Acceleration;

    int is_gravity;
    int is_static;

    double mass;
    double inverse_mass;
}RigidBody;

#endif