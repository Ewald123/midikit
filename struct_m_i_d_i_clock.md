# MIDIClock #
Provider for accurate timestamps.
```
#include <clock.h>

struct MIDIClock;
```
The [MIDIClock](struct_m_i_d_i_clock.md) provides accurate timestamps at any desired rate with a selectable offset. It focuses on stable timestamps and tries to avoid integer overflows in calculations.




---

## Global clock ##



---


### `int MIDIClockSetGlobalClock` ###
Set the global clock.
```
int MIDIClockSetGlobalClock(struct MIDIClock *clock);
```

Replace the global clock (if set) with another clock.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| clock    | The global clock.  |



---


### `int MIDIClockGetGlobalClock` ###
Get the global clock.
```
int MIDIClockGetGlobalClock(struct MIDIClock **clock);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| clock    | The global clock.  |



---

## Creation and destruction ##
Creating, destroying and reference counting of [MIDIClock](struct_m_i_d_i_clock.md) objects.


---


### `struct MIDIClock * MIDIClockProvide` ###
Provide clock with a specific timestamp rate.
```
struct MIDIClock * MIDIClockProvide(MIDISamplingRate rate);
```

Check if the global clock has the requested sampling rate. If the rate matches, retain and return the global clock. Create a new clock otherwise. If the global clock still NULL, assign the newly created clock.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| rate     | The number of times the clock should tick per second.  |

#### Return ####
a pointer to the created clock structure on success. a `NULL` pointer if the clock could not created.


---


### `struct MIDIClock * MIDIClockCreate` ###
Create a [MIDIClock](struct_m_i_d_i_clock.md) instance.
```
struct MIDIClock * MIDIClockCreate(MIDISamplingRate rate);
```

Allocate space and initialize a [MIDIClock](struct_m_i_d_i_clock.md) instance.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| rate     | The number of times the clock should tick per second.  |

#### Return ####
a pointer to the created clock structure on success. a `NULL` pointer if the clock could not created.


---


### `void MIDIClockDestroy` ###
Destroy a [MIDIClock](struct_m_i_d_i_clock.md) instance.
```
void MIDIClockDestroy(struct MIDIClock *clock);
```

Free all resources occupied by the clock and release all referenced objects.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| clock    | The clock.      |



---


### `void MIDIClockRetain` ###
Retain a [MIDIClock](struct_m_i_d_i_clock.md) instance.
```
void MIDIClockRetain(struct MIDIClock *clock);
```

Increment the reference counter of a clock so that it won't be destroyed.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| clock    | The clock.      |



---


### `void MIDIClockRelease` ###
Release a [MIDIClock](struct_m_i_d_i_clock.md) instance.
```
void MIDIClockRelease(struct MIDIClock *clock);
```

Decrement the reference counter of a clock. If the reference count reached zero, destroy the clock.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| clock    | The clock.      |



---

## Timing functions ##
Read and modify clocks and timestamps.


---


### `int MIDIClockSetNow` ###
Set the current time.
```
int MIDIClockSetNow(struct MIDIClock *clock, MIDITimestamp now);
```

Set the current time. The clock must not be referenced anywhere else.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| clock    | The clock to modify (pass `NULL` for global clock)  |
| now      | The new current time.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |
| >0        | if the time could not be set.  |



---


### `int MIDIClockGetNow` ###
Get the current time.
```
int MIDIClockGetNow(struct MIDIClock *clock, MIDITimestamp *now);
```

Get the current time.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| clock    | The clock to read (pass `NULL` for global clock)  |
| now      | The current time.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |



---


### `int MIDIClockSetSamplingRate` ###
Set the sampling rate.
```
int MIDIClockSetSamplingRate(struct MIDIClock *clock, MIDISamplingRate rate);
```

Set the clocks sampling rate in ticks per second. The clock must not be referenced anywhere else.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| clock    | The clock (pass `NULL` for global clock)  |
| rate     | The rate.       |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |



---


### `int MIDIClockGetSamplingRate` ###
Get the sampling rate.
```
int MIDIClockGetSamplingRate(struct MIDIClock *clock, MIDISamplingRate *rate);
```

Get the clocks sampling rate in ticks per second.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| clock    | The clock (pass `NULL` for global clock)  |
| rate     | The rate.       |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |



---


### `int MIDIClockTimestampToSeconds` ###
Convert a clock's timestamp to seconds.
```
int MIDIClockTimestampToSeconds(struct MIDIClock *clock, MIDITimestamp timestamp, double *seconds);
```

Converting the timestamp to seconds can be useful, when handling with time-deltas.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| clock    | The clock (pass `NULL` for global clock)  |
| timestamp | The timestamp to convert.  |
| seconds  | The value of the timestamp converted to seconds.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |



---


### `int MIDIClockTimestampFromSeconds` ###
Convert seconds to a clock's timestamp.
```
int MIDIClockTimestampFromSeconds(struct MIDIClock *clock, MIDITimestamp *timestamp, double seconds);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| clock    | The clock (pass `NULL` for global clock)  |
| timestamp | The value of the seconds converted to a timestamp.  |
| seconds  | The seconds to convert.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |



---


### `int MIDIClockConvertTimestamp` ###
Convert between different clocks.
```
int MIDIClockConvertTimestamp(struct MIDIClock *clock, struct MIDIClock *source, MIDITimestamp *timestamp);
```

Convert a timestamp that was created by a given clock to the timestamp of another clock. The function tries to avoid integer overflows where possible.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| clock    | The clock to convert to (pass `NULL` for global clock)  |
| source   | The clock that created the timestamp (pass `NULL` for global clock)  |
| timestamp | The timestamp to convert.  |

#### Return Values ####
| **Value** | **Description** |
|:----------|:----------------|
| 0         | on success.     |