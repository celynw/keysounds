#ifndef KEYSOUNDS_H_
#define KEYSOUNDS_H_

#include <Carbon/Carbon.h>

// Callback invoked on every keypress
CGEventRef CGEventCallback(CGEventTapProxy, CGEventType, CGEventRef, void*);
// Plays sounds based on which keys are pressed
void handleKey(int);

#endif // KEYSOUNDS_H_
