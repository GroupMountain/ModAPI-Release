#pragma once
#include <mc/world/item/crafting/Recipe.h>

class SmithingTrimRecipe : public ::ShapelessRecipe {
public:
    ::Recipe::ResultList mRuntimeResultList;

public:
    SmithingTrimRecipe& operator=(SmithingTrimRecipe const&);
    SmithingTrimRecipe(SmithingTrimRecipe const&);
    SmithingTrimRecipe();

public:
    bool matches(::CraftingContainer const& craftingContainer, ::CraftingContext const& craftingContext) const override;

    ::std::vector<::ItemInstance> const&
    assemble(::CraftingContainer& craftingContainer, ::CraftingContext& craftingContext) const override;

    bool hasDataDrivenResult() const override;

    ~SmithingTrimRecipe() override = default;

public:
    MCAPI SmithingTrimRecipe(
        ::std::string const&      recipeId,
        ::RecipeIngredient const& templateIngredient,
        ::RecipeIngredient const& baseIngredient,
        ::RecipeIngredient const& additionIngredient,
        ::HashedString const&     tag
    );

public:
    MCAPI static ::mce::UUID const& ID();
};