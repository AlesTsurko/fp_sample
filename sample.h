#pragma once

#include "fp_plugclass.h"

class Sample : public TFruityPlug {
  public:
    Sample(TFruityPlugHost *host, int tag);
    virtual ~Sample();

    virtual intptr_t _stdcall Dispatcher(intptr_t id, intptr_t index,
                                         intptr_t value);
    virtual void _stdcall Idle_Public();
    virtual void _stdcall SaveRestoreState(IStream *stream, BOOL save);
    virtual void _stdcall GetName(int section, int index, int value,
                                  char *name);
    virtual int _stdcall ProcessEvent(int event_id, int event_value, int flags);
    virtual int _stdcall ProcessParam(int index, int value, int rec_flags);
    virtual void _stdcall Eff_Render(PWAV32FS source_buffer,
                                     PWAV32FS dest_buffer, int length);
    virtual void _stdcall Gen_Render(PWAV32FS dest_buffer, int &length);
    virtual TVoiceHandle _stdcall TriggerVoice(PVoiceParams voice_params,
                                               intptr_t set_tag);
    virtual void _stdcall Voice_Release(TVoiceHandle handle);
    virtual void _stdcall Voice_Kill(TVoiceHandle handle);
    virtual int _stdcall Voice_ProcessEvent(TVoiceHandle handle, int event_id,
                                            int event_value, int flags);
    virtual int _stdcall Voice_Render(TVoiceHandle handle, PWAV32FS dest_buffer,
                                      int &length);
    virtual void _stdcall NewTick();
    virtual void _stdcall MIDITick();
    virtual void _stdcall MIDIIn(int &msg);
    virtual void _stdcall MsgIn(intptr_t msg);
    virtual int _stdcall OutputVoice_ProcessEvent(TOutVoiceHandle handle,
                                                  int event_id, int event_value,
                                                  int flags);
    virtual void _stdcall OutputVoice_Kill(TVoiceHandle handle);

  protected:
    TFruityPlugHost *host;
};
