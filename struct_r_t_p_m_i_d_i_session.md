# RTPMIDISession #
Send and receive [MIDIMessage](struct_m_i_d_i_message.md) objects via an `[struct_r_t_p_session RTPSession]`.
```

struct RTPMIDISession;
```
This class describes a payload format to code MIDI messages as RTP payload. It extends the [RTPSession](struct_r_t_p_session.md) by methods to send and receive [MIDIMessage](struct_m_i_d_i_message.md) objects. For implementation details refer to RFC 4695 & 4696.




---

## Public Attributes ##


### `size_t RTPMIDISession::refs` ###


### `struct RTPMIDIInfo RTPMIDISession::midi_info` ###


### `struct RTPPacketInfo RTPMIDISession::rtp_info` ###


### `struct RTPSession* RTPMIDISession::rtp_session` ###


### `size_t RTPMIDISession::size` ###


### `void* RTPMIDISession::buffer` ###



---

## Creation and destruction ##
Creating, destroying and reference counting of [RTPMIDISession](struct_r_t_p_m_i_d_i_session.md) objects.


---


### `struct RTPMIDISession * RTPMIDISessionCreate` ###
Create an [RTPMIDISession](struct_r_t_p_m_i_d_i_session.md) instance.
```
struct RTPMIDISession * RTPMIDISessionCreate(struct RTPSession *rtp_session);
```

Allocate space and initialize an [RTPMIDISession](struct_r_t_p_m_i_d_i_session.md) instance.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| rtp\_session | The RTP session to use for transmission.  |

#### Return ####
a pointer to the created structure on success. a `NULL` pointer if the session could not created.


---


### `void RTPMIDISessionDestroy` ###
Destroy an [RTPMIDISession](struct_r_t_p_m_i_d_i_session.md) instance.
```
void RTPMIDISessionDestroy(struct RTPMIDISession *session);
```

Free all resources occupied by the session and release the RTP session.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| session  | The session.    |



---


### `void RTPMIDISessionRetain` ###
Retain an [RTPMIDISession](struct_r_t_p_m_i_d_i_session.md) instance.
```
void RTPMIDISessionRetain(struct RTPMIDISession *session);
```

Increment the reference counter of a session so that it won't be destroyed.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| session  | The session.    |



---


### `void RTPMIDISessionRelease` ###
Release an [RTPMIDISession](struct_r_t_p_m_i_d_i_session.md) instance.
```
void RTPMIDISessionRelease(struct RTPMIDISession *session);
```

Decrement the reference counter of a session. If the reference count reached zero, destroy the session.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| session  | The session.    |



---

## RTP transmission extension ##
Sending and receiving [MIDIMessage](struct_m_i_d_i_message.md) objects using the RTP-protocol.


---


### `int RTPMIDISessionJournalTrunkate` ###
Trunkate a peers send journal.
```
int RTPMIDISessionJournalTrunkate(struct RTPMIDISession *session, struct RTPPeer *peer, unsigned long seqnum);
```

Remove all message entries that have a sequence number less or equal to `seqnum`.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| session  | The session.    |
| peer     | The peer.       |
| seqnum   | The sequence number.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |



---


### `int RTPMIDISessionJournalStoreMessages` ###
Store a list of messages in a peer's send journal and associate them with the given sequence number.
```
int RTPMIDISessionJournalStoreMessages(struct RTPMIDISession *session, struct RTPPeer *peer, unsigned long seqnum, struct MIDIMessageList *messages);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| session  | The session.    |
| peer     | The peer.       |
| seqnum   | The sequence number.  |
| messages | The messages list to encode.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |



---


### `int RTPMIDISessionJournalRecoverMessages` ###
Restore a list of messages from a peer's receive journal associated with the given sequence number.
```
int RTPMIDISessionJournalRecoverMessages(struct RTPMIDISession *session, struct RTPPeer *peer, unsigned long seqnum, struct MIDIMessageList *messages);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| session  | The session.    |
| peer     | The peer.       |
| seqnum   | The sequence number.  |
| messages | The messages list to decode messages to.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |



---


### `int RTPMIDISessionSend` ###
Send MIDI messages over an [RTPSession](struct_r_t_p_session.md).
```
int RTPMIDISessionSend(struct RTPMIDISession *session, struct MIDIMessageList *messages);
```

Broadcast the messages to all connected peers. Store the number of sent messages in `count`, if the `info` argument was specified it will be populated with the packet info of the last sent packet. The peer's control structures will be updated with the required journalling information.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| session  | The session.    |
| messages | A pointer to a list of `size` message pointers.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | On success.     |
| >0        | If the message could not be sent.  |



---


### `int RTPMIDISessionReceive` ###
Receive MIDI messages over an [RTPSession](struct_r_t_p_session.md).
```
int RTPMIDISessionReceive(struct RTPMIDISession *session, struct MIDIMessageList *messages);
```

Receive messages from any connected peer. Store the number of received messages in `count`, if the `info` argument was specified it will be populated with the packet info of the last received packet. If lost packets are detected the required information is recovered from the journal.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| session  | The session.    |
| messages | A pointer to a list of midi messages.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | If the message was corrupted or could not be received.  |



---


### `int RTPMIDIPeerSetInfo` ###
Set the pointer of the internal info-structure.
```
int RTPMIDIPeerSetInfo(struct RTPPeer *peer, void *info);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| peer     | The peer.       |
| info     | A pointer to the info-structure.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the info-structure could not be set.  |



---


### `int RTPMIDIPeerGetInfo` ###
Get a pointer to the info sub-structure.
```
int RTPMIDIPeerGetInfo(struct RTPPeer *peer, void **info);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| peer     | The peer.       |
| info     | A pointer to the info-structure.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the info-structure could not be obtained.  |