# MIDIMessageQueue #
Queue for MIDI message objects.
```

struct MIDIMessageQueue;
```





---

## Public Attributes ##


### `home jpommerening Private midikit midi message_queue c size_t MIDIMessageQueue::refs` ###


### `size_t MIDIMessageQueue::length` ###


### `struct MIDIMessageList* MIDIMessageQueue::first` ###


### `struct MIDIMessageList* MIDIMessageQueue::last` ###



---

## Creation and destruction ##
Creating, destroying and reference counting of [MIDIMessageQueue](struct_m_i_d_i_message_queue.md) objects.


---


### `struct MIDIMessageQueue * MIDIMessageQueueCreate` ###
Create a [MIDIMessageQueue](struct_m_i_d_i_message_queue.md) instance.
```
struct MIDIMessageQueue * MIDIMessageQueueCreate();
```

Allocate space and initialize a [MIDIMessageQueue](struct_m_i_d_i_message_queue.md) instance.


#### Return ####
a pointer to the created device structure on success. a `NULL` pointer if the device could not created.


---


### `void MIDIMessageQueueDestroy` ###
Destroy a [MIDIMessageQueue](struct_m_i_d_i_message_queue.md) instance.
```
void MIDIMessageQueueDestroy(struct MIDIMessageQueue *queue);
```

Free all resources occupied by the queue and release all referenced messages.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| queue    | The message queue.  |



---


### `void MIDIMessageQueueRetain` ###
Retain a [MIDIMessageQueue](struct_m_i_d_i_message_queue.md) instance.
```
void MIDIMessageQueueRetain(struct MIDIMessageQueue *queue);
```

Increment the reference counter of a message queue so that it won't be destroyed.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| queue    | The message queue.  |



---


### `void MIDIMessageQueueRelease` ###
Release a [MIDIMessageQueue](struct_m_i_d_i_message_queue.md) instance.
```
void MIDIMessageQueueRelease(struct MIDIMessageQueue *queue);
```

Decrement the reference counter of a message queue. If the reference count reached zero, destroy the message queue.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| queue    | The message queue.  |



---

## Queueing operations ##
Basic queue operations to store and retrieve messages.


---


### `int MIDIMessageQueueGetLength` ###
Get the length of a message queue.
```
int MIDIMessageQueueGetLength(struct MIDIMessageQueue *queue, size_t *length);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| queue    | The message queue.  |
| length   | The length.     |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the length could not be determined.  |



---


### `int MIDIMessageQueuePush` ###
Add a message to the end queue.
```
int MIDIMessageQueuePush(struct MIDIMessageQueue *queue, struct MIDIMessage *message);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| queue    | The message queue.  |
| message  | The message.    |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the item could not be added.  |



---


### `int MIDIMessageQueuePeek` ###
Get the message at the beginning of the queue but do not remove it.
```
int MIDIMessageQueuePeek(struct MIDIMessageQueue *queue, struct MIDIMessage **message);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| queue    | The message queue.  |
| message  | The message.    |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the item could not be fetched.  |



---


### `int MIDIMessageQueuePop` ###
Remove the first message in the queue and store it.
```
int MIDIMessageQueuePop(struct MIDIMessageQueue *queue, struct MIDIMessage **message);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| queue    | The queue.      |
| message  | The message.    |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the item could not be fetched or removed.  |