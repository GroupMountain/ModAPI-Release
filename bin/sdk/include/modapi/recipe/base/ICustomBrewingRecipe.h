#pragma once
#include "modapi/recipe/base/ICustomRecipe.h"

namespace modapi::inline recipe {

class ICustomBrewingRecipe : public ICustomRecipe {
public:
    MOD_NDAPI ICustomBrewingRecipe();

    MOD_NDAPI std::string getRecipeId() const override;

    MOD_NDAPI std::vector<::std::string> getCraftingTags() const override;

    virtual Ingredient getInput() const = 0;

    virtual Ingredient getReagent() const = 0;

    virtual Ingredient getOutput() const = 0;

protected:
    MOD_API void _init() override;
};

} // namespace modapi::inline recipe