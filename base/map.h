#ifndef MAP_H_
#define MAP_H_
#include"./public.h"
#include"./place.h"
#include<vector>
#include<memory>
namespace monopoly{
class Map{
public:
    void InitMap();
    void InitPlaces();
    void InitPlayers();
private:
    std::vector<std::unique_ptr<Place>> map;
};
}// namespace monopoly
#endif