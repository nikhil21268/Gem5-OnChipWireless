class WirelessInterface : public MemObject
{
public:
    // ... existing code ...

    // Custom MasterPort
    class UpperPort : public MasterPort
    {
    public:
        UpperPort(const std::string &name, WirelessInterface *parent)
            : MasterPort(name, parent), parent(parent) {}

        // Implement pure virtual functions
        bool recvTimingResp(PacketPtr pkt) override;
        void recvReqRetry() override;

    private:
        WirelessInterface *parent;
    };

    // Custom SlavePort
    class LowerPort : public SlavePort
    {
    public:
        LowerPort(const std::string &name, WirelessInterface *parent)
            : SlavePort(name, parent), parent(parent) {}

        // Implement pure virtual functions
        AddrRangeList getAddrRanges() const override;
        Tick recvAtomic(PacketPtr pkt) override;
        void recvFunctional(PacketPtr pkt) override;
        bool recvTimingReq(PacketPtr pkt) override;
        void recvRespRetry() override;

    private:
        WirelessInterface *parent;
    };

    // Port declarations
    UpperPort upperPort;
    LowerPort lowerPort;

    // ... existing code ...
};
