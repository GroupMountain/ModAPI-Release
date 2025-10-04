#pragma once
#include <ll/api/base/StdInt.h>

namespace modapi::inline recipe {

enum class RecipeIngredientType : uint8 {
    Item = 0,
    Tag  = 1,
};

}