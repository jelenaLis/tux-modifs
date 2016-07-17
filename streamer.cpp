#include "streamer.h"
#include "lsl_cpp.h"

#include <iostream>
#include <cstdlib>

Streamer::Streamer() {
    std::cout << "Init streamer" << std::endl;

    // make a new stream_info
    lsl::stream_info info("MyEventStream","Markers",1,lsl::IRREGULAR_RATE,lsl::cf_string,"myuniquesourceid23443");

    // make a new outlet
    outlet = new lsl::stream_outlet(info);
}

// pushing a string to LSL
void Streamer::push() {
  std::string mrk = "test";
  // and choose the marker to send
  std::cout << "now sending: " << mrk << std::endl;
  outlet->push_sample(&mrk);
}

void Streamer::send()
{
    // the first time we init our one copy of the object
  if (singleton == NULL) {
      singleton = new Streamer();
    }
    
    // send random marker strings
    std::cout << "Now sending markers... " << std::endl;
    while(true) {
        // wait for a random period of time
        double endtime = ((double)clock())/CLOCKS_PER_SEC + (rand()%1000)/1000.0;
        while (((double)clock())/CLOCKS_PER_SEC < endtime);

        // now send it (note the &)
	singleton->push();
    }
}
