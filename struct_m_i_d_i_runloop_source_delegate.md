# MIDIRunloopSourceDelegate #

```

struct MIDIRunloopSourceDelegate;
```





---

## Public Attributes ##


### `void* MIDIRunloopSourceDelegate::info` ###


### `int(* MIDIRunloopSourceDelegate::read)(void *info, int nfds, fd_set *readfds)` ###


### `int(* MIDIRunloopSourceDelegate::write)(void *info, int nfds, fd_set *readfds)` ###


### `int(* MIDIRunloopSourceDelegate::timeout)(void *info, struct timespec *elapsed)` ###