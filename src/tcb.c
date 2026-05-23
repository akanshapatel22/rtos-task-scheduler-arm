#include "tcb.h"
#include <string.h>

void tcb_init(TCB *tcb) {
    if (tcb == NULL) return;

    memset(tcb->stack, 0, sizeof(tcb->stack));
    tcb->stack_pointer = NULL;
    tcb->task_func     = NULL;
    tcb->priority      = PRIORITY_LOW;
    tcb->state         = TASK_INACTIVE;
}

void tcb_set_priority(TCB *tcb, TaskPriority priority) {
    if (tcb == NULL) return;
    tcb->priority = priority;
}

TaskState tcb_get_state(TCB *tcb) {
    if (tcb == NULL) return TASK_INACTIVE;
    return tcb->state;
}

void tcb_set_state(TCB *tcb, TaskState state) {
    if (tcb == NULL) return;
    tcb->state = state;
}
