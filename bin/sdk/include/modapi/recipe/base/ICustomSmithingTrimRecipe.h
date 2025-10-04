#pragma once
#include "modapi/recipe/base/ICustomRecipe.h"
#include <mc/world/item/ItemInstance.h>

namespace modapi::inline recipe {

class ICustomSmithingTrimRecipe : public ICustomRecipe {
public:
    MOD_NDAPI ICustomSmithingTrimRecipe();

    MOD_NDAPI std::vector<::std::string> getCraftingTags() const override;

    virtual Ingredient getSmithingTemplate() const = 0;

    virtual Ingredient getBaseIngredient() const = 0;

    virtual Ingredient getAdditionIngredient() const = 0;

protected:
    MOD_API void _init() override;
};

} // namespace modapi::inline recipe