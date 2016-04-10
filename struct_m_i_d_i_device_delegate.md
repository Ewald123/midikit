# MIDIDeviceDelegate #
Delegate to respond to received messages.
```
#include <device.h>

struct MIDIDeviceDelegate;
```
Every time the device receives a message, the device calls one of these callbacks (if available) with the message properties.




---

## Public Attributes ##


### `MIDIDeviceDelegate::recv_nof` ###
Note off callback. [MIDI\_STATUS\_NOTE\_OFF](group___m_i_d_i_1ga508f50a35543d3e5ea6baf9750440707.md)

### `MIDIDeviceDelegate::recv_non` ###
Note on callback. [MIDI\_STATUS\_NOTE\_ON](group___m_i_d_i_1gaa1b6ca289d856e41e2f1096d2b189d99.md)

### `MIDIDeviceDelegate::recv_pkp` ###
Polyphonic key pressure callback. [MIDI\_STATUS\_POLYPHONIC\_KEY\_PRESSURE](group___m_i_d_i_1ga6d3bf5d791b9f209240dcd372e7abd2a.md)

### `MIDIDeviceDelegate::recv_cc` ###
Control change callback. [MIDI\_STATUS\_CONTROL\_CHANGE](group___m_i_d_i_1gaa48b3e691cfc5475ce8149aeade30db7.md)

### `MIDIDeviceDelegate::recv_pc` ###
Program change callback. [MIDI\_STATUS\_PROGRAM\_CHANGE](group___m_i_d_i_1ga27f9e3880907e13a308f33c6cc7e3e0f.md)

### `MIDIDeviceDelegate::recv_cp` ###
Channel pressure callback. [MIDI\_STATUS\_CHANNEL\_PRESSURE](group___m_i_d_i_1gac8461943b06eb61c710f6d4a8d3ac9cd.md)

### `MIDIDeviceDelegate::recv_pwc` ###
Pitch wheel change callback. [MIDI\_STATUS\_PITCH\_WHEEL\_CHANGE](group___m_i_d_i_1ga5ccf32074e5679bad67653efa8002888.md)

### `MIDIDeviceDelegate::recv_sx` ###
System exclusive callback. [MIDI\_STATUS\_SYSTEM\_EXCLUSIVE](group___m_i_d_i_1ga99239cc83091295b41695327d9735c14.md)

### `MIDIDeviceDelegate::recv_tcqf` ###
Time code quarter frame callback. [MIDI\_STATUS\_TIME\_CODE\_QUARTER\_FRAME](group___m_i_d_i_1ga9968ce10ea1a19f32847896dde9ad58c.md)

### `MIDIDeviceDelegate::recv_spp` ###
Song position pointer callback. [MIDI\_STATUS\_SONG\_POSITION\_POINTER](group___m_i_d_i_1gaa965eb7d2e85dbcb48e62a5a833a191c.md)

### `MIDIDeviceDelegate::recv_ss` ###
Song select callback. [MIDI\_STATUS\_SONG\_SELECT](group___m_i_d_i_1ga61e127bbfbe17cca1135d999d74e6426.md)

### `MIDIDeviceDelegate::recv_tr` ###
Tune request callback. [MIDI\_STATUS\_TUNE\_REQUEST](group___m_i_d_i_1gac84f77995b04995520760a4affa138be.md)

### `MIDIDeviceDelegate::recv_eox` ###
End of exclusive callback. [MIDI\_STATUS\_END\_OF\_EXCLUSIVE](group___m_i_d_i_1ga5cb64db98a73ce224423852d5a02a45e.md)

### `MIDIDeviceDelegate::recv_rt` ###
Real time callback. [MIDI\_STATUS\_TIMING\_CLOCK](group___m_i_d_i_1ga298ba5b7d2acab27e582ecd0b0759c4a.md), [MIDI\_STATUS\_START](group___m_i_d_i_1ga17fb07b1dba8fd613ad7cb8cb00f0b25.md), [MIDI\_STATUS\_CONTINUE](group___m_i_d_i_1ga9052500b5acc03a3c415f51942a77995.md), [MIDI\_STATUS\_STOP](group___m_i_d_i_1ga5c8b5cfef562c82fe7586cfe4ed296b6.md), [MIDI\_STATUS\_ACTIVE\_SENSING](group___m_i_d_i_1gace7e8de824fd226dbf6deebaeecbffe6.md), [MIDI\_STATUS\_RESET](group___m_i_d_i_1ga2e8a64d0ea2664756c1b8f9cb4f8f480.md)