#pragma once
#include "modapi/effect/enum/MobEffectType.h"
#include "modapi/item/base/ICustomItem.h"
#include <mc/deps/core/math/Vec3.h>
#include <mc/world/effect/MobEffectInstance.h>

namespace modapi::inline item {

class ICustomFoodItem : public ICustomItem {
public:
    enum class UseAction : int {
        None                 = -1,
        ChorusTeleport       = 0,
        SuspiciousStewEffect = 1,
    };

public:
    MOD_NDAPI explicit ICustomFoodItem(std::string const& identifier);

    virtual int getNutrition() const = 0;

    virtual float getSaturation() const = 0;

    MOD_API virtual bool canAlwaysEat() const;

    MOD_API virtual std::string getUsingConvertTo() const;

    MOD_API virtual UseAction getUseAction() const;

    MOD_API virtual Vec3 getOnUseRange() const;

    MOD_API virtual std::vector<::MobEffectInstance> getEffects() const;

    MOD_API virtual std::vector<uint32_t> getRemoveEffects() const;

    MOD_API bool isFood() const override;

    MOD_API SharedTypes::Legacy::UseAnimation getUseAnimation() const override;

    MOD_API ::ItemUseMethod useTimeDepleted(::ItemStack&, ::Level*, ::Player*) const override;

    MOD_API void _init() override;

public:
    MOD_NDAPI static ::MobEffectInstance createEffect(
        MobEffectType effectType,
        int           durationTicks = 600,
        int           amplifier     = 0,
        bool          visible       = true,
        bool          ambient       = false,
        bool          animation     = false
    );
};

} // namespace modapi::inline item