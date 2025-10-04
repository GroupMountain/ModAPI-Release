#pragma once
#include "modapi/recipe/base/ICustomShapelessRecipe.h"
#include <mc/world/item/ItemStack.h>

namespace modapi::inline recipe {

class ICustomShapelessMultiRecipe : public ICustomShapelessRecipe {
public:
    using CraftingContainerInput = std::vector<::ItemStack const*>;
    using CraftingCallback       = std::function<void(CraftingContainerInput const& input, ::ItemInstance& output)>;

public:
    MOD_NDAPI ICustomShapelessMultiRecipe();

    virtual CraftingCallback getCraftingCallback() const = 0;

protected:
    MOD_API void _init() override;
};

} // namespace modapi::inline recipe