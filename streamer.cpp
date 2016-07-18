#include "streamer.h"
#include "lsl_cpp.h"

#include <iostream>
#include <cstdlib>


// kinda ugly way to use a kinda singleton. I will not brag about this code.
lsl::stream_info info("Tuxracer","Markers",1,lsl::IRREGULAR_RATE,lsl::cf_string,"myuniquetuxsourceid23443");

lsl::stream_outlet *outlet;

void Streamer::send(const char* message)
{

    if (outlet == NULL) {
        std::cout << "streamer: first call, init LSL outlet" << std::endl;
        outlet = new lsl::stream_outlet(info);
    }

    
    std::cout << "streamer: sending: " << message << std::endl;
    outlet->push_sample(message);
}