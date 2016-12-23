CC=gcc
CFLAGS=-Wall -framework ApplicationServices -framework Carbon
SOURCES=keysounds.c
EXECUTABLE=keysounds
APPFOLDER=KeySounds.app/Contents/MacOS
PLIST=com.celynwalters.keysounds.plist
INSTALLDIR=/usr/local/bin
SUPPORT=Support/
SUPPORTDIR=~/Library/Application\ Support/KeySounds/

all: $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) -o $(EXECUTABLE)
	mkdir -p $(APPFOLDER)
	mv $(EXECUTABLE) $(APPFOLDER)

install:
	mkdir -p $(INSTALLDIR)
	mv $(APPFOLDER) $(INSTALLDIR)
	mkdir -p $(SUPPORTDIR)
	cp -r $(SUPPORT) $(SUPPORTDIR)

uninstall:
	rm -r $(INSTALLDIR)/$(APPFOLDER)
	rm /Library/LaunchAgents/$(PLIST)
	rm -r $(SUPPORTDIR)

startup:
	cp $(PLIST) /Library/LaunchAgents

clean:
	rm $(EXECUTABLE)

