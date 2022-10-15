#include"player.h"
namespace monopoly{
//随机数生成骰子点数：1-6
void Player::GetDiceNum(){
    this->dice_num = 
}
//根据骰子点数决定前进步数
void Player::UpdateCurPlace(){

}
//获得货币
void Player::GetMoney(uint32_t money){

}
//失去货币，this->money - money < 0?
bool Player::LostMoney(uint32_t money){

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
void Player::SetNormState(){

}
//将用户状态设置为FORBIDDEN
void Player::SetForbiddenState(){

}
//判断place是否在player的PlaceVector中
bool Player::InPlaceVector(const Place& place) const{

}
}