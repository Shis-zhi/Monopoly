#ifndef TOOL_H_
#define TOOL_H_
#include"./public.h"
#include"./player.h"
#include"./place.h"
namespace monopoly{
class Tool{
public:
    Tool() = default;
    Tool(const Tool& Tool) = default;
    ~Tool() = default;

    friend class Player;

    ToolType GetType(){return this->tool_type;}
    uint8_t GetPointCost(){return this->point_cost;}
private:
    uint8_t point_cost;
    ToolType tool_type;
    int8_t position;
};
class Bomb : public Tool{
public:
    Bomb() = default;
    Bomb(const Bomb& Bomb) = default;
    ~Bomb() = default;
    ToolType GetType() = delete;
    uint8_t Cost(){return this->point_cost;};
    void Trigger(Player& player, Place& place) const ;
private:
    const uint8_t point_cost = 50;
};
class Barricade : public Tool{
public:
    Barricade() = default;
    Barricade(const Barricade& Barricade) = default;
    ~Barricade() = default;
    ToolType GetType() = delete;
    uint8_t Cost(){return this->point_cost;};
    void Trigger(Player& player, Place& place) const;
private:
    const uint8_t point_cost = 50;
};
class Doll : public Tool{
public:
    Doll() = default;
    Doll(const Doll& Doll) = default;
    ~Doll() = default;
    ToolType GetType() = delete;
    uint8_t Cost(){return this->point_cost;};
    void Trigger(Player& player, Place& place) const;
private:
    const uint8_t point_cost = 30;
};
}// namespace monopoly
#endif// TOOL_H_