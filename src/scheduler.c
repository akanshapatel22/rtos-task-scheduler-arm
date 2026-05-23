#include "scheduler.h"
#include "tcb.h"
#include <stddef.h>

static TCB tcb_pool[MAX_TASKS];
static uint8_t task_count = 0;
static uint8_t current_task = 0;

void scheduler_init(void) {
    uint8_t i;
    for (i = 0; i < MAX_TASKS; i++) {
        tcb_pool[i].state = TASK_INACTIVE;
        tcb_pool[i].priority = PRIORITY_LOW;
        tcb_pool[i].stack_pointer = NULL;
    }
    task_count = 0;
    current_task = 0;
}

void task_create(void (*task_func)(void),
                 TaskPriority priority,
                 uint32_t stack_size) {
    if (task_count >= MAX_TASKS) return;

    TCB *tcb = &tcb_pool[task_count];
    tcb->task_func    = task_func;
    tcb->priority     = priority;
    tcb->state        = TASK_READY;
    tcb->stack_pointer = (uint32_t *)(&tcb->stack[stack_size - 1]);
    task_count++;
}

void task_yield(void) {
    /* Trigger PendSV for context switch */
    *((volatile uint32_t *)0xE000ED04) |= (1 << 28);
}

void scheduler_start(void) {
    if (task_count == 0) return;
    current_task = 0;
    tcb_pool[current_task].state = TASK_RUNNING;
    tcb_pool[current_task].task_func();
}

uint8_t scheduler_next_task(void) {
    uint8_t i;
    uint8_t highest_priority_task = current_task;
    TaskPriority highest_priority = PRIORITY_LOW;

    for (i = 0; i < task_count; i++) {
        if (tcb_pool[i].state == TASK_READY &&
            tcb_pool[i].priority >= highest_priority) {
            highest_priority = tcb_pool[i].priority;
            highest_priority_task = i;
        }
    }

    tcb_pool[current_task].state = TASK_READY;
    current_task = highest_priority_task;
    tcb_pool[current_task].state = TASK_RUNNING;

    return current_task;
}
