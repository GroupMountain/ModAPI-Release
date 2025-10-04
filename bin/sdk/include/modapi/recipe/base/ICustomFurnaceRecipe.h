#pragma once
#include "modapi/recipe/base/ICustomRecipe.h"
#include <mc/world/item/ItemInstance.h>

namespace modapi::inline recipe {

class ICustomFurnaceRecipe : public ICustomRecipe {
public:
    MOD_NDAPI ICustomFurnaceRecipe();

    MOD_NDAPI std::string getRecipeId() const override;

    MOD_NDAPI std::vector<::std::string> getCraftingTags() const override;

    virtual Ingredient getIngredient() const = 0;

    virtual ::ItemInstance getResult() const = 0;

protected:
    MOD_API void _init() override;
};

} // namespace modapi::inline recipe