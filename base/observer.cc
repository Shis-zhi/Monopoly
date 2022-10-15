#include"./observer.h"

namespace monopoly{
//玩家(player)向银行(this->global_bank)支付货币购买区域(place),place所有权转让
void Observer::PlayerBuyFromBank(Player& player, Place& place){

}
//玩家(player)向银行(this->global_bank)出售区域(place)获取货币,place所有权转让
void Observer::PlayerSellToBank(Player& player, Place& place){

}
//玩家位置更新，可能会触发一系列动作：
//1. owner为bank
//2. owner为自己
//3. owner为他人
void Observer::PlayerUpdatePlace(Player& player, Place& place){

}
}