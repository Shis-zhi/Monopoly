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
std::vector<Player>::const_iterator Observer::FindPlayer(PlayerName player_name){
    std::vector<Player>::const_iterator it;
    it = std::find_if(this->global_players.begin(), this->global_players.end(), 
                        [player_name](PlayerName player_name_){
                            return player_name==player_name_;
                            });
    return it;
}
} // namespace monopoly
