#include "keysounds.h"
#include <Carbon/Carbon.h>

int main(int argc, const char *argv[]) {
		// Create an event tap to retrieve keypresses.
		CGEventMask eventMask = (CGEventMaskBit(kCGEventKeyDown) |
		                         CGEventMaskBit(kCGEventFlagsChanged) |
		                         CGEventMaskBit(kCGEventLeftMouseDown) |
		                         CGEventMaskBit(kCGEventLeftMouseUp) |
		                         CGEventMaskBit(kCGEventRightMouseDown) |
		                         CGEventMaskBit(kCGEventRightMouseUp));
		CFMachPortRef eventTap = CGEventTapCreate(
			kCGSessionEventTap, kCGHeadInsertEventTap, 0, eventMask, CGEventCallback, NULL
		);

		// Exit the program if unable to create the event tap.
		if(!eventTap) {
			fprintf(stderr, "ERROR: Unable to create event tap.\n");
			exit(1);
		}

		// Create a run loop source and add enable the event tap.
		CFRunLoopSourceRef runLoopSource = CFMachPortCreateRunLoopSource(kCFAllocatorDefault, eventTap, 0);
		CFRunLoopAddSource(CFRunLoopGetCurrent(), runLoopSource, kCFRunLoopCommonModes);
		CGEventTapEnable(eventTap, true);

		CFRunLoopRun();

		return 0;
}

// The following callback method is invoked on every keypress.
CGEventRef CGEventCallback(CGEventTapProxy proxy, CGEventType type, CGEventRef event, void *refcon) {
	if (type == kCGEventKeyDown ||
	    type == kCGEventFlagsChanged) {
		CGKeyCode keyCode = (CGKeyCode) CGEventGetIntegerValueField(event, kCGKeyboardEventKeycode);
		handleKey(keyCode);
		return event;
	}
	else if (type == kCGEventLeftMouseDown ||
	         type == kCGEventRightMouseDown) {
		system("afplay ~/Library/Application\\ Support/KeySounds/mousedown.aif &");
		return event;
	}
	else if (type == kCGEventLeftMouseUp ||
	         type == kCGEventRightMouseUp) {
		system("afplay ~/Library/Application\\ Support/KeySounds/mouseup.aif &");
		return event;
	}
	else
	    return event;
}

// The following method converts the key code returned by each keypress as
void handleKey(int keyCode) {
	printf("%02x\n", keyCode);
	if (keyCode == kVK_ANSI_A ||
	    keyCode == kVK_ANSI_B ||
	    keyCode == kVK_ANSI_C ||
	    keyCode == kVK_ANSI_D ||
	    keyCode == kVK_ANSI_E ||
	    keyCode == kVK_ANSI_F ||
	    keyCode == kVK_ANSI_G ||
	    keyCode == kVK_ANSI_H ||
	    keyCode == kVK_ANSI_I ||
	    keyCode == kVK_ANSI_J ||
	    keyCode == kVK_ANSI_K ||
	    keyCode == kVK_ANSI_L ||
	    keyCode == kVK_ANSI_M ||
	    keyCode == kVK_ANSI_N ||
	    keyCode == kVK_ANSI_O ||
	    keyCode == kVK_ANSI_P ||
	    keyCode == kVK_ANSI_Q ||
	    keyCode == kVK_ANSI_R ||
	    keyCode == kVK_ANSI_S ||
	    keyCode == kVK_ANSI_T ||
	    keyCode == kVK_ANSI_U ||
	    keyCode == kVK_ANSI_V ||
	    keyCode == kVK_ANSI_W ||
	    keyCode == kVK_ANSI_X ||
	    keyCode == kVK_ANSI_Y ||
	    keyCode == kVK_ANSI_Z) {
		system("afplay ~/Library/Application\\ Support/KeySounds/base.aif &");
	}
	else if (keyCode == kVK_ANSI_1 ||
	         keyCode == kVK_ANSI_2 ||
	         keyCode == kVK_ANSI_3 ||
	         keyCode == kVK_ANSI_4 ||
	         keyCode == kVK_ANSI_5 ||
	         keyCode == kVK_ANSI_6 ||
	         keyCode == kVK_ANSI_7 ||
	         keyCode == kVK_ANSI_8 ||
	         keyCode == kVK_ANSI_9 ||
	         keyCode == kVK_ANSI_0 ||
			 keyCode == kVK_ANSI_Minus ||
			 keyCode == kVK_ANSI_Equal ||
			 keyCode == kVK_ANSI_LeftBracket ||
			 keyCode == kVK_ANSI_RightBracket ||
			 keyCode == kVK_ANSI_Semicolon ||
			 keyCode == kVK_ANSI_Quote ||
			 keyCode == kVK_ANSI_Backslash ||
			 keyCode == kVK_ANSI_Comma ||
			 keyCode == kVK_ANSI_Period ||
			 keyCode == kVK_ANSI_Slash ||
			 keyCode == kVK_ANSI_Grave ||
	         keyCode == kVK_Return ||
			 keyCode == kVK_Tab ||
			 keyCode == kVK_Space
	         ) {
		system("afplay ~/Library/Application\\ Support/KeySounds/modifier.aif &");
	}
	else if (keyCode == kVK_Function ||
	         keyCode == kVK_Control ||
			 keyCode == kVK_RightControl || // Doesn't exist on my keyboard
			 keyCode == kVK_Option ||
			 keyCode == kVK_RightOption ||
			 keyCode == kVK_Command ||
			 keyCode == kVK_RightCommand ||
	         keyCode == kVK_Shift ||
			 keyCode == kVK_RightShift ||
			 keyCode == kVK_CapsLock) {
		system("afplay ~/Library/Application\\ Support/KeySounds/extra.aif &");
	}
	else if (keyCode == kVK_UpArrow ||
			 keyCode == kVK_DownArrow ||
			 keyCode == kVK_LeftArrow ||
			 keyCode == kVK_RightArrow) {
		system("afplay ~/Library/Application\\ Support/KeySounds/high.aif &");
	}
	else if (keyCode == kVK_Delete ||
			 keyCode == kVK_Escape) {
		system("afplay ~/Library/Application\\ Support/KeySounds/low.aif &");
	}
	else if (keyCode == kVK_F1 ||
	         keyCode == kVK_F2 ||
	         keyCode == kVK_F3 ||
	         keyCode == kVK_F4 ||
	         keyCode == kVK_F5 ||
	         keyCode == kVK_F6 ||
	         keyCode == kVK_F7 ||
	         keyCode == kVK_F8 ||
	         keyCode == kVK_F9 ||
	         keyCode == kVK_F10 ||
	         keyCode == kVK_F11 ||
	         keyCode == kVK_F12) {
		system("afplay ~/Library/Application\\ Support/KeySounds/super.aif &");
	}
	return;
}
