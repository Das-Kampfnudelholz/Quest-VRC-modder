#include <iostream>
#include <windows.h>

#include <cstdio>

#pragma comment(lib, "Urlmon.lib")

using namespace std;


int main()
{
    SetConsoleTitleA("QuestVRChatModInstaler");
    const wchar_t* destFile = L"LemonLoader.apk";
    const wchar_t* srcURL = L"https://cdn.discordapp.com/attachments/946558976781336586/1002402723712487514/app-release.apk";
    const wchar_t* destFil2 = L"HWIDPatch.dll";
    const wchar_t* srcUR2 = L"https://api.vrcmg.com/v1/mods/files/62/4/HWIDPatch.dll";
    const wchar_t* destFil = L"OculusPatch.dll";
    const wchar_t* srcUL = L"https://github.com/gompoc/MyEpicTestMod/releases/download/v1.0.0/MyEpicTestMod.dll";
    const wchar_t* aa = L"QuestPlayspaceMover.dll";
    const wchar_t* ab = L"https://github.com/Solexid/QuestPlayspaceMover/releases/download/r1/QuestPlayspaceMover.dll";
    const wchar_t* ba = L"NameplateStats.dll";
    const wchar_t* bb = L"https://github.com/Lewko6702/NameplateStats/releases/download/VRChat/NameplateStats.dll";
    const wchar_t* ca = L"ScaleGoesBrr.dll";
    const wchar_t* cb = L"https://github.com/Solexid/ScaleGoesBrrQuest/releases/download/r1/ScaleGoesBrrQuest.dll";
    int option;
    std::cout << "VRChat Mod installer for Oculus Quest\n\n Select action\n[1] Install LemonLoader [2]Post Patch Installation [3]MelonLoader Console Normal [4]MelonLoader Console Verbose [5] Mods for VRChat \n Select: ";
    std::cin >> option;
    switch (option)
    {
    case 1:
        std::cout << "Starting LemonLoader Install";
        std::cout << "\n Downloading LemonLoader.apk";
        if (S_OK == URLDownloadToFile(NULL, srcURL, destFile, 0, NULL))
        {
            printf("\n Downloaded!\n");
            system("adb.exe install LemonLoader.apk");
            Sleep(3500);
            return 0;
        }
        else
        {
            printf("Failed");
            return -1;
        }

        break;
    case 2:
        std::cout << "Starting Post Patch Install";
        std::cout << "\n Downloading OculusPatch.dll\n";
        if (S_OK == URLDownloadToFile(NULL, srcUL, destFil, 0, NULL))
        {
            printf("\n Downloaded!\n");
            system("adb.exe push OculusPatch.dll /sdcard/Android/data/com.vrchat.oculus.quest/files/Mods");
            Sleep(1000);
            if (S_OK == URLDownloadToFile(NULL, srcUR2, destFil2, 0, NULL))
            {
                printf("\n Downloaded!\n");
                system("adb.exe push HWIDPatch.dll /sdcard/Android/data/com.vrchat.oculus.quest/files/Mods");
                Sleep(3500);
                return 0;
            }
            else
            {
                printf("Failed");
                return -1;
            }

        }
        else
        {
            printf("Failed");
            return -1;
        }
        break;
    case 3:

        system("adb logcat -v time MelonLoader:D CRASH:D Mono:W mono:D mono-rt:D Zygote:D A64_HOOK:V DEBUG:D Binder:D AndroidRuntime:D *:S");
        break;
    case 4:
        system("adb logcat -v time MelonLoader:D CRASH:D Mono:D mono:D mono-rt:D Zygote:D A64_HOOK:V DEBUG:D funchook:D Unity:D Binder:D AndroidRuntime:D *:S");
        break;
    case 5:
        system("cls");
        int optio1;
        std::cout << "VRChat Mods\n[1] Install Playspacemover [2] Install NameplateStats [3] Install ScaleGoesBrr\n Select: ";
        std::cin >> optio1;
        switch (optio1)
        {
        case 1:
            std::cout << "\n Downloading Playspacemover.dll\n";
            if (S_OK == URLDownloadToFile(NULL, ab, aa, 0, NULL))
            {

                printf("\n Downloaded!\n");
                system("adb.exe push Playspacemover.dll /sdcard/Android/data/com.vrchat.oculus.quest/files/Mods");
                Sleep(1000);
                return 0;
            }
            else {
                std::cout << "\n failed!";
            }
        case 2:
            std::cout << "\n Downloading NameplateStats.dll\n";
            if (S_OK == URLDownloadToFile(NULL, bb, ba, 0, NULL))
            {

                printf("\n Downloaded!\n");
                system("adb.exe push NameplateStats.dll /sdcard/Android/data/com.vrchat.oculus.quest/files/Mods");
                Sleep(1000);
                return 0;
            }
            else {
                std::cout << "\n failed!";
            }
        case 3:
                        std::cout << "\n Downloading ScaleGoesBrr.dll\n";
            if (S_OK == URLDownloadToFile(NULL, cb, ca, 0, NULL))
            {
                
                printf("\n Downloaded!\n");
                system("adb.exe push ScaleGoesBrr.dll /sdcard/Android/data/com.vrchat.oculus.quest/files/Mods");
                Sleep(1000);
                return 0;
            }
            else {
                std::cout << "\n failed!";
            }

            }

        };





    }


