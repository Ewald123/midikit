# RTPMIDIChannelJournal #
Hold information for the channel history.
```

struct RTPMIDIChannelJournal;
```





---

## Public Attributes ##


### `unsigned short RTPMIDIChannelJournal::checkpoint_pkt_seqnum` ###
The latest RTP sequence number encoded in the journal.

### `unsigned char RTPMIDIChannelJournal::enhanced_chapter_c` ###
Use enhanced chapter C coding.

### `unsigned char RTPMIDIChannelJournal::channel` ###
The channel number.

### `struct RTPMIDIJournalChapterPart* RTPMIDIChannelJournal::chapter_p` ###
Chapter P: MIDI Program Change (0xc)

### `struct RTPMIDIJournalChapterPart* RTPMIDIChannelJournal::chapter_c` ###
Chapter C: MIDI Control Change (0xb)

### `struct RTPMIDIJournalChapterPart* RTPMIDIChannelJournal::chapter_m` ###
Chapter M: MIDI Parameter System (part of 0xb)

### `struct RTPMIDIJournalChapterPart* RTPMIDIChannelJournal::chapter_w` ###
Chapter W: MIDI Pitch Wheel (0xe)

### `struct RTPMIDIJournalChapterPart* RTPMIDIChannelJournal::chapter_n` ###
Chapter N: MIDI NoteOff (0x8), NoteOn (0x9)

### `struct RTPMIDIJournalChapterPart* RTPMIDIChannelJournal::chapter_e` ###
Chapter E: MIDI Note Command Extras (0x8, 0x9)