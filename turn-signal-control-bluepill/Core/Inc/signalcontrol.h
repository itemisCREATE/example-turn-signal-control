/** Generated by itemis CREATE code generator. */

#ifndef SIGNALCONTROL_H_
#define SIGNALCONTROL_H_

#ifdef __cplusplus
extern "C" { 
#endif

/*!
* Forward declaration for the Signalcontrol state machine.
*/
typedef struct Signalcontrol Signalcontrol;

/*!
* Forward declaration of the data structure for the SignalcontrolIface interface scope.
*/
typedef struct SignalcontrolIface SignalcontrolIface;

/*!
* Forward declaration of the data structure for the SignalcontrolInternal interface scope.
*/
typedef struct SignalcontrolInternal SignalcontrolInternal;

/*!
* Forward declaration of the data structure for the SignalcontrolShadow interface scope.
*/
typedef struct SignalcontrolShadow SignalcontrolShadow;

#ifdef __cplusplus
}
#endif

#include "sc_types.h"
#include "blink_required.h"
#include "flash_required.h"
#include <string.h>

#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file
Header of the state machine 'signalcontrol'.
*/

#ifndef SIGNALCONTROL_EVENTQUEUE_BUFFERSIZE
#define SIGNALCONTROL_EVENTQUEUE_BUFFERSIZE 20
#endif
#ifndef SIGNALCONTROL_IN_EVENTQUEUE_BUFFERSIZE
#define SIGNALCONTROL_IN_EVENTQUEUE_BUFFERSIZE SIGNALCONTROL_EVENTQUEUE_BUFFERSIZE
#endif
#ifndef SIGNALCONTROL_INTERNAL_EVENTQUEUE_BUFFERSIZE
#define SIGNALCONTROL_INTERNAL_EVENTQUEUE_BUFFERSIZE SIGNALCONTROL_EVENTQUEUE_BUFFERSIZE
#endif
#ifndef SC_INVALID_EVENT_VALUE
#define SC_INVALID_EVENT_VALUE 0
#endif
/*! Define number of states in the state enum */
#define SIGNALCONTROL_STATE_COUNT 9

/*! Define dimension of the state configuration vector for orthogonal states. */
#define SIGNALCONTROL_MAX_ORTHOGONAL_STATES 1
/*! Define dimension of the state configuration vector for history states. */
#define SIGNALCONTROL_MAX_HISTORY_STATES 3

/*! Define indices of states in the StateConfVector */
#define SCVI_SIGNALCONTROL_MAIN_IDLE 0
#define SCVI_SIGNALCONTROL_MAIN_BLINK 0
#define SCVI_SIGNALCONTROL_MAIN_BLINK_R_RIGHT 0
#define SCVI_SIGNALCONTROL_MAIN_BLINK_R_RIGHT_RIGHT_COMFORT 0
#define SCVI_SIGNALCONTROL_MAIN_BLINK_R_RIGHT_RIGHT_REGULAR 0
#define SCVI_SIGNALCONTROL_MAIN_BLINK_R_LEFT 0
#define SCVI_SIGNALCONTROL_MAIN_BLINK_R_LEFT_LEFT_COMFORT 0
#define SCVI_SIGNALCONTROL_MAIN_BLINK_R_LEFT_LEFT_REGULAR 0
#define SCVI_SIGNALCONTROL_MAIN_HAZARD_LIGHTS 0

/*
 * Union of all possible event value types.
 */
typedef union {
	sc_boolean Signalcontrol_right_value;
	sc_boolean Signalcontrol_left_value;
} signalcontrol_event_value;

/* 
 * Enum of event names in the statechart.
 */
typedef enum  {
	Signalcontrol_invalid_event = SC_INVALID_EVENT_VALUE,
	Signalcontrol_right,
	Signalcontrol_left,
	Signalcontrol_hazard,
	Signalcontrol_internal_stopBlinking,
	Signalcontrol_internal_blinkRight_cycleCompleted,
	Signalcontrol_internal_blinkLeft_cycleCompleted
} SignalcontrolEventID;

/*
 * Struct that represents a single event.
 */
typedef struct {
	SignalcontrolEventID name;
	sc_boolean has_value;
	signalcontrol_event_value value;
} signalcontrol_event;

/*
 * Queue that holds the raised events.
 */
typedef struct signalcontrol_eventqueue_s {
	signalcontrol_event *events;
	sc_integer capacity;
	sc_integer pop_index;
	sc_integer push_index;
	sc_integer size;
} signalcontrol_eventqueue;

/*! Enumeration of all states */ 
typedef enum
{
	Signalcontrol_last_state,
	Signalcontrol_main_Idle,
	Signalcontrol_main_Blink,
	Signalcontrol_main_Blink_r_Right,
	Signalcontrol_main_Blink_r_Right_right_Comfort,
	Signalcontrol_main_Blink_r_Right_right_Regular,
	Signalcontrol_main_Blink_r_Left,
	Signalcontrol_main_Blink_r_Left_left_Comfort,
	Signalcontrol_main_Blink_r_Left_left_Regular,
	Signalcontrol_main_Hazard_Lights
} SignalcontrolStates;






