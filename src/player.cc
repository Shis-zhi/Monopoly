#include<iostream>
#include<cstdlib>
#include<ctime>
#include"../include/player.h"
#include"../include/map.h"
namespace monopoly{
//随机数生成骰子点数：1-6
inline uint8_t Player::DiceNum(){
    srand((unsigned)time(NULL));
    return rand() % 6 + 1;
}
bool Player::Advance(Map& global_map){
    std::vector<std::unique_ptr<Place>>::const_iterator it;
    Place* tmp_place = this->CurPlace(); 
    it = std::find_if(global_map.PlacePtrVector.begin(), global_map.PlacePtrVector.end(), 
                        [tmp_place](std::unique_ptr<Place> place){
                            return tmp_place->getPosition()==place->getPosition();
                            });
    if(it != global_map.PlacePtrVector.end()){
        if((*it)->getPosition() == global_map.map_end->getPosition()){
            *(this->CurPlace()) = *(global_map.map_start);
        } else {
            std::advance(it,1);
            *(this->cur_place) = **it;
        }
        return true;
    } else {
        return false;
    }
}
//根据骰子点数决定前进步数
void Player::UpdateCurPlace(Map& global_map){
    //迭代器寻找this->cur_zone位置
    //利用迭代器寻找元素
    for(int i=0; i<this->DiceNum();i++){
        this->Advance(global_map);
        //TODO:道具判定
    }
}
//获取player当前位置
inline Place* Player::CurPlace(){
    return this->cur_place;
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
    std::vector<Zone>::const_iterator it;
    it = std::find_if(this->ZoneVector.begin(), this->ZoneVector.end(), 
                        [zone](Zone zone_){
                            return zone.getPosition()==zone_.getPosition();
                            });
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
    it = std::find_if(this->ToolVector.begin(), this->ToolVector.end(), 
                        [tool](Tool tool_){
                            return tool.tool_type==tool_.tool_type;
                            });
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
void Player::GoToHospital(){
    const Hospital hospital(14,HOSPITAL);
    const Place* const tmp = &hospital;
    *(this->cur_place) = *tmp;
    this->is_hurted = true;
}
}// namespace monopoly