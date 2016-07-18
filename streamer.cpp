#include "streamer.h"
#include "lsl_cpp.h"

#include <iostream>
#include <cstdlib>


// kinda ugly way to use a kinda singleton. I will not brag about this code.
lsl::stream_info info("Tuxracer","Markers",1,lsl::IRREGULAR_RATE,lsl::cf_string,"myuniquetuxsourceid23443");
// TODO: could init right here in fact...
lsl::stream_outlet *outlet;

void Streamer::init() {
    if (outlet == NULL) {
        outlet = new lsl::stream_outlet(info);
        std::cout << "streamer: LSL outlet created" << std::endl;
    }
    else {
        std::cout << "streamer: LSL outlet already created" << std::endl;
    }
}

void Streamer::send(const char* message) {

    if (outlet == NULL) {
        std::cout << "streamer: first call, init LSL outlet" << std::endl;
        init();
    }

    
    // complicated gymnastic so as to send the whole message for sure (??) 
    std::string mrk = message;
    std::cout << "streamer: sending: " << mrk << std::endl;
    outlet->push_sample(&mrk);
}
