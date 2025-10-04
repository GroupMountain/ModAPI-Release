#pragma once
#include "modapi/Macros.h"
#include <string>
#include <unordered_map>

namespace modapi::inline base {

class ItemIcon {
public:
    std::unordered_map<std::string, std::string> mTextures;

public:
    MOD_NDAPI ItemIcon();
    MOD_NDAPI explicit ItemIcon(char const* texture);
    MOD_NDAPI explicit ItemIcon(std::string_view texture);

    MOD_API void add(std::string_view type, std::string_view texture);
};

} // namespace modapi::inline base