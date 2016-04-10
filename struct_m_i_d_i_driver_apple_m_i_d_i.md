# MIDIDriverAppleMIDI #
[MIDIDriver](struct_m_i_d_i_driver.md) implementation using Apple's network MIDI protocol.
```

struct MIDIDriverAppleMIDI;
```





---

## Public Attributes ##


### `struct MIDIDriver MIDIDriverAppleMIDI::base` ###


### `int MIDIDriverAppleMIDI::control_socket` ###


### `int MIDIDriverAppleMIDI::rtp_socket` ###


### `unsigned short MIDIDriverAppleMIDI::port` ###


### `unsigned char MIDIDriverAppleMIDI::accept` ###


### `unsigned char MIDIDriverAppleMIDI::sync` ###


### `unsigned long MIDIDriverAppleMIDI::token` ###


### `char MIDIDriverAppleMIDI::name[32]` ###


### `struct AppleMIDICommand MIDIDriverAppleMIDI::command` ###


### `struct RTPPeer* MIDIDriverAppleMIDI::peer` ###


### `struct RTPSession* MIDIDriverAppleMIDI::rtp_session` ###


### `struct RTPMIDISession* MIDIDriverAppleMIDI::rtpmidi_session` ###


### `struct MIDIMessageQueue* MIDIDriverAppleMIDI::in_queue` ###


### `struct MIDIMessageQueue* MIDIDriverAppleMIDI::out_queue` ###



---

## Creation and destruction ##
Creating, destroying and reference counting of [MIDIClock](struct_m_i_d_i_clock.md) objects.


---


### `struct MIDIDriverAppleMIDI * MIDIDriverAppleMIDICreate` ###
Create a [MIDIDriverAppleMIDI](struct_m_i_d_i_driver_apple_m_i_d_i.md) instance.
```
struct MIDIDriverAppleMIDI * MIDIDriverAppleMIDICreate(char *name, unsigned short port);
```

Allocate space and initialize an [MIDIDriverAppleMIDI](struct_m_i_d_i_driver_apple_m_i_d_i.md) instance.


#### Return ####
a pointer to the created driver structure on success. a `NULL` pointer if the driver could not created.


---


### `void MIDIDriverAppleMIDIDestroy` ###
Destroy a [MIDIDriverAppleMIDI](struct_m_i_d_i_driver_apple_m_i_d_i.md) instance.
```
void MIDIDriverAppleMIDIDestroy(struct MIDIDriverAppleMIDI *driver);
```

Free all resources occupied by the driver.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| driver   | The driver.     |



---

## Public Functions ##



---


### `int MIDIDriverAppleMIDISetPort` ###
Set the base port to be used for session management.
```
int MIDIDriverAppleMIDISetPort(struct MIDIDriverAppleMIDI *driver, unsigned short port);
```

The RTP port will be the control port plus one.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| driver   | The driver.     |
| port     | The port.       |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | On success.     |
| >0        | If the port could not be set.  |



---


### `int MIDIDriverAppleMIDIGetPort` ###
Get the port used for session management.
```
int MIDIDriverAppleMIDIGetPort(struct MIDIDriverAppleMIDI *driver, unsigned short *port);
```

The RTP port can be computed by adding one.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| driver   | The driver.     |
| port     | The port.       |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | On success.     |
| >0        | If the port could not be set.  |



---


### `int MIDIDriverAppleMIDIReceiveMessage` ###
Handle incoming MIDI messages.
```
int MIDIDriverAppleMIDIReceiveMessage(struct MIDIDriverAppleMIDI *driver, struct MIDIMessage *message);
```

This is called by the RTP-MIDI payload parser whenever it encounters a new MIDI message. There may be multiple messages in a single packet so a single call of [MIDIDriverAppleMIDI](struct_m_i_d_i_driver_apple_m_i_d_i.md) may trigger multiple calls of this function.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| driver   | The driver.     |
| message  | The message that was just received.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the message could not be processed.  |



---


### `int MIDIDriverAppleMIDISendMessage` ###
Process outgoing MIDI messages.
```
int MIDIDriverAppleMIDISendMessage(struct MIDIDriverAppleMIDI *driver, struct MIDIMessage *message);
```

This is called by the generic driver interface to pass messages to this driver implementation. The driver may queue outgoing messages to reduce package overhead, trading of latency for throughput.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| driver   | The driver.     |
| message  | The message that should be sent.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the message could not be processed.  |



---


### `int MIDIDriverAppleMIDIAddPeerWithSockaddr` ###
Connect to a peer with a socket address.
```
int MIDIDriverAppleMIDIAddPeerWithSockaddr(struct MIDIDriverAppleMIDI *driver, socklen_t size, struct sockaddr *addr);
```

Use the AppleMIDI protocol to establish an RTP-session, including a SSRC that was received from the peer. Send the session packets to the given socket address.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| driver   | The driver.     |
| size     | The size of the address pointed to by `addr`.  |
| addr     | A pointer to an address that can be used to send packets to the client.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the connection could not be established.  |



