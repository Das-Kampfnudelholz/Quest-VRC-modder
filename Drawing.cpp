#include "Drawing.h"
#include <Windows.h>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#pragma comment(lib, "Urlmon.lib")
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

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


LPCSTR Drawing::lpWindowName = "LemonManager";
ImVec2 Drawing::vWindowSize = { 419, 248 };
ImGuiWindowFlags Drawing::WindowFlags = ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize;
bool Drawing::bDraw = true;



void Drawing::Active()
{
	bDraw = true;
}

bool Drawing::isActive()
{
	return bDraw == true;
}

void Drawing::Draw()
{
	if (isActive())
	{
		ImGui::SetNextWindowSize(vWindowSize);
		ImGui::SetNextWindowBgAlpha(1.0f);
		ImGui::Begin(lpWindowName, &bDraw, WindowFlags);
		{
			ImGui::SetCursorPos(ImVec2(79.5, 45.5));
			ImGui::StyleColorsDark();
			ImGui::Text("VRChat Mod installer for Oculus Quest");

			ImGui::SetCursorPos(ImVec2(202, 133.5));
			if (ImGui::Button("MelonLoader Console Verbose", ImVec2(197, 19)))
				system("adb logcat - v time MelonLoader : D CRASH : D Mono : D mono : D mono - rt : D Zygote : D A64_HOOK : V DEBUG : D funchook : D Unity : D Binder : D AndroidRuntime : D * : S");
			ImGui::SetCursorPos(ImVec2(199, 94.5));
			if (ImGui::Button("MelonLoader Console Normal", ImVec2(190, 19)))
				system("adb logcat -v time MelonLoader:D CRASH:D Mono:W mono:D mono-rt:D Zygote:D A64_HOOK:V DEBUG:D Binder:D AndroidRuntime:D *:S");
			ImGui::SetCursorPos(ImVec2(16, 133.5));
			if (ImGui::Button("Post Patch Installation", ImVec2(169, 19)))
				if (S_OK == URLDownloadToFile(NULL, srcUL, destFil, 0, NULL), URLDownloadToFile(NULL, srcUR2, destFil2, 0, NULL))
				{
					system("adb push OculusPatch.dll /sdcard/Android/data/com.vrchat.oculus.quest/files/Mods & adb push HWIDPatch.dll /sdcard/Android/data/com.vrchat.oculus.quest/files/Mods & pause");
				}
				else
				{
					printf("Failed");
					Sleep(1000);
					exit;

				}

		}





		ImGui::SetCursorPos(ImVec2(34, 94.5));
		if (ImGui::Button("Install LemonLoader", ImVec2(141, 19)))
			if (S_OK == URLDownloadToFile(NULL, srcURL, destFile, 0, NULL))
			{
				system("adb.exe install LemonLoader.apk & pause");
			};

		ImGui::SetCursorPos(ImVec2(19, 169));
		static bool c16 = true;
		ImGui::Checkbox("PlaySpaceMover", &c16);
		
		ImGui::SetCursorPos(ImVec2(19, 192.5));
		static bool b17 = true;
		ImGui::Checkbox("NameplateStats", &b17);

		ImGui::SetCursorPos(ImVec2(19, 215));
		static bool a18 = true;
		ImGui::Checkbox("ScaleGoesBrr", &a18);

		ImGui::SetCursorPos(ImVec2(50, 172));
		ImGui::Text("");

		ImGui::SetCursorPos(ImVec2(180, 220));
		static char str2[512] = "";
		ImGui::PushItemWidth(200);
		ImGui::InputText("##", str2, IM_ARRAYSIZE(str2));


		ImGui::SetCursorPos(ImVec2(232.5, 189.5));
		if (ImGui::Button("Install Mods", ImVec2(92, 19)))
		{
			std::ifstream file(str2);
		const	char* cmd1 = "adb push";
		const	char* cmd2 = " /sdcard/Android/data/com.vrchat.oculus.quest/files/Mods & pause";
			char buffer[512];
			strncpy(buffer, cmd1, sizeof(buffer));
			strncpy(buffer, str2, sizeof(buffer));
			strncat(buffer, cmd2, sizeof(buffer));

				

			if (file.is_open()) {
				system(buffer);
			}
			if (c16 == true)
				if (b17 == true)
					if (a18 == true)

					{
						URLDownloadToFile(NULL, ab, aa, 0, NULL);
						URLDownloadToFile(NULL, bb, ba, 0, NULL);
						URLDownloadToFile(NULL, cb, ca, 0, NULL);
						system("adb.exe push Playspacemover.dll /sdcard/Android/data/com.vrchat.oculus.quest/files/Mods & adb.exe push NameplateStats.dll /sdcard/Android/data/com.vrchat.oculus.quest/files/Mods & adb.exe push ScaleGoesBrr.dll /sdcard/Android/data/com.vrchat.oculus.quest/files/Mods & pause");
					}
					else
					{
						URLDownloadToFile(NULL, ab, aa, 0, NULL);
						URLDownloadToFile(NULL, bb, ba, 0, NULL);
						system("adb.exe push Playspacemover.dll /sdcard/Android/data/com.vrchat.oculus.quest/files/Mods & adb.exe push NameplateStats.dll /sdcard/Android/data/com.vrchat.oculus.quest/files/Mods & pause");
					}
				else
				{
					if (a18 == true)
					{
						URLDownloadToFile(NULL, ab, aa, 0, NULL);
						URLDownloadToFile(NULL, cb, ca, 0, NULL);
						system("adb.exe push Playspacemover.dll /sdcard/Android/data/com.vrchat.oculus.quest/files/Mods & adb.exe push ScaleGoesBrr.dll /sdcard/Android/data/com.vrchat.oculus.quest/files/Mods & pause");
					}
					else
					{
						URLDownloadToFile(NULL, ab, aa, 0, NULL);
						system("adb.exe push Playspacemover.dll /sdcard/Android/data/com.vrchat.oculus.quest/files/Mods & pause");
					}

				}
			else
			{
				if (b17 == true)
				{
					if (a18 == true)
					{
						URLDownloadToFile(NULL, bb, ba, 0, NULL);
						URLDownloadToFile(NULL, cb, ca, 0, NULL);
						system("adb.exe push NameplateStats.dll /sdcard/Android/data/com.vrchat.oculus.quest/files/Mods & adb.exe push ScaleGoesBrr.dll /sdcard/Android/data/com.vrchat.oculus.quest/files/Mods & pause");
					}
					else
					{
						URLDownloadToFile(NULL, bb, ba, 0, NULL);
						system("adb.exe push NameplateStats.dll /sdcard/Android/data/com.vrchat.oculus.quest/files/Mods & pause");
					}

				}
				else
				{
					URLDownloadToFile(NULL, cb, ca, 0, NULL);
					system("adb.exe push ScaleGoesBrr.dll /sdcard/Android/data/com.vrchat.oculus.quest/files/Mods & pause");

				}
			}




		}
		ImGui::End();
	};
}


	   
	#ifdef _WINDLL
	if (GetAsyncKeyState(VK_INSERT) & 1)
		bDraw = !bDraw;
	#endif
