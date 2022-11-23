/*
 * This file is part of the Susci project, an ultra lightweight general purpose
 * operating system aimed at devices without an MMU module and with very little
 * RAM memory.
 * 
 * It is released under the terms of the MIT license, you can use Susca in your
 * projects, you just need to mention it in the documentation, manual or other 
 * such place.
 * 
 * Author: Cixo
 *
 *
 * This file stores all the interfaces needed by processes to communicate with
 * the system and with each other.
 */

#include "types.h"
#include "process.h"
#include "scheduler.h"

#ifndef KERNEL_INTERFACE_H_INCLUDED
#define KERNEL_INTERFACE_H_INCLUDED

/** \fn wait_for_signal
 * It causes the transition of the currently executed process to the state
 * of waiting for a signal from a parameter.
 * @id The signal that the process will be waiting for
 */
void wait_for_signal(signal_t id);

/** \fn to_wait_for_signal
 * It sets a process with a given PID waiting for a given signal.
 * @process PID of process to set
 * @signal_id The signal that the process will be waiting for
 */
exec_state_t to_wait_for_signal(pid_t process, signal_t signal_id);

/** \fn make_signal
 * Creates a signal on the system.
 * @signal_id Signal to be called
 */
static inline void make_signal(signal_t signal_id) {
    current_signal= signal_id;
}

/** \fn sleep
 * It puts the currently running process to sleep.
 */
static inline void sleep(void) {
    current_process->state = WAITING_STATE;
}

/** \fn to_sleep
 * It puts the process to sleep with the PID specified in the parameter.
 * @process PID of process to set
 */
exec_state_t to_sleep(pid_t process);

/** \fn wake_up
 * Resumes the process with the set PID from sleep.
 * @process PID of process to set
 */
exec_state_t wake_up(pid_t process);

#endif
