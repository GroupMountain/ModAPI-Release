#pragma once
#include "modapi/gamerule/base/ICustomGameRule.h"
#include <functional>
#include <memory>

namespace modapi::inline gamerule {

class CustomGameRuleRegistry {
public:
    struct Impl;
    std::unique_ptr<Impl> pImpl;

public:
    CustomGameRuleRegistry();
    CustomGameRuleRegistry& operator=(CustomGameRuleRegistry const&) = delete;
    CustomGameRuleRegistry(CustomGameRuleRegistry const&)            = delete;

public:
    MOD_NDAPI static CustomGameRuleRegistry& getInstance();

public:
    CustomGameRuleRegistry& registerGameRuleBool(
        std::string const& identifier,
        bool               defaultValue,
        bool               requiresCheats        = false,
        bool               shouleSaveToDisk      = true,
        bool               allowUseInCommand     = true,
        bool               allowUseInScripting   = true,
        bool               canBeModifiedByPlayer = true
    );

    CustomGameRuleRegistry& registerGameRuleInt(
        std::string const& identifier,
        int                defaultValue,
        bool               requiresCheats        = false,
        bool               shouleSaveToDisk      = true,
        bool               allowUseInCommand     = true,
        bool               allowUseInScripting   = true,
        bool               canBeModifiedByPlayer = true
    );

    CustomGameRuleRegistry& registerGameRuleFloat(
        std::string const& identifier,
        float              defaultValue,
        bool               requiresCheats        = false,
        bool               shouleSaveToDisk      = true,
        bool               allowUseInCommand     = true,
        bool               allowUseInScripting   = true,
        bool               canBeModifiedByPlayer = true
    );

    template <typename T, class... Args>
        requires(std::is_base_of_v<ICustomGameRule<bool>, T> || std::is_base_of_v<ICustomGameRule<int>, T> || std::is_base_of_v<ICustomGameRule<float>, T>)
    CustomGameRuleRegistry& registerGameRule(Args&&... args) {
        return _registerGameRule([... args = std::forward<Args>(args)]() -> std::unique_ptr<T> {
            return std::make_unique<T>(args...);
        });
    }

protected:
    MOD_NDAPI CustomGameRuleRegistry& _registerGameRule(std::function<std::unique_ptr<ICustomGameRule<bool>>()>&&);
    MOD_NDAPI CustomGameRuleRegistry& _registerGameRule(std::function<std::unique_ptr<ICustomGameRule<int>>()>&&);
    MOD_NDAPI CustomGameRuleRegistry& _registerGameRule(std::function<std::unique_ptr<ICustomGameRule<float>>()>&&);
};

} // namespace modapi::inline gamerule

#define GMLIB_REGISTER_GAME_RULE(RULE_CLASS, ...)                                                                      \
    inline static auto GMLIB_CUSTOM_GAME_RULE_##RULE_CLASS = [] {                                                      \
        ::modapi::CustomGameRuleRegistry::getInstance().registerGameRule<RULE_CLASS>(__VA_ARGS__);                     \
        return 0;                                                                                                      \
    }();

#define GMLIB_REGISTER_GAME_RULES(IDENTIFIER, RULE_CLASS, ...)                                                         \
    inline static auto GMLIB_CUSTOM_GAME_RULE_##IDENTIFIER = [] {                                                      \
        ::modapi::CustomGameRuleRegistry::getInstance().registerGameRule<RULE_CLASS>(__VA_ARGS__);                     \
        return 0;                                                                                                      \
    }();