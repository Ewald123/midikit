# RTPMIDIJournalChapterPart #
Structure for easily removing journal parts by sequence number.
```

struct RTPMIDIJournalChapterPart;
```





---

## Public Attributes ##


### `unsigned short RTPMIDIJournalChapterPart::checkpoint_pkt_seqnum` ###
The RTP sequence number encoded in this journal part.

### `unsigned short RTPMIDIJournalChapterPart::length` ###
Number of bytes[.md](.md) allocated.

### `unsigned char RTPMIDIJournalChapterPart::bytes[1]` ###
Variable length array of chapter bytes.