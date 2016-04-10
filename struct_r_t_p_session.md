# RTPSession #
An RTP session that may be connected to multiple peers.
```

struct RTPSession;
```





---

## Public Attributes ##


### `size_t RTPSession::refs` ###


### `int RTPSession::socket` ###


### `struct RTPAddress RTPSession::self` ###


### `struct RTPPeer* RTPSession::peers[RTP_MAX_PEERS]` ###


### `struct RTPPacketInfo RTPSession::info` ###


### `struct iovec RTPSession::iov[RTP_IOV_LEN]` ###


### `size_t RTPSession::buflen` ###


### `void* RTPSession::buffer` ###



---

## Creation and destruction ##
Creating, destroying and reference counting of [RTPSession](struct_r_t_p_session.md) objects.


---


### `struct RTPSession * RTPSessionCreate` ###
Create an [RTPSession](struct_r_t_p_session.md) instance.
```
struct RTPSession * RTPSessionCreate(int socket);
```

Allocate space and initialize an [RTPSession](struct_r_t_p_session.md) instance.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| socket   | The socket to use for communication.  |

#### Return ####
a pointer to the created controller structure on success. a `NULL` pointer if the controller could not created.


---


### `void RTPSessionDestroy` ###
Destroy an [RTPSession](struct_r_t_p_session.md) instance.
```
void RTPSessionDestroy(struct RTPSession *session);
```

Free all resources occupied by the session.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| session  | The session.    |



---


### `void RTPSessionRetain` ###
Retain an [RTPSession](struct_r_t_p_session.md) instance.
```
void RTPSessionRetain(struct RTPSession *session);
```

Increment the reference counter of a session so that it won't be destroyed.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| session  | The session.    |



---


### `void RTPSessionRelease` ###
Release an [RTPSession](struct_r_t_p_session.md) instance.
```
void RTPSessionRelease(struct RTPSession *session);
```

Decrement the reference counter of a session. If the reference count reached zero, destroy the session.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| session  | The session.    |



---

## Public Functions ##



---


### `int RTPSessionSetSSRC` ###
Set the SSRC used by this session.
```
int RTPSessionSetSSRC(struct RTPSession *session, unsigned long ssrc);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| session  | The session.    |
| ssrc     | The synchronization source.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |



---


### `int RTPSessionGetSSRC` ###
Get the SSRC used by this session.
```
int RTPSessionGetSSRC(struct RTPSession *session, unsigned long *ssrc);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| session  | The session.    |
| ssrc     | The synchronization source.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |



---


### `int RTPSessionSetSocket` ###
Set the socket used to communicate with other clients.
```
int RTPSessionSetSocket(struct RTPSession *session, int socket);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| session  | The session.    |
| socket   | The socket.     |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |



---


### `int RTPSessionGetSocket` ###
Get the socket used to communicate with other clients.
```
int RTPSessionGetSocket(struct RTPSession *session, int *socket);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| session  | The session.    |
| socket   | The socket.     |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |



---


### `int RTPSessionAddPeer` ###
Add an [RTPPeer](struct_r_t_p_peer.md) to the session.
```
int RTPSessionAddPeer(struct RTPSession *session, struct RTPPeer *peer);
```

Lookup the peer using the (pseudo) hash-table, add it to the list and retain it. The peer will be included when data is sent via RTPSessionSendPayload.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| session  | The session.    |
| peer     | The peer to add.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the peer could not be added.  |



---


### `int RTPSessionRemovePeer` ###
Remove an [RTPPeer](struct_r_t_p_peer.md) from the session.
```
int RTPSessionRemovePeer(struct RTPSession *session, struct RTPPeer *peer);
```

Lookup the peer using the (pseudo) hash-table, remove it from the list and release it.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| session  | The session.    |
| peer     | The peer to remove.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the peer could not be removed.  |



---


### `int RTPSessionNextPeer` ###
Advance the pointer to the next peer.
```
int RTPSessionNextPeer(struct RTPSession *session, struct RTPPeer **peer);
```

Given a `NULL` pointer the first peer will be returned. When the last peer was reached a `NULL` pointer will be returned.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| session  | The session.    |
| peer     | The peer.       |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the given peer does not exist.  |



---


### `int RTPSessionFindPeerBySSRC` ###
Retrieve peer information by looking up the given SSRC identifier.
```
int RTPSessionFindPeerBySSRC(struct RTPSession *session, struct RTPPeer **peer, unsigned long ssrc);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| session  | The session.    |
| peer     | The peer.       |
| ssrc     | The SSRC.       |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if no peer with the given ssrc was found.  |



---


### `int RTPSessionFindPeerByAddress` ###
Retrieve peer information by looking up the given host address.
```
int RTPSessionFindPeerByAddress(struct RTPSession *session, struct RTPPeer **peer, socklen_t size, struct sockaddr *addr);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| session  | The session.    |
| peer     | The peer.       |
| size     | The length of the structure pointed to by `addr`.  |
| addr     | Any sockaddr structure.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if no peer with the given address was found.  |



---


### `int RTPSessionSendPacket` ###
Send an RTP packet.
```
int RTPSessionSendPacket(struct RTPSession *session, struct RTPPacketInfo *info);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| session  | The session.    |
| info     | The packet info.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | On success.     |
| >0        | If the message could not be sent.  |



---


### `int RTPSessionReceivePacket` ###
Receive an RTP packet.
```
int RTPSessionReceivePacket(struct RTPSession *session, struct RTPPacketInfo *info);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| session  | The session.    |
| info     | The packet info.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | On success.     |
| >0        | If the message could not be received.  |



---


### `int RTPSessionSend` ###
Send an RTP packet.
```
int RTPSessionSend(struct RTPSession *session, size_t size, void *payload, struct RTPPacketInfo *info);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| session  | The session.    |
| size     | The number of bytes in the `payload` buffer.  |
| payload  | The buffer to read the payload from.  |
| info     | The packet info.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | On success.     |
| >0        | If the message could not be sent.  |



---


### `int RTPSessionReceive` ###
Receive an RTP packet.
```
int RTPSessionReceive(struct RTPSession *session, size_t size, void *payload, struct RTPPacketInfo *info);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| session  | The session.    |
| size     | The number of available bytes in the `payload` buffer.  |
| payload  | The buffer to store the payload in.  |
| info     | The packet info.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | On success.     |
| >0        | If the message could not be received.  |