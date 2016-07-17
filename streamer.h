// sending stimulations to the outside world

// NB: this file was written while I had the most awesome woman resting on my shoulder. Life bless her.

#ifndef _STREAMER_H_
#define _STREAMER_H_

#include "lsl_cpp.h"

class Streamer 
{
public:
    Streamer();
    static void send();
    void push();
    static Streamer *singleton;
// in order to share the stream with each caller, we gonna use a singleton
private:
    // reference to output stream
    lsl::stream_outlet *outlet;
};


#endif
