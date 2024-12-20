/************************************************************************
 FAUST Architecture File
 Copyright (C) 2019-2020 GRAME, Centre National de Creation Musicale &
 Aalborg University (Copenhagen, Denmark)
 ---------------------------------------------------------------------
 This Architecture section is free software; you can redistribute it
 and/or modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 3 of
 the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; If not, see <http://www.gnu.org/licenses/>.
 
 EXCEPTION : As a special exception, you may create a larger work
 that contains this FAUST architecture section and distribute
 that work under terms of your choice, so long as this FAUST
 architecture section is not modified.
 
 ************************************************************************/

#ifndef faust_untitled_h_
#define faust_untitled_h_

#include <string>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/i2s_std.h"

class dsp;
class esp32audio;
class MapUI;
#ifdef MIDICTRL
class MidiUI;
class esp32_midi;
#endif
#ifdef SOUNDFILE
class SoundUI;
#endif

class untitled
{
    private:
    
        esp32audio* fAudio;
    	dsp* fDSP;
        MapUI* fUI;
    #ifdef MIDICTRL
        esp32_midi* fMIDIHandler;        
        MidiUI* fMIDIInterface;
    #endif
    #ifdef SOUNDFILE
        SoundUI* fSoundUI;
    #endif

    public:
    
        untitled(int sample_rate, int buffer_size);
        ~untitled();
    
        bool start();
        void stop();
    
        void setParamValue(const std::string&, float);
        float getParamValue(const std::string& path);
};

#endif
