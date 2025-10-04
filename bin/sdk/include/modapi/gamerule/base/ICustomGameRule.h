#pragma once
#include "modapi/Macros.h"
#include <string>
#include <type_traits>

namespace modapi::inline gamerule {

template <typename T>
class ICustomGameRule {
public:
    static_assert(
        std::is_same_v<T, bool> || std::is_same_v<T, int> || std::is_same_v<T, float>,
        "ICustomGameRule<T> can only be instantiated with T = bool, T = int or T = float"
    );

    using ValueType = T;

public:
    MOD_API virtual ~ICustomGameRule();

    virtual std::string getIdentifier() const = 0;

    virtual T getDefaultValue() const = 0;

    MOD_NDAPI virtual bool requiresCheats() const;

    MOD_NDAPI virtual bool shouleSaveToDisk() const;

    MOD_NDAPI virtual bool allowUseInCommand() const;

    MOD_NDAPI virtual bool allowUseInScripting() const;

    MOD_NDAPI virtual bool canBeModifiedByPlayer() const;
};

} // namespace modapi::inline gamerule
