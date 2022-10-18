#ifndef PUBLIC_H_
#define PUBLIC_H_

namespace monopoly{
    typedef signed char             int8_t;
    typedef short int               int16_t;
    typedef int                     int32_t;
    typedef unsigned char           uint8_t;
    typedef unsigned short int      uint16_t;
    typedef unsigned int            uint32_t;

    extern const uint8_t MaxSize = 70;
    typedef enum {NORMAL, FORBIDDEN1, FORBIDDEN2, FORBIDDEN3}PlayerState;
    typedef enum{BOMB, BARRICADE, DOLL}ToolType;
    typedef enum{Black, Red, Green, Yellow} Color;
    typedef enum{START,ZONE,HOSPITAL,PRISON,MINE,MAGICROOM,GIFTROOM,TOOLROOM} Type;
}// namespace monopoly
#endif