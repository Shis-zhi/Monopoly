#ifndef PLAYER_H_
#define PLAYER_H_

#include<vector>
#include"./place.h"
namespace monopoly{
class Player{
public:
    Player() = default;
    Player(const Player& player) = default;
    ~Player() = default;
    Player& operator=(const Player& player) = delete;

    void GetDiceNum();
    void GetMoney(uint32_t money);
    bool LostMoney(uint32_t money);
private:
    uint32_t money;
    uint8_t dice_num;
    enum state{NORMAL, FORBIDDEN};
    Place CurPlace;
    std::vector<Place> PlaceList;
};
}// namespace monopoly
#endif// PLAYER_H_