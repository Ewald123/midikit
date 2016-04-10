# MIDIMessageData #
Store any kind of MIDI message.
```
#include <message_format.h>

struct MIDIMessageData;
```
Usually the message data only makes sense in combination with a message format. However, there is one important thing to remember. You may only free the data field if bytes[3](3.md) has the least significant bit set! (And you need to set it o one if you allocate some buffer for it.

The size and data fields are only used for system exclusive messages. Those messages store the system exclusive data inside the data field. Status, manufacturer ID and fragment number are stored in the bytes array. [MIDIMessageFormat](struct_m_i_d_i_message_format.md)




---

## Public Attributes ##


### `unsigned char MIDIMessageData::bytes[MIDI_MESSAGE_DATA_BYTES]` ###


### `size_t MIDIMessageData::size` ###


### `void* MIDIMessageData::data` ###