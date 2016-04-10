# MIDIDevice #
An abstract MIDI device.
```
#include <device.h>

struct MIDIDevice;
```
The [MIDIDevice](struct_m_i_d_i_device.md) class provides a skeleton for customized MIDI devices. Standardized functionality can be plugged in by using [MIDITimer](struct_m_i_d_i_timer.md), [MIDIController](struct_m_i_d_i_controller.md) and MIDIInstrument objects. Every [MIDIDevice](struct_m_i_d_i_device.md) is equipped with an input, an output and a thru-port that forwards every [MIDIMessage](struct_m_i_d_i_message.md) received on the input.




---

## Creation and destruction ##
Creating, destroying and reference counting of [MIDIDevice](struct_m_i_d_i_device.md) objects.


---


### `struct MIDIDevice * MIDIDeviceCreate` ###
Create a [MIDIDevice](struct_m_i_d_i_device.md) instance.
```
struct MIDIDevice * MIDIDeviceCreate(struct MIDIDeviceDelegate *delegate);
```

Allocate space and initialize a [MIDIDevice](struct_m_i_d_i_device.md) instance.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| delegate | The delegate to use for the device. May be `NULL`.  |

#### Return ####
a pointer to the created device structure on success. a `NULL` pointer if the device could not created.


---


### `void MIDIDeviceDestroy` ###
Destroy a [MIDIDevice](struct_m_i_d_i_device.md) instance.
```
void MIDIDeviceDestroy(struct MIDIDevice *device);
```

Free all resources occupied by the device and release all referenced objects.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The device.     |



---


### `void MIDIDeviceRetain` ###
Retain a [MIDIDevice](struct_m_i_d_i_device.md) instance.
```
void MIDIDeviceRetain(struct MIDIDevice *device);
```

Increment the reference counter of a device so that it won't be destroyed.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The device.     |



---


### `void MIDIDeviceRelease` ###
Release a [MIDIDevice](struct_m_i_d_i_device.md) instance.
```
void MIDIDeviceRelease(struct MIDIDevice *device);
```

Decrement the reference counter of a device. If the reference count reached zero, destroy the device.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The device.     |



---

## Port access ##
Methods to access the devices `IN`, `OUT` and `THRU` ports.


---


### `int MIDIDeviceGetInputPort` ###
Get the device's `IN` port.
```
int MIDIDeviceGetInputPort(struct MIDIDevice *device, struct MIDIPort **port);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The device.     |
| port     | The `IN` port.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |



---


### `int MIDIDeviceGetOutputPort` ###
Get the device's `OUT` port.
```
int MIDIDeviceGetOutputPort(struct MIDIDevice *device, struct MIDIPort **port);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The device.     |
| port     | The `OUT` port.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |



---


