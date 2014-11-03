#pragma once
#include "dev/io_device.hh"
#include "params/HelloDevice.hh"
class BadDevice : public BasicPioDevice {
  private:
    std::string devname;
  public:
    typedef BadDeviceParams Params;
  protected:
    const Params *
    params() const {
        return dynamic_cast<const Params *>(_params);
    }
  public:
    BadDevice(Params *p);
    virtual Tick read(PacketPtr pkt);
    virtual Tick write(PacketPtr pkt);
};
