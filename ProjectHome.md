MIDIKit is a slim library implementing a basic MIDI interface supporting all standardized messages.


---

**Current status:** Basic MIDI messaging working. Big cleanup in progress.

**AppleMIDI:** Tested and working, no journalling yet. Driver still needs to send receiver feedback.

---


MIDIKit is event-driven and supports multiple drivers (backends) to send and receive MIDI messages. Initially we will focus on Network-based implementations ([Apple's RTP-MIDI](http://www.cs.berkeley.edu/~lazzaro/rtpmidi/), [OSC](http://opensoundcontrol.org/spec-1_0)) and a "general purpose implementation" streaming MIDI messages exactly the way they are transmitted over standard MIDI cables.

MIDI over USB and Firewire will follow at a later point.

MIDIKit can be integrated in a non-blocking fashion into any program's run-loop without the need for multiple threads.