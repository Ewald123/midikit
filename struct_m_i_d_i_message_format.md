# MIDIMessageFormat #
Message format descriptor.
```
#include <message_format.h>

struct MIDIMessageFormat;
```
Contains pointers to functions that access messages of a certain type. [MIDIMessageData](struct_m_i_d_i_message_data.md)




---

## Public Attributes ##


### `int(* MIDIMessageFormat::test)(void *buffer)` ###


### `int(* MIDIMessageFormat::size)(struct MIDIMessageData *data, size_t *size)` ###


### `int(* MIDIMessageFormat::set)(struct MIDIMessageData *data, MIDIProperty property, size_t size, void *value)` ###


### `int(* MIDIMessageFormat::get)(struct MIDIMessageData *data, MIDIProperty property, size_t size, void *value)` ###


### `int(* MIDIMessageFormat::encode)(struct MIDIMessageData *data, MIDIRunningStatus *status, size_t size, void *buffer, size_t *written)` ###


### `int(* MIDIMessageFormat::decode)(struct MIDIMessageData *data, MIDIRunningStatus *status, size_t size, void *buffer, size_t *read)` ###



---

## Message coding ##
Methods for encoding and decoding midi message objects.


---


### `int MIDIMessageDecode` ###
Decode messages.
```
int MIDIMessageDecode(struct MIDIMessage *message, size_t size, unsigned char *buffer, size_t *read);
```

Decode message objects from a buffer.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| message  | The message.    |
| size     | The size of the memory pointed to by `buffer`.  |
| buffer   | The buffer to decode the message from.  |
| read     | The number of bytes that were actually read.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be encoded.  |



---


### `int MIDIMessageEncodeRunningStatus` ###
Encode messages with running status.
```
int MIDIMessageEncodeRunningStatus(struct MIDIMessage *message, MIDIRunningStatus *status, size_t size, unsigned char *buffer, size_t *written);
```

Encode message objects into a buffer. Use the running status and update it if necessary.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| message  | The message.    |
| status   | A pointer to the running status.  |
| size     | The size of the memory pointed to by `buffer`.  |
| buffer   | The buffer to decode the message from.  |
| written  | The number of bytes that were actually written.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be encoded.  |



---


### `int MIDIMessageDecodeRunningStatus` ###
Decode messages with running status.
```
int MIDIMessageDecodeRunningStatus(struct MIDIMessage *message, MIDIRunningStatus *status, size_t size, unsigned char *buffer, size_t *read);
```

Decode message objects from a buffer. Use the running status and update it if necessary.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| message  | The message.    |
| status   | A pointer to the running status.  |
| size     | The size of the memory pointed to by `buffer`.  |
| buffer   | The buffer to decode the message from.  |
| read     | The number of bytes that were actually read.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be encoded.  |



---


### `int MIDIMessageListDecode` ###
Decode multiple messages at once.
```
int MIDIMessageListDecode(struct MIDIMessageList *messages, size_t size, unsigned char *buffer, size_t *read);
```

Decode multiple message objects from a buffer and use running status coding.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| messages | The list of messages.  |
| size     | The size of the memory pointed to by `buffer`.  |
| buffer   | The buffer to decode the message from.  |
| read     | The number of bytes that were actually read.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be encoded.  |



---

## Public Functions ##



---


### `struct MIDIMessageFormat * MIDIMessageFormatDetect` ###
Detect the format of message stored in a buffer.
```
struct MIDIMessageFormat * MIDIMessageFormatDetect(void *buffer);
```

Determine the message format used in a stream of bytes.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| buffer   | The message as it would appear on a MIDI cable.  |

#### Return ####
a pointer to the correct message format if the format could be detected. a NULL pointer if the format could not be detected.


---


### `struct MIDIMessageFormat * MIDIMessageFormatDetectRunningStatus` ###
Detect the format of message stored in a buffer.
```
struct MIDIMessageFormat * MIDIMessageFormatDetectRunningStatus(void *buffer, MIDIRunningStatus *status);
```

Determine the message format used in a stream of bytes but check for running status as well.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| buffer   | The message as it would appear on a MIDI cable.  |
| status   | The running status to use if the buffer does not contain a status byte.  |

#### Return ####
a pointer to the correct message format if the format could be detected. a NULL pointer if the format could not be detected.


---


### `struct MIDIMessageFormat * MIDIMessageFormatForStatus` ###
Get a format used for a given status.
```
struct MIDIMessageFormat * MIDIMessageFormatForStatus(MIDIStatus status);
```

