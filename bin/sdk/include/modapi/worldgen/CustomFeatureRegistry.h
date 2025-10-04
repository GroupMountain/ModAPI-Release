#pragma once
#include "modapi/worldgen/ICustomFeature.h"
#include <functional>
#include <ll/api/coro/Generator.h>

namespace modapi::inline worldgen {

class CustomFeatureRegistry {
    struct Impl;
    std::unique_ptr<Impl> pImpl;

public:
    CustomFeatureRegistry();
    CustomFeatureRegistry& operator=(CustomFeatureRegistry const&) = delete;
    CustomFeatureRegistry(CustomFeatureRegistry const&)            = delete;
    using CustomFeatureRule =
        std::function<ll::coro::Generator<BlockPos>(BlockHelper const& helper, BlockPos const& pos, Random& random)>;

    MOD_API CustomFeatureRegistry& registerFeature(std::string_view identifier, std::unique_ptr<IFeature> feature);
    MOD_API CustomFeatureRegistry&
    registerFeatureRule(std::string_view identifier, std::vector<std::string> const& passes, CustomFeatureRule rule);
    MOD_API static CustomFeatureRegistry& getInstance();
};

} // namespace modapi::inline worldgen