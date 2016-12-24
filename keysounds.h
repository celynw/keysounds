#ifndef KEYSOUNDS_H_
#define KEYSOUNDS_H_

// #include <stdio.h>
#include <Carbon/Carbon.h>

CGEventRef CGEventCallback(CGEventTapProxy, CGEventType, CGEventRef, void*);
void handleKey(int);

#endif // KEYSOUNDS_H_
