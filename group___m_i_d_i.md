# MIDI #
MIDI. Whenever the type is MIDIBoolean you can expect them to work like "real" booleans.

Whenever a MIDIChannel is expected any of the MIDI channels 1-16 can be specified.

(Status has eight bits, message has no data bytes.)

(Status has eight bits.)

(Status has 4 bits & is followed by a 4 bit channel number.)

In some cases special constants for a device's base channel or all channels (1-16) can be used.

MIDIProperty [MIDIMessage](struct_m_i_d_i_message.md) property type enumeration.
When the type is MIDIValue you can't expect them to be normalized and MIDI semantics apply. Use MIDI\_BOOL to convert a MIDIValue into a boolean.




---

## Defines ##



---


### `MIDI_DRIVER_WILL_SEND_MESSAGE` ###
MIDI driver will send a message.
```
#define MIDI_DRIVER_WILL_SEND_MESSAGE 0;
```
This is called by the driver interface before it will send a message to the implementation. Return a value other than 0 to cancel the sending. The info pointer points the the message that will be sent.


---


### `MIDI_DRIVER_WILL_RECEIVE_MESSAGE` ###
MIDI driver will receive a message.
```
#define MIDI_DRIVER_WILL_RECEIVE_MESSAGE 1;
```
This is called by the driver interface after it has been notified (by the implementation) that a new message was received. The interface will then deliver it to all connected devices unless the callback returned a value other than 0. The info pointer points to the message that will be received.


---


### `MIDI_NIBBLE_VALUE` ###
Create a status byte with a channel number.
```
#define MIDI_NIBBLE_VALUE ( ((h)<<4)|((l)&0xf) );
```



---


### `MIDI_HIGH_NIBBLE` ###
Access the high nibble of a byte.
```
#define MIDI_HIGH_NIBBLE (((b)>>4)&0xf);
```



---


### `MIDI_LOW_NIBBLE` ###
Access the low nibble of a byte.
```
#define MIDI_LOW_NIBBLE ((b)&0xf);
```



---


### `MIDI_LONG_VALUE` ###
Compose a MIDILongValue from two MIDIValues.
```
#define MIDI_LONG_VALUE (((m & 0x7f)<<7) | (l & 0x7f));
```



---


### `MIDI_LSB` ###
Access the lowest 7 bits of a MIDILongValue.
```
#define MIDI_LSB (v)     & 0x7f;
```



---


### `MIDI_MSB` ###
Access the higher 7 bits of a MIDILongValue.
```
#define MIDI_MSB ((v)>>7) & 0x7f;
```



---


### `MIDI_MANUFACTURER_ID_EXTENDED` ###
Mark a manufacturer ID as "extended".
```
#define MIDI_MANUFACTURER_ID_EXTENDED v | 0x80;
```
Extended manufacturer IDs use 2 bytes + one empty byte.


---


### `MIDI_BOOL` ###
Interpret a MIDIValue as MIDIBoolean.
```
#define MIDI_BOOL (((v)>=64) ? MIDI_ON : MIDI_OFF);
```



---


### `EASSERT` ###

```
#define EASSERT -1;
```



---


### `MIDI_LOG_1` ###

```
#define MIDI_LOG_1 0x01;
```



---


### `MIDI_LOG_DEVELOP` ###

```
#define MIDI_LOG_DEVELOP 0x02;
```



---


### `MIDI_LOG_DEBUG` ###

```
#define MIDI_LOG_DEBUG 0x04;
```



---


### `MIDI_LOG_INFO` ###

```
#define MIDI_LOG_INFO 0x08;
```



---


### `MIDI_LOG_ERROR` ###

```
#define MIDI_LOG_ERROR 0x10;
```



---


### `MIDI_LOG_CHANNELS` ###

```
#define MIDI_LOG_CHANNELS MIDI_LOG_ERROR;
```



---

## Logging and error handling ##



---


### `MIDILog` ###
Send a message to the MIDI logger.
```
#define MIDILog do { if( MIDILogger != NULL ) { (*MIDILogger)( MIDI_LOG_ ## channel, __VA_ARGS__ ); } } while( 0 );
```

#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| channels | The log channels to use for logging.  |
| ...      | The log message format and variable arguments.  |

#### Return ####
This macro can not be used as an lvalue.


---


### `MIDILogLocation` ###
Send a message to the MIDI logger and log the source location.
```
#define MIDILogLocation MIDILog( channel, "%s:%i: " fmt, __FILE__, __LINE__, __VA_ARGS__ );;
```

#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| channels | The log channels to use for logging.  |
| ...      | The log message format and variable arguments.  |

#### Return ####
This macro can not be used as an lvalue.


---


### `MIDIError` ###
Indicate that an error occured.
```
#define MIDIError do { MIDIErrorNumber = kind; \
     MIDILogLocation( ERROR, "[" #kind "] %s\n", msg ); \
} while( 0 );
```
Normal code execution will continue, but the MIDI error number will be set and a message will be logged.
#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| kind     | The symbolic error number.  |
| msg      | The log message.  |

#### Return ####
This macro does not return.


---


### `MIDIAssert` ###
Check for programming errors.
```
#define MIDIAssert do { if( !(expr) ) { \
  MIDIErrorNumber = EASSERT; \
  MIDILogLocation( ERROR, "[EASSERT] Assertion failed (%s)\n", #expr ); \
  exit( EASSERT ); \
} } while( 0 );
```
Use this macro to check for programming errors. Inside a function you may assume various conditions that should be fulfilled if you programmed your code correctly. For example if you have numerous static functions in you C code and use them to solve recurring tasks, these functions are only called by you, never by a client. To check if you use those functions correctly you can use assertions inside those functions. Assertions check for errors that should never happen. Failed assertions indicate a programming error and therefore result in the program exiting immediately. Use many assertions, cover all implicit knowledge with them, there is no penalty, because they will be removed in release mode.
#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| expr     | The expression to test.  |

#### Return ####
This macro only returns only if the assertion is fulfilled. It can not be used as an lvalue.


---


### `MIDIPrecondFailed` ###
Indicate a failed precondition and return an error.
```
#define MIDIPrecondFailed MIDIErrorNumber = kind; \
MIDILogLocation( ERROR, "%s\n", message ); \
return retval;;
```
This should usually not be used directly. Instead either MIDIPrecond or MIDIPrecondReturn can be used.
#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| message  | The error message.  |
| kind     | The error number.  |
| retval   | The return value.  |

#### Return ####
This macro does not return.


---


### `MIDIPrecondReturn` ###
Check preconditions of a method and return a specified value.
```
#define MIDIPrecondReturn do { if( !(expr) ) { \
  MIDIPrecondFailed( "[" #kind "] Precondition failed (" #expr ")", kind, retval ); \
} } while( 0 );
```
Use this macro to check your preconditions inside a function. Unlike MIDIPrecond this macro allows you to specify the return value if the precondition was violated.
#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| expr     | The expression to test.  |
| kind     | The symbolic error number.  |
| retval   | The value that should be returned on error.  |

#### Return ####
This macro only returns only if the precondition is fulfilled. It can not be used as an lvalue.


---


### `MIDIPrecond` ###
Check preconditions of a method.
```
#define MIDIPrecond do { if( !(expr) ) { \
  MIDIPrecondFailed( "[" #kind "] Precondition failed (" #expr ")", kind, kind ); \
} } while( 0 );
```
Use this macro to check your preconditions inside a function. Those preconditions may be specific values of arguments, or checks if a malloc succeeded. Preconditions may also be used to check if some piece of code should continue it's operation. A failed precondition is a program error that was triggered by misuse of the API or by the an external error. When the precondition fails the function returns immediately.
#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| expr     | The expression to test.  |
| kind     | The symbolic error number.  |

#### Return ####
This macro only returns only if the precondition is fulfilled. It can not be used as an lvalue.


---

## Channel Voice Messages. ##



---


### `MIDI_STATUS_NOTE_OFF` ###
Note Off event.
```
#define MIDI_STATUS_NOTE_OFF 0x8;
```
This message is sent when a note is released (ended).


---


### `MIDI_STATUS_NOTE_ON` ###
Note On event.
```
#define MIDI_STATUS_NOTE_ON 0x9;
```
This message is sent when a note is depressed (start).


---


### `MIDI_STATUS_POLYPHONIC_KEY_PRESSURE` ###
Polyphonic Key Pressure (Aftertouch).
```
#define MIDI_STATUS_POLYPHONIC_KEY_PRESSURE 0xa;
```
This message is most often sent by pressing down on the key after it "bottoms out".


---


### `MIDI_STATUS_CONTROL_CHANGE` ###
Control Change.
```
#define MIDI_STATUS_CONTROL_CHANGE 0xb;
```
This message is sent when a controller value changes. Controllers include devices such as pedals and levers.


---


### `MIDI_STATUS_PROGRAM_CHANGE` ###
Program Change.
```
#define MIDI_STATUS_PROGRAM_CHANGE 0xc;
```
This message sent when the patch number changes.


---


### `MIDI_STATUS_CHANNEL_PRESSURE` ###
Channel Pressure (After-touch).
```
#define MIDI_STATUS_CHANNEL_PRESSURE 0xd;
```
This message is most often sent by pressing down on the key after it "bottoms out". This message is different from polyphonic after-touch. Use this message to send the single greatest pressure value (of all the current depressed keys).


---


### `MIDI_STATUS_PITCH_WHEEL_CHANGE` ###
Pitch Wheel Change.
```
#define MIDI_STATUS_PITCH_WHEEL_CHANGE 0xe;
```



---

## System Common Messages ##



---


### `MIDI_STATUS_SYSTEM_EXCLUSIVE` ###
System Exclusive.
```
#define MIDI_STATUS_SYSTEM_EXCLUSIVE 0xf0;
```
This message makes up for all that MIDI doesn't support.


---


### `MIDI_STATUS_TIME_CODE_QUARTER_FRAME` ###
MIDI Time Code Quarter Frame.
```
#define MIDI_STATUS_TIME_CODE_QUARTER_FRAME 0xf1;
```
(What is this?)


---


### `MIDI_STATUS_SONG_POSITION_POINTER` ###
Song Position Pointer.
```
#define MIDI_STATUS_SONG_POSITION_POINTER 0xf2;
```



---


### `MIDI_STATUS_SONG_SELECT` ###
Song Select.
```
#define MIDI_STATUS_SONG_SELECT 0xf3;
```
The Song Select specifies which sequence or song is to be played.


---


### `MIDI_STATUS_UNDEFINED0` ###
Undefined.
```
#define MIDI_STATUS_UNDEFINED0 0xf4;
```
(Reserved)


---


### `MIDI_STATUS_UNDEFINED1` ###
Undefined.
```
#define MIDI_STATUS_UNDEFINED1 0xf5;
```
(Reserved)


---


### `MIDI_STATUS_TUNE_REQUEST` ###
Tune Request.
```
#define MIDI_STATUS_TUNE_REQUEST 0xf6;
```
Upon receiving a Tune Request, all analog synthesizers should tune their oscillators.


---


### `MIDI_STATUS_END_OF_EXCLUSIVE` ###
End of Exclusive.
```
#define MIDI_STATUS_END_OF_EXCLUSIVE 0xf7;
```
Used to terminate a System Exclusive dump (see above).


---

## System Real-Time Messages ##



---


### `MIDI_STATUS_TIMING_CLOCK` ###
Timing Clock.
```
#define MIDI_STATUS_TIMING_CLOCK 0xf8;
```
Sent 24 times per quarter note when synchronization is required.


---


### `MIDI_STATUS_UNDEFINED2` ###
Undefined.
```
#define MIDI_STATUS_UNDEFINED2 0xf9;
```
(Reserved)


---


### `MIDI_STATUS_START` ###
Start.
```
#define MIDI_STATUS_START 0xfa;
```
Start the current sequence playing. (This message will be followed with Timing Clocks).


---


### `MIDI_STATUS_CONTINUE` ###
Continue.
```
#define MIDI_STATUS_CONTINUE 0xfb;
```
Continue at the point the sequence was Stopped.


---


### `MIDI_STATUS_STOP` ###
Stop.
```
#define MIDI_STATUS_STOP 0xfc;
```
Stop the current sequence.


---


### `MIDI_STATUS_UNDEFINED3` ###
Undefined.
```
#define MIDI_STATUS_UNDEFINED3 0xfd;
```
(Reserved)


---


### `MIDI_STATUS_ACTIVE_SENSING` ###
Active Sensing.
```
#define MIDI_STATUS_ACTIVE_SENSING 0xfe;
```
Use of this message is optional. When initially sent, the receiver will expect to receive another Active Sensing message each 300ms (max), or it will be assume that the connection has been terminated. At termination, the receiver will turn off all voices and return to normal (non-active sensing) operation.


---


