#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdint.h>
#include "tcb.h"

/* Maximum number of tasks supported */
#define MAX_TASKS           8
#define STACK_SIZE_DEFAULT  256

/* Scheduler API */
void    scheduler_init(void);
void    task_create(void (*task_func)(void),
                    TaskPriority priority,
                    uint32_t stack_size);
void    scheduler_start(void);
uint8_t scheduler_next_task(void);
void    task_yield(void);

#endif /* SCHEDULER_H */
