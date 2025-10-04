#pragma once
#include <mc/world/item/crafting/Recipe.h>

class SmithingTransformRecipe : public ::ShapelessRecipe {
public:
    ::Recipe::ResultList mRuntimeResultList;

public:
    SmithingTransformRecipe& operator=(SmithingTransformRecipe const&);
    SmithingTransformRecipe(SmithingTransformRecipe const&);
    SmithingTransformRecipe();

public:
    bool matches(::CraftingContainer const& craftingContainer, ::CraftingContext const&) const override;

    ::std::vector<::ItemInstance> const&
    assemble(::CraftingContainer& craftingContainer, ::CraftingContext&) const override;

    ~SmithingTransformRecipe() override = default;

public:
    MCAPI SmithingTransformRecipe(
        ::std::string const&      recipeId,
        ::RecipeIngredient const& templateIngredient,
        ::RecipeIngredient const& baseIngredient,
        ::RecipeIngredient const& additionIngredient,
        ::Recipe::Results&&       results,
        ::HashedString const&     tag
    );

public:
    MCAPI static ::mce::UUID const& ID();
};
