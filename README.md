# RTOS-Based Task Scheduler on ARM Cortex-M

A lightweight cooperative RTOS scheduler implemented in Embedded C for ARM Cortex-M microcontrollers. The project demonstrates core RTOS concepts including task management, scheduling logic, task control blocks, interrupt-driven timing, and low-level context switching.

## Overview

This project implements a minimal RTOS scheduler from scratch using ARM Cortex-M architecture and CMSIS. It focuses on understanding the internal working of an RTOS kernel by implementing task creation, task state management, scheduling decisions, and CPU context switching.

The scheduler supports multiple execution strategies including round-robin scheduling and priority-based task selection for deterministic task execution.


## Features

- Cooperative multitasking scheduler 
- Priority-based task scheduling
- Task Control Block (TCB) based task management
- ARM Cortex-M context switching using assembly
- SysTick timer-driven scheduler tick generation
- PendSV exception-based context switching
- Configurable task priorities
- Lightweight kernel architecture

## Technical Details

| Parameter | Details |
|---|---|
| Platform | ARM Cortex-M (STM32) |
| Language | Embedded C |
| Framework | CMSIS |
| Scheduling |  Priority-Based Task Selection |
| Context Switching | ARM Assembly + PendSV Handler |
| Timer | SysTick Interrupt |
| Development Environment | STM32CubeIDE |

## Architecture Overview

The scheduler follows a layered architecture:

```text
Application Tasks
        |
        |
Task Management Layer
        |
        |
Scheduler Kernel
        |
        |
Context Switching Layer
        |
        |
ARM Cortex-M Hardware
```

## How It Works

1. Tasks are created and stored using Task Control Blocks (TCBs).
2. The scheduler maintains task states and selects the next runnable task.
3. SysTick generates periodic timer interrupts for scheduling decisions.
4. PendSV performs the context switch by saving the current task context and restoring the next task context.
5. Execution resumes from the selected task.


## Project Structure

```text
cortex-m-rtos-task-scheduler/
│
├── src/
│   ├── main.c
│   ├── scheduler.c
│   ├── tcb.c
│   └── context_switch.s
│
├── inc/
│   ├── scheduler.h
│   └── tcb.h
│
├── docs/
│   └── architecture.md
│
└── README.md
```


## Key Concepts Demonstrated

### Task Control Block (TCB)

Each task is represented using a TCB structure containing task-related information such as:

- Stack pointer
- Task state
- Task priority
- Task execution information


### Context Switching

The project implements low-level CPU context switching by saving and restoring processor registers during task transitions.

The context switching mechanism demonstrates understanding of:

- ARM Cortex-M exception handling
- Stack management
- Register preservation
- Low-level assembly programming

### Scheduling Algorithm

The scheduler selects the next runnable task based on task priority.

Higher priority tasks are selected before lower priority tasks, providing predictable task execution behavior.

### Timer-Based Scheduling

The SysTick timer provides periodic scheduler ticks used for task timing and scheduling decisions.


## Tools & Environment

- STM32CubeIDE
- CMSIS (Cortex Microcontroller Software Interface Standard)
- ARM GCC Toolchain
- STM32 Debugging Tools


## Skills Demonstrated

`Embedded C` | `ARM Cortex-M` | `RTOS Kernel Design` | `Task Scheduling` | `Context Switching` | `Interrupt Handling` | `Assembly Programming` | `CMSIS` | `STM32` | `Real-Time Systems` | `Operating System Internals`


## Future Improvements

- Preemptive scheduling support
- Inter-task communication mechanisms
- Mutex and semaphore support
- Dynamic memory management
