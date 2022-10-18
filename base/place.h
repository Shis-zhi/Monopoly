#ifndef PLACE_H_
#define PLACE_H_
#include"./public.h"
#include"./player.h"
#include"./tool.h"
#include<vector>
namespace monopoly{
class Place{
public:
    Place() = default;
    Place(const Place& place) = default;
    Place(uint8_t pos,Type type):position(pos),type(type){};
    ~Place() = default;
    uint8_t getPosition() const { return position; }
    Color getColor() const { return color; }
    Tool getTool() const { return tool; }
    void setTool(const Tool& tool) { this->tool = tool; }
    Type getType() const { return type; }
protected:
    bool belong_to_bank = true;
    uint8_t position;
    Color color; 
    Tool tool;
    Type type;
};
class Zone : public Place{
public:
    Zone() = default;
    Zone(const Zone& zone) = default;
    Zone(uint8_t pos,Type type,uint16_t cost){
        this->position = pos;
        this->type = type;
        this->cost = cost;    
    };
    ~Zone() = default;
    Type getType() = delete;
    uint16_t getCost() const { return cost; }
    uint8_t getHouseNum() const { return house_num; }
    Player getOwner() const { return this->owner; }
    void setOwner(Player& owner) { this->owner = owner; }
    bool MaybeTriggerEvent(Player& player);
    void OnOwnZone(Player& player);
    void OnOthersZone(Player& player);
    void OnEmptyZone(Player& player);
private:
    Player owner;
    uint16_t cost;
    uint8_t house_num;
};
class Hospital : public Place{
public:
    Hospital() = default;
    Hospital(const Hospital& hospital) = delete;
    Hospital(uint8_t position,Type type){
        this->position = position;
        this->type = type;
    }
    ~Hospital() = default;
    Type getType() = delete;

    void SetForbiddenState3(Player& player);
};
class Prison : public Place{
public:
    Prison() = default;
    Prison(const Prison& prison) = delete;
    Prison(uint8_t position,Type type){
        this->position = position;
        this->type = type;
    }
    ~Prison() = default;
    Type getType() = delete;

    void SetForbiddenState2(Player& player);
};
class Mine : public Place{
public:
    Mine() = default;
    Mine(const Mine& mine) = delete;
    Mine(uint8_t position,Type type,uint8_t point){
        this->position = position;
        this->type = type;
        this->point_num = point;
    }
    ~Mine() = default;
    Type getType() = delete;

    void GivePointToPlayer(Player& player);
private:
    uint8_t point_num;
};
class MagicRoom : public Place{
public:
    MagicRoom() = default;
    MagicRoom(const MagicRoom& magicRoom) = delete;
    MagicRoom(uint8_t position,Type type){
        this->position = position;
        this->type = type;
    }
    ~MagicRoom() = default;
    Type getType() = delete;

    bool MaybePlayerUseMagic(Player& player);
};
class GiftRoom : public Place{
public:
    GiftRoom() = default;
    GiftRoom(const GiftRoom& giftRoom) = delete;
    GiftRoom(uint8_t position,Type type){
        this->position = position;
        this->type = type;
    }
    ~GiftRoom() = default;
    Type getType() = delete;

    bool MaybePlayerGetGift(Player& player, uint8_t choice);
    void ChooseGift1(Player& player);
    void ChooseGift2(Player& player);
    void ChooseGift3(Player& player);
private:
    const uint8_t money_num = 2000;
    const uint8_t point_num = 200;
};
class ToolRoom : public Place{
public:
    friend class Player;
    ToolRoom() = default;
    ToolRoom(const ToolRoom& toolRoom) = delete;
    ToolRoom(uint8_t position,Type type){
        this->position = position;
        this->type = type;
    }
    ~ToolRoom() = default;
    Type getType() = delete;

    bool MaybePlayerBuyTool(Player& player, uint8_t choice);
    bool MaybeBuyTool(Player& player, Tool tool);
private:
    const std::vector<Tool> tools;
};
}// namespace monopoly
#endif // PLACE_H_