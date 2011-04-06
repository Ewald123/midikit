#ifndef MIDIKIT_DRIVER_APPLEMIDI_H
#define MIDIKIT_DRIVER_APPLEMIDI_H
#include <sys/socket.h>

/*struct MIDIDriverDelegate;
struct MIDIRunloopSource;*/

#ifndef MIDI_DRIVER_INTERNALS
/**
 * When used as an opaque pointer type, an instance of
 * MIDIDriverAppleMIDI can be used as a MIDIDriver.
 */
#define MIDIDriverAppleMIDI MIDIDriver
#endif

struct MIDIMessage;
struct MIDIDriverAppleMIDI;

#define MIDI_APPLEMIDI_PEER_DID_SEND_INVITATION   3000
#define MIDI_APPLEMIDI_PEER_DID_ACCEPT_INVITATION 3001
#define MIDI_APPLEMIDI_PEER_DID_REJECT_INVITATION 3002
#define MIDI_APPLEMIDI_PEER_DID_END_SESSION       3003

struct MIDIDriverAppleMIDI * MIDIDriverAppleMIDICreate( char * name, unsigned short port );

int MIDIDriverAppleMIDISetPort( struct MIDIDriverAppleMIDI * driver, unsigned short port ); 
int MIDIDriverAppleMIDIGetPort( struct MIDIDriverAppleMIDI * driver, unsigned short * port ); 

int MIDIDriverAppleMIDIAcceptFromNone( struct MIDIDriverAppleMIDI * driver );
int MIDIDriverAppleMIDIAcceptFromAny( struct MIDIDriverAppleMIDI * driver );
int MIDIDriverAppleMIDIAcceptFromPeer( struct MIDIDriverAppleMIDI * driver, char * address, unsigned short port );

int MIDIDriverAppleMIDIAddPeerWithSockaddr( struct MIDIDriverAppleMIDI * driver, socklen_t size, struct sockaddr * addr );
int MIDIDriverAppleMIDIRemovePeerWithSockaddr( struct MIDIDriverAppleMIDI * driver, socklen_t size, struct sockaddr * addr );
int MIDIDriverAppleMIDIAddPeer( struct MIDIDriverAppleMIDI * driver, char * address, unsigned short port );
int MIDIDriverAppleMIDIRemovePeer( struct MIDIDriverAppleMIDI * driver, char * address, unsigned short port );

int MIDIDriverAppleMIDISetRTPSocket( struct MIDIDriverAppleMIDI * driver, int socket );
int MIDIDriverAppleMIDIGetRTPSocket( struct MIDIDriverAppleMIDI * driver, int * socket );
int MIDIDriverAppleMIDISetControlSocket( struct MIDIDriverAppleMIDI * driver, int socket );
int MIDIDriverAppleMIDIGetControlSocket( struct MIDIDriverAppleMIDI * driver, int * socket );

/*
int MIDIDriverAppleMIDIReceiveMessage( struct MIDIDriverAppleMIDI * driver, struct MIDIMessage * message );
int MIDIDriverAppleMIDISendMessage( struct MIDIDriverAppleMIDI * driver, struct MIDIMessage * message );

int MIDIDriverAppleMIDIReceive( struct MIDIDriverAppleMIDI * driver );
int MIDIDriverAppleMIDISend( struct MIDIDriverAppleMIDI * driver );
int MIDIDriverAppleMIDIIdle( struct MIDIDriverAppleMIDI * driver );

int MIDIDriverAppleMIDIGetRunloopSource( struct MIDIDriverAppleMIDI * driver, struct MIDIRunloopSource ** source );
*/
#endif
