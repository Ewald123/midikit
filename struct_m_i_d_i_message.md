# MIDIMessage #
Structure of MIDI message object.
```
#include <message.h>

struct MIDIMessage;
```





---

## Creation and destruction ##
Creating, destroying and reference counting of [MIDIMessage](struct_m_i_d_i_message.md) objects.


---


### `struct MIDIMessage * MIDIMessageCreate` ###
Create a [MIDIMessage](struct_m_i_d_i_message.md) instance.
```
struct MIDIMessage * MIDIMessageCreate(MIDIStatus status);
```

Allocate space and initialize a [MIDIMessage](struct_m_i_d_i_message.md) instance.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| status   | The message status to be used for initialization.  |

#### Return ####
a pointer to the created message structure on success. a `NULL` pointer if the message could not created.


---


### `void MIDIMessageDestroy` ###
Destroy a [MIDIMessage](struct_m_i_d_i_message.md) instance.
```
void MIDIMessageDestroy(struct MIDIMessage *message);
```

Free all resources occupied by the message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| message  | The message.    |



---


### `void MIDIMessageRetain` ###
Retain a [MIDIMessage](struct_m_i_d_i_message.md) instance.
```
void MIDIMessageRetain(struct MIDIMessage *message);
```

Increment the reference counter of a message so that it won't be destroyed.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| message  | The message.    |



---


### `void MIDIMessageRelease` ###
Release a [MIDIMessage](struct_m_i_d_i_message.md) instance.
```
void MIDIMessageRelease(struct MIDIMessage *message);
```

Decrement the reference counter of a message. If the reference count reached zero, destroy the message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| message  | The message.    |



---

## Property access ##
Get and set message properties.


---


### `int MIDIMessageSetStatus` ###

```
int MIDIMessageSetStatus(struct MIDIMessage *message, MIDIStatus status);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| message  | The message.    |
| status   | The MIDIStatus.  |



---


### `int MIDIMessageGetStatus` ###

```
int MIDIMessageGetStatus(struct MIDIMessage *message, MIDIStatus *status);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| message  | The message.    |
| status   | The MIDIStatus.  |



---


### `int MIDIMessageSetTimestamp` ###

```
int MIDIMessageSetTimestamp(struct MIDIMessage *message, MIDITimestamp timestamp);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| message  | The message.    |
| timestamp | The MIDITimestamp.  |



---


### `int MIDIMessageGetTimestamp` ###

```
int MIDIMessageGetTimestamp(struct MIDIMessage *message, MIDITimestamp *timestamp);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| message  | The message.    |
| timestamp | The MIDITimestamp.  |



---


### `int MIDIMessageGetSize` ###

```
int MIDIMessageGetSize(struct MIDIMessage *message, size_t *size);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| message  | The message.    |
| size     | The size.       |



---


### `int MIDIMessageSet` ###
Set properties.
```
int MIDIMessageSet(struct MIDIMessage *message, MIDIProperty property, size_t size, void *value);
```

Set properties of the message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| message  | The message.    |
| property | The property to set.  |
| size     | The size of the memory object pointed to by `value`.  |
| value    | A pointer to the memory object who's contents shall be copied to the message property.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the property was not set.  |



---


### `int MIDIMessageGet` ###
Get properties.
```
int MIDIMessageGet(struct MIDIMessage *message, MIDIProperty property, size_t size, void *value);
```

Get properties of the message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| message  | The message.    |
| property | The property to get.  |
| size     | The size of the memory object pointed to by `value`.  |
| value    | A pointer to the memory object who's contents shall be copied from the message property.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the value was not set.  |



---

## Message coding ##
Methods for encoding and decoding midi message objects.


---


### `int MIDIMessageEncode` ###
Encode messages.
```
int MIDIMessageEncode(struct MIDIMessage *message, size_t size, unsigned char *buffer, size_t *written);
```

Encode message objects into a buffer.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| message  | The message.    |
| size     | The size of the memory pointed to by `buffer`.  |
| buffer   | The buffer to encode the message into.  |
| written  | The number of bytes that have been written.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be encoded.  |



---


### `int MIDIMessageListEncode` ###
Encode multiple messages at one.
```
int MIDIMessageListEncode(struct MIDIMessageList *messages, size_t size, unsigned char *buffer, size_t *written);
```

Encode multiple message objects into a buffer and use running status coding.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| messages | The list of messages.  |
| size     | The size of the memory pointed to by `buffer`.  |
| buffer   | The buffer to encode the message into.  |
| written  | The number of bytes that were actually written.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be encoded.  |