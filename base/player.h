#ifndef PLAYER_H_
#define PLAYER_H_

#include"./place.h"
#include<vector>

namespace monopoly{
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
    void GetZone(Zone& zone);
    bool LostZone(Zone& zone);
    void GetTool(Tool& tool,Zone& zone);
    bool UseTool(Tool& tool,Zone& zone);
    
private:
    uint32_t money;
    uint32_t point;
    uint8_t dice_num;
    enum PlayerState{NORMAL, FORBIDDEN1, FORBIDDEN2, FORBIDDEN3} state;
    Zone cur_zone;
    uint8_t rest_wealth_time;
    std::vector<Zone> ZoneVector;
    std::vector<Tool> ToolVector;
};
}// namespace monopoly
#endif// PLAYER_H_