# RTPPeer #
A control structure to manage the connection to an RTP peer.
```

struct RTPPeer;
```





---

## Public Attributes ##


### `size_t RTPPeer::refs` ###


### `struct RTPAddress RTPPeer::address` ###


### `unsigned long RTPPeer::in_timestamp` ###


### `unsigned long RTPPeer::out_timestamp` ###


### `unsigned long RTPPeer::in_seqnum` ###


### `unsigned long RTPPeer::out_seqnum` ###


### `void* RTPPeer::info` ###



---

## Public Functions ##



---


### `struct RTPPeer * RTPPeerCreate` ###
Create an [RTPPeer](struct_r_t_p_peer.md) instance.
```
struct RTPPeer * RTPPeerCreate(unsigned long ssrc, socklen_t size, struct sockaddr *addr);
```

Allocate space and initialize an [RTPPeer](struct_r_t_p_peer.md) instance.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| ssrc     | The synchronization source identifier that uniquely identifies the peer.  |
| size     | The size of the address pointed to by `addr`.  |
| addr     | A pointer to an address that can be used to send packets to the client.  |

#### Return ####
a pointer to the created peer structure on success. a `NULL` pointer if the peer could not created.


---


### `void RTPPeerDestroy` ###
Destroy an [RTPPeer](struct_r_t_p_peer.md) instance.
```
void RTPPeerDestroy(struct RTPPeer *peer);
```

Free all resources occupied by the peer.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| peer     | The peer.       |



---


### `void RTPPeerRetain` ###
Retain an [RTPPeer](struct_r_t_p_peer.md) instance.
```
void RTPPeerRetain(struct RTPPeer *peer);
```

Increment the reference counter of a peer so that it won't be destroyed.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| peer     | The peer.       |



---


### `void RTPPeerRelease` ###
Release an [RTPPeer](struct_r_t_p_peer.md) instance.
```
void RTPPeerRelease(struct RTPPeer *peer);
```

Decrement the reference counter of a peer. If the reference count reached zero, destroy the peer.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| peer     | The peer.       |



---


### `int RTPPeerGetSSRC` ###
Get the synchronization source identifier of a peer.
```
int RTPPeerGetSSRC(struct RTPPeer *peer, unsigned long *ssrc);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| peer     | The peer.       |
| ssrc     | The synchronization source.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the SSRC could not be obtained.  |



---


### `int RTPPeerGetAddress` ###
Obtain the size of the address and a pointer to it's content.
```
int RTPPeerGetAddress(struct RTPPeer *peer, socklen_t *size, struct sockaddr **addr);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| peer     | The peer.       |
| size     | The size.       |
| addr     | The address.    |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the address could not be obtained.  |



---


### `int RTPPeerSetInfo` ###
Set the internal info pointer.
```
int RTPPeerSetInfo(struct RTPPeer *peer, void *info);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| peer     | The peer.       |
| info     | The info.       |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the info could not be changed.  |



---


### `int RTPPeerGetInfo` ###
Obtain a pointer to the info structure of a peer.
```
int RTPPeerGetInfo(struct RTPPeer *peer, void **info);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| peer     | The peer.       |
| info     | The info.       |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the info could not be obtained.  |