#pragma once
#include "modapi/recipe/base/ICustomShapelessRecipe.h"

namespace modapi::inline recipe {

class ICustomStoneCutterRecipe : public ICustomShapelessRecipe {
public:
    MOD_NDAPI ICustomStoneCutterRecipe();

    MOD_NDAPI std::vector<std::string> getCraftingTags() const override;

    MOD_NDAPI std::vector<Ingredient> getIngredients() const override;

    virtual Ingredient getIngredient() const = 0;
};

} // namespace modapi::inline recipe