### `int MIDIDeviceGetThroughPort` ###
Get the device's `THRU` port.
```
int MIDIDeviceGetThroughPort(struct MIDIDevice *device, struct MIDIPort **port);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The device.     |
| port     | The `THRU` port.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |



---

## Deprecated connector attachment functions ##



---


### `int MIDIDeviceDetachIn` ###

```
int MIDIDeviceDetachIn(struct MIDIDevice *device);
```

DeprecatedUse ports instead.


---


### `int MIDIDeviceAttachIn` ###

```
int MIDIDeviceAttachIn(struct MIDIDevice *device, struct MIDIPort *port);
```

DeprecatedUse ports instead.


---


### `int MIDIDeviceDetachOut` ###

```
int MIDIDeviceDetachOut(struct MIDIDevice *device);
```

DeprecatedUse ports instead.


---


### `int MIDIDeviceAttachOut` ###

```
int MIDIDeviceAttachOut(struct MIDIDevice *device, struct MIDIPort *port);
```

DeprecatedUse ports instead.


---


### `int MIDIDeviceDetachThru` ###

```
int MIDIDeviceDetachThru(struct MIDIDevice *device);
```

DeprecatedUse ports instead.


---


### `int MIDIDeviceAttachThru` ###

```
int MIDIDeviceAttachThru(struct MIDIDevice *device, struct MIDIPort *port);
```

DeprecatedUse ports instead.


---

## Property access ##
Get and set device properties.


---


### `int MIDIDeviceSetBaseChannel` ###
Set the device's base channel.
```
int MIDIDeviceSetBaseChannel(struct MIDIDevice *device, MIDIChannel channel);
```

Every MIDI device has a base channel. The base channel is used to reply to certain messages like the "Control Change" message for MIDI-Modes "Omni" and "Polyphonic". Even in Omni-Mode the device expects to receive those messages only on the base channel.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The device.     |
| channel  | The base channel.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the base channel coult not be set.  |



---


### `int MIDIDeviceGetBaseChannel` ###
Get the device's base channel.
```
int MIDIDeviceGetBaseChannel(struct MIDIDevice *device, MIDIChannel *channel);
```

[MIDIDeviceSetBaseChannel](struct_m_i_d_i_device_1ad1b1d03751dee307ea1035e122dc193a.md)
#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The device.     |
| channel  | The base channel.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the base channel coult not be stored.  |



---


### `int MIDIDeviceSetTimer` ###
Set the device's timer.
```
int MIDIDeviceSetTimer(struct MIDIDevice *device, struct MIDITimer *timer);
```

The device's timer is responsible for following real time messages to approximate the message sender's midi time and clock rate. It is used to obtain timestamps for outgoing messages. [MIDIDeviceSetTimer](struct_m_i_d_i_device_1a0417092eaf955832f527094c24455e7c.md)
#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The device.     |
| timer    | The timer.      |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the timer could not be set.  |



---


### `int MIDIDeviceGetTimer` ###
Get the device's timer.
```
int MIDIDeviceGetTimer(struct MIDIDevice *device, struct MIDITimer **timer);
```

[MIDIDeviceSetTimer](struct_m_i_d_i_device_1a0417092eaf955832f527094c24455e7c.md)
#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The device.     |
| timer    | The timer.      |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the timer could not be stored.  |



---


### `int MIDIDeviceSetChannelController` ###
Set the controller for a specific channel.
```
int MIDIDeviceSetChannelController(struct MIDIDevice *device, MIDIChannel channel, struct MIDIController *controller);
```

Each channel can have it's own controller. A controller may be attached to multiple channels, even multiple devices.

The controller is retained by the device, once for each channel it is connected to. Thus if the controller is attached to 5 channels it is retained five times.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The midi device.  |
| channel  | The channel to attach the controller to. To attach the controller to the device's base channel use special MIDI\_CHANNEL\_BASE; to attach it to all channels at once, use MIDI\_CHANNEL\_ALL.  |
| controller | The controller to attach.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the controller could not be attached to the channel(s).  |



---


### `int MIDIDeviceGetChannelController` ###
Get the controller for a specific channel.
```
int MIDIDeviceGetChannelController(struct MIDIDevice *device, MIDIChannel channel, struct MIDIController **controller);
```

[MIDIDeviceSetChannelController](struct_m_i_d_i_device_1ae58670754b0f6eb1bd95dd96d0169787.md)
#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The midi device.  |
| channel  | The channel for which to get the controller.  |
| controller | The a pointer to the location to store the controller reference in.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the controller was not stored.  |



---

## Message passing ##
Receiving and and sending [MIDIMessage](struct_m_i_d_i_message.md) objects.


---


### `int MIDIDeviceReceive` ###
Receive a generic MIDI message.
```
int MIDIDeviceReceive(struct MIDIDevice *device, struct MIDIMessage *message);
```

This simulates a received message on the device's `IN` port.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The midi device.  |
| message  | The received message.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be processed.  |



---


### `int MIDIDeviceSend` ###
Send a generic MIDI message.
```
int MIDIDeviceSend(struct MIDIDevice *device, struct MIDIMessage *message);
```

This calls the the relay method of the `OUT` connector.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The device.     |
| message  | The message.    |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be sent.  |



---


### `int MIDIDeviceReceiveNoteOff` ###
Receive a "Note Off" message.
```
int MIDIDeviceReceiveNoteOff(struct MIDIDevice *device, MIDIChannel channel, MIDIKey key, MIDIVelocity velocity);
```

This is called whenever the device receives a "Note Off" message. It can be used to simulate the reception of such a message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The midi device.  |
| channel  | The channel on which the note ended.  |
| key      | The key that ended.  |
| velocity | The velocity with which the "key" was released.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be processed.  |



---


### `int MIDIDeviceSendNoteOff` ###
Send a "Note Off" message.
```
int MIDIDeviceSendNoteOff(struct MIDIDevice *device, MIDIChannel channel, MIDIKey key, MIDIVelocity velocity);
```

This is called when the device wants to send a "Note Off" message. It can be used to trigger the sending of such a message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The midi device.  |
| channel  | The channel on which the note ended.  |
| key      | The key that ended.  |
| velocity | The velocity with which the "key" was released.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be sent.  |



---


### `int MIDIDeviceReceiveNoteOn` ###
Receive a "Note On" message.
```
int MIDIDeviceReceiveNoteOn(struct MIDIDevice *device, MIDIChannel channel, MIDIKey key, MIDIVelocity velocity);
```

This is called whenever the device receives a "Note On" message. It can be used to simulate the reception of such a message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The midi device.  |
| channel  | The channel on which the note occurred.  |
| key      | The key that was played.  |
| velocity | The velocity with which the "key" was pressed.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be processed.  |



---


### `int MIDIDeviceSendNoteOn` ###
Send a "Note On" message.
```
int MIDIDeviceSendNoteOn(struct MIDIDevice *device, MIDIChannel channel, MIDIKey key, MIDIVelocity velocity);
```

This is called when the device wants to send a "Note On" message. It can be used to trigger the sending of such a message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The midi device.  |
| channel  | The channel on which the note occurred.  |
| key      | The key that was played.  |
| velocity | The velocity with which the "key" was pressed.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be sent.  |



---


### `int MIDIDeviceReceivePolyphonicKeyPressure` ###
Receive a "Polyphonic Key Pressure" message.
```
int MIDIDeviceReceivePolyphonicKeyPressure(struct MIDIDevice *device, MIDIChannel channel, MIDIKey key, MIDIPressure pressure);
```

This is called whenever the device receives a "Polyphonic Key Pressure" message. It can be used to simulate the reception of such a message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The midi device.  |
| channel  | The channel on which the pressure change occured.  |
| key      | The key that was played.  |
| pressure | The pressure applied to the "key".  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be processed.  |



---


### `int MIDIDeviceSendPolyphonicKeyPressure` ###
Send a "Polyphonic Key Pressure" message.
```
int MIDIDeviceSendPolyphonicKeyPressure(struct MIDIDevice *device, MIDIChannel channel, MIDIKey key, MIDIPressure pressure);
```

This is called when the device wants to send a "Polyphonic Key Pressure" message. It can be used to trigger the sending of such a message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The midi device.  |
| channel  | The channel on which the note occurred.  |
| key      | The key that was played.  |
| pressure | The pressure applied to the "key".  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be sent.  |



---


### `int MIDIDeviceReceiveControlChange` ###
Receive a "Control Change" message.
```
int MIDIDeviceReceiveControlChange(struct MIDIDevice *device, MIDIChannel channel, MIDIControl control, MIDIValue value);
```

This is called whenever the device receives a "Control Change" message. It can be used to simulate the reception of such a message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The midi device.  |
| channel  | The channel on which the control change occured.  |
| control  | The control that was changed.  |
| value    | The new value of the control.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be processed.  |



---


### `int MIDIDeviceSendControlChange` ###
Send a "Control Change" message.
```
int MIDIDeviceSendControlChange(struct MIDIDevice *device, MIDIChannel channel, MIDIControl control, MIDIValue value);
```

This is called when the device wants to send a "Control Change" message. It can be used to trigger the sending of such a message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The midi device.  |
| channel  | The channel on which the control change occured.  |
| control  | The control that was changed.  |
| value    | The new value of the control.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be sent.  |



---


### `int MIDIDeviceReceiveProgramChange` ###
Receive a "Program Change" message.
```
int MIDIDeviceReceiveProgramChange(struct MIDIDevice *device, MIDIChannel channel, MIDIProgram program);
```

This is called whenever the device receives a "Program Change" message. It can be used to simulate the reception of such a message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The midi device.  |
| channel  | The channel on which the program change occured.  |
| program  | The new program.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be processed.  |



---


### `int MIDIDeviceSendProgramChange` ###
Send a "Program Change" message.
```
int MIDIDeviceSendProgramChange(struct MIDIDevice *device, MIDIChannel channel, MIDIProgram program);
```

This is called when the device wants to send a "Program Change" message. It can be used to trigger the sending of such a message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The midi device.  |
| channel  | The channel on which the program change occured.  |
| program  | The new program.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be sent.  |



---


### `int MIDIDeviceReceiveChannelPressure` ###
Receive a "Channel Pressure" message.
```
int MIDIDeviceReceiveChannelPressure(struct MIDIDevice *device, MIDIChannel channel, MIDIPressure pressure);
```

This is called whenever the device receives a "Channel Pressure" message. It can be used to simulate the reception of such a message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The midi device.  |
| channel  | The channel on which the pressure change occured.  |
| pressure | The pressure applied to all notes currently played on the channel.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be processed.  |



---


### `int MIDIDeviceSendChannelPressure` ###
Send a "Channel Pressure" message.
```
int MIDIDeviceSendChannelPressure(struct MIDIDevice *device, MIDIChannel channel, MIDIPressure pressure);
```

This is called when the device wants to send a "Channel Pressure" message. It can be used to trigger the sending of such a message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The midi device.  |
| channel  | The channel on which the pressure change occured.  |
| pressure | The pressure applied to all notes currently played on the channel.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be sent.  |



---


### `int MIDIDeviceReceivePitchWheelChange` ###
Receive a "Pitch Wheel Change" message.
```
int MIDIDeviceReceivePitchWheelChange(struct MIDIDevice *device, MIDIChannel channel, MIDILongValue value);
```

This is called whenever the device receives a "Pitch Wheel Change" message. It can be used to simulate the reception of such a message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The midi device.  |
| channel  | The channel on which the pitch wheel change occured.  |
| value    | The amount of pitch-change of all notes played on the channel. (`0x2000` = Original pitch)  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be processed.  |



---


### `int MIDIDeviceSendPitchWheelChange` ###
Send a "Pitch Wheel Change" message.
```
int MIDIDeviceSendPitchWheelChange(struct MIDIDevice *device, MIDIChannel channel, MIDILongValue value);
```

This is called when the device wants to send a "Pitch Wheel Change" message. It can be used to trigger the sending of such a message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The midi device.  |
| channel  | The channel on which the pitch wheel change occured.  |
| value    | The amount of pitch-change of all notes played on the channel. (`0x2000` = Original pitch)  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be sent.  |



---


### `int MIDIDeviceReceiveSystemExclusive` ###
Receive a "System Exclusive" message.
```
int MIDIDeviceReceiveSystemExclusive(struct MIDIDevice *device, MIDIManufacturerId manufacturer_id, size_t size, void *data, uint8_t fragment);
```

This is called whenever the device receives a "System Exclusive" message. It can be used to simulate the reception of such a message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The midi device.  |
| manufacturer\_id | The ID of the manufacturer that defines the message syntax. (`0x7d` = Educational Use, `0x7e` = Non-Realtime Universal, `0x7f` = Realtime Universal)  |
| size     | The size of the buffer pointed to by `data`.  |
| data     | The system exclusive data. (`size` bytes)  |
| fragment | The fragment number of the system exclusive message, starting with zero. A message may be fragmented due to various reasons. A receiver should collect fragments until it receives an "End of Exclusive" message.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be processed.  |



---


### `int MIDIDeviceSendSystemExclusive` ###
Send a "System Exclusive" message.
```
int MIDIDeviceSendSystemExclusive(struct MIDIDevice *device, MIDIManufacturerId manufacturer_id, size_t size, void *data, uint8_t fragment);
```

This is called when the device wants to send a "System Exclusive" message. It can be used to trigger the sending of such a message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The midi device.  |
| manufacturer\_id | The ID of the manufacturer that defines the message syntax. (`0x7d` = Educational Use, `0x7e` = Non-Realtime Universal, `0x7f` = Realtime Universal)  |
| size     | The size of the buffer pointed to by `data`.  |
| data     | The system exclusive data. (`size` bytes)  |
| fragment | The fragment number of the system exclusive message, starting with zero. A message may be fragmented due to various reasons. A receiver should collect fragments until it receives an "End of Exclusive" message.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be sent.  |



---


### `int MIDIDeviceReceiveTimeCodeQuarterFrame` ###
Receive a "Time Code Quarter Frame" message.
```
int MIDIDeviceReceiveTimeCodeQuarterFrame(struct MIDIDevice *device, MIDIValue time_code_type, MIDIValue value);
```

This is called whenever the device receives a "Time Code Quarter Frame" message. It can be used to simulate the reception of such a message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The midi device.  |
| time\_code\_type | One of the eight code-types specified by the MIDI time code spec.  |
| value    | The 4-bit value for the given time code type.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be processed.  |



---


### `int MIDIDeviceSendTimeCodeQuarterFrame` ###
Send a "Time Code Quarter Frame" message.
```
int MIDIDeviceSendTimeCodeQuarterFrame(struct MIDIDevice *device, MIDIValue time_code_type, MIDIValue value);
```

This is called when the device wants to send a "Time Code Quarter Frame" message. It can be used to trigger the sending of such a message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The midi device.  |
| time\_code\_type | One of the eight code-types specified by the MIDI time code spec.  |
| value    | The 4-bit value for the given time code type.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be sent.  |



---


### `int MIDIDeviceReceiveSongPositionPointer` ###
Receive a "Song Position Pointer" message.
```
int MIDIDeviceReceiveSongPositionPointer(struct MIDIDevice *device, MIDILongValue value);
```

This is called whenever the device receives a "Song Position Pointer" message. It can be used to simulate the reception of such a message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The midi device.  |
| value    | A 14-bit value specifying a "beat" inside the current song or sequence. (1 beat = 1/16 note = 6 clocks)  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be processed.  |



---


### `int MIDIDeviceSendSongPositionPointer` ###
Send a "Song Position Pointer" message.
```
int MIDIDeviceSendSongPositionPointer(struct MIDIDevice *device, MIDILongValue value);
```

This is called when the device wants to send a "Song Position Pointer" message. It can be used to trigger the sending of such a message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The midi device.  |
| value    | A 14-bit value specifying a "beat" inside the current song or sequence. (1 beat = 1/16 note = 6 clocks)  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be sent.  |



---


### `int MIDIDeviceReceiveSongSelect` ###
Receive a "Song Select" message.
```
int MIDIDeviceReceiveSongSelect(struct MIDIDevice *device, MIDIValue value);
```

This is called whenever the device receives a "Song Select" message. It can be used to simulate the reception of such a message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The midi device.  |
| value    | The song or sequence number to select.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be processed.  |



---


### `int MIDIDeviceSendSongSelect` ###
Send a "Song Select" message.
```
int MIDIDeviceSendSongSelect(struct MIDIDevice *device, MIDIValue value);
```

This is called when the device wants to send a "Song Select" message. It can be used to trigger the sending of such a message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The midi device.  |
| value    | The song or sequence number to select.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be sent.  |



---


### `int MIDIDeviceReceiveTuneRequest` ###
Receive a "Tune Request" message.
```
int MIDIDeviceReceiveTuneRequest(struct MIDIDevice *device);
```

This is called whenever the device receives a "Tune Request" message. It can be used to simulate the reception of such a message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The midi device.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be processed.  |



---


### `int MIDIDeviceSendTuneRequest` ###
Send a "Tune Request" message.
```
int MIDIDeviceSendTuneRequest(struct MIDIDevice *device);
```

This is called when the device wants to send a "Tune Request" message. It can be used to trigger the sending of such a message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The midi device.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be sent.  |



---


### `int MIDIDeviceReceiveEndOfExclusive` ###
Receive an "End Of Exclusive" message.
```
int MIDIDeviceReceiveEndOfExclusive(struct MIDIDevice *device);
```

This is called whenever the device receives an "End Of Exclusive" message. It can be used to simulate the reception of such a message. [MIDIDeviceReceiveSystemExclusive](struct_m_i_d_i_device_1a6f390e0422202844b794e0ddcbe08153.md)
#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The midi device.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be processed.  |



---


### `int MIDIDeviceSendEndOfExclusive` ###
Send an "End Of Exclusive" message.
```
int MIDIDeviceSendEndOfExclusive(struct MIDIDevice *device);
```

This is called when the device wants to send an "End Of Exclusive" message. It can be used to trigger the sending of such a message. [MIDIDeviceReceiveSystemExclusive](struct_m_i_d_i_device_1a6f390e0422202844b794e0ddcbe08153.md)
#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The midi device.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be sent.  |



---


### `int MIDIDeviceReceiveRealTime` ###
Receive a "Real-Time" message.
```
int MIDIDeviceReceiveRealTime(struct MIDIDevice *device, MIDIStatus status, MIDITimestamp timestamp);
```

This is called whenever the device receives a "Real-Time" message. It can be used to simulate the reception of such a message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The midi device.  |
| status   | The actual status of the message.  |
| timestamp | The message timestamp.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be processed.  |



---


### `int MIDIDeviceSendRealTime` ###
Send a "Real-Time" message.
```
int MIDIDeviceSendRealTime(struct MIDIDevice *device, MIDIStatus status, MIDITimestamp timestamp);
```

This is called when the device wants to send a "Real-Time" message. It can be used to trigger the sending of such a message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| device   | The midi device.  |
| status   | The actual status of the message.  |
| timestamp | The message timestamp.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be sent.  |