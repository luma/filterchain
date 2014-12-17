// Foo Filter
'use strict';

function meta() {
  return {
    name: 'Foo'
  };
}

// Process a new packet being received. The buffer may be modified,
// and so its length
//
// @param {Packet} packet
//            Packet with the data being processed.
//
// @return true to continue processing this packet and false to discard it.
//
function onIncomingPacket(packet) {
  echo('  ' + meta().name + '.processIncoming(', packet, ')');
  return false;
}

// Process a new packet being sent.
//
// @param {Packet} packet
//              Packet with the data being processed.
//
// @return true to continue processing this packet and false to discard it.
//
function onOutgoingPacket(packet) {
  echo('  ' + meta().name + '.processOutgoing(', packet, ')');
}
