#ifndef TCB_H
#define TCB_H

#include <stdint.h>

/* Stack size for each task */
#define STACK_SIZE  256

/* Task priority levels */
typedef enum {
    PRIORITY_LOW    = 0,
    PRIORITY_MEDIUM = 1,
    PRIORITY_HIGH   = 2
} TaskPriority;

/* Task state definitions */
typedef enum {
    TASK_INACTIVE = 0,
    TASK_READY    = 1,
    TASK_RUNNING  = 2,
    TASK_BLOCKED  = 3
} TaskState;

/* Task Control Block structure */
typedef struct {
    uint32_t     *stack_pointer;
    uint32_t      stack[STACK_SIZE];
    void        (*task_func)(void);
    TaskPriority  priority;
    TaskState     state;
} TCB;

/* TCB API */
void      tcb_init(TCB *tcb);
void      tcb_set_priority(TCB *tcb, TaskPriority priority);
TaskState tcb_get_state(TCB *tcb);
void      tcb_set_state(TCB *tcb, TaskState state);

#endif /* TCB_H */
