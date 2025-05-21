#ifndef INCLUDE_PHYSICBODY_H
#define INCLUDE_PHYSICBODY_H

#include "Transform.h"
#include "RigidBody.h"
#include "Collider.h"

typedef struct PhysicalBody
{
    Transform* transform;
    RigidBody* rigidBody;
    Collider* collider;
}PhysicalBody;

#endif