/*! Type declaration of the data structure for the SignalcontrolIface interface scope. */
struct SignalcontrolIface
{
	sc_boolean right_raised;
	sc_boolean right_value;
	sc_boolean left_raised;
	sc_boolean left_value;
	sc_boolean hazard_raised;
	Blink* blinkRight;
	Blink* blinkLeft;
	Flash* flash;
	sc_integer comfortBlinkingPeriods;
};



/*! Type declaration of the data structure for the SignalcontrolInternal interface scope. */
struct SignalcontrolInternal
{
	sc_boolean stopBlinking_raised;
	sc_boolean interrupted;
	sc_integer periodCount;
};



/*! Type declaration of the data structure for the SignalcontrolShadow interface scope. */
struct SignalcontrolShadow
{
	sc_boolean blinkRight_cycleCompleted_raised;
	sc_boolean blinkLeft_cycleCompleted_raised;
	sc_single_subscription_observer blinkRight_cycleCompleted;
	sc_single_subscription_observer blinkLeft_cycleCompleted;
};






/*! 
 * Type declaration of the data structure for the Signalcontrol state machine.
 * This data structure has to be allocated by the client code. 
 */
struct Signalcontrol
{
	SignalcontrolStates stateConfVector[SIGNALCONTROL_MAX_ORTHOGONAL_STATES];
	SignalcontrolStates historyVector[SIGNALCONTROL_MAX_HISTORY_STATES];
	SignalcontrolIface iface;
	SignalcontrolInternal internal;
	SignalcontrolShadow shadow;
	sc_boolean isExecuting;
	signalcontrol_eventqueue internal_event_queue;
	signalcontrol_event internal_buffer[SIGNALCONTROL_INTERNAL_EVENTQUEUE_BUFFERSIZE];
	signalcontrol_eventqueue in_event_queue;
	signalcontrol_event in_buffer[SIGNALCONTROL_IN_EVENTQUEUE_BUFFERSIZE];
};



/*! Initializes the Signalcontrol state machine data structures. Must be called before first usage.*/
extern void signalcontrol_init(Signalcontrol* handle);


/*! Activates the state machine. */
extern void signalcontrol_enter(Signalcontrol* handle);

/*! Deactivates the state machine. */
extern void signalcontrol_exit(Signalcontrol* handle);

/*! 
Can be used by the client code to trigger a run to completion step without raising an event.
*/
extern void signalcontrol_trigger_without_event(Signalcontrol* handle);



/*! Raises the in event 'right' that is defined in the default interface scope. */ 
extern void signalcontrol_raise_right(Signalcontrol* handle, sc_boolean value);
/*! Raises the in event 'left' that is defined in the default interface scope. */ 
extern void signalcontrol_raise_left(Signalcontrol* handle, sc_boolean value);
/*! Raises the in event 'hazard' that is defined in the default interface scope. */ 
extern void signalcontrol_raise_hazard(Signalcontrol* handle);
/*! Gets the value of the variable 'blinkRight' that is defined in the default interface scope. */ 
extern Blink* signalcontrol_get_blinkRight(const Signalcontrol* handle);
/*! Sets the value of the variable 'blinkRight' that is defined in the default interface scope. */ 
extern void signalcontrol_set_blinkRight(Signalcontrol* handle, Blink* value);
/*! Gets the value of the variable 'blinkLeft' that is defined in the default interface scope. */ 
extern Blink* signalcontrol_get_blinkLeft(const Signalcontrol* handle);
/*! Sets the value of the variable 'blinkLeft' that is defined in the default interface scope. */ 
extern void signalcontrol_set_blinkLeft(Signalcontrol* handle, Blink* value);
/*! Gets the value of the variable 'flash' that is defined in the default interface scope. */ 
extern Flash* signalcontrol_get_flash(const Signalcontrol* handle);
/*! Sets the value of the variable 'flash' that is defined in the default interface scope. */ 
extern void signalcontrol_set_flash(Signalcontrol* handle, Flash* value);
/*! Gets the value of the variable 'comfortBlinkingPeriods' that is defined in the default interface scope. */ 
extern sc_integer signalcontrol_get_comfortBlinkingPeriods(const Signalcontrol* handle);
/*! Sets the value of the variable 'comfortBlinkingPeriods' that is defined in the default interface scope. */ 
extern void signalcontrol_set_comfortBlinkingPeriods(Signalcontrol* handle, sc_integer value);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean signalcontrol_is_active(const Signalcontrol* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean signalcontrol_is_final(const Signalcontrol* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean signalcontrol_is_state_active(const Signalcontrol* handle, SignalcontrolStates state);


#ifdef __cplusplus
}
#endif 

#endif /* SIGNALCONTROL_H_ */
