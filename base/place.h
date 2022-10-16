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
    ~Place() = default;

    //friend class Player;

    uint8_t getPosition() const { return position; }
    Color getColor() const { return color; }
    Tool getTool() const { return tool; }
    void setTool(const Tool& tool) { this->tool = tool; }
    Type getType() const { return type; }
protected:
    bool belong_to_bank = true;
private:
    uint8_t position;
    Color color;
    Tool tool;
    Type type;
};
class Zone : public Place{
public:
    Zone() = default;
    Zone(const Zone& zone) = default;
    ~Zone() = default;
    Type getType() = delete;
    uint16_t getCost() const { return cost; }
    uint8_t getHouseNum() const { return house_num; }
private:
    Player owner;
    uint16_t cost;
    uint8_t house_num;
};
class Hospital : public Place{
public:
    Hospital() = default;
    Hospital(const Hospital& hospital) = delete;
    ~Hospital() = default;
    Type getType() = delete;

    void SetForbiddenState3(Player& player);
};
class Prison : public Place{
public:
    Prison() = default;
    Prison(const Prison& prison) = delete;
    ~Prison() = default;
    Type getType() = delete;

    void SetForbiddenState2(Player& player);
};
class Mine : public Place{
public:
    Mine() = default;
    Mine(const Mine& mine) = delete;
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
    ~MagicRoom() = default;
    Type getType() = delete;

    void MaybePlayerUseMagic(Player& player);
};
class GiftRoom : public Place{
public:
    GiftRoom() = default;
    GiftRoom(const GiftRoom& giftRoom) = delete;
    ~GiftRoom() = default;
    Type getType() = delete;

    void MaybePlayerGetGift(Player& player, uint8_t choice);
    void ChooseGift1(Player& player);
    void ChooseGift2(Player& player);
    void ChooseGift3(Player& player);
private:
    const uint8_t money_num;
    const uint8_t point_num;
};
class ToolRoom : public Place{
public:
    ToolRoom() = default;
    ToolRoom(const ToolRoom& toolRoom) = delete;
    ~ToolRoom() = default;
    Type getType() = delete;

    void MaybePlayerBuyTool(Player& player, uint8_t choice);
    void BuyTool(Player& player, Tool& tool);
private:
    const std::vector<Tool> tools;
};
}// namespace monopoly
#endif // PLACE_H_