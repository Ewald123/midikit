#ifndef MIDIKIT_DRIVER_APPLEMIDI_H
#define MIDIKIT_DRIVER_APPLEMIDI_H
#include <stdlib.h>
#include <sys/socket.h>
#include "midi/driver.h"
#include "midi/message.h"

struct MIDIDriverAppleMIDI;
extern struct MIDIDriverDelegate MIDIDriverDelegateAppleMIDI;

struct MIDIDriverAppleMIDI * MIDIDriverAppleMIDICreate();
void MIDIDriverAppleMIDIDestroy( struct MIDIDriverAppleMIDI * driver );
void MIDIDriverAppleMIDIRetain( struct MIDIDriverAppleMIDI * driver );
void MIDIDriverAppleMIDIRelease( struct MIDIDriverAppleMIDI * driver );

int MIDIDriverAppleMIDISetRTPPort( struct MIDIDriverAppleMIDI * driver, unsigned short port ); 
int MIDIDriverAppleMIDIGetRTPPort( struct MIDIDriverAppleMIDI * driver, unsigned short * port ); 
int MIDIDriverAppleMIDISetControlPort( struct MIDIDriverAppleMIDI * driver, unsigned short port ); 
int MIDIDriverAppleMIDIGetControlPort( struct MIDIDriverAppleMIDI * driver, unsigned short * port ); 

int MIDIDriverAppleMIDIAddPeer( struct MIDIDriverAppleMIDI * driver, socklen_t size, struct sockaddr * addr );
int MIDIDriverAppleMIDIRemovePeer( struct MIDIDriverAppleMIDI * driver, socklen_t size, struct sockaddr * addr );

int MIDIDriverAppleMIDISetRTPSocket( struct MIDIDriverAppleMIDI * driver, int socket );
int MIDIDriverAppleMIDIGetRTPSocket( struct MIDIDriverAppleMIDI * driver, int * socket );
int MIDIDriverAppleMIDISetControlSocket( struct MIDIDriverAppleMIDI * driver, int socket );
int MIDIDriverAppleMIDIGetControlSocket( struct MIDIDriverAppleMIDI * driver, int * socket );

int MIDIDriverAppleMIDIConnect( struct MIDIDriverAppleMIDI * driver );
int MIDIDriverAppleMIDIDisconnect( struct MIDIDriverAppleMIDI * driver );

int MIDIDriverAppleMIDIReceiveMessage( struct MIDIDriverAppleMIDI * driver, struct MIDIMessage * message );
int MIDIDriverAppleMIDISendMessage( struct MIDIDriverAppleMIDI * driver, struct MIDIMessage * message );

int MIDIDriverAppleMIDIReceive( struct MIDIDriverAppleMIDI * driver );
int MIDIDriverAppleMIDISend( struct MIDIDriverAppleMIDI * driver );
int MIDIDriverAppleMIDIIdle( struct MIDIDriverAppleMIDI * driver );

#endif