#ifndef _TASKS_H_
#define _TASKS_H_

typedef void (*SetupFunction)(void *);

typedef struct {
    SetupFunction setup;
    const char *name;
    uint16_t stackSize;
    void *parameters;
    uint8_t priority;
} Task;

#endif /* _TASKS_H_ */