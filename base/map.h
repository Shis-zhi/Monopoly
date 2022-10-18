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
    void InitMap();
    void InitAllPlaces();
    std::unique_ptr<Place> InitSinglePlace(uint8_t pos);
    friend class Player;
private:
    std::vector<std::unique_ptr<Place>> PlacePtrVector;
    const std::unique_ptr<Place> map_start;
    const std::unique_ptr<Place> map_end;
};
}// namespace monopoly
#endif// MAP_H_