# MIDIControllerDelegate #

```

struct MIDIControllerDelegate;
```





---

## Public Attributes ##


### `int(* MIDIControllerDelegate::recv_cc)(struct MIDIController *controller, struct MIDIDevice *device, MIDIChannel channel, MIDIControl control, MIDILongValue value)` ###