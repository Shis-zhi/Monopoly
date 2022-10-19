#include"./map.h"
#include"./public.h"
namespace monopoly{
void Map::InitAllPlaces(){
    uint8_t mine_point[6]={20,80,100,40,80,60};
    for(int pos=0;pos< MaxSize;pos++){
        if(pos==0){ // set start
            this->PlacePtrVector.push_back(std::unique_ptr<Place>(new Place(pos,START)));
        } else if(pos>=1 && pos<=27 && pos!=14){
            this->PlacePtrVector.push_back(std::unique_ptr<Place>(new Zone(pos,ZONE,200)));
        } else if(pos==14){
            this->PlacePtrVector.push_back(std::unique_ptr<Place>(new Hospital(pos,HOSPITAL)));
        } else if(pos==28){
            this->PlacePtrVector.push_back(std::unique_ptr<Place>(new ToolRoom(pos,TOOLROOM)));
        } else if(pos>=29 && pos <=34){
            this->PlacePtrVector.push_back(std::unique_ptr<Place>(new Zone(pos,ZONE,500)));
        } else if(pos==35){
            this->PlacePtrVector.push_back(std::unique_ptr<Place>(new GiftRoom(pos,GIFTROOM)));
        } else if(pos>=36 && pos <=62 && pos!=49){
            this->PlacePtrVector.push_back(std::unique_ptr<Place>(new Zone(pos,ZONE,300)));
        } else if(pos==49){
            this->PlacePtrVector.push_back(std::unique_ptr<Place>(new Prison(pos,PRISON)));
        } else if(pos==63){
            this->PlacePtrVector.push_back(std::unique_ptr<Place>(new MagicRoom(pos,MAGICROOM)));
        } else if(pos>=64 && pos<=69){
            this->PlacePtrVector.push_back(std::unique_ptr<Place>(new Mine(pos,PRISON,mine_point[pos-64])));
        }
    }
}
std::vector<std::unique_ptr<Place>>::const_iterator Map::FindPlace(uint8_t pos) const {
    std::vector<std::unique_ptr<Place>>::const_iterator iter;
    iter = std::find_if(this->PlacePtrVector.begin(), this->PlacePtrVector.end(), 
                        [pos](std::unique_ptr<Place> place){
                            return pos==place->getPosition();
                            });
    return iter;
}
}// namespace monopoly