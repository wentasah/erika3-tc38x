/* ###*B*###
 * Erika Enterprise, version 3
 * 
 * Copyright (C) 2017 - 2018 Evidence s.r.l.
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License, version 2, for more details.
 * 
 * You should have received a copy of the GNU General Public License,
 * version 2, along with this program; if not, see
 * < www.gnu.org/licenses/old-licenses/gpl-2.0.html >.
 * 
 * This program is distributed to you subject to the following
 * clarifications and special exceptions to the GNU General Public
 * License, version 2.
 * 
 * THIRD PARTIES' MATERIALS
 * 
 * Certain materials included in this library are provided by third
 * parties under licenses other than the GNU General Public License. You
 * may only use, copy, link to, modify and redistribute this library
 * following the terms of license indicated below for third parties'
 * materials.
 * 
 * In case you make modified versions of this library which still include
 * said third parties' materials, you are obligated to grant this special
 * exception.
 * 
 * The complete list of Third party materials allowed with ERIKA
 * Enterprise version 3, together with the terms and conditions of each
 * license, is present in the file THIRDPARTY.TXT in the root of the
 * project.
 * ###*E*### */


#include "shared.h"

#if (defined(__TASKING__))
#define OS_CORE1_START_SEC_CODE
#include "Os_MemMap.h"
#endif /* __TASKING__ */

#include <stdio.h>
#include "Blinky_LED.h"

void idle_hook_core1(void);
void idle_hook_core1(void)
{
  idle_hook_body();
}

TASK(TaskSlave1)
{
  while (1) {
    printf("TaskSlave1\n");
    blinkLED();
    WaitEvent(RemoteEvent);
    ActivateTask(TaskSlave2);
    ClearEvent(RemoteEvent);
  }
  TerminateTask();
}

#if (defined(__TASKING__))
#define OS_CORE1_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif /* __TASKING__ */
