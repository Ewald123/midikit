# MIDIDriver #
Abstract class to send MIDI messages with various drivers.
```
#include <driver.h>

struct MIDIDriver;
```
The [MIDIDriver](struct_m_i_d_i_driver.md) is an abstract class / interface that can be used to pass messages to an underlying implementation. Extend this class by using it as the first member in your driver implementation structure. The C-standard asserts that there is no unnamed padding at the beginning of a struct. Extended structs can be used whereever a [MIDIDriver](struct_m_i_d_i_driver.md) struct is expected.




---

## Creation and destruction ##
Creating, destroying and reference counting of [MIDIDriver](struct_m_i_d_i_driver.md) objects.


---


### `struct MIDIDriver * MIDIDriverCreate` ###
Create a [MIDIDriver](struct_m_i_d_i_driver.md) instance.
```
struct MIDIDriver * MIDIDriverCreate(char *name, MIDISamplingRate rate);
```

Allocate space and initialize a [MIDIDriver](struct_m_i_d_i_driver.md) instance.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| name     | The name to identify the driver.  |
| rate     | The sampling rate to use.  |

#### Return ####
a pointer to the created driver structure on success. a `NULL` pointer if the driver could not created.


---


### `void MIDIDriverInit` ###
Initialize a [MIDIDriver](struct_m_i_d_i_driver.md) instance.
```
void MIDIDriverInit(struct MIDIDriver *driver, char *name, MIDISamplingRate rate);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| name     | The name to identify the driver.  |
| rate     | The sampling rate to use.  |



---


### `void MIDIDriverDestroy` ###
Destroy a [MIDIDriver](struct_m_i_d_i_driver.md) instance.
```
void MIDIDriverDestroy(struct MIDIDriver *driver);
```

Free all resources occupied by the driver and release all referenced objects.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| driver   | The driver.     |



---


### `void MIDIDriverRetain` ###
Retain a [MIDIDriver](struct_m_i_d_i_driver.md) instance.
```
void MIDIDriverRetain(struct MIDIDriver *driver);
```

Increment the reference counter of a driver so that it won't be destroyed.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| driver   | The driver.     |



---


### `void MIDIDriverRelease` ###
Release a [MIDIDriver](struct_m_i_d_i_driver.md) instance.
```
void MIDIDriverRelease(struct MIDIDriver *driver);
```

Decrement the reference counter of a driver. If the reference count reached zero, destroy the driver.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| driver   | The driver.     |



---

## Port access ##



---


### `int MIDIDriverGetPort` ###
Get the driver port.
```
int MIDIDriverGetPort(struct MIDIDriver *driver, struct MIDIPort **port);
```

Provide a port that can be used to send and receive MIDI messages using the driver. The port that is stored in `port` will have a retain count of one and should only be released by the user if it was retained before.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| driver   | The driver.     |
| port     | The port.       |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |



---

## Message passing ##
Receiving and sending [MIDIMessage](struct_m_i_d_i_message.md) objects.


---


### `int MIDIDriverMakeLoopback` ###
Make the [MIDIDriver](struct_m_i_d_i_driver.md) implement itself as loopback.
```
int MIDIDriverMakeLoopback(struct MIDIDriver *driver);
```

The driver's callback will be modified so that it passes outgoing messages to it's own receive method.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| driver   | The driver      |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the operation could not be completed.  |



---


### `int MIDIDriverReceive` ###
Receive a generic [MIDIMessage](struct_m_i_d_i_message.md).
```
int MIDIDriverReceive(struct MIDIDriver *driver, struct MIDIMessage *message);
```

Relay an incoming message via all attached receiving ports. This should be called by the driver implementation whenever a new message was received.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| driver   | The driver.     |
| message  | The message.    |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the message could not be relayed.  |



---


### `int MIDIDriverSend` ###
Send a generic [MIDIMessage](struct_m_i_d_i_message.md).
```
int MIDIDriverSend(struct MIDIDriver *driver, struct MIDIMessage *message);
```

Pass an outgoing message (through the port) to the implementation. The implementation's `send` callback is responsible for sending the message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| driver   | The driver.     |
| message  | The message.    |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the message could not be sent.  |



---


### `int MIDIDriverTriggerEvent` ###
Trigger an event that occured in the driver implementation.
```
int MIDIDriverTriggerEvent(struct MIDIDriver *driver, struct MIDIEvent *event);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| driver   | The driver.     |
| event    | The event.      |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |



---

## Private Functions ##



---


### `static int _port_receive` ###
Port callback.
```
static int _port_receive(void *target, void *source, struct MIDITypeSpec *type, void *object);
```

This may be confusing at first but when the driver receives a message on it's port it has to send the message using it's implementation. This is because the port receives messages from (virtual) MIDIDevices when these devices send a message through their own ports.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| target   | The target of the port callback, the driver itself.  |
| source   | The source that sended the message.  |
| type     | The type of the message that was received.  |
| object   | The actual message object that was received.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |