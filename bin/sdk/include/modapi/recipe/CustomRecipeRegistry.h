#pragma once
#include "modapi/recipe/base/ICustomShapedMultiRecipe.h"
#include "modapi/recipe/base/ICustomShapelessMultiRecipe.h"

namespace modapi::inline recipe {

class CustomRecipeRegistry {
public:
    struct Impl;
    std::unique_ptr<Impl> pImpl;

public:
    CustomRecipeRegistry();
    CustomRecipeRegistry& operator=(CustomRecipeRegistry const&) = delete;
    CustomRecipeRegistry(CustomRecipeRegistry const&)            = delete;

public:
    MOD_NDAPI static CustomRecipeRegistry& getInstance();

public:
    template <std::derived_from<ICustomRecipe> T, class... Args>
    CustomRecipeRegistry& registerRecipe(Args&&... args) {
        return _registerRecipe([... args = std::forward<Args>(args)]() -> std::unique_ptr<ICustomRecipe> {
            return std::make_unique<T>(args...);
        });
    }

    MOD_API CustomRecipeRegistry& registerShapedRecipe(
        std::string const&                            recipeId,
        std::vector<std::string> const&               shape,
        ICustomShapedRecipe::ShapedIngredients const& ingredients,
        ::ItemInstance const&                         result,
        ICustomRecipe::UnlockingRequirement const&    unlock =
            ICustomRecipe::UnlockingRequirement(RecipeUnlockingContext::AlwaysUnlocked),
        std::vector<std::string> const& tags           = {"crafting_table"},
        bool                            assumeSymmetry = false,
        int                             priority       = 50
    );

    MOD_API CustomRecipeRegistry& registerShapedMultiRecipe(
        std::string const&                            recipeId,
        std::vector<std::string> const&               shape,
        ICustomShapedRecipe::ShapedIngredients const& ingredients,
        ::ItemInstance const&                         result,
        ICustomShapedMultiRecipe::CraftingCallback&&  craftingCallback,
        ICustomRecipe::UnlockingRequirement const&    unlock =
            ICustomRecipe::UnlockingRequirement(RecipeUnlockingContext::AlwaysUnlocked),
        std::vector<std::string> const& tags           = {"crafting_table"},
        bool                            assumeSymmetry = false,
        int                             priority       = 50
    );

    MOD_API CustomRecipeRegistry& registerShapelessRecipe(
        std::string const&                            recipeId,
        std::vector<ICustomRecipe::Ingredient> const& ingredients,
        ::ItemInstance const&                         result,
        ICustomRecipe::UnlockingRequirement const&    unlock =
            ICustomRecipe::UnlockingRequirement(RecipeUnlockingContext::AlwaysUnlocked),
        std::vector<std::string> const& tags     = {"crafting_table"},
        int                             priority = 50
    );

    MOD_API CustomRecipeRegistry& registerShapelessMultiRecipe(
        std::string const&                              recipeId,
        std::vector<ICustomRecipe::Ingredient> const&   ingredients,
        ::ItemInstance const&                           result,
        ICustomShapelessMultiRecipe::CraftingCallback&& craftingCallback,
        ICustomRecipe::UnlockingRequirement const&      unlock =
            ICustomRecipe::UnlockingRequirement(RecipeUnlockingContext::AlwaysUnlocked),
        std::vector<std::string> const& tags     = {"crafting_table"},
        int                             priority = 50
    );

    MOD_API CustomRecipeRegistry& registerStoneCutterRecipe(
        std::string const&               recipeId,
        ICustomRecipe::Ingredient const& ingredient,
        ::ItemInstance const&            result,
        int                              priority = 50
    );

    MOD_API CustomRecipeRegistry& registerFurnaceRecipe(
        ICustomRecipe::Ingredient const& input,
        ::ItemInstance const&            output,
        std::vector<std::string> const&  tags = {"furnace"}
    );

    MOD_API CustomRecipeRegistry& registerBrewingRecipe(
        ICustomRecipe::Ingredient const& input,
        ICustomRecipe::Ingredient const& reagent,
        ICustomRecipe::Ingredient const& output
    );

    MOD_API CustomRecipeRegistry& registerSmithingTransformRecipe(
        std::string const&               recipeId,
        ICustomRecipe::Ingredient const& smithingTemplate,
        ICustomRecipe::Ingredient const& baseIngredient,
        ICustomRecipe::Ingredient const& additionIngredient,
        ::ItemInstance const&            result
    );

    MOD_API CustomRecipeRegistry& registerSmithingTrimRecipe(
        std::string const&               recipeId,
        ICustomRecipe::Ingredient const& smithingTemplate,
        ICustomRecipe::Ingredient const& baseIngredient,
        ICustomRecipe::Ingredient const& additionIngredient
    );

    MOD_API bool unregisterRecipe(std::string const& recipeId, bool updateClients = false);

    MOD_API void updateClientRecipes();

    MOD_API CustomRecipeRegistry& registerRecipeFromMemoryJson(std::string const& rawJson);

public:
    MOD_API CustomRecipeRegistry& registerRecipeFromJsonFile(std::filesystem::path const& jsonPath);

    MOD_NDAPI CustomRecipeRegistry& _registerRecipe(std::function<std::unique_ptr<ICustomRecipe>()>&&);
};

} // namespace modapi::inline recipe

#define GMLIB_REGISTER_RECIPE(RECIPE_CLASS, ...)                                                                       \
    inline static auto GMLIB_CUSTOM_RECIPE_##RECIPE_CLASS = [] {                                                       \
        ::modapi::CustomRecipeRegistry::getInstance().registerRecipe<RECIPE_CLASS>(__VA_ARGS__);                       \
        return 0;                                                                                                      \
    }();

#define GMLIB_REGISTER_RECIPES(IDENTIFIER, RECIPE_CLASS, ...)                                                          \
    inline static auto GMLIB_CUSTOM_RECIPE_##IDENTIFIER = [] {                                                         \
        ::modapi::CustomRecipeRegistry::getInstance().registerRecipe<RECIPE_CLASS>(__VA_ARGS__);                       \
        return 0;                                                                                                      \
    }();
