# KeySounds
A tiny app to play sounds when keys are pressed.  
May be useful for touch typing, or screen recordings.  
If you're worried about evil keylogging, check out the source code.

Mobiles do this, why can't computers?

#### Installation
You're going to have to compile this, but it's easy.  
In the application directory:
```bash
$ make
$ sudo make install
$ sudo make startup
```
The app should be added to your accessibility settings.  
In OSX Sierra, it is under `System Preferences`, `Security & Privacy`, `Privacy`, `Accessibility`.  
![System_Preferences](/uploads/12e6a8fca2acb7dccf29dac8c93db546/System_Preferences.png)
After installation the app is located here: `/usr/local/bin/KeySounds.app`


#### Running
This creates the barest-bones of apps, neccesary to be added to the `Assistive Devices` preference pane.  
This inserts a `LaunchAgent` which will run the app in the background after login.  

#### Troubleshooting
- If you can hear sounds only for modifier keys, like ⌘⌥⇧, the app probably hasn't been added to Assisted Devices. See the installation instructions
- Protected fields like passwords don't trigger the sounds. It's a feature!
- Open an issue if there's keys missing. I didn't blindly add them all.  
  Some don't trigger the callback, such as ⏏ or §
