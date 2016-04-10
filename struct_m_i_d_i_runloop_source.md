# MIDIRunloopSource #

```

struct MIDIRunloopSource;
```





---

## Public Attributes ##


### `int MIDIRunloopSource::refs` ###


### `int MIDIRunloopSource::nfds` ###


### `fd_set MIDIRunloopSource::readfds` ###


### `fd_set MIDIRunloopSource::writefds` ###


### `struct timespec MIDIRunloopSource::timeout_start` ###


### `struct timespec MIDIRunloopSource::timeout_time` ###


### `struct MIDIRunloopSourceDelegate MIDIRunloopSource::delegate` ###


### `struct MIDIRunloop* MIDIRunloopSource::runloop` ###



---

## Public Functions ##



---


### `int MIDIRunloopSourceInvalidate` ###
Mark a runloop source as invalid.
```
int MIDIRunloopSourceInvalidate(struct MIDIRunloopSource *source);
```

Disable all callbacks of a runloop source and remove it from the runloop it is scheduled in.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| source   | The source the should be invalidated.  |



---


### `int MIDIRunloopSourceWait` ###
Wait until any callback of the runloop source is triggered.
```
int MIDIRunloopSourceWait(struct MIDIRunloopSource *source);
```

If no callbacks are scheduled return immediately.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| source   | The runloop source.  |



---


### `int MIDIRunloopSourceScheduleRead` ###
Schedule the read callback of a runloop source.
```
int MIDIRunloopSourceScheduleRead(struct MIDIRunloopSource *source, int fd);
```

Enable the read callback of a runloop source. The callback will be invoked the next time any of the runloop source's "read" file descriptors have new data to be read. The read callback will stay enabled until it is cleared using MIDIRunloopSourceClearRead.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| source   | The source that should be scheduled.  |
| fd       | The file descriptor from which to read.  |



---


### `int MIDIRunloopSourceClearRead` ###
Stop a scheduled read callback of a runloop source.
```
int MIDIRunloopSourceClearRead(struct MIDIRunloopSource *source, int fd);
```

Unschedule a previously scheduled read operation.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| source   | The source that should be scheduled.  |
| fd       | The file descriptor from which to read.  |



---


### `int MIDIRunloopSourceScheduleWrite` ###
Schedule the write callback of a runloop source.
```
int MIDIRunloopSourceScheduleWrite(struct MIDIRunloopSource *source, int fd);
```

Enable the write callback of a runloop source. The callback will be invoked the next time any of the runloop source's "write" file descriptors can accept new data. After that the callback will be disabled until this function is called again.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| source   | The source that should be scheduled.  |
| fd       | The file descriptor to which to write.  |



---


### `int MIDIRunloopSourceClearWrite` ###
Stop a scheduled write callback of a runloop source.
```
int MIDIRunloopSourceClearWrite(struct MIDIRunloopSource *source, int fd);
```

Unschedule a previously scheduled write operation.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| source   | The source that should be scheduled.  |
| fd       | The file descriptor to which to write.  |



---


### `int MIDIRunloopSourceScheduleTimeout` ###
Schedule the idle callback of a runloop source.
```
int MIDIRunloopSourceScheduleTimeout(struct MIDIRunloopSource *source, struct timespec *timeout);
```

Enable the idle callback of a runloop source. The callback will be invoked the next time any of the runloop source's timeout expired. After that the callback will be disabled until this function is called again.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| source   | The source that should be scheduled.  |
| timeout  | The timeout to be scheduled.  |



---


### `int MIDIRunloopSourceClearTimeout` ###
Stop a scheduled write callback of a runloop source.
```
int MIDIRunloopSourceClearTimeout(struct MIDIRunloopSource *source);
```

Unschedule a previously scheduled write operation.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| source   | The source that should be scheduled.  |



---

## Private Functions ##



---


### `static void _runloop_source_timeout_start` ###
Start a new timeout.
```
static void _runloop_source_timeout_start(struct MIDIRunloopSource *source, struct timespec *now);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| source   | The runloop source.  |
| now      | Must be set to the current time.  |



---


### `static void _runloop_source_timeout_remain` ###
Get the remaining time of the current timeout.
```
static void _runloop_source_timeout_remain(struct MIDIRunloopSource *source, struct timespec *remain, struct timespec *now);
```

Zero if timeout is now set.


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| source   | The runloop source.  |
| remain   | Will be set to the remaining time.  |
| now      | Must be set to the current time.  |



---


### `static int _runloop_source_timeout_check` ###
Check if the current timeout is over.
```
static int _runloop_source_timeout_check(struct MIDIRunloopSource *source, struct timespec *now);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| source   | The runloop source.  |
| now      | Must be set to the current time.  |



---


### `static int _runloop_source_timeout` ###
Trigger a timeout.
```
static int _runloop_source_timeout(struct MIDIRunloopSource *source, struct timespec *now);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| source   | The runloop source.  |
| now      | Must be set to the current time.  |



---


### `static int _runloop_source_read` ###
Trigger a read operation.
```
static int _runloop_source_read(struct MIDIRunloopSource *source, struct timespec *now, fd_set *fds);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| source   | The runloop source.  |
| now      | Must be set to the current time.  |
| fds      | The fd\_set from which to read.  |



---


### `static int _runloop_source_write` ###
Trigger a write operation.
```
static int _runloop_source_write(struct MIDIRunloopSource *source, struct timespec *now, fd_set *fds);
```


#### Parameters ####
| **Name** | **Description** |
|:---------|:----------------|
| source   | The runloop source.  |
| now      | Must be set to the current time.  |
| fds      | The fd\_set to which to write.  |