#include <string>
#include "base/trace.hh"
#include "dev/baddev.hh"
#include "params/BadDevice.hh"
#include "sim/system.hh"
using namespace std;
BadDevice::BadDevice(Params *p)
    : BasicPioDevice(p, 0x10), devname(p->devicename){
}
Tick BadDevice::read(PacketPtr pkt) {
    Addr daddr = pkt->getAddr() - pioAddr;
    assert(pkt->getSize() == 8);
    pkt->allocate();
    pkt->set((uint64_t)0);
    pkt->makeAtomicResponse();
    warn("Device %s : Read request at offset %#X", devname, daddr);
    return pioDelay;
}
Tick BadDevice::write(PacketPtr pkt) {
    Addr daddr = pkt->getAddr() - pioAddr;
    assert(pkt->getSize() == 8);
    pkt->makeAtomicResponse();
    warn("Device %s : Write request at offset %#X", devname, daddr);
    return pioDelay;
}
BadDevice * BadDeviceParams::create() {
    return new BadDevice(this);
}
