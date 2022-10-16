#ifndef OBSERVER_H_
#define OBSERVER_H_

#include"./place.h"
#include"./player.h"

namespace monopoly{
class Observer{
public:
    Observer() = default;
    Observer(const Observer& other) = delete;
    ~Observer() = default;
    const Observer& operator=(const Observer& other) = delete;

    void PlayerBuyFromBank(Player& player, Place& place);
    void PlayerSellToBank(Player& player, Place& place);
    void PlayerUpdatePlace(Player& player);

private:
    Bank global_bank;
};
}
#endif