#ifndef _TASKS_H_
#define _TASKS_H_

#include <template.h>

typedef void (*SetupFunction)(void *);

typedef struct {
    SetupFunction setup;
    const char *name;
    uint16_t stackSize;
    uint8_t priority;
} Task;

Task tasks[] = {  
    {templateSetup, "template", 4096, 2},
};

#endif /* _TASKS_H_ */