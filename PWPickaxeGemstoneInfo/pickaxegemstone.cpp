#include <windows.h>
#include "pickaxegemstone.h"
DWORD GetGemAmountGemstone(DWORD gemstoneId)
{
    DWORD retval = 0;
    switch (gemstoneId)
    {
    case GEMSTONE_TOPAZ_TINY:
        retval = 3;
        break;
    case GEMSTONE_TOPAZ_SMALL:
        retval = 6;
        break;
    case GEMSTONE_TOPAZ_MEDIUM:
        retval = 12;
        break;
    case GEMSTONE_TOPAZ_LARGE:
        retval = 30;
        break;
    case GEMSTONE_TOPAZ_HUGE:
        retval = 90;
        break;
    case GEMSTONE_EMERALD_TINY:
        retval = 5;
        break;
    case GEMSTONE_EMERALD_SMALL:
        retval = 10;
        break;
    case GEMSTONE_EMERALD_MEDIUM:
        retval = 20;
        break;
    case GEMSTONE_EMERALD_LARGE:
        retval = 50;
        break;
    case GEMSTONE_EMERALD_HUGE:
        retval = 150;
        break;
    case GEMSTONE_SAPPHIRE_TINY:
        retval = 10;
        break;
    case GEMSTONE_SAPPHIRE_SMALL:
        retval = 20;
        break;
    case GEMSTONE_SAPPHIRE_MEDIUM:
        retval = 40;
        break;
    case GEMSTONE_SAPPHIRE_LARGE:
        retval = 100;
        break;
    case GEMSTONE_SAPPHIRE_HUGE:
        retval = 300;
        break;
    case GEMSTONE_RUBY_TINY:
        retval = 20;
        break;
    case GEMSTONE_RUBY_SMALL:
        retval = 40;
        break;
    case GEMSTONE_RUBY_MEDIUM:
        retval = 80;
        break;
    case GEMSTONE_RUBY_LARGE:
        retval = 200;
        break;
    case GEMSTONE_RUBY_HUGE:
        retval = 600;
        break;
    case GEMSTONE_DIAMOND_TINY:
        retval = 30;
        break;
    case GEMSTONE_DIAMOND_SMALL:
        retval = 60;
        break;
    case GEMSTONE_DIAMOND_MEDIUM:
        retval = 120;
        break;
    case GEMSTONE_DIAMOND_LARGE:
        retval = 300;
        break;
    case GEMSTONE_DIAMOND_HUGE:
        retval = 900;
        break;
    }
    return retval;
}
DWORD GetLevelGemstone(DWORD gemstoneId)
{
    DWORD retval = 0;
    switch (gemstoneId)
    {
    case GEMSTONE_TOPAZ_TINY:
    case GEMSTONE_TOPAZ_SMALL:
    case GEMSTONE_TOPAZ_MEDIUM:
    case GEMSTONE_TOPAZ_LARGE:
    case GEMSTONE_TOPAZ_HUGE:
        retval = 1;
        break;
    case GEMSTONE_EMERALD_TINY:
    case GEMSTONE_EMERALD_SMALL:
    case GEMSTONE_EMERALD_MEDIUM:
    case GEMSTONE_EMERALD_LARGE:
    case GEMSTONE_EMERALD_HUGE:
        retval = 2;
        break;
    case GEMSTONE_SAPPHIRE_TINY:
    case GEMSTONE_SAPPHIRE_SMALL:
    case GEMSTONE_SAPPHIRE_MEDIUM:
    case GEMSTONE_SAPPHIRE_LARGE:
    case GEMSTONE_SAPPHIRE_HUGE:
        retval = 3;
        break;
    case GEMSTONE_RUBY_TINY:
    case GEMSTONE_RUBY_SMALL:
    case GEMSTONE_RUBY_MEDIUM:
    case GEMSTONE_RUBY_LARGE:
    case GEMSTONE_RUBY_HUGE:
        retval = 4;
        break;
    case GEMSTONE_DIAMOND_TINY:
    case GEMSTONE_DIAMOND_SMALL:
    case GEMSTONE_DIAMOND_MEDIUM:
    case GEMSTONE_DIAMOND_LARGE:
    case GEMSTONE_DIAMOND_HUGE:
        retval = 5;
        break;
    }
    return retval;
}
BOOL GetGemstoneDropsPickaxe(DWORD pickaxeId, PDWORD pdMin, PDWORD pdMax)
{
    BOOL retval = TRUE;
    switch (pickaxeId)
    {
    case PICKAXE_CRAPPY:
    case PICKAXE_FLIMSY:
    case PICKAXE_BASIC:
    case PICKAXE_CLASSIC:
    case PICKAXE_DARK:
        *pdMin = 1;
        break;
    case PICKAXE_STURDY:
    case PICKAXE_HEAVY:
        *pdMin = 2;
        break;
    case PICKAXE_MASTER:
        *pdMin = 3;
        *pdMax = 7;
        break;
    case PICKAXE_EPIC:
        *pdMin = 4;
        *pdMax = 8;
        break;
    default:
        retval = FALSE;
        break;
    }
    switch (pickaxeId)
    {
    case PICKAXE_CRAPPY:
        *pdMax = 1;
        break;
    case PICKAXE_FLIMSY:
        *pdMax = 2;
        break;
    case PICKAXE_BASIC:
    case PICKAXE_CLASSIC:
        *pdMax = 3;
        break;
    case PICKAXE_STURDY:
        *pdMax = 4;
        break;
    case PICKAXE_HEAVY:
        *pdMax = 5;
        break;
    case PICKAXE_DARK:
        *pdMax = 12;
        break;
    default:
        retval = FALSE;
        break;
    }
    return retval;
}
DWORD GetDurabilityPickaxe(DWORD pickaxeId)
{
    DWORD retval = 0;
    switch (pickaxeId)
    {
    case PICKAXE_CRAPPY:
        retval = 5000;
        break;
    case PICKAXE_FLIMSY:
        retval = 5500;
        break;
    case PICKAXE_BASIC:
    case PICKAXE_CLASSIC:
        retval = 6000;
        break;
    case PICKAXE_STURDY:
        retval = 6500;
        break;
    case PICKAXE_HEAVY:
        retval = 7000;
        break;
    case PICKAXE_MASTER:
        retval = 8000;
        break;
    case PICKAXE_EPIC:
    case PICKAXE_DARK:
        retval = 10000;
        break;
    }
    return retval;
}
DWORD GetEfficiencyAgainstRocksPickaxe(DWORD pickaxeId)
{
    DWORD retval = 0;
    switch (pickaxeId)
    {
    case PICKAXE_CRAPPY:
    case PICKAXE_FLIMSY:
        retval = EFF_POOR;
        break;
    case PICKAXE_BASIC:
    case PICKAXE_CLASSIC:
    case PICKAXE_STURDY:
        retval = EFF_AVERAGE;
        break;
    case PICKAXE_HEAVY:
    case PICKAXE_MASTER:
        retval = EFF_GOOD;
        break;
    case PICKAXE_EPIC:
    case PICKAXE_DARK:
        retval = EFF_EXCELLENT;
        break;
    }
    return retval;
}
DWORD GetRangePickaxe(DWORD pickaxeId)
{
    DWORD retval = 0;
    if (pickaxeId == PICKAXE_EPIC || pickaxeId == PICKAXE_DARK)
    {
        retval = 3;
    }
    else
    {
        retval = 2;
    }
    return retval;
}