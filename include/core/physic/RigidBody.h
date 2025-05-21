#ifndef INCLUDE_RIGID_H
#define INCLUDE_RIGID_H

#include "Vector.h"

typedef struct RigidBody
{
    Vector3 Velocity;
    Vector3 Acceleration;

    double mass;
    double inverse_mass;
    
    bool is_gravity;
    bool is_static;
}RigidBody;

#endif