#pragma once
#include "modapi/recipe/base/ICustomShapedRecipe.h"
#include <mc/world/item/ItemStack.h>

namespace modapi::inline recipe {

class ICustomShapedMultiRecipe : public ICustomShapedRecipe {
public:
    using CraftingContainerInput = std::unordered_map<std::string, std::vector<::ItemStack const*>>;
    using CraftingCallback       = std::function<void(CraftingContainerInput const& input, ::ItemInstance& output)>;

public:
    MOD_NDAPI ICustomShapedMultiRecipe();

    virtual CraftingCallback getCraftingCallback() const = 0;

protected:
    MOD_API void _init() override;
};

} // namespace modapi::inline recipe