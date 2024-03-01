#ifndef EVENT_H
#define EVENT_H
#include "wire.h"
#include <cstdint> // For uint64_t
struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
        //write the operator() required to make this a functor that compares Events by time
    bool operator()(const Event* lhs, const Event* rhs) const {
        // Return true if lhs's time is greater than rhs's time,
        // making the heap a min-heap based on the time of events.
        return lhs->time > rhs->time;
    }
} EventLess;
	
#endif
