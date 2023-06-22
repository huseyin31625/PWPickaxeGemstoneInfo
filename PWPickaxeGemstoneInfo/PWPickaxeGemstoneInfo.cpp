#include <iostream>
#include <windows.h>
#include "pickaxegemstone.h"
HINSTANCE hInst = NULL;
HFONT font = NULL;
HFONT fontBold = NULL;
HFONT fontTitle = NULL;
HFONT fontDesc = NULL;
HMENU hmItemList = NULL;
LRESULT MainWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
    switch (Msg) {
    case WM_CLOSE:
        DestroyWindow(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_COMMAND:
    {
        int nCmd = LOWORD(wParam);
        switch (nCmd)
        {
        case 1001:
        {
            HWND hwndButton = (HWND)lParam;
            RECT rect;
            GetWindowRect(hwndButton, &rect);
            auto cmd = TrackPopupMenu(hmItemList, TPM_RETURNCMD, rect.left, rect.bottom, 0, hwndButton, NULL);
            int itemId = 0;
            switch (cmd)
            {
            case 110:
                itemId = GEMSTONE_TOPAZ_TINY;
                break;
            case 111:
                itemId = GEMSTONE_TOPAZ_SMALL;
                break;
            case 112:
                itemId = GEMSTONE_TOPAZ_MEDIUM;
                break;
            case 113:
                itemId = GEMSTONE_TOPAZ_LARGE;
                break;
            case 114:
                itemId = GEMSTONE_TOPAZ_HUGE;
                break;
            case 115:
                itemId = GEMSTONE_EMERALD_TINY;
                break;
            case 116:
                itemId = GEMSTONE_EMERALD_SMALL;
                break;
            case 117:
                itemId = GEMSTONE_EMERALD_MEDIUM;
                break;
            case 118:
                itemId = GEMSTONE_EMERALD_LARGE;
                break;
            case 119:
                itemId = GEMSTONE_EMERALD_HUGE;
                break;
            case 120:
                itemId = GEMSTONE_SAPPHIRE_TINY;
                break;
            case 121:
                itemId = GEMSTONE_SAPPHIRE_SMALL;
                break;
            case 122:
                itemId = GEMSTONE_SAPPHIRE_MEDIUM;
                break;
            case 123:
                itemId = GEMSTONE_SAPPHIRE_LARGE;
                break;
            case 124:
                itemId = GEMSTONE_SAPPHIRE_HUGE;
                break;
            case 125:
                itemId = GEMSTONE_RUBY_TINY;
                break;
            case 126:
                itemId = GEMSTONE_RUBY_SMALL;
                break;
            case 127:
                itemId = GEMSTONE_RUBY_MEDIUM;
                break;
            case 128:
                itemId = GEMSTONE_RUBY_LARGE;
                break;
            case 129:
                itemId = GEMSTONE_RUBY_HUGE;
                break;
            case 130:
                itemId = GEMSTONE_DIAMOND_TINY;
                break;
            case 131:
                itemId = GEMSTONE_DIAMOND_SMALL;
                break;
            case 132:
                itemId = GEMSTONE_DIAMOND_MEDIUM;
                break;
            case 133:
                itemId = GEMSTONE_DIAMOND_LARGE;
                break;
            case 134:
                itemId = GEMSTONE_DIAMOND_HUGE;
                break;
            case 160:
                itemId = PICKAXE_CRAPPY;
                break;
            case 161:
                itemId = PICKAXE_FLIMSY;
                break;
            case 162:
                itemId = PICKAXE_BASIC;
                break;
            case 163:
                itemId = PICKAXE_CLASSIC;
                break;
            case 164:
                itemId = PICKAXE_STURDY;
                break;
            case 165:
                itemId = PICKAXE_HEAVY;
                break;
            case 166:
                itemId = PICKAXE_MASTER;
                break;
            case 167:
                itemId = PICKAXE_EPIC;
                break;
            case 168:
                itemId = PICKAXE_DARK;
                break;
            default:
                itemId = -1;
                break;
            }
            if (itemId != -1)
            {
                ShowInfoDialog(hWnd, itemId);
            }
        }
        break;
        default:
            return DefWindowProc(hWnd, Msg, wParam, lParam);
        }
    }
    break;
    default:
        return DefWindowProc(hWnd, Msg, wParam, lParam);
    }
}
LRESULT ItemWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
    switch (Msg) {
    case WM_CLOSE:
        DestroyWindow(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_COMMAND:
    {
        int nCmd = LOWORD(wParam);
        switch (nCmd)
        {
        case IDOK:
            DestroyWindow(hWnd);
            break;
        default:
            return DefDlgProc(hWnd, Msg, wParam, lParam);
        }
    }
    break;
    default:
        return DefDlgProc(hWnd, Msg, wParam, lParam);
    }
}
void CreateItemListMenu()
{
    HMENU hmPickaxeList = CreatePopupMenu();
    HMENU hmGemstoneList = CreatePopupMenu();
    HMENU hmList = CreatePopupMenu();
    MENUITEMINFO mpicks = { 0 };
    mpicks.cbSize = sizeof(MENUITEMINFO);
    mpicks.dwTypeData = L"Pickaxes";
    mpicks.hSubMenu = hmPickaxeList;
    mpicks.fMask = MIIM_SUBMENU | MIIM_STRING;
    MENUITEMINFO mgems = { 0 };
    mgems.cbSize = sizeof(MENUITEMINFO);
    mgems.dwTypeData = L"Gemstones";
    mgems.hSubMenu = hmGemstoneList;
    mgems.fMask = MIIM_SUBMENU | MIIM_STRING;
    for (int i = 160; i <= 168; i++)
    {
        wchar_t pickaxeName[256];
        LoadString(hInst, i, pickaxeName, 256);
        InsertMenu(hmPickaxeList, 0, 0, i, pickaxeName);
    }
    for (int i = 110; i <= 134; i++)
    {
        wchar_t gemstoneName[256];
        LoadString(hInst, i, gemstoneName, 256);
        InsertMenu(hmGemstoneList, 0, 0, i, gemstoneName);
    }
    InsertMenuItem(hmList, 0, TRUE, &mpicks);
    InsertMenuItem(hmList, 0, TRUE, &mgems);
    hmItemList = hmList;
}
ATOM RegisterMainWindowClass()
{
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = MainWndProc;
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpszClassName = L"PWPGMainWindowClass";
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    return RegisterClass(&wc);
}
ATOM RegisterItemWindowClass()
{
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = ItemWndProc;
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpszClassName = L"PWPGItemWindowClass";
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.cbWndExtra = DLGWINDOWEXTRA;
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    return RegisterClass(&wc);
}
void ShowInfoDialog(HWND parent, DWORD itemId)
{
    if (parent != NULL)
        EnableWindow(parent, FALSE);
    RECT rectMain;
    GetWindowRect(parent, &rectMain);
    wchar_t itemString[256];
    wchar_t desc[1025];
    wchar_t gems[256];
    wchar_t lvl[256];
    HBITMAP itemBitmap = NULL;
    DWORD imgId = 0;
    DWORD stringId = 0;
    DWORD gemMax = 0;
    DWORD gemMin = 0;
    DWORD range = 0;
    DWORD durability = 0;
    DWORD efficiency = 0;
    DWORD descId = 0;
    switch (itemId)
    {
    case GEMSTONE_TOPAZ_TINY:
        stringId = 110;
        imgId = 146;
        break;
    case GEMSTONE_TOPAZ_SMALL:
        stringId = 111;
        imgId = 143;
        break;
    case GEMSTONE_TOPAZ_MEDIUM:
        stringId = 112;
        imgId = 142;
        break;
    case GEMSTONE_TOPAZ_LARGE:
        stringId = 113;
        imgId = 141;
        break;
    case GEMSTONE_TOPAZ_HUGE:
        stringId = 114;
        imgId = 140;
        break;
    case GEMSTONE_EMERALD_TINY:
        stringId = 115;
        imgId = 139;
        break;
    case GEMSTONE_EMERALD_SMALL:
        stringId = 116;
        imgId = 137;
        break;
    case GEMSTONE_EMERALD_MEDIUM:
        stringId = 117;
        imgId = 136;
        break;
    case GEMSTONE_EMERALD_LARGE:
        stringId = 118;
        imgId = 135;
        break;
    case GEMSTONE_EMERALD_HUGE:
        stringId = 119;
        imgId = 138;
        break;
    case GEMSTONE_SAPPHIRE_TINY:
        stringId = 120;
        imgId = 158;
        break;
    case GEMSTONE_SAPPHIRE_SMALL:
        stringId = 121;
        imgId = 159;
        break;
    case GEMSTONE_SAPPHIRE_MEDIUM:
        stringId = 122;
        imgId = 157;
        break;
    case GEMSTONE_SAPPHIRE_LARGE:
        stringId = 123;
        imgId = 156;
        break;
    case GEMSTONE_SAPPHIRE_HUGE:
        stringId = 124;
        imgId = 155;
        break;
    case GEMSTONE_RUBY_TINY:
        stringId = 125;
        imgId = 154;
        break;
    case GEMSTONE_RUBY_SMALL:
        stringId = 126;
        imgId = 153;
        break;
    case GEMSTONE_RUBY_MEDIUM:
        stringId = 127;
        imgId = 151;
        break;
    case GEMSTONE_RUBY_LARGE:
        stringId = 128;
        imgId = 152;
        break;
    case GEMSTONE_RUBY_HUGE:
        stringId = 129;
        imgId = 150;
        break;
    case GEMSTONE_DIAMOND_TINY:
        stringId = 130;
        imgId = 149;
        break;
    case GEMSTONE_DIAMOND_SMALL:
        stringId = 131;
        imgId = 148;
        break;
    case GEMSTONE_DIAMOND_MEDIUM:
        stringId = 132;
        imgId = 147;
        break;
    case GEMSTONE_DIAMOND_LARGE:
        stringId = 133;
        imgId = 145;
        break;
    case GEMSTONE_DIAMOND_HUGE:
        stringId = 134;
        imgId = 144;
        break;
    case PICKAXE_CRAPPY:
        stringId = 160;
        imgId = 108;
        break;
    case PICKAXE_FLIMSY:
        stringId = 161;
        imgId = 109;
        break;
    case PICKAXE_BASIC:
        stringId = 162;
        imgId = 107;
        break;
    case PICKAXE_CLASSIC:
        stringId = 163;
        imgId = 106;
        break;
    case PICKAXE_STURDY:
        stringId = 164;
        imgId = 105;
        break;
    case PICKAXE_HEAVY:
        stringId = 165;
        imgId = 104;
        break;
    case PICKAXE_MASTER:
        stringId = 166;
        imgId = 103;
        break;
    case PICKAXE_EPIC:
        stringId = 167;
        imgId = 102;
        break;
    case PICKAXE_DARK:
        stringId = 168;
        imgId = 101;
        break;
    }
    switch (itemId)
    {
    case GEMSTONE_TOPAZ_TINY:
    case GEMSTONE_TOPAZ_SMALL:
    case GEMSTONE_TOPAZ_MEDIUM:
    case GEMSTONE_TOPAZ_LARGE:
    case GEMSTONE_TOPAZ_HUGE:
        descId = 169;
        break;
    case GEMSTONE_EMERALD_TINY:
    case GEMSTONE_EMERALD_SMALL:
    case GEMSTONE_EMERALD_MEDIUM:
    case GEMSTONE_EMERALD_LARGE:
    case GEMSTONE_EMERALD_HUGE:
        descId = 170;
        break;
    case GEMSTONE_SAPPHIRE_TINY:
    case GEMSTONE_SAPPHIRE_SMALL:
    case GEMSTONE_SAPPHIRE_MEDIUM:
    case GEMSTONE_SAPPHIRE_LARGE:
    case GEMSTONE_SAPPHIRE_HUGE:
        descId = 171;
        break;
    case GEMSTONE_RUBY_TINY:
    case GEMSTONE_RUBY_SMALL:
    case GEMSTONE_RUBY_MEDIUM:
    case GEMSTONE_RUBY_LARGE:
    case GEMSTONE_RUBY_HUGE:
        descId = 172;
        break;
    case GEMSTONE_DIAMOND_TINY:
    case GEMSTONE_DIAMOND_SMALL:
    case GEMSTONE_DIAMOND_MEDIUM:
    case GEMSTONE_DIAMOND_LARGE:
    case GEMSTONE_DIAMOND_HUGE:
        descId = 173;
        break;
    case PICKAXE_CRAPPY:
        descId = 174;
        break;
    case PICKAXE_FLIMSY:
        descId = 175;
        break;
    case PICKAXE_BASIC:
        descId = 176;
        break;
    case PICKAXE_CLASSIC:
        descId = 177;
        break;
    case PICKAXE_STURDY:
        descId = 178;
        break;
    case PICKAXE_HEAVY:
        descId = 179;
        break;
    case PICKAXE_MASTER:
        descId = 180;
        break;
    case PICKAXE_EPIC:
        descId = 181;
        break;
    case PICKAXE_DARK:
        descId = 182;
        break;
    }
    LoadString(hInst, stringId, itemString, 256);
    LoadString(hInst, descId, desc, 1025);
    itemBitmap = LoadBitmap(hInst, MAKEINTRESOURCE(imgId));
    HWND infoWindow = CreateWindowEx(WS_EX_DLGMODALFRAME, L"PWPGItemWindowClass", itemString, WS_CAPTION | WS_SYSMENU, rectMain.left, rectMain.top, 816, 489, parent, NULL, hInst, NULL);
    HMENU menuSys = GetSystemMenu(infoWindow, FALSE);
    RemoveMenu(menuSys, SC_MAXIMIZE, MF_BYCOMMAND);
    RemoveMenu(menuSys, SC_SIZE, MF_BYCOMMAND);
    RemoveMenu(menuSys, SC_MINIMIZE, MF_BYCOMMAND);
    RemoveMenu(menuSys, SC_RESTORE, MF_BYCOMMAND);
    RemoveMenu(menuSys, 1, MF_BYPOSITION);
    RECT rect;
    GetClientRect(infoWindow, &rect);
    HDC hDC = GetDC(infoWindow);
    HDC hDCMem = CreateCompatibleDC(hDC);
    SelectObject(hDCMem, fontTitle);
    int w = rect.right - rect.left;
    int h = rect.bottom - rect.top;
    RECT rectTitle;
    DrawText(hDCMem, L"test", -1, &rectTitle, DT_CALCRECT);
    int hTitle = rectTitle.bottom - rectTitle.top;
    HWND itemBitmapCtrl = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP | SS_CENTERIMAGE, 10, 10, w - 20, 256, infoWindow, NULL, hInst, NULL);
    SendMessage(itemBitmapCtrl, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)itemBitmap);
    HWND itemTitleCtrl = CreateWindowEx(0, L"STATIC", itemString, WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE, 10, 276, w - 20, hTitle, infoWindow, NULL, hInst, NULL);
    SendMessage(itemTitleCtrl, WM_SETFONT, (WPARAM)fontTitle, (LPARAM)TRUE);
    SelectObject(hDCMem, fontBold);
    RECT rectBold;
    DrawText(hDCMem, L"test", -1, &rectBold, DT_CALCRECT);
    int hBold = rectBold.bottom - rectBold.top;
    SelectObject(hDCMem, font);
    RECT rectFont;
    DrawText(hDCMem, L"test", -1, &rectFont, DT_CALCRECT);
    int hFont = rectFont.bottom - rectFont.top;
    switch (itemId)
    {
        case PICKAXE_CRAPPY:
        case PICKAXE_FLIMSY:
        case PICKAXE_BASIC:
        case PICKAXE_CLASSIC:
        case PICKAXE_STURDY:
        case PICKAXE_HEAVY:
        case PICKAXE_MASTER:
        case PICKAXE_EPIC:
        case PICKAXE_DARK:
        {
            GetGemstoneDropsPickaxe(itemId, &gemMin, &gemMax);
            range = GetRangePickaxe(itemId);
            durability = GetDurabilityPickaxe(itemId);
            efficiency = GetEfficiencyAgainstRocksPickaxe(itemId);
            wchar_t gemdrop[256];
            wchar_t rang[256];
            wchar_t durb[256];
            if (gemMax == gemMin)
            {
                wsprintf(gemdrop, L"%d", gemMax);
            }
            else
            {
                wsprintf(gemdrop, L"%d-%d", gemMin, gemMax);
            }
            if (range != 2)
            {
                wsprintf(rang, L"%d", range);
            }
            else
            {
                wsprintf(rang, L"Default");
            }
            wsprintf(durb, L"%d", durability);
            HWND itemGemstoneDropsTitle = CreateWindowEx(0, L"STATIC", L"Gemstone drops: ", WS_CHILD | WS_VISIBLE, 10, 276 + hTitle, 200, hBold, infoWindow, NULL, hInst, NULL);
            SendMessage(itemGemstoneDropsTitle, WM_SETFONT, (WPARAM)fontBold, (LPARAM)TRUE);
            HWND itemGemstoneDropsVal = CreateWindowEx(0, L"STATIC", gemdrop, WS_CHILD | WS_VISIBLE | SS_RIGHT, 210, 276 + hTitle, 50, hFont, infoWindow, NULL, hInst, NULL);
            SendMessage(itemGemstoneDropsVal, WM_SETFONT, (WPARAM)font, (LPARAM)TRUE);
            HWND itemRangeTitle = CreateWindowEx(0, L"STATIC", L"Range: ", WS_CHILD | WS_VISIBLE, 10, 276 + hTitle + hBold, 200, hBold, infoWindow, NULL, hInst, NULL);
            SendMessage(itemRangeTitle, WM_SETFONT, (WPARAM)fontBold, (LPARAM)TRUE);
            HWND itemRangeVal = CreateWindowEx(0, L"STATIC", rang, WS_CHILD | WS_VISIBLE | SS_RIGHT, 210, 276 + hTitle + hFont, 50, hFont, infoWindow, NULL, hInst, NULL);
            SendMessage(itemRangeVal, WM_SETFONT, (WPARAM)font, (LPARAM)TRUE);
            HWND itemDurabilityTitle = CreateWindowEx(0, L"STATIC", L"Durability: ", WS_CHILD | WS_VISIBLE, 10, 276 + hTitle + (hBold*2), 200, hBold, infoWindow, NULL, hInst, NULL);
            SendMessage(itemDurabilityTitle, WM_SETFONT, (WPARAM)fontBold, (LPARAM)TRUE);
            HWND itemDurabilityVal = CreateWindowEx(0, L"STATIC", durb, WS_CHILD | WS_VISIBLE | SS_RIGHT, 210, 276 + hTitle + (hFont*2), 50, hFont, infoWindow, NULL, hInst, NULL);
            SendMessage(itemDurabilityVal, WM_SETFONT, (WPARAM)font, (LPARAM)TRUE);
        }
        break;
        case GEMSTONE_TOPAZ_TINY:
        case GEMSTONE_TOPAZ_SMALL:
        case GEMSTONE_TOPAZ_MEDIUM:
        case GEMSTONE_TOPAZ_LARGE:
        case GEMSTONE_TOPAZ_HUGE:
        case GEMSTONE_EMERALD_TINY:
        case GEMSTONE_EMERALD_SMALL:
        case GEMSTONE_EMERALD_MEDIUM:
        case GEMSTONE_EMERALD_LARGE:
        case GEMSTONE_EMERALD_HUGE:
        case GEMSTONE_SAPPHIRE_TINY:
        case GEMSTONE_SAPPHIRE_SMALL:
        case GEMSTONE_SAPPHIRE_MEDIUM:
        case GEMSTONE_SAPPHIRE_LARGE:
        case GEMSTONE_SAPPHIRE_HUGE:
        case GEMSTONE_RUBY_TINY:
        case GEMSTONE_RUBY_SMALL:
        case GEMSTONE_RUBY_MEDIUM:
        case GEMSTONE_RUBY_LARGE:
        case GEMSTONE_RUBY_HUGE:
        case GEMSTONE_DIAMOND_TINY:
        case GEMSTONE_DIAMOND_SMALL:
        case GEMSTONE_DIAMOND_MEDIUM:
        case GEMSTONE_DIAMOND_LARGE:
        case GEMSTONE_DIAMOND_HUGE:
        {
            wsprintf(gems, L"%d", GetGemAmountGemstone(itemId));
            wsprintf(lvl, L"Level %d", GetLevelGemstone(itemId));
            HWND itemFoundOnTitle = CreateWindowEx(0, L"STATIC", L"Found on: ", WS_CHILD | WS_VISIBLE, 10, 276 + hTitle + hBold, 200, hBold, infoWindow, NULL, hInst, NULL);
            SendMessage(itemFoundOnTitle, WM_SETFONT, (WPARAM)fontBold, (LPARAM)TRUE);
            HWND itemFoundOnVal = CreateWindowEx(0, L"STATIC", lvl, WS_CHILD | WS_VISIBLE | SS_RIGHT, 210, 276 + hTitle + hFont, 50, hFont, infoWindow, NULL, hInst, NULL);
            SendMessage(itemFoundOnVal, WM_SETFONT, (WPARAM)font, (LPARAM)TRUE);
            HWND itemGemsTitle = CreateWindowEx(0, L"STATIC", L"Gems: ", WS_CHILD | WS_VISIBLE, 10, 276 + hTitle + (hBold * 2), 200, hBold, infoWindow, NULL, hInst, NULL);
            SendMessage(itemGemsTitle, WM_SETFONT, (WPARAM)fontBold, (LPARAM)TRUE);
            HWND itemGemsVal = CreateWindowEx(0, L"STATIC", gems, WS_CHILD | WS_VISIBLE | SS_RIGHT, 210, 276 + hTitle + (hFont * 2), 50, hFont, infoWindow, NULL, hInst, NULL);
            SendMessage(itemGemsVal, WM_SETFONT, (WPARAM)font, (LPARAM)TRUE);
        }
        break;
    }
    HWND itemDescVal = CreateWindowEx(0, L"STATIC", desc, WS_CHILD | WS_VISIBLE | SS_CENTER | SS_EDITCONTROL, 10, 276 + hTitle + (hFont * 3), w - 20, h - (276 + hTitle + (hFont * 3)), infoWindow, NULL, hInst, NULL);
    SendMessage(itemDescVal, WM_SETFONT, (WPARAM)fontDesc, (LPARAM)TRUE);
    ShowWindow(infoWindow, SW_SHOW);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        if (!IsDialogMessage(infoWindow, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    DeleteObject(itemBitmap);
    DeleteDC(hDCMem);
    if (parent != NULL)
    {
        EnableWindow(parent, TRUE);
        SetForegroundWindow(parent);
    }
}
int
WINAPI
wWinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR lpCmdLine,
    _In_ int nShowCmd
)
{
    hInst = hInstance;
    RegisterMainWindowClass();
    RegisterItemWindowClass();
    CreateItemListMenu();
    font = CreateFont(-12, 0, 0, 0, FW_REGULAR, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
        CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, VARIABLE_PITCH, TEXT("Segoe UI"));
    fontBold = CreateFont(-12, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
        CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, VARIABLE_PITCH, TEXT("Segoe UI"));
    fontTitle = CreateFont(-24, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
        CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, VARIABLE_PITCH, TEXT("Segoe UI"));
    fontDesc = CreateFont(-12, 0, 0, 0, FW_REGULAR, TRUE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
        CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, VARIABLE_PITCH, TEXT("Segoe UI"));
    HWND hwndMain = CreateWindowEx(0, L"PWPGMainWindowClass", L"Pixel Worlds Pickaxe Gemstone Info", WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
        CW_USEDEFAULT, 0, 816, 489, NULL, NULL, hInst, NULL);
    HWND buttonStart = CreateWindowEx(0, L"BUTTON", L"Pickaxes / Gemstones", WS_CHILD | WS_VISIBLE,
        10, 10, 200, 27, hwndMain, (HMENU)1001, hInst, NULL);
    SendMessage(buttonStart, WM_SETFONT, (WPARAM)font, (LPARAM)TRUE);
    ShowWindow(hwndMain, SW_SHOW);
    UpdateWindow(hwndMain);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}