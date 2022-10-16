#include"player.h"
namespace monopoly{
//随机数生成骰子点数：1-6
inline uint8_t Player::DiceNum(){

}
//根据骰子点数决定前进步数
inline void Player::UpdateCurPlace(){

}
//获取player当前位置
inline Place Player::CurPlace(){

}
//获得货币
inline void Player::GetMoney(uint32_t money){
    this->money += money;
}
//失去货币，this->money - money < 0?
inline bool Player::LostMoney(uint32_t money){

}
//向其他用户支付货币
void Player::PayToOtherPlayer(uint32_t money, Player& other){

}
//第一次买地向银行支付
void Player::PayToBankForInit(uint32_t money, Bank& bank){

}
//盖房子向银行支付
void Player::PayToBankForHouse(uint32_t money, Bank& bank){

}
//将用户状态设置为NORMAL
inline void Player::SetNormState(){

}
//将用户状态设置为FORBIDDEN
inline void Player::SetForbiddenState(){

}
//判断place是否在player的PlaceVector中
bool Player::InPlaceVector(const Place& place) const{

}
//将place添加到player的PlaceVector中
void Player::GetPlace(Place& place){

}
//将place从player的PlaceVector中删除,成功返回true，否则返回false
bool Player::LostPlace(Place& place){

}
}