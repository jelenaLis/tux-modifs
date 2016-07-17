#include "streamer.h"
#include "lsl_cpp.h"

#include <iostream>
#include <cstdlib>


// kinda ugly way to use a kinda singleton. I will not brag about this code.
lsl::stream_info info("MyEventStream","Markers",1,lsl::IRREGULAR_RATE,lsl::cf_string,"myuniquesourceid23443");

lsl::stream_outlet *outlet;

void Streamer::send()
{

  if (outlet == NULL) {
      outlet = new lsl::stream_outlet(info);
  }

    // send random marker strings
    std::cout << "Now sending markers... " << std::endl;
    while(true) {
        // wait for a random period of time
        double endtime = ((double)clock())/CLOCKS_PER_SEC + (rand()%1000)/1000.0;
        while (((double)clock())/CLOCKS_PER_SEC < endtime);

  std::string mrk = "test";
  // and choose the marker to send
  std::cout << "now sending: " << mrk << std::endl;
  outlet->push_sample(&mrk);
    }
}
