#pragma once
#include "modapi/worldgen/BlockHelper.h"
#include <mc/world/level/levelgen/feature/IFeature.h>

class Random;

namespace modapi::inline worldgen {

class ICustomFeature : public IFeature {
public:
    MOD_API ICustomFeature();
    MOD_API virtual ~ICustomFeature() override;
    MOD_API virtual std::optional<BlockPos> place(IFeature::PlacementContext const&) const override;
    MOD_API virtual std::optional<BlockPos> place(BlockHelper& helper, BlockPos const& pos, Random& random) const = 0;
};

} // namespace modapi::inline worldgen