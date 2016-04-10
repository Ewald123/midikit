# RTPPacketInfo #
RTP packet information.
```
#include <rtp.h>

struct RTPPacketInfo;
```
Hold information, data for one RTP packet. The RTP header has the following format:

<pre>
0                   1                   2                   3<br>
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1<br>
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+<br>
| V |P|X|  CC   |M|     PT      |        Sequence number        |<br>
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+<br>
|                           Timestamp                           |<br>
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+<br>
|                             SSRC                              |<br>
+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+<br>
|            contributing source (CSRC) identifiers             |<br>
|                             ....                              |<br>
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+<br>
</pre>

The first twelve octets are present in every RTP packet, while the list of CSRC identifiers is present only when inserted by a mixer.


#### Version (V): 2 bits. ####
The version field identifies the version of RTP. The version we use and the one specified by RFC3550 is two (2). (The value 1 is used by the first draft version of RTP and the value 0 is used by the protocol initially implemented in the "vat" audio tool.)
#### Padding (P): 1 bit. ####
If the padding bit is set, the packet contains one or more additional padding octets at the end which are not part of the payload. The last octet of the padding contains a count of how many padding octets should be ignored, including itself. Padding may be needed by some encryption algorithms with fixed block sizes or for carrying several RTP packets in a lower-layer protocol data unit.
> (See [RTPPacketInfo::padding](struct_r_t_p_packet_info_1aaa8c79cdd040dc5cb2cec895f1ab3bdd.md))
#### Extension (X): 1 bit. ####
If the extension bit is set, the fixed header MUST be followed by exactly one header extension.
> (See [RTPPacketInfo::extension](struct_r_t_p_packet_info_1a7f1131031387cb743b5359408b06c2ff.md))
#### CSRC count (CC): 4 bits. ####

> (See [RTPPacketInfo::csrc\_count](struct_r_t_p_packet_info_1a26c874cdb2f6be1acb02f36eabeb2dcd.md))
#### Marker (M): 1 bit. ####
It is intended to allow significant events such as frame boundaries to be marked in the packet stream. A profile MAY define additional marker bits or specify that there is no marker bit by changing the number of bits in the payload type field.
> (See [RTPPacketInfo::marker](struct_r_t_p_packet_info_1aeb83e74c7ea0cb898f120d8a8104d43f.md))
#### Payload type (PT): 7 bits. ####
A profile MAY specify a default static mapping of payload type codes to payload formats.
> (See [RTPPacketInfo::payload\_type](struct_r_t_p_packet_info_1a232ad225a97b4e57b6860b6b1c6a058d.md))
#### Sequence number: 16 bits. ####
The initial value of the sequence number SHOULD be random (unpredictable) to make known-plaintext attacks on encryption more difficult, even if the source itself does not encrypt, because the packets may flow through a translator that does.
> (See [RTPPacketInfo::sequence\_number](struct_r_t_p_packet_info_1a20c0040b1014d5b3d620e9666d49254e.md))
#### Timestamp: 32 bits. ####
The sampling instant MUST be derived from a clock that increments monotonically and linearly in time to allow synchronization and jitter calculations.
> (See [RTPPacketInfo::timestamp](struct_r_t_p_packet_info_1a05b2a90f1abce5f2b9bf45f4024b4a52.md))
#### SSRC: 32 bits. ####
This identifier SHOULD be chosen randomly, with the intent that no two synchronization sources within the same RTP session will have the same SSRC identifier.
> (See [RTPPacketInfo::ssrc](struct_r_t_p_packet_info_1a0f7a62bb6892c5316058bb515e096d18.md))
#### CSRC list: 0 to 15 items, 32 bits each. ####
The number of identifiers is given by the CC field. If there are more than 15 contributing sources, only 15 can can be identified. CSRC identifiers are inserted by mixers, using the SSRC identifiers of contributing sources. For example, for audio packets the SSRC identifiers of all sources that were mixed together to create a packet are listed, allowing correct talker indication at the receiver.
> (See [RTPPacketInfo::csrc](struct_r_t_p_packet_info_1a57484de430b3fe6a870c0f9e5f115ede.md))
RTP header extension.

