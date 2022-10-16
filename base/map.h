#ifndef MAP_H_
#define MAP_H_
#include"./place.h"
#include<vector>
#include<memory>
namespace monopoly{
const uint8_t MaxSize = 69;
class Map{
public:
    void InitMap();
    void InitPlaces();
    void InitPlayers();
private:
    std::vector<std::unique_ptr<Place>> map;
};
}
#endif