---


### `int MIDIDriverAppleMIDIAddPeer` ###
Connect to a peer.
```
int MIDIDriverAppleMIDIAddPeer(struct MIDIDriverAppleMIDI *driver, char *address, unsigned short port);
```

Use the AppleMIDI protocol to establish an RTP-session, including a SSRC that was received from the peer.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| driver   | The driver.     |
| address  | The internet address of the peer.  |
| port     | The AppleMIDI control port (usually 5004), the RTP-port is the next port.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the connection could not be established.  |



---


### `int MIDIDriverAppleMIDIRemovePeerWithSockaddr` ###
Disconnect from a peer.
```
int MIDIDriverAppleMIDIRemovePeerWithSockaddr(struct MIDIDriverAppleMIDI *driver, socklen_t size, struct sockaddr *addr);
```

Use the AppleMIDI protocol to tell the peer that the session ended. Remove the peer from the [RTPSession](struct_r_t_p_session.md).


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| driver   | The driver.     |
| size     | The size of the address pointed to by `addr`.  |
| addr     | A pointer to an address that can be used to send packets to the client.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the session could not be ended.  |



---


### `int MIDIDriverAppleMIDIRemovePeer` ###
Disconnect from a peer.
```
int MIDIDriverAppleMIDIRemovePeer(struct MIDIDriverAppleMIDI *driver, char *address, unsigned short port);
```

Use the AppleMIDI protocol to tell the peer that the session ended. Remove the peer from the [RTPSession](struct_r_t_p_session.md).


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| driver   | The driver.     |
| address  | The internet address of the peer.  |
| port     | The AppleMIDI control port (usually 5004), the RTP-port is the next port.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the session could not be ended.  |



---


### `int MIDIDriverAppleMIDIReceive` ###
Receive from any peer.
```
int MIDIDriverAppleMIDIReceive(struct MIDIDriverAppleMIDI *driver);
```

This should be called whenever there is new data to be received on a socket.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| driver   | The driver.     |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the packet could not be processed.  |



---


### `int MIDIDriverAppleMIDISend` ###
Send queued messages to all connected peers.
```
int MIDIDriverAppleMIDISend(struct MIDIDriverAppleMIDI *driver);
```

This should be called whenever new messages are added to the queue and whenever the socket can accept new data.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| driver   | The driver.     |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if packets could not be sent, or any other operation failed.  |



---


### `int MIDIDriverAppleMIDIIdle` ###
Do idling operations.
```
int MIDIDriverAppleMIDIIdle(struct MIDIDriverAppleMIDI *driver);
```

When there is nothing else to do, keep in sync with connected peers, dispatch incoming messages, send receiver feedback.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| driver   | The driver.     |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if packets could not be sent, or any other operation failed.  |



---


### `int MIDIDriverAppleMIDIGetRunloopSource` ###
Get a pointer to the driver's runloop source.
```
int MIDIDriverAppleMIDIGetRunloopSource(struct MIDIDriverAppleMIDI *driver, struct MIDIRunloopSource **source);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| driver   | The driver.     |
| source   | The runloop source.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the runloop source could not be created.  |



---

## Private Functions ##



---


### `static int _test_applemidi` ###
Test incoming packets for the AppleMIDI signature.
```
static int _test_applemidi(int fd);
```

Check if the data that is waiting on a socket begins with the special AppleMIDI signature (0xffff).


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| fd       | The file descriptor to use for communication.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | if the packet is AppleMIDI  |
| 1         | if the packet is not AppleMIDI  |
| -1        | if no signature data could be received  |



---


### `static int _applemidi_send_command` ###
Send the given AppleMIDI command.
```
static int _applemidi_send_command(struct MIDIDriverAppleMIDI *driver, int fd, struct AppleMIDICommand *command);
```

Compose a message buffer and send the datagram to the given peer.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| driver   | The driver.     |
| fd       | The file descriptor to use for communication.  |
| command  | The command.    |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | On success.     |
| >0        | If the packet could not be sent.  |



---


### `static int _applemidi_recv_command` ###
Receive an AppleMIDI command.
```
static int _applemidi_recv_command(struct MIDIDriverAppleMIDI *driver, int fd, struct AppleMIDICommand *command);
```

Receive a datagram and decompose the message into the message structure.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| driver   | The driver.     |
| fd       | The file descriptor to use for communication.  |
| command  | The command.    |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | On success.     |
| >0        | If the packet could not be sent.  |



---


### `static int _applemidi_respond` ###
Respond to a given AppleMIDI command.
```
static int _applemidi_respond(struct MIDIDriverAppleMIDI *driver, int fd, struct AppleMIDICommand *command);
```

Use the command as response and - if neccessary - send it back to the peer.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| driver   | The driver.     |
| fd       | The file descriptor to be used for communication.  |
| command  | The command.    |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | On success.     |
| >0        | If the packet could not be sent.  |