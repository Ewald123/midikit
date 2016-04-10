# RTPMIDISystemJournal #
Hold information for the system history.
```

struct RTPMIDISystemJournal;
```





---

## Public Attributes ##


### `unsigned short RTPMIDISystemJournal::checkpoint_pkt_seqnum` ###
The latest RTP sequence number encoded in the journal.

### `struct RTPMIDIJournalChapterPart* RTPMIDISystemJournal::chapter_d` ###
Chapter D: Song Select (0xf3), Tune Request (0xf6), Reset (0xff), undefined System commands (0xf4, 0xf5, 0xf9, 0xfd)

### `struct RTPMIDIJournalChapterPart* RTPMIDISystemJournal::chapter_v` ###
Chapter V: Active Sense (0xfe)

### `struct RTPMIDIJournalChapterPart* RTPMIDISystemJournal::chapter_q` ###
Chapter Q: Sequencer State (0xf2, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc)

### `struct RTPMIDIJournalChapterPart* RTPMIDISystemJournal::chapter_f` ###
Chapter F: MTC Tape Position (0xf1, 0xf0, 0x7f, 0xcc 0x01 0x01)

### `struct RTPMIDIJournalChapterPart* RTPMIDISystemJournal::chapter_x` ###
Chapter X: System Exclusive (all other 0xf0)