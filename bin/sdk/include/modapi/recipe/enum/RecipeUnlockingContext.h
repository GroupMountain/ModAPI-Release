#pragma once

namespace modapi::inline recipe {

enum class RecipeUnlockingContext : int {
    None               = 0,
    AlwaysUnlocked     = 1,
    PlayerInWater      = 2,
    PlayerHasManyItems = 3,
};

}