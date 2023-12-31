#pragma once
#define PICKAXE_CRAPPY 0
#define PICKAXE_FLIMSY 1
#define PICKAXE_BASIC 2
#define PICKAXE_STURDY 3
#define PICKAXE_HEAVY 4
#define PICKAXE_MASTER 5
#define PICKAXE_EPIC 6
#define PICKAXE_CLASSIC 7
#define PICKAXE_DARK 8
#define GEMSTONE_TOPAZ_TINY 9
#define GEMSTONE_TOPAZ_SMALL 10
#define GEMSTONE_TOPAZ_MEDIUM 11
#define GEMSTONE_TOPAZ_LARGE 12
#define GEMSTONE_TOPAZ_HUGE 13
#define GEMSTONE_EMERALD_TINY 14
#define GEMSTONE_EMERALD_SMALL 15
#define GEMSTONE_EMERALD_MEDIUM 16
#define GEMSTONE_EMERALD_LARGE 17
#define GEMSTONE_EMERALD_HUGE 18
#define GEMSTONE_SAPPHIRE_TINY 19
#define GEMSTONE_SAPPHIRE_SMALL 20
#define GEMSTONE_SAPPHIRE_MEDIUM 21
#define GEMSTONE_SAPPHIRE_LARGE 22
#define GEMSTONE_SAPPHIRE_HUGE 23
#define GEMSTONE_RUBY_TINY 24
#define GEMSTONE_RUBY_SMALL 25
#define GEMSTONE_RUBY_MEDIUM 26
#define GEMSTONE_RUBY_LARGE 27
#define GEMSTONE_RUBY_HUGE 28
#define GEMSTONE_DIAMOND_TINY 29
#define GEMSTONE_DIAMOND_SMALL 30
#define GEMSTONE_DIAMOND_MEDIUM 31
#define GEMSTONE_DIAMOND_LARGE 32
#define GEMSTONE_DIAMOND_HUGE 33
#define EFF_POOR 0
#define EFF_AVERAGE 1
#define EFF_GOOD 2
#define EFF_EXCELLENT 3
DWORD GetGemAmountGemstone(DWORD);
DWORD GetLevelGemstone(DWORD);
BOOL GetGemstoneDropsPickaxe(DWORD, PDWORD, PDWORD);
DWORD GetDurabilityPickaxe(DWORD);
DWORD GetEfficiencyAgainstRocksPickaxe(DWORD);
DWORD GetRangePickaxe(DWORD);
void ShowInfoDialog(HWND, DWORD);