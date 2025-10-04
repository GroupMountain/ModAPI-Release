#pragma once
#include <mc/world/item/ItemInstance.h>
#include <mc/world/item/NetworkItemInstanceDescriptor.h>
#include <mc/world/item/crafting/Recipe.h>

class ShapedRecipe : public ::Recipe {
public:
    bool mAssumeSymmetry;

public:
    ShapedRecipe& operator=(ShapedRecipe const&);
    ShapedRecipe(ShapedRecipe const&);

    ShapedRecipe() : Recipe(ConstructionContext()) {}

public:
    ~ShapedRecipe() override = default;

    ::std::vector<::ItemInstance> const& assemble(::CraftingContainer&, ::CraftingContext&) const override;

    int getCraftingSize() const override;

    ::RecipeIngredient const& getIngredient(int x, int y) const override;

    bool isShapeless() const override;

    bool matches(::CraftingContainer const& craftSlots, ::CraftingContext const&) const override;

    int size() const override;

public:
    MCAPI uint64 getIngredientsHashOffset(int simulatedWidth, int simulatedHeight, int offsetX, int offsetY) const;
    MCAPI bool   matches(::CraftingContainer const& craftSlots, int xOffs, int yOffs, bool xFlip) const;
};