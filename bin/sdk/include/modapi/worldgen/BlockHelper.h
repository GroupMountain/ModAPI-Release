#pragma once
#include "modapi/Macros.h"
#include <mc/world/level/BlockPos.h>
#include <mc/world/level/dimension/DimensionHeightRange.h>
#include <memory>

class Block;
class BlockSource;
class LevelChunk;

namespace modapi::inline worldgen {

class BlockHelper {
    struct Impl;
    std::unique_ptr<Impl> pImpl;

public:
    MOD_API explicit BlockHelper(BlockSource*);
    MOD_API explicit BlockHelper(LevelChunk*);
    MOD_API ~BlockHelper();

    MOD_API void         setBlock(BlockPos const& pos, Block const& block, uchar layer = 0, int updateFlags = 0);
    MOD_API Block const& getBlock(BlockPos const& pos, uchar layer = 0) const;

    MOD_API DimensionHeightRange getHeightRange() const;

    template <typename T, typename = std::enable_if_t<std::is_same_v<T, BlockSource> || std::is_same_v<T, LevelChunk>>>
    MOD_API T* get();
    template <typename T, typename = std::enable_if_t<std::is_same_v<T, BlockSource> || std::is_same_v<T, LevelChunk>>>
    MOD_API T const* get() const;
};

} // namespace modapi::inline worldgen