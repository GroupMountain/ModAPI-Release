#pragma once
#include "modapi/recipe/base/ICustomRecipe.h"
#include <mc/world/item/ItemInstance.h>

namespace modapi::inline recipe {

class ICustomShapelessRecipe : public ICustomRecipe {
public:
    MOD_NDAPI ICustomShapelessRecipe();

    MOD_NDAPI std::vector<::std::string> getCraftingTags() const override;

    virtual std::vector<Ingredient> getIngredients() const = 0;

    virtual ::ItemInstance getResult() const = 0;

    MOD_NDAPI virtual int getPriority() const;

    MOD_NDAPI virtual UnlockingRequirement getUnlockingRequirement() const;

protected:
    MOD_API void _init() override;
};

} // namespace modapi::inline recipe