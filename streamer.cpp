#include "streamer.h"
#include "lsl_cpp.h"

#include <iostream>
#include <cstdlib>

// and in your cpp...
void Streamer::send()
{
    // make a new stream_info
    lsl::stream_info info("MyEventStream","Markers",1,lsl::IRREGULAR_RATE,lsl::cf_string,"myuniquesourceid23443");

    // make a new outlet
    lsl::stream_outlet outlet(info);

    // send random marker strings
    std::cout << "Now sending markers... " << std::endl;
    while(true) {
        // wait for a random period of time
        double endtime = ((double)clock())/CLOCKS_PER_SEC + (rand()%1000)/1000.0;
        while (((double)clock())/CLOCKS_PER_SEC < endtime);
        // and choose the marker to send
	std::string mrk = "test";
	std::cout << "now sending: " << mrk << std::endl;

        // now send it (note the &)
        outlet.push_sample(&mrk);
    }
}
