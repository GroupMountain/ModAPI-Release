#pragma once
#include <mc/_HeaderOutputPredefine.h>
#include <mc/world/item/Item.h>

class ItemDescriptor;
class ItemInstance;

class PotionBrewing {
public:
    class Ingredient {
    public:
        int mItemId;
        int mData;

    public:
        MCAPI bool equals(::ItemDescriptor const& input) const;
    };

    template <typename T>
    class Mix {
    public:
        T          mFrom;
        Ingredient mIngredient;
        T          mTo;
    };

public:
    MCAPI static void addContainerRecipe(::Item const& from, Ingredient const& ingredient, ::Item const& to);

    MCAPI static void
    addPotionMix(::ItemDescriptor const& from, Ingredient const& ingredient, ::ItemDescriptor const& to);

    MCAPI static ::ItemInstance getChemistryMix(::ItemDescriptor const& from, ::ItemDescriptor const& ingredient);

    MCAPI static int getFuelValue(::ItemDescriptor const& item);

    MCAPI static bool hasMix(::ItemInstance const& source, ::ItemDescriptor const& ingredient);

    MCAPI static void initPotionBrewing();

    MCAPI static bool isContainerIngredient(::ItemDescriptor const& item);

    MCAPI static bool isFuel(::ItemDescriptor const& item);

    MCAPI static bool isPotionContainer(::ItemDescriptor const& item);

    MCAPI static bool isPotionIngredient(::ItemDescriptor const& item);

    MCAPI static bool isPotionRecipeInput(::ItemDescriptor const& item);

    MCAPI static ::ItemInstance mix(::ItemDescriptor const& ingredient, ::ItemInstance const& source);

    MCAPI static void shutdown();

public:
    MCAPI static ::std::vector<Mix<::ItemInstance>>& mChemistryMixes();

    MCAPI static ::std::vector<Mix<::Item const&>>& mContainerMixes();

    MCAPI static bool& mIsInitialized();

    MCAPI static ::std::vector<Mix<::ItemDescriptor>>& mPotionMixes();

    MCAPI static ::std::vector<Ingredient>& mValidContainers();

    MCAPI static ::std::unordered_set<Ingredient>& mValidIngredients();

    MCAPI static ::std::unordered_set<Ingredient>& mValidRecipeInputs();
};