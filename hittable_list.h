#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H
#include "constants.h"
#include "hittable.h"
#include <memory>
#include <vector>

class hittable_list : public hittable {
    public:
        std::vector<shared_ptr<hittable>> objects;
        hittable_list() {}
        hittable_list(shared_ptr<hittable> object) {add(object);}
        void clear() {objects.clear();}
        void add(shared_ptr<hittable> object) { objects.push_back(object);}

        virtual bool hit (
            const ray &r, double t_min, double t_max, hit_record &rec) const override;
        
        
};

bool hittable_list::hit(const ray& r, double t_min, double t_max, hit_record& rec) const {
    bool hit_something = false;
    auto closest_so_far = t_max;
    hit_record temp_rec;
    for (const auto &object : objects){
        if(object->hit(r, t_min, closest_so_far, temp_rec)){
            hit_something = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }
    return hit_something;
}

#endif
