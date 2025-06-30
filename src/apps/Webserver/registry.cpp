#include "registry.h"

namespace web
{
    WebRegistry webReg;
    
    // Create AsyncWebServer object on port 80
    AsyncWebServer server(80);

    // Create an Event Source on /events
    AsyncEventSource events("/events"); 
}