#ifndef PLAYER_H_
#define PLAYER_H_

#include"./place.h"
#include<vector>

namespace monopoly{
class Player{
public:
    Player() = default;
    Player(const Player& player) = default;
    ~Player() = default;

    void GetDiceNum();
    void UpdateCurPlace();
    void GetMoney(uint32_t money);
    bool LostMoney(uint32_t money);
    void PayToOtherPlayer(uint32_t money, Player& other);
    void PayToBankForInit(uint32_t money, Bank& bank);
    void PayToBankForHouse(uint32_t money, Bank& bank);
    void SetNormState();
    void SetForbiddenState();
    bool InPlaceVector(const Place& place) const;
private:
    uint32_t money;
    uint8_t dice_num;
    enum PlayerState{NORMAL, FORBIDDEN} state;
    Place CurPlace;
    std::vector<Place> PlaceVector;
};
}// namespace monopoly
#endif// PLAYER_H_