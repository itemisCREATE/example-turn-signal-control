/** Generated by itemis CREATE code generator. */

#ifndef BLINK_H_
#define BLINK_H_

#ifdef __cplusplus
extern "C" { 
#endif

/*!
* Forward declaration for the Blink state machine.
*/
typedef struct Blink Blink;

/*!
* Forward declaration of the data structure for the BlinkIface interface scope.
*/
typedef struct BlinkIface BlinkIface;

/*!
* Forward declaration of the data structure for the BlinkTimeEvents interface scope.
*/
typedef struct BlinkTimeEvents BlinkTimeEvents;

#ifdef __cplusplus
}
#endif

#include "sc_types.h"
#include "sc_rxc.h"
#include <string.h>

#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file
Header of the state machine 'blink'.
*/

#ifndef BLINK_EVENTQUEUE_BUFFERSIZE
#define BLINK_EVENTQUEUE_BUFFERSIZE 20
#endif
#ifndef BLINK_IN_EVENTQUEUE_BUFFERSIZE
#define BLINK_IN_EVENTQUEUE_BUFFERSIZE BLINK_EVENTQUEUE_BUFFERSIZE
#endif
#ifndef SC_INVALID_EVENT_VALUE
#define SC_INVALID_EVENT_VALUE 0
#endif
/*! Define number of states in the state enum */
#define BLINK_STATE_COUNT 7

/*! Define dimension of the state configuration vector for orthogonal states. */
#define BLINK_MAX_ORTHOGONAL_STATES 1
/*! Define maximum number of time events that can be active at once */
#define BLINK_MAX_PARALLEL_TIME_EVENTS 1

/*! Define indices of states in the StateConfVector */
#define SCVI_BLINK_MAIN_LIGHT 0
#define SCVI_BLINK_MAIN_LIGHT__REGION0_ON1 0
#define SCVI_BLINK_MAIN_LIGHT__REGION0_ON2 0
#define SCVI_BLINK_MAIN_LIGHT__REGION0_ON3 0
#define SCVI_BLINK_MAIN_LIGHT__REGION0_ON4 0
#define SCVI_BLINK_MAIN_LIGHT__REGION0_ON5 0
#define SCVI_BLINK_MAIN_DARK 0


/* 
 * Enum of event names in the statechart.
 */
typedef enum  {
	Blink_invalid_event = SC_INVALID_EVENT_VALUE,
	Blink_blink_main_Light__region0_On1_time_event_0,
	Blink_blink_main_Light__region0_On2_time_event_0,
	Blink_blink_main_Light__region0_On3_time_event_0,
	Blink_blink_main_Light__region0_On4_time_event_0,
	Blink_blink_main_Light__region0_On5_time_event_0,
	Blink_blink_main_Dark_time_event_0
} BlinkEventID;

/*
 * Struct that represents a single event.
 */
typedef struct {
	BlinkEventID name;
} blink_event;

/*
 * Queue that holds the raised events.
 */
typedef struct blink_eventqueue_s {
	blink_event *events;
	sc_integer capacity;
	sc_integer pop_index;
	sc_integer push_index;
	sc_integer size;
} blink_eventqueue;

/*! Enumeration of all states */ 
typedef enum
{
	Blink_last_state,
	Blink_main_Light,
	Blink_main_Light__region0_On1,
	Blink_main_Light__region0_On2,
	Blink_main_Light__region0_On3,
	Blink_main_Light__region0_On4,
	Blink_main_Light__region0_On5,
	Blink_main_Dark
} BlinkStates;


/*! Type declaration of the data structure for the BlinkIface interface scope. */
struct BlinkIface
{
	sc_observable cycleCompleted;
	sc_integer t_light;
	sc_integer t_dark;
};





/*! Type declaration of the data structure for the BlinkTimeEvents interface scope. */
struct BlinkTimeEvents
{
	sc_boolean blink_main_Light__region0_On1_tev0_raised;
	sc_boolean blink_main_Light__region0_On2_tev0_raised;
	sc_boolean blink_main_Light__region0_On3_tev0_raised;
	sc_boolean blink_main_Light__region0_On4_tev0_raised;
	sc_boolean blink_main_Light__region0_On5_tev0_raised;
	sc_boolean blink_main_Dark_tev0_raised;
};






/*! 
 * Type declaration of the data structure for the Blink state machine.
 * This data structure has to be allocated by the client code. 
 */
struct Blink
{
	BlinkStates stateConfVector[BLINK_MAX_ORTHOGONAL_STATES];
	BlinkIface iface;
	BlinkTimeEvents timeEvents;
	sc_boolean isExecuting;
	blink_eventqueue in_event_queue;
	blink_event in_buffer[BLINK_IN_EVENTQUEUE_BUFFERSIZE];
};



/*! Initializes the Blink state machine data structures. Must be called before first usage.*/
extern void blink_init(Blink* handle);


/*! Activates the state machine. */
extern void blink_enter(Blink* handle);

/*! Deactivates the state machine. */
extern void blink_exit(Blink* handle);

/*! 
Can be used by the client code to trigger a run to completion step without raising an event.
*/
extern void blink_trigger_without_event(Blink* handle);


/*! Raises a time event. */
extern void blink_raise_time_event(Blink* handle, sc_eventid evid);

/*! Returns the observable for the out event 'cycleCompleted' that is defined in the default interface scope. */ 
extern sc_observable* blink_get_cycleCompleted(Blink* handle);

/*! Gets the value of the variable 't_light' that is defined in the default interface scope. */ 
extern sc_integer blink_get_t_light(const Blink* handle);
/*! Sets the value of the variable 't_light' that is defined in the default interface scope. */ 
extern void blink_set_t_light(Blink* handle, sc_integer value);
/*! Gets the value of the variable 't_dark' that is defined in the default interface scope. */ 
extern sc_integer blink_get_t_dark(const Blink* handle);
/*! Sets the value of the variable 't_dark' that is defined in the default interface scope. */ 
extern void blink_set_t_dark(Blink* handle, sc_integer value);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean blink_is_active(const Blink* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean blink_is_final(const Blink* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean blink_is_state_active(const Blink* handle, BlinkStates state);


#ifdef __cplusplus
}
#endif 

#endif /* BLINK_H_ */
