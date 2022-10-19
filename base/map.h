#ifndef MAP_H_
#define MAP_H_
#include"./public.h"
#include"./place.h"
#include<vector>
#include<memory>
namespace monopoly{
class Map{
public:
    Map() = default;
    Map(const Map& other) = delete;
    ~Map() = default;
    const Map& operator=(const Map& other) = delete;
    
    friend class Player;

    void InitMap();
    void InitAllPlaces();
    std::vector<std::unique_ptr<Place>>::const_iterator FindPlace(uint8_t pos) const;
private:
    std::vector<std::unique_ptr<Place>> PlacePtrVector;
    const std::unique_ptr<Place> map_start{new Place(0,START)};
    const std::unique_ptr<Place> map_end{new Mine(69,MINE,60)};
};
}// namespace monopoly
#endif// MAP_H_