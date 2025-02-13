#include "CargoObject.h"
#include "Interop/Interop.hpp"

namespace OpenLoco
{
    // 0x0042F533
    bool CargoObject::validate() const
    {
        if (var_2 > 3840)
        {
            return false;
        }
        if (var_4 == 0)
        {
            return false;
        }
        return true;
    }

    // 0x0042F4D0
    void CargoObject::load(const LoadedObjectHandle& handle, stdx::span<std::byte> data)
    {
        Interop::registers regs;
        regs.esi = Interop::X86Pointer(this);
        regs.ebx = handle.id;
        regs.ecx = enumValue(handle.type);
        Interop::call(0x0042F4D0, regs);
    }

    // 0x0042F514
    void CargoObject::unload()
    {
        name = 0;
        unitsAndCargoName = 0;
        unitNameSingular = 0;
        unitNamePlural = 0;
        unitInlineSprite = 0;
    }
}
