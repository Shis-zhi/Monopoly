#include"player.h"
namespace monopoly{
//随机数生成骰子点数：1-6
inline uint8_t Player::DiceNum(){

}
//根据骰子点数决定前进步数
inline void Player::UpdateCurZone(){
    this->cur_zone.position += this->dice_num;
}
//获取player当前位置
inline Zone Player::CurZone(){
    return this->cur_zone;
}
//获得货币
inline void Player::GetMoney(uint32_t money){
    this->money += money;
}
//失去货币，this->money - money < 0?
inline bool Player::LostMoney(uint32_t money){
    if(this->money-money<0){
        //TODO trigger out
        return false;
    } else {
        this->money -= money;
        return true;
    }
}
//获取点数
inline void Player::GetPoint(uint32_t point){
    this->point += point;
}
//失去点数，this->point - point < 0?
inline bool Player::LostPoint(uint32_t point){
    if(this->point-point<0){
        return false;
    } else {
        this->point -= point;
        return true;
    }
}
//向其他用户支付货币
void Player::PayToOtherPlayer(uint32_t money, Player& other){
    this->LostMoney(money);
    other.GetMoney(money);
}
//判断zone是否在player的ZoneVector中
bool Player::InZoneVector(const Zone& zone) const{

}
//将zone添加到player的ZoneVector中
void Player::GetZone(Zone& zone){

}
//将zone从player的ZoneVector中删除,成功返回true，否则返回false
bool Player::LostZone(Zone& zone){

}
//获得道具tool
void GetTool(Tool& tool){

}
//在zone位置使用道具tool
bool UseTool(Tool& tool,Zone& zone){

}
}