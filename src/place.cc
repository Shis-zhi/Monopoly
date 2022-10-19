#include"../include/place.h"
#include"../include/public.h"
#include<vector>
namespace monopoly{
//设置player的state为FORBIDDEN3
void Hospital::SetForbiddenState3(Player& player){   
    player.state = FORBIDDEN3;
}
//设置player的state为FORBIDDEN2
void Prison::SetForbiddenState2(Player& player){
    player.state = FORBIDDEN2;
}
//mine给予player点数
void Mine::GivePointToPlayer(Player& player){
    player.GetPoint(this->point_num);
}
//TODO
bool MagicRoom::MaybePlayerUseMagic(Player& player){

}
//通过choice决定player资产变动
bool GiftRoom::MaybePlayerGetGift(Player& player, uint8_t choice){
    switch (choice){
        case 1:
            this->ChooseGift1(player);
            break;
        case 2:
            this->ChooseGift2(player);
            break;
        case 3:
            this->ChooseGift3(player);
            break;
    }
    return true;
}
//选择礼品1
void GiftRoom::ChooseGift1(Player& player){
    player.money += this->money_num;
}
//选择礼品2
void GiftRoom::ChooseGift2(Player& player){
    player.point += this->point_num;
}
//选择礼品3
void GiftRoom::ChooseGift3(Player& player){
    player.rest_wealth_time = 3;
}
bool ToolRoom::MaybeBuyTool(Player& player, Tool tool){
    if(player.LostMoney(tool.GetPointCost())){
        player.ToolVector.push_back(tool);
        return true;
    } else {
        return false;
    }
}
//通过choice决定player是否购买道具以及购买哪个道具
bool ToolRoom::MaybePlayerBuyTool(Player& player, uint8_t choice){
    //TODO
    return MaybeBuyTool(player, this->tools[choice-1]);
}
//choice=1,2,3时表示player购买了道具this->tools[--choice]

}// namespace monopoly