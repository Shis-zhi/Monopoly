#include"map.h"
namespace monopoly{
void Map::InitMap(){
    Player player1;
    std::unique_ptr<Place> place1(new Zone);
    map.push_back(place1);
}
void Map::InitPlaces(){
    
}
void Map::InitPlayers(){

}
}// namespace monopoly