### `MIDI_STATUS_RESET` ###
Reset.
```
#define MIDI_STATUS_RESET 0xff;
```
Reset all receivers in the system to power-up status. This should be used sparingly, preferably under manual control. In particular, it should not be sent on power-up.


---

## MIDI channel enumeration values ##



---


### `MIDI_CHANNEL_1` ###

```
#define MIDI_CHANNEL_1 0x0;
```



---


### `MIDI_CHANNEL_2` ###

```
#define MIDI_CHANNEL_2 0x1;
```



---


### `MIDI_CHANNEL_3` ###

```
#define MIDI_CHANNEL_3 0x2;
```



---


### `MIDI_CHANNEL_4` ###

```
#define MIDI_CHANNEL_4 0x3;
```



---


### `MIDI_CHANNEL_5` ###

```
#define MIDI_CHANNEL_5 0x4;
```



---


### `MIDI_CHANNEL_6` ###

```
#define MIDI_CHANNEL_6 0x5;
```



---


### `MIDI_CHANNEL_7` ###

```
#define MIDI_CHANNEL_7 0x6;
```



---


### `MIDI_CHANNEL_8` ###

```
#define MIDI_CHANNEL_8 0x7;
```



---


### `MIDI_CHANNEL_9` ###

```
#define MIDI_CHANNEL_9 0x8;
```



---


### `MIDI_CHANNEL_10` ###

```
#define MIDI_CHANNEL_10 0x9;
```



---


### `MIDI_CHANNEL_11` ###

```
#define MIDI_CHANNEL_11 0xa;
```



---


### `MIDI_CHANNEL_12` ###

```
#define MIDI_CHANNEL_12 0xb;
```



---


### `MIDI_CHANNEL_13` ###

```
#define MIDI_CHANNEL_13 0xc;
```



---


### `MIDI_CHANNEL_14` ###

```
#define MIDI_CHANNEL_14 0xd;
```



---


### `MIDI_CHANNEL_15` ###

```
#define MIDI_CHANNEL_15 0xe;
```



---


### `MIDI_CHANNEL_16` ###

```
#define MIDI_CHANNEL_16 0xf;
```



---


### `MIDI_CHANNEL_BASE` ###

```
#define MIDI_CHANNEL_BASE 0x10;
```



---


### `MIDI_CHANNEL_ALL` ###

```
#define MIDI_CHANNEL_ALL 0x1f;
```



---

## MIDI property enumeration values ##



---


### `MIDI_STATUS` ###

```
#define MIDI_STATUS 0x00;
```



---


### `MIDI_CHANNEL` ###

```
#define MIDI_CHANNEL 0x01;
```



---


### `MIDI_KEY` ###

```
#define MIDI_KEY 0x02;
```



---


### `MIDI_VELOCITY` ###

```
#define MIDI_VELOCITY 0x03;
```



---


### `MIDI_PRESSURE` ###

```
#define MIDI_PRESSURE 0x04;
```



---


### `MIDI_CONTROL` ###

```
#define MIDI_CONTROL 0x05;
```



---


### `MIDI_VALUE` ###

```
#define MIDI_VALUE 0x06;
```



---


### `MIDI_PROGRAM` ###

```
#define MIDI_PROGRAM 0x07;
```



---


### `MIDI_VALUE_LSB` ###

```
#define MIDI_VALUE_LSB 0x08;
```



---


### `MIDI_VALUE_MSB` ###

```
#define MIDI_VALUE_MSB 0x09;
```



---


### `MIDI_MANUFACTURER_ID` ###

```
#define MIDI_MANUFACTURER_ID 0x0a;
```



---


### `MIDI_SYSEX_DATA` ###

```
#define MIDI_SYSEX_DATA 0x0b;
```



---


### `MIDI_SYSEX_SIZE` ###

```
#define MIDI_SYSEX_SIZE 0x0c;
```



---


### `MIDI_SYSEX_FRAGMENT` ###

```
#define MIDI_SYSEX_FRAGMENT 0x0d;
```



---


### `MIDI_TIME_CODE_TYPE` ###

```
#define MIDI_TIME_CODE_TYPE 0x0e;
```



---


### `MIDI_NOTHING` ###

```
#define MIDI_NOTHING 0xff;
```



---

## MIDI boolean enumeration values ##



---


### `MIDI_ON` ###

```
#define MIDI_ON 0x7f;
```



---


### `MIDI_OFF` ###

```
#define MIDI_OFF 0x00;
```