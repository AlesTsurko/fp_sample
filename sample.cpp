#include "sample.h"
#include <cstring>

char l_name[] = "Sample";
char s_name[] = "Sample";
TFruityPlugInfo info = {CurrentSDKVersion, l_name, s_name, FPF_Type_Effect, 0};

extern "C" TFruityPlug *_stdcall CreatePlugInstance(TFruityPlugHost *host,
                                                    int tag) {
    return new Sample(host, tag);
}

Sample::Sample(TFruityPlugHost *host_ptr, int tag) {
    Info = &info;
    HostTag = tag;
    EditorHandle = 0;
    host = host_ptr;
}

Sample::~Sample() {}

void _stdcall Sample::SaveRestoreState(IStream *, BOOL) {}

intptr_t _stdcall Sample::Dispatcher(intptr_t id, intptr_t index,
                                     intptr_t value) {
    if (id == FPD_SetEnabled) {
        // works
        // host->Dispatcher(HostTag, FHD_MsgBox, (intptr_t) "Test|Hello",
                         // 0x00000001L);

        // will crash
        host->Dispatcher(HostTag, FHD_WantMIDIInput, 0, value);
    }

    return 0;
}

void _stdcall Sample::GetName(int, int, int, char *) {}

int _stdcall Sample::ProcessEvent(int, int, int) { return 0; }

int _stdcall Sample::ProcessParam(int, int, int) { return 0; }

void _stdcall Sample::Idle_Public() {}

void _stdcall Sample::Eff_Render(PWAV32FS source_buf, PWAV32FS dest_buf,
                                 int len) {
    float mul = 0.25;
    for (int n = 0; n < len; n++) {
        (*dest_buf)[n][0] = (*source_buf)[n][0] * mul;
        (*dest_buf)[n][1] = (*source_buf)[n][1] * mul;
    }
}

void _stdcall Sample::Gen_Render(PWAV32FS, int &) {}

TVoiceHandle _stdcall Sample::TriggerVoice(PVoiceParams, intptr_t) {
    return TVoiceHandle();
}

void _stdcall Sample::Voice_Release(TVoiceHandle) {}

void _stdcall Sample::Voice_Kill(TVoiceHandle) {}

int _stdcall Sample::Voice_ProcessEvent(TVoiceHandle, int, int, int) {
    return 0;
}

int _stdcall Sample::Voice_Render(TVoiceHandle, PWAV32FS, int &) { return 0; }

void _stdcall Sample::NewTick() {}

void _stdcall Sample::MIDITick() {}

void _stdcall Sample::MIDIIn(int &) {}

void _stdcall Sample::MsgIn(intptr_t) {}

int _stdcall Sample::OutputVoice_ProcessEvent(TOutVoiceHandle, int, int, int) {
    return 0;
}

void _stdcall Sample::OutputVoice_Kill(TVoiceHandle) {}
