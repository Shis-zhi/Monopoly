#include"./observer.h"
namespace monopoly{
void Observer::InitGlobalMap(){
    this->global_map.InitAllPlaces();
}
void Observer::InitGlobalPlayers(std::string choice){
    const PlayerName all_name[4] = {QFR,ATB,SXM,JBB};
    for(int i=0; i<choice.length(); i++){
        int tmp = choice[i] - '0';
        this->global_players.push_back(Player(all_name[tmp]));
    }
}
void Observer::InitGlobalObserver(std::string choice){
    this->InitGlobalMap();
    this->InitGlobalPlayers(choice);
    this->MaybePresetParas();
}
void Observer::MaybePresetParas(){
    //TODO:set player&place paras(private)
}
std::vector<Player>::const_iterator FindPlayer(PlayerName player_name){
    
}
} // namespace monopoly
