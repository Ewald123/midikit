# MIDIRTPJournalSection #
Journal section.
```

struct MIDIRTPJournalSection;
```
<pre>
0                   1                   2                   3<br>
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1<br>
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+<br>
|S|Y|A|H|TOTCHAN|   Checkpoint Packet Seqnum    | S-journal ... |<br>
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+<br>
|                      Channel journals ...                     |<br>
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+<br>
</pre>




---

## Public Attributes ##


### `unsigned char MIDIRTPJournalSection::single_loss` ###
Single-packet loss (S): 1 bit. The S (single-packet loss) bit appears in most recovery journal structures, including the recovery journal header. The S bit helps receivers efficiently parse the recovery journal in the common case of the loss of a single packet.

### `unsigned char MIDIRTPJournalSection::system_journal` ###
System journal (Y): 1 bit. If the Y header bit is set to 1, the system journal appears in the recovery journal, directly following the recovery journal header.

### `unsigned char MIDIRTPJournalSection::channel_journals` ###
Channel journals (A): 1 bit. If the A header bit is set to 1, the recovery journal ends with a list of (TOTCHAN + 1) channel journals (the 4-bit TOTCHAN header field is interpreted as an unsigned integer). If A and Y are both zero, the recovery journal only contains its 3- octet header and is considered to be an "empty" journal.

### `unsigned char MIDIRTPJournalSection::enhanced_chapter_encoding` ###
Enhanced Chapter C encoding (H): 1 bit. The H bit indicates if MIDI channels in the stream have been configured to use the enhanced Chapter C encoding.

By default, the payload format does not use enhanced Chapter C encoding. In this default case, the H bit MUST be set to 0 for all packets in the stream.

### `unsigned char MIDIRTPJournalSection::total_channels` ###
Total number of channels (TOTCHAN): 4 bits. A MIDI channel MAY be represented by (at most) one channel journal in a recovery journal. Channel journals MUST appear in the recovery journal in ascending channel-number order.

### `unsigned short MIDIRTPJournalSection::checkpoint_packet_seqnum` ###
Checkpoint Packet Seqnum: 16 bits. The 16-bit Checkpoint Packet Seqnum header field codes the sequence number of the checkpoint packet for this journal, in network byte order (big-endian). The choice of the checkpoint packet sets the depth of the checkpoint history for the journal.