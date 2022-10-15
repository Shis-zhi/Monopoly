#ifndef PLACE_H_
#define PLACE_H_

#include"./player.h"
namespace monopoly{
class Place{
public:
    Place() = default;
    Place(const Place& place) = default;
    ~Place() = default;
    Place& operator=(const Place& place) = delete;
    uint32_t GetCost() const{
        return this->cost;
    }
    void SetCost(const uint32_t cost) {
        this->cost = cost;
    }
private:
    Player owner;
    uint32_t cost;
};
}// namespace monopoly
#endif // PLACE_H_