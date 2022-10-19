#ifndef OBSERVER_H_
#define OBSERVER_H_

#include"./public.h"
#include"./place.h"
#include"./player.h"
#include"./map.h"
#include<string>
#include<vector>
namespace monopoly{
class Observer{
public:
    Observer() = default;
    Observer(const Observer& other) = delete;
    ~Observer() = default;
    Observer& operator=(const Observer& other) = delete;

    void InitGlobalObserver(std::string choice);
    void InitGlobalMap();
    void InitGlobalPlayers(std::string choice);
    void MaybePresetParas();
    Map& GlobalMap(){return global_map;}
    std::vector<Player>::const_iterator FindPlayer(PlayerName player_name);
private:
    Map global_map;
    std::vector<Player> global_players;
};
}
#endif