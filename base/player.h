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

    uint8_t DiceNum();
    void UpdateCurPlace();
    Place CurPlace();
    void GetMoney(uint32_t money);
    bool LostMoney(uint32_t money);
    void PayToOtherPlayer(uint32_t money, Player& other);
    void PayToBankForInit(uint32_t money, Bank& bank);
    void PayToBankForHouse(uint32_t money, Bank& bank);
    void SetNormState();
    void SetForbiddenState();
    bool InPlaceVector(const Place& place) const;
    void GetPlace(Place& place);
    bool LostPlace(Place& place);
private:
    uint32_t money;
    uint8_t dice_num;
    enum PlayerState{NORMAL, FORBIDDEN} state;
    Place cur_place;
    std::vector<Place> PlaceVector;
};
}// namespace monopoly
#endif// PLAYER_H_