#ifndef PLAYER_H_
#define PLAYER_H_

#include"./place.h"
#include<vector>

namespace monopoly{
const int INITMONEY = 10000;
class Player{
public:
    Player()= default;
    Player(const Player& player) = default;
    ~Player() = default;

    friend class Zone;
    friend class GiftRoom;
    friend class Hospital;
    friend class Prison;

    uint8_t DiceNum();
    void UpdateCurZone();
    Zone CurZone();
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
    
private:
    uint32_t money = INITMONEY;
    uint32_t point = 0;
    uint8_t dice_num;
    enum PlayerState{NORMAL, FORBIDDEN1, FORBIDDEN2, FORBIDDEN3} state;
    Zone cur_zone;
    uint8_t rest_wealth_time = 0;
    std::vector<Zone> ZoneVector;
    std::vector<Tool> ToolVector;
};
}// namespace monopoly
#endif// PLAYER_H_