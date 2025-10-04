#pragma once
#include <mc/world/item/crafting/Recipe.h>

class ShapelessRecipe : public ::Recipe {
public:
    ShapelessRecipe& operator=(ShapelessRecipe const&);
    ShapelessRecipe(ShapelessRecipe const&);

    ShapelessRecipe() : Recipe(ConstructionContext()) {}

public:
    ::std::vector<::ItemInstance> const& assemble(::CraftingContainer&, ::CraftingContext&) const override;

    int getCraftingSize() const override;

    ::RecipeIngredient const& getIngredient(int x, int y) const override;

    bool isShapeless() const override;

    bool matches(::CraftingContainer const& craftSlots, ::CraftingContext const&) const override;

    int size() const override;

    ~ShapelessRecipe() override;
};
