#ifndef PUBLIC_H_
#define PUBLIC_H_

namespace monopoly{
    typedef signed char             int8_t;
    typedef short int               int16_t;
    typedef int                     int32_t;
    typedef unsigned char           uint8_t;
    typedef unsigned short int      uint16_t;
    typedef unsigned int            uint32_t;

    const uint8_t MaxSize = 69;

    typedef enum{Black, Red, Green, Yellow} Color;
    typedef enum{ZONE,HOSPITAL,PRISON,MINE,MAGICROOM,GIFTROOM,TOOLROOM} Type;
}// namespace monopoly
#endif