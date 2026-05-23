# RTOS-Based Task Scheduler on ARM Cortex-M

A cooperative multitasking scheduler implemented in Embedded C on ARM Cortex-M, supporting round-robin and priority-based scheduling with full context switching.

## Overview

This project implements a lightweight Real-Time Operating System (RTOS) scheduler from scratch on ARM Cortex-M using CMSIS. It demonstrates core OS internals including task control blocks, context switching, and deterministic real-time task execution.

## Features

- Cooperative multitasking with round-robin and priority-based scheduling
- Task Control Block (TCB) implementation for task state management
- Context switching using ARM Cortex-M SysTick and PendSV interrupts
- Deterministic task execution with low scheduling latency
- Configurable task priorities and time slices

## Technical Details

| Parameter | Details |
|---|---|
| **Platform** | ARM Cortex-M (STM32) |
| **Language** | Embedded C |
| **Framework** | CMSIS |
| **Scheduling** | Round-Robin + Priority-Based |
| **Context Switch** | PendSV Handler |
| **Timer** | SysTick |

## Project Structure
rtos-task-scheduler-arm/
├── src/
│   ├── main.c          # Entry point and task definitions
│   ├── scheduler.c     # Core scheduling logic
│   ├── tcb.c           # Task Control Block management
│   └── context_switch.s # ARM assembly context switch
├── inc/
│   ├── scheduler.h
│   └── tcb.h
└── README.md

## Key Concepts Demonstrated

- **Task Control Blocks (TCB):** Each task maintains its own stack pointer, priority, state, and timing parameters
- **Context Switching:** Implemented via ARM PendSV exception for minimal interrupt latency
- **SysTick Timer:** Used for periodic scheduling ticks and task timeout tracking
- **Priority Scheduling:** Higher priority tasks preempt lower priority ones deterministically

## Tools & Environment

- STM32CubeIDE
- CMSIS (Cortex Microcontroller Software Interface Standard)
- ARM GCC Toolchain
- OpenOCD / JTAG for debugging

## Skills Demonstrated

`Embedded C` `ARM Cortex-M` `RTOS` `Context Switching` `Interrupt Handling` `Memory Management` `OS Internals` `STM32` `CMSIS` `Real-Time Systems`
