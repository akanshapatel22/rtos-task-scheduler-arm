.syntax unified
.cpu cortex-m4
.thumb

.global PendSV_Handler
.global task_yield

/*
 * PendSV_Handler - Lowest priority exception for context switching
 * Triggered by task_yield() to perform cooperative context switch
 */
.type PendSV_Handler, %function
PendSV_Handler:
    /* Disable interrupts during context switch */
    CPSID   I

    /* Save current task context */
    MRS     R0, PSP
    STMDB   R0!, {R4-R11}

    /* Load address of current stack pointer storage */
    LDR     R1, =current_sp
    LDR     R2, [R1]
    STR     R0, [R2]

    /* Call scheduler to get next task */
    PUSH    {R1, LR}
    BL      scheduler_next_task
    POP     {R1, LR}

    /* Restore next task context */
    LDR     R2, [R1]
    LDR     R0, [R2]
    LDMIA   R0!, {R4-R11}
    MSR     PSP, R0

    /* Enable interrupts */
    CPSIE   I

    /* Return to thread mode */
    BX      LR

.size PendSV_Handler, .-PendSV_Handler

/*
 * task_yield - Trigger PendSV for cooperative context switch
 */
.type task_yield, %function
task_yield:
    LDR     R0, =0xE000ED04
    LDR     R1, =0x10000000
    STR     R1, [R0]
    BX      LR
.size task_yield, .-task_yield
