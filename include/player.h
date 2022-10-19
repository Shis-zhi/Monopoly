#ifndef PLAYER_H_
#define PLAYER_H_

#include"./public.h"
#include"./place.h"
#include"./map.h"
#include<vector>

namespace monopoly{
class Player{
public:
    Player()= default;
    Player(const Player& player) = default;
    Player(PlayerName name):name(name) {};
    ~Player() = default;

    friend class Zone;
    friend class GiftRoom;
    friend class ToolRoom;
    friend class Hospital;
    friend class Barricade;
    friend class Prison;

    uint8_t DiceNum();
    bool Advance(Map& global_map);
    void UpdateCurPlace(Map& global_map);
    Place* CurPlace();
    void GetMoney(uint32_t money);
    bool LostMoney(uint32_t money);
    void GetPoint(uint32_t point);
    bool LostPoint(uint32_t point);
    void PayToOtherPlayer(uint32_t money, Player& other);
    bool InZoneVector(const Zone& zone) const;
    bool InToolVector(const Tool& tool) const;
    void GetZone(Zone& zone);
    bool LostZone(Zone& zone);
    void GetTool(Tool& tool);
    bool UseTool(Tool& tool, Zone& zone);
    void GoToHospital();
    bool IsHurted(){return this->is_hurted;};
    bool CanAdvance(){return this->can_advance;};
private:
    bool is_hurted=false;
    bool can_advance=true;
    PlayerName name;
    uint32_t money = INITMONEY;
    uint32_t point = 0;
    uint8_t dice_num;
    PlayerState state = NORMAL;
    Place* cur_place;
    uint8_t rest_wealth_time = 0;
    std::vector<Zone> ZoneVector;
    std::vector<Tool> ToolVector;
};
}// namespace monopoly
#endif// PLAYER_H_