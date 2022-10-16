#include"./place.h"
#include<vector>
namespace monopoly{
//设置player的state为FORBIDDEN3
void Hospital::SetForbiddenState3(Player& player){

}
//设置player的state为FORBIDDEN2
void Prison::SetForbiddenState2(Player& player){

}
//mine给予player点数
void Mine::GivePointToPlayer(Player& player){

}
//TODO
void MagicRoom::MaybePlayerUseMagic(Player& player){

}
//通过choice决定player资产变动
void GiftRoom::MaybePlayerGetGift(Player& player, uint8_t choice){

}
//选择礼品1
void GiftRoom::ChooseGift1(Player& player){

}
//选择礼品2
void GiftRoom::ChooseGift2(Player& player){

}
//选择礼品3
void GiftRoom::ChooseGift3(Player& player){

}
//通过choice决定player是否购买道具以及购买哪个道具
void ToolRoom::MaybePlayerBuyTool(Player& player, uint8_t choice){

}
//choice=1,2,3时表示player购买了道具this->tools[--choice]
void ToolRoom::BuyTool(Player& player, Tool& tool){

}
}// namespace monopoly