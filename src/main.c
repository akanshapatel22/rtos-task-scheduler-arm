#include "scheduler.h"
#include "tcb.h"

/* Task 1: LED Blink simulation */
void task1(void) {
    while (1) {
        /* Simulate LED ON */
        volatile uint32_t i;
        for (i = 0; i < 100000; i++);
        /* Simulate LED OFF */
        for (i = 0; i < 100000; i++);
        task_yield();
    }
}

/* Task 2: UART transmission simulation */
void task2(void) {
    while (1) {
        /* Simulate UART data send */
        volatile uint32_t i;
        for (i = 0; i < 50000; i++);
        task_yield();
    }
}

/* Task 3: Sensor polling simulation */
void task3(void) {
    while (1) {
        /* Simulate sensor read */
        volatile uint32_t i;
        for (i = 0; i < 75000; i++);
        task_yield();
    }
}

int main(void) {
    /* Initialize scheduler */
    scheduler_init();

    /* Register tasks with priorities */
    task_create(task1, PRIORITY_LOW,    STACK_SIZE_DEFAULT);
    task_create(task2, PRIORITY_MEDIUM, STACK_SIZE_DEFAULT);
    task_create(task3, PRIORITY_HIGH,   STACK_SIZE_DEFAULT);

    /* Start scheduler - never returns */
    scheduler_start();

    while (1);
    return 0;
}
