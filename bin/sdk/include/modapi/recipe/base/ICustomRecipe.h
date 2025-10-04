#pragma once
#include "modapi/Macros.h"
#include "modapi/recipe/enum/RecipeIngredientType.h"
#include "modapi/recipe/enum/RecipeUnlockingContext.h"
#include <memory>
#include <optional>
#include <string>
#include <vector>


namespace modapi::inline recipe {

class CustomRecipeRegistry;

class ICustomRecipe {
public:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
    friend class CustomRecipeRegistry;

public:
    struct Ingredient {
        struct Impl;
        std::unique_ptr<Impl> pImpl;

        MOD_NDAPI explicit Ingredient(char const* type);
        MOD_NDAPI explicit Ingredient(
            ::std::string_view   type,
            RecipeIngredientType ingredientType = RecipeIngredientType::Item,
            uint8_t              count          = 1
        );
        MOD_NDAPI explicit Ingredient(::std::string_view type, uint8_t count, ::std::optional<short> aux = {});

        MOD_NDAPI Ingredient(Ingredient const&);
        MOD_NDAPI Ingredient(Ingredient&&);

        MOD_API Ingredient& operator=(Ingredient const&);
        MOD_API Ingredient& operator=(Ingredient&&);

        MOD_API ~Ingredient();
    };

    struct UnlockingRequirement {
        struct Impl;
        ::std::unique_ptr<Impl> pImpl;

        MOD_NDAPI UnlockingRequirement(
            ::std::vector<Ingredient> const& items,
            RecipeUnlockingContext = RecipeUnlockingContext::None
        );
        MOD_NDAPI UnlockingRequirement(RecipeUnlockingContext context);

        MOD_NDAPI UnlockingRequirement(UnlockingRequirement const&);
        MOD_NDAPI UnlockingRequirement(UnlockingRequirement&&);

        MOD_API UnlockingRequirement& operator=(UnlockingRequirement const&);
        MOD_API UnlockingRequirement& operator=(UnlockingRequirement&&);

        MOD_API ~UnlockingRequirement();
    };

public:
    ICustomRecipe();
    ICustomRecipe& operator=(ICustomRecipe const&) = delete;
    ICustomRecipe(ICustomRecipe const&)            = delete;

public:
    MOD_API virtual ~ICustomRecipe();

    virtual std::string getRecipeId() const = 0;

    virtual std::vector<std::string> getCraftingTags() const = 0;

    virtual void _init() = 0;
};

} // namespace modapi::inline recipe
