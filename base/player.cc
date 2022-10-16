#include<iostream>
#include"player.h"
using std::cout;
using std::endl;
namespace monopoly{
//随机数生成骰子点数：1-6
inline uint8_t Player::DiceNum(){

}
//根据骰子点数决定前进步数
inline void Player::UpdateCurZone(){
    //迭代器寻找this->cur_zone位置
    //利用迭代器寻找元素
    std::vector<Zone>::const_iterator it;
    it = std::find(this->ZoneVector.begin(), this->ZoneVector.end(), this->cur_zone);
    //TODO:循环
    std::advance(it,this->dice_num);
    this->cur_zone = it;
}
//获取player当前位置
inline Zone Player::CurZone(){
    return this->cur_zone;
}
//获得货币
inline void Player::GetMoney(uint32_t money){
    cout << "this->money" << this->money << endl;
    this->money += money;
    cout << "this->money" << this->money << endl;
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
    std::vector<Zone>::const_iterator it;
    it = std::find(this->ZoneVector.begin(), this->ZoneVector.end(), zone);
    if(it == this->ZoneVector.end()){
        return false;
    } else {
        return true;
    }
}
//将zone添加到player的ZoneVector中
void Player::GetZone(Zone& zone){
    this->ZoneVector.push_back(zone);
}
//将zone从player的ZoneVector中删除,成功返回true，否则返回false
bool Player::LostZone(Zone& zone){
    if(this->InZoneVector(zone)){
        auto iter = std::remove(this->ZoneVector.begin(), this->ZoneVector.end(), zone);
        return true;
    } else {
        return false;
    }
}
//获得道具tool
void Player::GetTool(Tool& tool){
    this->ToolVector.push_back(tool);
}
//判断tool是否在player的ToolVector中
bool Player::InToolVector(const Tool& tool) const{
    std::vector<Tool>::const_iterator it;
    it = std::find(this->ToolVector.begin(), this->ToolVector.end(), tool);
    if(it == this->ToolVector.end()){
        return false;
    } else {
        return true;
    }
}
//在zone位置使用道具tool
bool Player::UseTool(Tool& tool,Zone& zone){
    if(this->InZoneVector(zone)){
        auto iter = std::remove(this->ZoneVector.begin(), this->ZoneVector.end(), zone);
        zone.setTool(tool);
        return true;
    } else {
        return false;
    }
}
}// namespace monopoly