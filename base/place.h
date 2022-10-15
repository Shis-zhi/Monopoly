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
    int GetCost() const{
        return this->cost;
    }
    void SetCost(const int cost) {
        this->cost = cost;
    }
private:
    Player owner;
    int cost;
};
}// namespace monopoly
#endif // PLACE_H_