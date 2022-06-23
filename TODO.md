# stuff to do

## Game CPP classes to implement:

### Distinction between objects initial positions and current positions (when ran)
#### Idea 1: Copying hell
- One const vector of objects that represents initial positions
- One vector of objects that represents current positions
- Second vector is initially copied from first
- Second vector is the one actually displayed
- When running stops, second vector is destroyed, and first vector is re-copied over to the second

### load()
- Overwrite the window with its garbage
- Display objects as squares
### unload()
- Wipe window
### run()

### layer system thingy
- essentially we need a way to update
- the screen whilst keeping the background in the back
- and keeping the character moving

### stop_run()
