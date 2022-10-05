
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