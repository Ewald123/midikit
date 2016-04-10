# MIDIController #
Convenience class to handle control changes.
```

struct MIDIController;
```
The [MIDIController](struct_m_i_d_i_controller.md) implements the full set of controls specified by the MIDI standard and can be attached to any [MIDIDevice](struct_m_i_d_i_device.md) channel to monitor control change messages.




---

## Public Attributes ##


### `size_t MIDIController::refs` ###


### `struct MIDIControllerDelegate* MIDIController::delegate` ###


### `MIDILongValue MIDIController::current_parameter` ###


### `MIDIBoolean MIDIController::current_parameter_registered` ###


### `MIDIValue MIDIController::controls[N_CONTROLS]` ###


### `MIDIValue MIDIController::registered_parameters[6]` ###


### `struct MIDINRPList* MIDIController::list` ###



---

## Creation and destruction ##
Creating, destroying and reference counting of [MIDIController](struct_m_i_d_i_controller.md) objects.


---


### `struct MIDIController * MIDIControllerCreate` ###
Create a [MIDIController](struct_m_i_d_i_controller.md) instance.
```
struct MIDIController * MIDIControllerCreate(struct MIDIControllerDelegate *delegate);
```

Allocate space and initialize a [MIDIController](struct_m_i_d_i_controller.md) instance.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| delegate | The delegate to use for the controller. May be `NULL`.  |

#### Return ####
a pointer to the created controller structure on success. a `NULL` pointer if the controller could not created.


---


### `void MIDIControllerDestroy` ###
Destroy a [MIDIController](struct_m_i_d_i_controller.md) instance.
```
void MIDIControllerDestroy(struct MIDIController *controller);
```

Free all resources occupied by the controller.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| controller | The controller.  |



---


### `void MIDIControllerRetain` ###
Retain a [MIDIController](struct_m_i_d_i_controller.md) instance.
```
void MIDIControllerRetain(struct MIDIController *controller);
```

Increment the reference counter of a controller so that it won't be destroyed.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| controller | The controller.  |



---


### `void MIDIControllerRelease` ###
Release a [MIDIController](struct_m_i_d_i_controller.md) instance.
```
void MIDIControllerRelease(struct MIDIController *controller);
```

Decrement the reference counter of a controller. If the reference count reached zero, destroy the controller.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| controller | The controller.  |



---

## Controller interface ##
Atomically read, edit, load and save controller values.


---


### `int MIDIControllerSetControl` ###
Set a controller value.
```
int MIDIControllerSetControl(struct MIDIController *controller, MIDIControl control, size_t size, void *value);
```

Set the value of a controller and send the control change message to the connected device.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| controller | The controller.  |
| control  | The control number.  |
| size     | The size of the buffer pointed to by `value`.  |
| value    | The value to store. The type may vary depending on the kind of control.  |



---


### `int MIDIControllerGetControl` ###
Get a controller value.
```
int MIDIControllerGetControl(struct MIDIController *controller, MIDIControl control, size_t size, void *value);
```

Get the value of a controller.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| controller | The controller.  |
| control  | The control number.  |
| size     | The size of the buffer pointed to by `value`.  |
| value    | The value to store. The type may vary depending on the kind of control.  |



---


### `int MIDIControllerSetRegisteredParameter` ###
Atomically set a registered parameter.
```
int MIDIControllerSetRegisteredParameter(struct MIDIController *controller, MIDIControlParameter parameter, size_t size, void *value);
```

Set the value of a registered parameter, change the current registered parameter "pointer" accordingly. Send any required messages to keep connected devices in sync.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| controller | The controller.  |
| parameter | The registered parameter number number.  |
| size     | The size of the buffer pointed to by `value`.  |
| value    | The value to store. The type may vary depending on the kind of parameter.  |



---


### `int MIDIControllerGetRegisteredParameter` ###
Get a registered parameter.
```
int MIDIControllerGetRegisteredParameter(struct MIDIController *controller, MIDIControlParameter parameter, size_t size, void *value);
```

Get the value of a registered parameter.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| controller | The controller.  |
| parameter | The registered parameter number number.  |
| size     | The size of the buffer pointed to by `value`.  |
| value    | The value to store. The type may vary depending on the kind of parameter.  |



---


### `int MIDIControllerSetNonRegisteredParameter` ###
Atomically set a non-registered parameter.
```
int MIDIControllerSetNonRegisteredParameter(struct MIDIController *controller, MIDIControlParameter parameter, size_t size, void *value);
```

Set the value of a non-registered parameter, change the current non-registered parameter "pointer" accordingly. Send any required messages to keep connected devices in sync.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| controller | The controller.  |
| parameter | The non-registered parameter number number.  |
| size     | The size of the buffer pointed to by `value`.  |
| value    | The value to store. The type may vary depending on the kind of parameter.  |



---


### `int MIDIControllerGetNonRegisteredParameter` ###
Get a non-registered parameter.
```
int MIDIControllerGetNonRegisteredParameter(struct MIDIController *controller, MIDIControlParameter parameter, size_t size, void *value);
```

Get the value of a non-registered parameter.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| controller | The controller.  |
| parameter | The non-registered parameter number number.  |
| size     | The size of the buffer pointed to by `value`.  |
| value    | The value to store. The type may vary depending on the kind of parameter.  |



---


### `int MIDIControllerStore` ###
Store control values.
```
int MIDIControllerStore(struct MIDIController *controller, size_t size, void *buffer, size_t *written);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| controller | The controller.  |
| size     | The size of the buffer pointed to by `buffer`.  |
| buffer   | The buffer to store the controller values in.  |
| written  | The number of bytes written to the buffer.  |



---


### `int MIDIControllerRecall` ###
Recall the values of previously stored controls.
```
int MIDIControllerRecall(struct MIDIController *controller, size_t size, void *buffer, size_t *read);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| controller | The controller.  |
| size     | The size of the buffer pointed to by `buffer`.  |
| buffer   | The buffer to store the controller values in.  |
| read     | The number of bytes read from the buffer.  |



---

## Message passing ##
Receiving and sending [MIDIMessage](struct_m_i_d_i_message.md) objects.


---


### `int MIDIControllerReceiveControlChange` ###
Receive a "Control Change" message.
```
int MIDIControllerReceiveControlChange(struct MIDIController *controller, struct MIDIDevice *device, MIDIChannel channel, MIDIControl control, MIDIValue value);
```

This is called by the connected device when receives a "Control Change" message. It can be used to simulate the reception of such a message.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| controller | The controller.  |
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


### `int MIDIControllerSendControlChange` ###
Send a "Control Change" message.
```
int MIDIControllerSendControlChange(struct MIDIController *controller, struct MIDIDevice *device, MIDIChannel channel, MIDIControl control, MIDIValue value);
```

This can be used to notify other devices when controls have been changed.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| controller | The controller.  |
| device   | The midi device.  |
| channel  | The channel on which the control change occured.  |
| control  | The control that was changed.  |
| value    | The new value of the control.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| 1         | if the message could not be sent.  |