Determine the format that shall be used when accessing messages of a known status. If the status byte looks like a channel status it is correctly shifted so that the correct byte can be checked by MIDIMessageFormatDetect. [MIDIMessageFormatDetect](struct_m_i_d_i_message_format_1a1431f58ae5260ccd0072f0d72f064990.md)
#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| status   | A message status.  |

#### Return ####
a pointer to the correct message format if the format could be detected. a NULL pointer if the format could not be detected or if the given status is not an allowed MIDIStatus.


---


### `int MIDIMessageFormatTest` ###
Test that the format can be used for a given buffer.
```
int MIDIMessageFormatTest(struct MIDIMessageFormat *format, void *buffer);
```

Test that the format specified by `format` can be used to decode the bytes in the buffer.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| format   | The message format.  |
| buffer   | A pointer to the buffer to test.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | If the format can not be used to access the buffer.  |



---


### `int MIDIMessageFormatGetSize` ###
Get the size of a given message.
```
int MIDIMessageFormatGetSize(struct MIDIMessageFormat *format, struct MIDIMessageData *data, size_t *size);
```

Determine the size of a given message data object using a given message format. This is constant for all messages except system exclusive messages.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| format   | The message format.  |
| data     | The message data.  |
| size     | A pointer to the variable in which to store the result.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | If the size could not be determined.  |



---


### `int MIDIMessageFormatSet` ###
Set properties.
```
int MIDIMessageFormatSet(struct MIDIMessageFormat *format, struct MIDIMessageData *data, MIDIProperty property, size_t size, void *value);
```

Set properties of messages with a given format.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| format   | The message format.  |
| data     | The message data object to write to.  |
| property | The property to set.  |
| size     | The size of the memory object pointed to by `value`.  |
| value    | A pointer to the memory object who's contents shall be copied to the message property.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the property was not set.  |



---


### `int MIDIMessageFormatGet` ###
Get properties.
```
int MIDIMessageFormatGet(struct MIDIMessageFormat *format, struct MIDIMessageData *data, MIDIProperty property, size_t size, void *value);
```

Get properties of messages with a given format.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| format   | The message format.  |
| data     | The message data object to read from.  |
| property | The property to get.  |
| size     | The size of the memory object pointed to by `value`.  |
| value    | A pointer to the memory object who's contents shall be copied from the message property.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the value was not set.  |



---


### `int MIDIMessageFormatEncodeRunningStatus` ###
Encode messages with running status byte.
```
int MIDIMessageFormatEncodeRunningStatus(struct MIDIMessageFormat *format, struct MIDIMessageData *data, MIDIRunningStatus *status, size_t size, void *buffer, size_t *written);
```

Encode message data objects into a buffer.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| format   | The message format.  |
| data     | The message data object to read from.  |
| status   | The running status inherited from previous messages.  |
| size     | The size of the memory pointed to by `buffer`.  |
| buffer   | The buffer to encode the message into.  |
| written  | The number of bytes that were written to the `buffer`.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be encoded.  |



---


### `int MIDIMessageFormatDecodeRunningStatus` ###
Decode messages with running status byte.
```
int MIDIMessageFormatDecodeRunningStatus(struct MIDIMessageFormat *format, struct MIDIMessageData *data, MIDIRunningStatus *status, size_t size, void *buffer, size_t *read);
```

Decode message data objects from a buffer.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| format   | The message format.  |
| data     | The message data object to read from.  |
| status   | The running status inherited from previous messages.  |
| size     | The size of the memory pointed to by `buffer`.  |
| buffer   | The buffer to decode the message from.  |
| read     | The number of bytes that were read from the `buffer`.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be encoded.  |



---


### `int MIDIMessageFormatEncode` ###
Encode messages.
```
int MIDIMessageFormatEncode(struct MIDIMessageFormat *format, struct MIDIMessageData *data, size_t size, void *buffer, size_t *written);
```

Encode message data objects into a buffer.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| format   | The message format.  |
| data     | The message data object to read from.  |
| size     | The size of the memory pointed to by `buffer`.  |
| buffer   | The buffer to encode the message into.  |
| written  | The number of bytes that were written to the `buffer`.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be encoded.  |



---


### `int MIDIMessageFormatDecode` ###
Decode messages.
```
int MIDIMessageFormatDecode(struct MIDIMessageFormat *format, struct MIDIMessageData *data, size_t size, void *buffer, size_t *read);
```

Decode message data objects from a buffer.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| format   | The message format.  |
| data     | The message data object to read from.  |
| size     | The size of the memory pointed to by `buffer`.  |
| buffer   | The buffer to decode the message from.  |
| read     | The number of bytes that were read from the `buffer`.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be encoded.  |