The RTP header extension has the following format:

<pre>
0                   1                   2                   3<br>
0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1<br>
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+<br>
|      defined by profile       |           length              |<br>
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+<br>
|                        header extension                       |<br>
|                             ....                              |<br>
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+<br>
</pre>

An extension mechanism is provided to allow individual implementations to experiment with new payload-format-independent functions that require additional information to be carried in the RTP data packet header. This mechanism is designed so that the header extension may be ignored by other interoperating implementations that have not been extended.

Defined by profile: 16 bits.

To allow multiple interoperating implementations to each experiment independently with different header extensions, or to allow a particular implementation to experiment with more than one type of header extension, the first 16 bits of the header extension are left open for distinguishing identifiers or parameters. The format of these 16 bits is to be defined by the profile specification under which the implementations are operating. This RTP specification does not define any header extensions itself.


#### Length: 16 bits. ####
The length field counts the number of 32-bit words in the extension, excluding the four-octet extension header (therefore zero is a valid length).
#### Header extension. ####
The header extension may contain arbitary data defined by one or more profiles.




---

## Public Attributes ##


### `RTPPacketInfo::peer` ###
The peer associated with the packet. This can either be the peer that originally sent the packet we did receive or it can be the peer that the packet should be sent to.

### `RTPPacketInfo::padding` ###
The number of padding bytes following the payload. If the padding bit is set, the packet contains one or more additional padding octets at the end which are not part of the payload. The last octet of the padding contains a count of how many padding octets should be ignored, including itself. Padding may be needed by some encryption algorithms with fixed block sizes or for carrying several RTP packets in a lower-layer protocol data unit.

### `RTPPacketInfo::extension` ###
Set if the first `iovec` element is used as a header extension. If the extension bit is set, the fixed header MUST be followed by exactly one header extension.

### `RTPPacketInfo::csrc_count` ###
The CSRC count contains the number of CSRC identifiers that follow the fixed header.

### `RTPPacketInfo::marker` ###
The interpretation of the marker is defined by a profile. It is intended to allow significant events such as frame boundaries to be marked in the packet stream. A profile MAY define additional marker bits or specify that there is no marker bit by changing the number of bits in the payload type field.

### `RTPPacketInfo::payload_type` ###
This field identifies the format of the RTP payload and determines its interpretation by the application. A profile MAY specify a default static mapping of payload type codes to payload formats.

### `RTPPacketInfo::sequence_number` ###
The sequence number increments by one for each RTP data packet sent, and may be used by the receiver to detect packet loss and to restore packet sequence. The initial value of the sequence number SHOULD be random (unpredictable) to make known-plaintext attacks on encryption more difficult, even if the source itself does not encrypt, because the packets may flow through a translator that does.

### `RTPPacketInfo::timestamp` ###
The timestamp reflects the sampling instant of the first octet in the RTP data packet. The sampling instant MUST be derived from a clock that increments monotonically and linearly in time to allow synchronization and jitter calculations.

### `RTPPacketInfo::ssrc` ###
The SSRC field identifies the synchronization source. This identifier SHOULD be chosen randomly, with the intent that no two synchronization sources within the same RTP session will have the same SSRC identifier.

### `RTPPacketInfo::csrc` ###
The CSRC list identifies the contributing sources for the payload contained in this packet. The number of identifiers is given by the CC field. If there are more than 15 contributing sources, only 15 can can be identified. CSRC identifiers are inserted by mixers, using the SSRC identifiers of contributing sources. For example, for audio packets the SSRC identifiers of all sources that were mixed together to create a packet are listed, allowing correct talker indication at the receiver.

### `RTPPacketInfo::total_size` ###
The total size of the sent or received RTP packet. The total size includes all RTP-Header informatio and the padding. It only acts as an information for the payload implementation. It is never read or interpreted by the RTP session.

### `RTPPacketInfo::payload_size` ###
The total payload size including all `iovec` elements.

### `RTPPacketInfo::iovlen` ###
The number of elements in the `iovec` structure.

### `RTPPacketInfo::iov` ###
A number of iovec elements that belong to the packet.