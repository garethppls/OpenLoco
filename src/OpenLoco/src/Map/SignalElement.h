#pragma once

#include "TileElementBase.h"

namespace OpenLoco::Map
{
#pragma pack(push, 1)
    struct SignalElement : public TileElementBase
    {
        static constexpr ElementType kElementType = ElementType::signal;

        struct Side
        {
        private:
            uint8_t _4;
            uint8_t _5;

        public:
            bool hasSignal() const { return _4 & 0x80; }
            bool hasUnk4_40() const { return _4 & (1 << 6); }
            void setUnk4_40(bool newState)
            {
                _4 &= ~(1 << 6);
                _4 |= newState ? (1 << 6) : 0;
            }
            void setUnk4(uint8_t newUnk4)
            {
                _4 &= ~0x30;
                _4 |= (newUnk4 & 0x3) << 4;
            }
            uint8_t signalObjectId() const { return _4 & 0xF; } // _4l
            uint8_t frame() const { return _5 & 0xF; }          // _5l
            uint8_t allLights() const { return _5 >> 4; }       // _5u
            void setAllLights(uint8_t newLights)
            {
                _5 &= ~(0xF0);
                _5 |= newLights << 4;
            }
            bool hasRedLight() const { return _5 & 0x40; }    // TBC colours
            bool hasRedLight2() const { return _5 & 0x10; }   // TBC colours
            bool hasGreenLight() const { return _5 & 0x80; }  // TBC colours
            bool hasGreenLight2() const { return _5 & 0x20; } // TBC colours
        };

    private:
        Side sides[2];

    public:
        uint8_t rotation() const { return _type & 0x3; }
        bool isLeftGhost() const { return _type & 0x80; }
        bool isRightGhost() const { return _type & 0x40; }
        Side& getLeft() { return sides[0]; }
        Side& getRight() { return sides[1]; }
        const Side& getLeft() const { return sides[0]; }
        const Side& getRight() const { return sides[1]; }
    };
#pragma pack(pop)
    static_assert(sizeof(SignalElement) == kTileElementSize);
}
