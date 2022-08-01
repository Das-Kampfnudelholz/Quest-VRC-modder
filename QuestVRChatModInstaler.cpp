// QuestVRChatModInstaler.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <windows.h>

#include <cstdio>

#pragma comment(lib, "Urlmon.lib")

using namespace std;


int main()
{
    const wchar_t* destFile = L"LemonLoader.apk";
    const wchar_t* srcURL = L"https://cdn.discordapp.com/attachments/946558976781336586/1002402723712487514/app-release.apk";
    const wchar_t* destFil2 = L"HWIDPatch.dll";
    const wchar_t* srcUR2 = L"https://api.vrcmg.com/v1/mods/files/62/4/HWIDPatch.dll";
    const wchar_t* destFil = L"AntiCrash.dll";
    const wchar_t* srcUL = L"https://github.com/gompoc/MyEpicTestMod/releases/download/v1.0.0/MyEpicTestMod.dll";
    int option;
    std::cout << "VRChat Mod installer for Oculus Quest\n\n Select action\n[1] Install LemonLoader [2]Post Patch Installation [3]MelonLoader Console Normal [4]MelonLoader Console Verbose\nSelect:";
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
        std::cout << "\n Downloading AntiCrash.dll\n";
        if (S_OK == URLDownloadToFile(NULL, srcUL, destFil, 0, NULL))
        {
            printf("\n Downloaded!\n");
            system("adb.exe push AntiCrash.dll /sdcard/Android/data/com.vrchat.oculus.quest/files/Mods");
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
        system("adb logcat -v time MelonLoader:D CRASH:D Mono:D mono:D mono-rt:D Zygote:D A64_HOOK:V DEBUG:D funchook:D Unity:D Binder:D AndroidRuntime:D *:S");
        break;

    default:
        std::cout << "\n\n Status: Failure: Invalid Selection";
        Sleep(3000);
        exit(0);
    }
}