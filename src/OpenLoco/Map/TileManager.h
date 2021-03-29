#pragma once

#include "../Core/Span.hpp"
#include "Tile.h"
#include <cstdint>
#include <tuple>

namespace OpenLoco::Map::TileManager
{
    enum MapSelectFlag : uint16_t
    {
        enable = (1 << 0),
        enableConstruct = (1 << 1)
    };

    constexpr size_t maxElements = 0x6C000;

    void initialise();
    stdx::span<tile_element> getElements();
    tile_element* getElementsEnd();
    tile_element** getElementIndex();
    tile get(TilePos pos);
    tile get(map_pos pos);
    tile get(coord_t x, coord_t y);
    TileHeight getHeight(const map_pos& pos);
    void updateTilePointers();
    void reorganise();
    map_pos screenGetMapXY(int16_t x, int16_t y);
    uint16_t setMapSelectionTiles(int16_t x, int16_t y);
    map_pos3 screenPosToMapPos(int16_t x, int16_t y);
    uint16_t setMapSelectionSingleTile(int16_t x, int16_t y, bool setQuadrant = false);
    void mapInvalidateSelectionRect();
    void mapInvalidateTileFull(Map::map_pos pos);
    void mapInvalidateMapSelectionTiles();
}
