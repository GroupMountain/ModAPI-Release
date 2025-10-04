#pragma once
#include "modapi/item/base/ICustomArmorItem.h"
#include "modapi/item/base/ICustomItem.h"

namespace modapi::inline item {

class CustomItemRegistry {
public:
    struct Impl;
    std::unique_ptr<Impl> pImpl;

public:
    CustomItemRegistry();
    CustomItemRegistry& operator=(CustomItemRegistry const&) = delete;
    CustomItemRegistry(CustomItemRegistry const&)            = delete;

public:
    MOD_NDAPI static CustomItemRegistry& getInstance();

public:
    template <std::derived_from<Item> T, class... Args>
    CustomItemRegistry& registerItem(Args&&... args) {
        return _registerItem([... args = std::forward<Args>(args)]() -> std::unique_ptr<Item> {
            auto item = std::make_unique<T>(args...);
            if constexpr (requires { item->_init(); }) item->_init();
            return std::move(item);
        });
    }

    MOD_API void forEachItemInRegistry(std::function<bool(Item& item)>&& func);

    MOD_NDAPI ::WeakPtr<::Item> getItem(std::string_view name);

public:
    MOD_API bool setFireResistant(std::string_view itemName, bool value = true);

    MOD_API bool addTag(std::string_view itemName, std::string_view tag);

    MOD_API bool setIcon(std::string_view itemName, std::string_view icon);

    MOD_API bool setDisplayName(std::string_view itemName, std::string_view displayName);

    MOD_API bool setRepairItem(std::string_view itemName, std::string_view fixItem);

    MOD_NDAPI ::CompoundTag& getAndModifyVanillaNetworkTagInfo(std::string_view itemName);

public:
    MOD_NDAPI CustomItemRegistry& _modifyItem(std::function<void(CustomItemRegistry&)>&&);

    MOD_NDAPI CustomItemRegistry& _registerItem(std::function<std::unique_ptr<Item>()>&&);
};

} // namespace modapi::inline item

#define GMLIB_REGISTER_ITEM(ITEM_CLASS, ...)                                                                           \
    inline static auto GMLIB_CUSTOM_ITEM_##ITEM_CLASS = [] {                                                           \
        ::modapi::CustomItemRegistry::getInstance().registerItem<ITEM_CLASS>(__VA_ARGS__);                             \
        return 0;                                                                                                      \
    }();

#define GMLIB_REGISTER_ITEMS(IDENTIFIER, ITEM_CLASS, ...)                                                              \
    inline static auto GMLIB_CUSTOM_ITEM_##IDENTIFIER = [] {                                                           \
        ::modapi::CustomItemRegistry::getInstance().registerItem<ITEM_CLASS>(__VA_ARGS__);                             \
        return 0;                                                                                                      \
    }();