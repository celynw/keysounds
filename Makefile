CC=gcc
CFLAGS=-Wall -framework ApplicationServices -framework Carbon
SOURCES=keysounds.c
EXECUTABLE=keysounds
PLIST=keysounds.plist
INSTALLDIR=/usr/local/bin
SUPPORT=Support/
SUPPORTDIR=~/Library/Application\ Support/KeySounds/

all: $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) -o $(EXECUTABLE)

install:
	mkdir -p $(INSTALLDIR)
	cp $(EXECUTABLE) $(INSTALLDIR)
	mkdir -p $(SUPPORTDIR)
	cp -r $(SUPPORT) $(SUPPORTDIR)

uninstall:
	rm $(INSTALLDIR)/$(EXECUTABLE)
	rm /Library/LaunchDaemons/$(PLIST)
	rm -r $(SUPPORTDIR)

startup:
	cp $(PLIST) /Library/LaunchDaemons

clean:
	rm $(EXECUTABLE)
