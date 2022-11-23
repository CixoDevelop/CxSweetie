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
 * This file is the system bootloader, it is responsible for the initialization
 * of the platform and then the operation of the system. You should override 
 * the functions susciBoot and susciPanic which are individual for the project.
 */

#ifndef KERNEL_LOADER_H_INCLUDED
#define KERNEL_LOADER_H_INCLUDED

/** \fn susci_boot
 * This function is called when the system is ready to create processes and
 * the platform is properly initialized. So write your own project 
 * initiation here.
 */
void susci_boot(void);

/** \fn susci_panic
 * This function is run just before the processor freezes at the time of the
 * system failure, or if any of the processes returns a fatal error.
 */
void susci_panic(void);

#endif
