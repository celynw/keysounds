CC=gcc
CFLAGS=-Wall -framework Carbon
SOURCES=keysounds.c
EXECUTABLE=keysounds
APP=KeySounds.app
APPINTERNAL=Contents/MacOS
PLIST=com.celynwalters.keysounds.plist
INSTALLDIR=/usr/local/bin
SUPPORT=Support/
SUPPORTDIR=~/Library/Application\ Support/KeySounds/

all: $(SOURCES)
# Fudges an app so it can go into Assistive Devices prefpane
	$(CC) $(SOURCES) $(CFLAGS) -o $(EXECUTABLE)
	mkdir -p $(APP)/$(APPINTERNAL)
	mv $(EXECUTABLE) $(APP)/$(APPINTERNAL)

install:
# Move the app (location should exist already)
	mkdir -p $(INSTALLDIR)
	cp -r $(APP) $(INSTALLDIR)
# Move the sounds to Application Support
	mkdir -p $(SUPPORTDIR)
	cp -r $(SUPPORT) $(SUPPORTDIR)

uninstall:
# (sudo)
	-rm -r $(INSTALLDIR)/$(APP)
	-rm /Library/LaunchAgents/$(PLIST)
	-rm -r $(SUPPORTDIR)

startup:
# (sudo) Enable the LaunchAgent
	cp $(PLIST) /Library/LaunchAgents

clean:
# (sudo) Should be the only thing in here
	-rm -r $(APP)


