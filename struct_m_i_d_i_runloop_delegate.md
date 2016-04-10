# MIDIRunloopDelegate #

```

struct MIDIRunloopDelegate;
```





---

## Public Attributes ##


### `void* MIDIRunloopDelegate::info` ###


### `int(* MIDIRunloopDelegate::schedule_read)(void *info, int fd)` ###


### `int(* MIDIRunloopDelegate::schedule_write)(void *info, int fd)` ###


### `int(* MIDIRunloopDelegate::schedule_timeout)(void *info, struct timespec *)` ###


### `int(* MIDIRunloopDelegate::clear_read)(void *info, int fd)` ###


### `int(* MIDIRunloopDelegate::clear_write)(void *info, int fd)` ###


### `int(* MIDIRunloopDelegate::clear_timeout)(void *info, struct timespec *)` ###