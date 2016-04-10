# MIDIPort #
Endpoint for message based communication.
```
#include <port.h>

struct MIDIPort;
```





---

## Creation and destruction ##
Creating, destroying and reference counting of [MIDIDriver](struct_m_i_d_i_driver.md) objects.


---


### `struct MIDIPort * MIDIPortCreate` ###
Create a [MIDIPort](struct_m_i_d_i_port.md) instance.
```
struct MIDIPort * MIDIPortCreate(char *name, int mode, void *target, int(*receive)(void *, void *, struct MIDITypeSpec *, void *));
```

Allocate space and initialize a [MIDIPort](struct_m_i_d_i_port.md) instance.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| name     | The name of the [MIDIPort](struct_m_i_d_i_port.md).  |
| mode     | The communication mode flags.  |
| target   | The target for receiving messages.  |
| receive  | The callback for incoming messages.  |

#### Return ####
a pointer to the created port structure on success. a `NULL` pointer if the port could not created.


---


### `void MIDIPortDestroy` ###
Destroy a [MIDIPort](struct_m_i_d_i_port.md) instance.
```
void MIDIPortDestroy(struct MIDIPort *port);
```

Free all resources occupied by the port and release connected ports.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| port     | The port.       |



---


### `void MIDIPortRetain` ###
Retain a [MIDIPort](struct_m_i_d_i_port.md) instance.
```
void MIDIPortRetain(struct MIDIPort *port);
```

Increment the reference counter of a port so that it won't be destroyed.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| port     | The port.       |



---


### `void MIDIPortRelease` ###
Release a [MIDIPort](struct_m_i_d_i_port.md) instance.
```
void MIDIPortRelease(struct MIDIPort *port);
```

Decrement the reference counter of a port. If the reference count reached zero, destroy the port. Before decrementing the reference count check for invalidated connected ports and remove them to break retain cycles.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| port     | The port.       |



---

## Connection management and message passing ##
Methods to connect ports and pass messages between them.


---


### `int MIDIPortConnect` ###
Connect a port to another port.
```
int MIDIPortConnect(struct MIDIPort *port, struct MIDIPort *target);
```

Connect a target port to a source port so that the target port will receive messages sent from the source port.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| port     | The source port.  |
| target   | The target port.  |



---


### `int MIDIPortDisconnect` ###
Disconnect a port from another port.
```
int MIDIPortDisconnect(struct MIDIPort *port, struct MIDIPort *target);
```

Disconnect a connected port from another port.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| port     | The source port.  |
| target   | The target port.  |



---


### `int MIDIPortDisconnectAll` ###
Disconnect all ports from another port.
```
int MIDIPortDisconnectAll(struct MIDIPort *port);
```

Disconnect all connected ports from another port.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| port     | The source port.  |



---


### `int MIDIPortInvalidate` ###
Invalidate the port.
```
int MIDIPortInvalidate(struct MIDIPort *port);
```

This has to be called by the instance that created the port, when it is being destroyed or no longer available. A port that has been invalidated will never again dereference the `target` pointer that was passed during creation or call the given `receive` function.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| port     | The port to invalidate.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |



---


### `int MIDIPortSetObserver` ###
Set the observer of a port.
```
int MIDIPortSetObserver(struct MIDIPort *port, void *target, MIDIPortInterceptFn *intercept);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| port     | The port.       |
| target   | The target (observer) to be called for each event.  |
| intercept | The interceptor function.  |



---


### `int MIDIPortGetObserver` ###
Get the observer of a port.
```
int MIDIPortGetObserver(struct MIDIPort *port, void **target, MIDIPortInterceptFn **intercept);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| port     | The port.       |
| target   | The target (observer) to be called for each event.  |
| intercept | The interceptor function.  |



---


### `int MIDIPortReceiveFrom` ###
Simulate an incoming message that was sent by another port.
```
int MIDIPortReceiveFrom(struct MIDIPort *port, struct MIDIPort *source, struct MIDITypeSpec *type, void *object);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| port     | The target port.  |
| source   | The source port.  |
| type     | The message type that was received.  |
| object   | The message data that was received.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |



---


### `int MIDIPortReceive` ###
Simulate an incoming message.
```
int MIDIPortReceive(struct MIDIPort *port, struct MIDITypeSpec *type, void *object);
```

This is called whenever the port receives a new message and can be used to simulate an incoming message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| port     | The target port.  |
| type     | The message type that was received.  |
| object   | The message data that was received.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |



---


### `int MIDIPortSendTo` ###
Send a message to another port.
```
int MIDIPortSendTo(struct MIDIPort *port, struct MIDIPort *target, struct MIDITypeSpec *type, void *object);
```

Send the given message to any other port. The target port does not have to be connected to the source port.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| port     | The source port.  |
| target   | The target port.  |
| type     | The message type to send.  |
| object   | The message data to send.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |



---


### `int MIDIPortSend` ###
Send the given message to all connected ports.
```
int MIDIPortSend(struct MIDIPort *port, struct MIDITypeSpec *type, void *object);
```

Use the apply mechanism of the list to send the given message to all connected ports.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| port     | The source port.  |
| type     | The message type to send.  |
| object   | The message data to send.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |



---

## Related ##



---


### `MIDI_TYPE_SPEC_OBJECT` ###
Declare the MIDIPortType type specification.
```
MIDI_TYPE_SPEC_OBJECT( MIDIPort, 0x3000 );
```