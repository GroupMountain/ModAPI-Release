#pragma once
#include "modapi/Macros.h"
#include "modapi/item/types/DamageChance.h"
#include "modapi/item/types/ItemIcon.h"
#include "modapi/item/types/RepairItems.h"
#include <mc/deps/shared_types/legacy/item/UseAnimation.h>
#include <mc/nbt/CompoundTag.h>
#include <mc/world/item/Item.h>
#include <mc/world/item/Rarity.h>
#include <mc/world/item/enchanting/Enchant.h>

namespace modapi::inline item {

class ICustomItem : public ::Item {
public:
    MOD_NDAPI explicit ICustomItem(std::string const& identifier);

    MOD_API ~ICustomItem();

    virtual ItemIcon getIcon() const = 0;

    MOD_API virtual uint8_t getItemMaxStackSize() const;

    MOD_API virtual std::vector<std::string> getItemTags() const;

    MOD_API virtual bool allowOffhand() const;

    MOD_API virtual std::string getHoverTextColorFormat() const;

    MOD_API virtual bool shouldDespawn() const;

    MOD_API virtual ::Enchant::Slot getEnchantmentSlot() const;

    MOD_API virtual bool isFoil() const;

    MOD_API virtual uint8_t getCompostChance() const;

    MOD_API virtual DamageChance getItemDamageChance() const;

    MOD_API virtual short getItemDurability() const;

    MOD_API virtual std::vector<RepairItems> getRepairItems() const;

    MOD_API virtual ::SharedTypes::Legacy::UseAnimation getUseAnimation() const;

    MOD_API virtual bool requiresWorldBuilder() const;

    MOD_API virtual bool isExplodable() const;

    MOD_API virtual bool isFireResistant() const;

    MOD_API virtual bool shouldIgnoresPermissions() const;

    MOD_API virtual bool shouldAnimatesInToolbar() const;

    MOD_API virtual std::string getDisplayName() const;

    MOD_API virtual int getUseDuration() const;

    MOD_API virtual ::Interactions::Mining::MineBlockItemEffectType getMineBlockItemEffectType() const;

    MOD_API virtual ::CreativeItemCategory getCreativeCategory() const;

    MOD_API virtual ::std::string getCreativeGroup() const;

    MOD_API virtual ::HashedString const& getCooldownCategory() const;

    MOD_API virtual bool isDiggerItem() const;

    MOD_API virtual float getMiningSpeed() const;

    MOD_API virtual bool isFuel() const;

    MOD_API virtual float getFurnaceBurnInterval() const;

    MOD_API virtual float getFurnaceXPmultiplier() const;

    MOD_API virtual ::ItemCommandVisibility shouldHiddenInCommands() const;

    MOD_API virtual bool isSmithingTransformable() const;

    MOD_API virtual bool isSmithingTransformMaterial() const;

    MOD_API virtual bool isSmithingTemplate() const;

    MOD_API virtual bool canDestroyInCreative() const;

    MOD_API virtual int getFrameCount() const;

    MOD_API virtual std::string getInteractButtonText() const;

    MOD_API float getDestroySpeed(::ItemStackBase const& item, ::Block const& block) const override;

    MOD_API bool
    isValidRepairItem(::ItemStackBase const&, ::ItemStackBase const&, ::BaseGameVersion const&) const override;

    MOD_API int getEnchantSlot() const override;

    MOD_API int getDamageChance(int) const override;

    MOD_API short getMaxDamage() const override;

    MOD_API bool isComponentBased() const override;

    MOD_API std::unique_ptr<CompoundTag> buildNetworkTag() const override;

    MOD_API std::string getInteractText(::Player const& player) const override;

    MOD_API virtual void _init();
};

} // namespace modapi::inline item
