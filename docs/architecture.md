# RTOS Architecture

## Overview

This document describes the architecture of the lightweight RTOS-based task scheduler implemented for ARM Cortex-M microcontrollers.

The scheduler is designed around fundamental RTOS components including task management, scheduling logic, timer-driven execution, and low-level context switching.

## System Architecture

```text
                Application Tasks
                       |
                       |
              Task Management Layer
                       |
                       |
              Task Control Blocks
                       |
                       |
              Scheduler Kernel
                       |
        -------------------------------
        |                             |
 Round-Robin Scheduler       Priority Scheduler
                       |
                       |
              Context Switching Layer
                       |
                       |
              ARM Cortex-M CPU
```

## Components

### 1. Application Tasks

User-defined tasks contain the application functionality that needs to execute concurrently.

Each task maintains its own execution context and is managed by the scheduler.


### 2. Task Control Block (TCB)

The Task Control Block stores information required by the scheduler to manage each task.

Typical task information includes:

- Task stack pointer
- Task priority
- Task state
- Task execution information

The scheduler uses TCB structures to track and switch between tasks.


### 3. Scheduler Kernel

The scheduler is responsible for:

- Maintaining task states
- Selecting the next runnable task
- Applying scheduling policies
- Managing task execution order

Supported scheduling approaches:

- Round-robin scheduling
- Priority-based scheduling


### 4. Timer Management

The SysTick timer provides periodic scheduler ticks.

Timer interrupts are used to:

- Trigger scheduler decisions
- Maintain timing information
- Support deterministic task execution


### 5. Context Switching

Context switching transfers CPU execution from one task to another.

The ARM Cortex-M context switching mechanism involves:

- Saving the current task CPU context
- Updating the stack pointer
- Restoring the next task context
- Resuming execution of the selected task

The implementation uses ARM assembly for low-level register handling.


## Execution Flow

1. System initialization configures scheduler components.
2. Tasks are created and stored using TCB structures.
3. The scheduler selects the next task based on scheduling policy.
4. SysTick generates periodic timing events.
5. Context switching transfers CPU execution between tasks.
