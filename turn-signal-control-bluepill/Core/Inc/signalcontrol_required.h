/** Generated by itemis CREATE code generator. */

#ifndef SIGNALCONTROL_REQUIRED_H_
#define SIGNALCONTROL_REQUIRED_H_

#include "sc_types.h"
#include "signalcontrol.h"

#ifdef __cplusplus
extern "C"
{
#endif 

/*! \file
This header defines prototypes for all functions that are required by the state machine implementation.

This is a state machine uses time events which require access to a timing service. Thus the function prototypes:
- signalcontrol_set_timer and
- signalcontrol_unset_timer
are defined.
These functions will be called during a 'run to completion step' (runCycle) of the statechart. 
There are some constraints that have to be considered for the implementation of these functions:
- never call the statechart API functions from within these functions.
- make sure that the execution time is as short as possible.

*/






/*! 
This function has to set up timers for the time events that are required by the state machine.
It will be called for each time event that is relevant for a state when a state will be entered.
\param evid An unique identifier of the event.
\time_ms The time in milliseconds
\periodic Indicates the the time event must be raised periodically until the timer is unset 
*/
extern void signalcontrol_set_timer(Signalcontrol* handle, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic);

/*! 
This function has to unset timers for the time events that are required by the state machine.
It will be called for each time event that is relevant for a state when a state will be left.
\param evid An unique identifier of the event.
*/
extern void signalcontrol_unset_timer(Signalcontrol* handle, const sc_eventid evid);



#ifdef __cplusplus
}
#endif 

#endif /* SIGNALCONTROL_REQUIRED_H_ */