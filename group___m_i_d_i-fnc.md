# MIDI-fnc #





---

## Functions ##



---


### `int MIDIUtilReadVarLen` ###
Read an encoded number with a variable number of bytes.
```
int MIDIUtilReadVarLen(MIDIVarLen *value, size_t size, unsigned char *buffer, size_t *read);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| value    | The location to store the read number in.  |
| size     | The number of available bytes in the buffer.  |
| buffer   | The buffer to read from.  |
| read     | The location to store the number of read bytes in. (may be `NULL`)  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the number could not be read.  |



---


### `int MIDIUtilWriteVarLen` ###
Write a number encoding it with a variable number of bytes.
```
int MIDIUtilWriteVarLen(MIDIVarLen *value, size_t size, unsigned char *buffer, size_t *written);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| value    | The location to read the number from.  |
| size     | The number of available bytes in the buffer.  |
| buffer   | The buffer to write to.  |
| written  | The location to store the number of written bytes in. (may be `NULL`)  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the number could not be read.  |



---


### `int MIDIDriverConnectDevice` ###
Connect a device to a driver.
```
int MIDIDriverConnectDevice(struct MIDIDriver *driver, struct MIDIDevice *device);
```

Connect both the device's `IN` and `OUT` ports to their respective counterparts on the driver. [MIDIDriver](struct_m_i_d_i_driver.md), [MIDIDevice](struct_m_i_d_i_device.md)
#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| driver   | The driver to connect.  |
| device   | The device to connect.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |