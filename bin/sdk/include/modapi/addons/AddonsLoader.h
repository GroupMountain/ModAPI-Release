#pragma once
#include "modapi/Macros.h"
#include <filesystem>
#include <mc/deps/core/resource/PackType.h>

class ResourcePackRepository;

namespace modapi::inline addons {

class AddonsLoader {
private:
    struct Impl;
    std::unique_ptr<Impl> pImpl;
    AddonsLoader();
    ~AddonsLoader();

public:
    MOD_API static AddonsLoader& getInstance();

    MOD_API void addCustomPackPath(std::filesystem::path const& path);
    MOD_API void setCustomPackPath(ResourcePackRepository& repo, std::filesystem::path const& path, PackType type);
};

} // namespace modapi::inline addons