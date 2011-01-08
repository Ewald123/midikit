#ifndef MIDIKIT_MIDI_MESSAGE_H
#define MIDIKIT_MIDI_MESSAGE_H
#include <stdlib.h>
#include "midi.h"
#include "clock.h"

struct MIDIMessage;
struct MIDIMessageList;
struct MIDIMessageList {
  struct MIDIMessage * message;
  struct MIDIMessageList * next;
};

struct MIDIMessage * MIDIMessageCreate( MIDIStatus status );
void MIDIMessageDestroy( struct MIDIMessage * message );
void MIDIMessageRetain( struct MIDIMessage * message );
void MIDIMessageRelease( struct MIDIMessage * message );

int MIDIMessageSetStatus( struct MIDIMessage * message, MIDIStatus status );
int MIDIMessageGetStatus( struct MIDIMessage * message, MIDIStatus * status );
int MIDIMessageSetTimestamp( struct MIDIMessage * message, MIDITimestamp timestamp );
int MIDIMessageGetTimestamp( struct MIDIMessage * message, MIDITimestamp * timestamp );
int MIDIMessageGetSize( struct MIDIMessage * message, size_t * size );
int MIDIMessageSet( struct MIDIMessage * message, MIDIProperty property, size_t size, void * value );
int MIDIMessageGet( struct MIDIMessage * message, MIDIProperty property, size_t size, void * value );

int MIDIMessageEncode( struct MIDIMessage * message, size_t size, unsigned char * buffer, size_t * written );
int MIDIMessageDecode( struct MIDIMessage * message, size_t size, unsigned char * buffer, size_t * read );

int MIDIMessageEncodeRunningStatus( struct MIDIMessage * message, MIDIRunningStatus * status,
                                    size_t size, unsigned char * buffer, size_t * written );
int MIDIMessageDecodeRunningStatus( struct MIDIMessage * message, MIDIRunningStatus * status,
                                    size_t size, unsigned char * buffer, size_t * read );

int MIDIMessageEncodeList( struct MIDIMessageList * messages, size_t size, unsigned char * buffer, size_t * written );
int MIDIMessageDecodeList( struct MIDIMessageList * messages, size_t size, unsigned char * buffer, size_t * read );

#endif
