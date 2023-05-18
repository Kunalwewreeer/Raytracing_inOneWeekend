#ifndef HITTABLE_H
#define HITTABLE_H
#include "constants.h"

class material;
struct hit_record {
    vec3 normal;
    point3 p;
    shared_ptr<material> mat_ptr;
    double t;
    bool front_face;
    inline void set_face_normal(const ray &r, const vec3& outward_normal){
        front_face = dot(r.direction(), outward_normal) < 0;
        if(front_face) normal = outward_normal;
        else normal = -outward_normal;
    }

};

class hittable {
    public:
        virtual bool hit(const ray &r, double t_min, double t_max, hit_record &rec) const = 0;
};

#endif