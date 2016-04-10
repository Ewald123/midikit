# MIDIEvent #
A basic event consisting of an id, a message and arbitary optional data.
```

struct MIDIEvent;
```





---

## Creation and destruction ##
Creating, destroying and reference counting of [MIDIEvent](struct_m_i_d_i_event.md) objects.


---


### `struct MIDIEvent * MIDIEventCreate` ###
Create a [MIDIEvent](struct_m_i_d_i_event.md) instance.
```
struct MIDIEvent * MIDIEventCreate(size_t id, void *info, char *message,...);
```

Allocate space and initialize a [MIDIEvent](struct_m_i_d_i_event.md) instance.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| id       | A (hopefully) unique ID.  |
| info     | Any optional data to be associated with the event.  |
| message  | A message format that may contain placeholders.  |
| ...      | The data to be filled into the message format placeholders. (Refer to the sprintf specification for details.)  |

#### Return ####
a pointer to the created event structure on success. a `NULL` pointer if the event could not created.


---


### `void MIDIEventDestroy` ###
Destroy a [MIDIEvent](struct_m_i_d_i_event.md) instance.
```
void MIDIEventDestroy(struct MIDIEvent *event);
```

Free all resources occupied by the event and release all referenced objects.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| event    | The event.      |



---


### `void MIDIEventRetain` ###
Retain a [MIDIEvent](struct_m_i_d_i_event.md) instance.
```
void MIDIEventRetain(struct MIDIEvent *event);
```

Increment the reference counter of an event so that it won't be destroyed.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| event    | The event.      |



---


### `void MIDIEventRelease` ###
Release a [MIDIEvent](struct_m_i_d_i_event.md) instance.
```
void MIDIEventRelease(struct MIDIEvent *event);
```

Decrement the reference counter of an event. If the reference count reached zero, destroy the event.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| event    | The event.      |



---

## Property access ##
Acces properties of MIDIEvents


---


### `int MIDIEventGetId` ###
Get the event identifier.
```
int MIDIEventGetId(struct MIDIEvent *event, size_t *id);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| event    | The event.      |
| id       | The ID.         |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |



---


### `int MIDIEventGetInfo` ###
Get the event info-object.
```
int MIDIEventGetInfo(struct MIDIEvent *event, void **info);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| event    | The event.      |
| info     | The info.       |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |



---

## Coding ##
Encoding and decoding of [MIDIEvent](struct_m_i_d_i_event.md) objects.


---


### `int MIDIEventEncode` ###
Encode events.
```
int MIDIEventEncode(struct MIDIEvent *event, size_t size, void *buffer, size_t *written);
```

Encode an event to a buffer.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| event    | The event.      |
| size     | The size of the memory pointed to by `buffer`.  |
| buffer   | The buffer to encode the event into.  |
| written  | The number of bytes that have been written.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the event could not be encoded.  |



---


### `int MIDIEventDecode` ###
Decode events.
```
int MIDIEventDecode(struct MIDIEvent *event, size_t size, void *buffer, size_t *read);
```

Decode event objects from a buffer.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| event    | The event.      |
| size     | The size of the memory pointed to by `buffer`.  |
| buffer   | The buffer to decode the event from.  |
| read     | The number of bytes that were actually read.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the event could not be encoded.  |