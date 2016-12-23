#ifndef KEYSOUNDS_H_
#define KEYSOUNDS_H_

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ApplicationServices/ApplicationServices.h>
#include <Carbon/Carbon.h>
// https://developer.apple.com/library/mac/documentation/Carbon/Reference/QuartzEventServicesRef/Reference/reference.html

CGEventRef CGEventCallback(CGEventTapProxy, CGEventType, CGEventRef, void*);
void handleKey(int);

#endif // KEYSOUNDS_H_
