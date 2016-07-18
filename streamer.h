// sending stimulations to the outside world

// NB: this file was written while I had the most awesome woman resting on my shoulder. Life bless her.

#ifndef _STREAMER_H_
#define _STREAMER_H_

class Streamer 
{
public:
    // message: string to send to OpenViBE, should be one of the code that it knows
    static void send(const char* message);
};


#endif
