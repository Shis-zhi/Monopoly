#ifndef PLACE_H_
#define PLACE_H_

#include"./player.h"
namespace monopoly{
const uint32_t INITMONEY = 10000;
class Place{
public:
    Place() = default;
    Place(const Place& place) = default;
    ~Place() = default;
    uint32_t GetCost() const{
        return this->cost;
    }
    void SetCost(const uint32_t& cost) {
        this->cost = cost;
    }
    void SetOwner(const Player& owner) {
        this->owner = owner;
        this->belongs_to_bank = false;
    }
    void BuildHouse(const Player& player){
        this->house_num++;
    }
    void BelongsToBank(Bank& bank) {
        this->belongs_to_bank = true; 
    }
private:
    bool belongs_to_bank;
    Player owner;
    uint32_t init_cost;
    uint32_t cost;
    uint8_t house_num;
};
class Bank{
public:
    Bank() = default;
    Bank(const Bank& bank) = default;
    ~Bank() = default;
    Bank& operator=(const Bank& bank) = delete;
    void GetMoney(uint32_t money){
        this->money += money;
    }
    void DistributeMoneyToPlayer(uint32_t money, Player& player);
private:
    uint32_t money = INITMONEY;
}
}// namespace monopoly
#endif // PLACE_H_