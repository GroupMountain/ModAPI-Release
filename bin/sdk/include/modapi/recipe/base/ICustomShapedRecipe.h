#pragma once
#include "modapi/recipe/base/ICustomRecipe.h"
#include <mc/world/item/ItemInstance.h>

namespace modapi::inline recipe {

class ICustomShapedRecipe : public ICustomRecipe {
public:
    struct ShapedIngredients {
        std::unordered_map<std::string, Ingredient> mIngredients;

        MOD_NDAPI ShapedIngredients();
        MOD_NDAPI ShapedIngredients(std::initializer_list<std::pair<const std::string, Ingredient>> init);
        MOD_NDAPI explicit ShapedIngredients(std::unordered_map<std::string, Ingredient> const& mIngredients);

        MOD_API void add(std::string_view key, Ingredient const& ingredient);
    };

public:
    MOD_NDAPI ICustomShapedRecipe();

    MOD_NDAPI std::vector<::std::string> getCraftingTags() const override;

    virtual std::vector<std::string> getShape() const = 0;

    virtual ShapedIngredients getIngredients() const = 0;

    virtual ::ItemInstance getResult() const = 0;

    MOD_NDAPI virtual int getPriority() const;

    MOD_NDAPI virtual UnlockingRequirement getUnlockingRequirement() const;

    MOD_NDAPI virtual bool isAssumeSymmetry() const;

protected:
    MOD_API void _init() override;
};

} // namespace modapi::inline recipe