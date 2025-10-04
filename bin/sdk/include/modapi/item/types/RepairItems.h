#pragma once
#include "modapi/Macros.h"
#include <set>
#include <string>
#include <vector>

namespace modapi::inline item {

struct RepairItems {
    std::set<std::string> mItems;
    float                 mRepairAmount;

    MOD_NDAPI RepairItems();
    MOD_NDAPI RepairItems(std::string_view item, float repairAmount);
    MOD_NDAPI RepairItems(std::vector<std::string> const& items, float repairAmount);
};

} // namespace modapi::inline item