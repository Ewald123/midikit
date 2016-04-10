# RTPMIDIJournal #
Hold information for the RTP-MIDI session history.
```

struct RTPMIDIJournal;
```





---

## Public Attributes ##


### `unsigned char RTPMIDIJournal::enhanced_chapter_c` ###
Use enhanced chapter C coding in at least one channel journal.

### `unsigned char RTPMIDIJournal::total_channels` ###
The number of valid entries in the channel journals list.

### `unsigned short RTPMIDIJournal::checkpoint_pkt_seqnum` ###
The latest RTP sequence number encoded in the journal.

### `struct RTPMIDISystemJournal* RTPMIDIJournal::system_journal` ###


### `struct RTPMIDIChannelJournal* RTPMIDIJournal::channel_journals[16]` ###


### `size_t RTPMIDIJournal::size` ###


### `void* RTPMIDIJournal::buffer` ###



---

## RTP-MIDI journal coding ##
Functions for encoding the various journals and their chapters to a continuous stream of bytes.


---


### `static int _rtpmidi_journal_encode` ###
Encode the RTP-MIDI history to a stream.
```
static int _rtpmidi_journal_encode(struct RTPMIDISession *session, struct RTPMIDIJournal *journal, size_t size, void *buffer, size_t *written);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| session  | The session.    |
| journal  | The journal.    |
| size     | The number of available bytes in the buffer.  |
| buffer   | The buffer to write the journal to.  |
| written  | The number of bytes written to the stream.  |



---


### `static int _rtpmidi_journal_decode` ###
Decode the RTP-MIDI history from a stream.
```
static int _rtpmidi_journal_decode(struct RTPMIDISession *session, struct RTPMIDIJournal *journal, size_t size, void *buffer, size_t *read);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| session  | The session.    |
| journal  | The journal.    |
| size     | The number of available bytes in the buffer.  |
| buffer   | The buffer to read the journal from.  |
| read     | The number of bytes read from the stream.  |



---


### `static int _rtpmidi_journal_encode_messages` ###
Store a list of messages in the journal.
```
static int _rtpmidi_journal_encode_messages(struct RTPMIDIJournal *journal, unsigned short checkpoint, struct MIDIMessageList *messages);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| journal  | The journal.    |
| checkpoint | The sequence number of the packet that contains the messages.  |
| messages | The list of messages to store.  |



---


### `static int _rtpmidi_journal_decode_messages` ###
Restore a list of messages from the journal.
```
static int _rtpmidi_journal_decode_messages(struct RTPMIDIJournal *journal, unsigned short checkpoint, struct MIDIMessageList *messages);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| journal  | The journal.    |
| checkpoint | The sequence number of the packet that contains the messages.  |
| messages | The list to store the recovered messages in.  |