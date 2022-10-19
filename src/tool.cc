#include"../include/public.h"
#include"../include/tool.h"

namespace monopoly{
void Bomb::Trigger(Player& player, Place& place) const{
    Hospital hospital(14,HOSPITAL);
    player.GoToHospital();
    hospital.SetForbiddenState3(player);
}
void Barricade::Trigger(Player& player, Place& place) const{
    player.can_advance = false;
}
void Doll::Trigger(Player& player, Place& place) const{
    int8_t player_cur_pos = place.getPosition();
    
}
}// namespace monopoly