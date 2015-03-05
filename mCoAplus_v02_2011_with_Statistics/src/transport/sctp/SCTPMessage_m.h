//
// Generated file, do not edit! Created by opp_msgc 4.4 from transport/sctp/SCTPMessage.msg.
//

#ifndef _SCTPMESSAGE_M_H_
#define _SCTPMESSAGE_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0404
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif

// cplusplus {{
#include "IPvXAddress.h"
// }}

// cplusplus {{
typedef cPacket *cPacketPtr;
// }}



/**
 * Class generated from <tt>transport/sctp/SCTPMessage.msg</tt> by opp_msgc.
 * <pre>
 * message SCTPSimpleMessage extends cPacket
 * {
 *      uint32 dataLen;
 *      char data[];       
 *      simtime_t creationTime = 0;
 *      bool encaps = false;
 * }
 * </pre>
 */
class SCTPSimpleMessage : public ::cPacket
{
  protected:
    uint32 dataLen_var;
    char *data_var; // array ptr
    unsigned int data_arraysize;
    simtime_t creationTime_var;
    bool encaps_var;

  private:
    void copy(const SCTPSimpleMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPSimpleMessage&);

  public:
    SCTPSimpleMessage(const char *name=NULL, int kind=0);
    SCTPSimpleMessage(const SCTPSimpleMessage& other);
    virtual ~SCTPSimpleMessage();
    SCTPSimpleMessage& operator=(const SCTPSimpleMessage& other);
    virtual SCTPSimpleMessage *dup() const {return new SCTPSimpleMessage(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual uint32 getDataLen() const;
    virtual void setDataLen(uint32 dataLen);
    virtual void setDataArraySize(unsigned int size);
    virtual unsigned int getDataArraySize() const;
    virtual char getData(unsigned int k) const;
    virtual void setData(unsigned int k, char data);
    virtual simtime_t getCreationTime() const;
    virtual void setCreationTime(simtime_t creationTime);
    virtual bool getEncaps() const;
    virtual void setEncaps(bool encaps);
};

inline void doPacking(cCommBuffer *b, SCTPSimpleMessage& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, SCTPSimpleMessage& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>transport/sctp/SCTPMessage.msg</tt> by opp_msgc.
 * <pre>
 * message SCTPMessage extends cPacket
 * {
 *      @customize(true);
 *      
 *      uint16 srcPort;
 *      
 *      uint16 destPort;
 *      
 *      uint32 tag;
 *      bool checksumOk;
 *      abstract cPacketPtr chunks[];
 * }
 * </pre>
 *
 * SCTPMessage_Base is only useful if it gets subclassed, and SCTPMessage is derived from it.
 * The minimum code to be written for SCTPMessage is the following:
 *
 * <pre>
 * class SCTPMessage : public SCTPMessage_Base
 * {
 *   private:
 *     void copy(const SCTPMessage& other) { ... }

 *   public:
 *     SCTPMessage(const char *name=NULL, int kind=0) : SCTPMessage_Base(name,kind) {}
 *     SCTPMessage(const SCTPMessage& other) : SCTPMessage_Base(other) {copy(other);}
 *     SCTPMessage& operator=(const SCTPMessage& other) {if (this==&other) return *this; SCTPMessage_Base::operator=(other); copy(other); return *this;}
 *     virtual SCTPMessage *dup() const {return new SCTPMessage(*this);}
 *     // ADD CODE HERE to redefine and implement pure virtual functions from SCTPMessage_Base
 * };
 * </pre>
 *
 * The following should go into a .cc (.cpp) file:
 *
 * <pre>
 * Register_Class(SCTPMessage);
 * </pre>
 */
class SCTPMessage_Base : public ::cPacket
{
  protected:
    uint16 srcPort_var;
    uint16 destPort_var;
    uint32 tag_var;
    bool checksumOk_var;

  private:
    void copy(const SCTPMessage_Base& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPMessage_Base&);
    // make constructors protected to avoid instantiation
    SCTPMessage_Base(const char *name=NULL, int kind=0);
    SCTPMessage_Base(const SCTPMessage_Base& other);
    // make assignment operator protected to force the user override it
    SCTPMessage_Base& operator=(const SCTPMessage_Base& other);

  public:
    virtual ~SCTPMessage_Base();
    virtual SCTPMessage_Base *dup() const {throw cRuntimeError("You forgot to manually add a dup() function to class SCTPMessage");}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual uint16 getSrcPort() const;
    virtual void setSrcPort(uint16 srcPort);
    virtual uint16 getDestPort() const;
    virtual void setDestPort(uint16 destPort);
    virtual uint32 getTag() const;
    virtual void setTag(uint32 tag);
    virtual bool getChecksumOk() const;
    virtual void setChecksumOk(bool checksumOk);
    virtual void setChunksArraySize(unsigned int size) = 0;
    virtual unsigned int getChunksArraySize() const = 0;
    virtual cPacketPtr& getChunks(unsigned int k) = 0;
    virtual const cPacketPtr& getChunks(unsigned int k) const {return const_cast<SCTPMessage_Base*>(this)->getChunks(k);}
    virtual void setChunks(unsigned int k, const cPacketPtr& chunks) = 0;
};

/**
 * Class generated from <tt>transport/sctp/SCTPMessage.msg</tt> by opp_msgc.
 * <pre>
 * message SCTPChunk extends cPacket
 * {
 *      @customize(false);
 *      
 *      uint8 chunkType;
 * }
 * </pre>
 */
class SCTPChunk : public ::cPacket
{
  protected:
    uint8 chunkType_var;

  private:
    void copy(const SCTPChunk& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPChunk&);

  public:
    SCTPChunk(const char *name=NULL, int kind=0);
    SCTPChunk(const SCTPChunk& other);
    virtual ~SCTPChunk();
    SCTPChunk& operator=(const SCTPChunk& other);
    virtual SCTPChunk *dup() const {return new SCTPChunk(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual uint8 getChunkType() const;
    virtual void setChunkType(uint8 chunkType);
};

inline void doPacking(cCommBuffer *b, SCTPChunk& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, SCTPChunk& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>transport/sctp/SCTPMessage.msg</tt> by opp_msgc.
 * <pre>
 * message SCTPInitChunk extends SCTPChunk
 * {
 *      
 *      uint32 initTag;
 *      
 *      uint32 a_rwnd;
 *      
 *      uint16 noOutStreams;
 *      
 *      uint16 noInStreams;
 *      
 *      uint32 initTSN;
 *      bool forwardTsn;
 *      IPvXAddress addresses[];
 *      uint8 unrecognizedParameters[]; 
 * }
 * </pre>
 */
class SCTPInitChunk : public ::SCTPChunk
{
  protected:
    uint32 initTag_var;
    uint32 a_rwnd_var;
    uint16 noOutStreams_var;
    uint16 noInStreams_var;
    uint32 initTSN_var;
    bool forwardTsn_var;
    IPvXAddress *addresses_var; // array ptr
    unsigned int addresses_arraysize;
    uint8 *unrecognizedParameters_var; // array ptr
    unsigned int unrecognizedParameters_arraysize;

  private:
    void copy(const SCTPInitChunk& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPInitChunk&);

  public:
    SCTPInitChunk(const char *name=NULL, int kind=0);
    SCTPInitChunk(const SCTPInitChunk& other);
    virtual ~SCTPInitChunk();
    SCTPInitChunk& operator=(const SCTPInitChunk& other);
    virtual SCTPInitChunk *dup() const {return new SCTPInitChunk(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual uint32 getInitTag() const;
    virtual void setInitTag(uint32 initTag);
    virtual uint32 getA_rwnd() const;
    virtual void setA_rwnd(uint32 a_rwnd);
    virtual uint16 getNoOutStreams() const;
    virtual void setNoOutStreams(uint16 noOutStreams);
    virtual uint16 getNoInStreams() const;
    virtual void setNoInStreams(uint16 noInStreams);
    virtual uint32 getInitTSN() const;
    virtual void setInitTSN(uint32 initTSN);
    virtual bool getForwardTsn() const;
    virtual void setForwardTsn(bool forwardTsn);
    virtual void setAddressesArraySize(unsigned int size);
    virtual unsigned int getAddressesArraySize() const;
    virtual IPvXAddress& getAddresses(unsigned int k);
    virtual const IPvXAddress& getAddresses(unsigned int k) const {return const_cast<SCTPInitChunk*>(this)->getAddresses(k);}
    virtual void setAddresses(unsigned int k, const IPvXAddress& addresses);
    virtual void setUnrecognizedParametersArraySize(unsigned int size);
    virtual unsigned int getUnrecognizedParametersArraySize() const;
    virtual uint8 getUnrecognizedParameters(unsigned int k) const;
    virtual void setUnrecognizedParameters(unsigned int k, uint8 unrecognizedParameters);
};

inline void doPacking(cCommBuffer *b, SCTPInitChunk& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, SCTPInitChunk& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>transport/sctp/SCTPMessage.msg</tt> by opp_msgc.
 * <pre>
 * message SCTPInitAckChunk extends SCTPChunk
 * {
 *      
 *      uint32 initTag;
 *      
 *      uint32 a_rwnd;
 *      
 *      uint16 noOutStreams;
 *      
 *      uint16 noInStreams;
 *      
 *      uint32 initTSN;
 *      bool forwardTsn;
 *      IPvXAddress addresses[];
 *      char cookie[];
 *      uint8 unrecognizedParameters[];
 *      cPacketPtr stateCookie;
 * }
 * </pre>
 */
class SCTPInitAckChunk : public ::SCTPChunk
{
  protected:
    uint32 initTag_var;
    uint32 a_rwnd_var;
    uint16 noOutStreams_var;
    uint16 noInStreams_var;
    uint32 initTSN_var;
    bool forwardTsn_var;
    IPvXAddress *addresses_var; // array ptr
    unsigned int addresses_arraysize;
    char *cookie_var; // array ptr
    unsigned int cookie_arraysize;
    uint8 *unrecognizedParameters_var; // array ptr
    unsigned int unrecognizedParameters_arraysize;
    cPacketPtr stateCookie_var;

  private:
    void copy(const SCTPInitAckChunk& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPInitAckChunk&);

  public:
    SCTPInitAckChunk(const char *name=NULL, int kind=0);
    SCTPInitAckChunk(const SCTPInitAckChunk& other);
    virtual ~SCTPInitAckChunk();
    SCTPInitAckChunk& operator=(const SCTPInitAckChunk& other);
    virtual SCTPInitAckChunk *dup() const {return new SCTPInitAckChunk(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual uint32 getInitTag() const;
    virtual void setInitTag(uint32 initTag);
    virtual uint32 getA_rwnd() const;
    virtual void setA_rwnd(uint32 a_rwnd);
    virtual uint16 getNoOutStreams() const;
    virtual void setNoOutStreams(uint16 noOutStreams);
    virtual uint16 getNoInStreams() const;
    virtual void setNoInStreams(uint16 noInStreams);
    virtual uint32 getInitTSN() const;
    virtual void setInitTSN(uint32 initTSN);
    virtual bool getForwardTsn() const;
    virtual void setForwardTsn(bool forwardTsn);
    virtual void setAddressesArraySize(unsigned int size);
    virtual unsigned int getAddressesArraySize() const;
    virtual IPvXAddress& getAddresses(unsigned int k);
    virtual const IPvXAddress& getAddresses(unsigned int k) const {return const_cast<SCTPInitAckChunk*>(this)->getAddresses(k);}
    virtual void setAddresses(unsigned int k, const IPvXAddress& addresses);
    virtual void setCookieArraySize(unsigned int size);
    virtual unsigned int getCookieArraySize() const;
    virtual char getCookie(unsigned int k) const;
    virtual void setCookie(unsigned int k, char cookie);
    virtual void setUnrecognizedParametersArraySize(unsigned int size);
    virtual unsigned int getUnrecognizedParametersArraySize() const;
    virtual uint8 getUnrecognizedParameters(unsigned int k) const;
    virtual void setUnrecognizedParameters(unsigned int k, uint8 unrecognizedParameters);
    virtual cPacketPtr& getStateCookie();
    virtual const cPacketPtr& getStateCookie() const {return const_cast<SCTPInitAckChunk*>(this)->getStateCookie();}
    virtual void setStateCookie(const cPacketPtr& stateCookie);
};

inline void doPacking(cCommBuffer *b, SCTPInitAckChunk& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, SCTPInitAckChunk& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>transport/sctp/SCTPMessage.msg</tt> by opp_msgc.
 * <pre>
 * message SCTPCookieEchoChunk extends SCTPChunk
 * {
 *      char cookie[];
 *      cPacketPtr stateCookie;
 *      uint8 unrecognizedParameters[]; 
 * }
 * </pre>
 */
class SCTPCookieEchoChunk : public ::SCTPChunk
{
  protected:
    char *cookie_var; // array ptr
    unsigned int cookie_arraysize;
    cPacketPtr stateCookie_var;
    uint8 *unrecognizedParameters_var; // array ptr
    unsigned int unrecognizedParameters_arraysize;

  private:
    void copy(const SCTPCookieEchoChunk& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPCookieEchoChunk&);

  public:
    SCTPCookieEchoChunk(const char *name=NULL, int kind=0);
    SCTPCookieEchoChunk(const SCTPCookieEchoChunk& other);
    virtual ~SCTPCookieEchoChunk();
    SCTPCookieEchoChunk& operator=(const SCTPCookieEchoChunk& other);
    virtual SCTPCookieEchoChunk *dup() const {return new SCTPCookieEchoChunk(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual void setCookieArraySize(unsigned int size);
    virtual unsigned int getCookieArraySize() const;
    virtual char getCookie(unsigned int k) const;
    virtual void setCookie(unsigned int k, char cookie);
    virtual cPacketPtr& getStateCookie();
    virtual const cPacketPtr& getStateCookie() const {return const_cast<SCTPCookieEchoChunk*>(this)->getStateCookie();}
    virtual void setStateCookie(const cPacketPtr& stateCookie);
    virtual void setUnrecognizedParametersArraySize(unsigned int size);
    virtual unsigned int getUnrecognizedParametersArraySize() const;
    virtual uint8 getUnrecognizedParameters(unsigned int k) const;
    virtual void setUnrecognizedParameters(unsigned int k, uint8 unrecognizedParameters);
};

inline void doPacking(cCommBuffer *b, SCTPCookieEchoChunk& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, SCTPCookieEchoChunk& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>transport/sctp/SCTPMessage.msg</tt> by opp_msgc.
 * <pre>
 * message SCTPCookie extends cPacket
 * {
 *      simtime_t creationTime;
 *      uint32 localTag;
 *      uint32 peerTag;
 *      uint8 localTieTag[];
 *      uint8 peerTieTag[];
 * }
 * </pre>
 */
class SCTPCookie : public ::cPacket
{
  protected:
    simtime_t creationTime_var;
    uint32 localTag_var;
    uint32 peerTag_var;
    uint8 *localTieTag_var; // array ptr
    unsigned int localTieTag_arraysize;
    uint8 *peerTieTag_var; // array ptr
    unsigned int peerTieTag_arraysize;

  private:
    void copy(const SCTPCookie& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPCookie&);

  public:
    SCTPCookie(const char *name=NULL, int kind=0);
    SCTPCookie(const SCTPCookie& other);
    virtual ~SCTPCookie();
    SCTPCookie& operator=(const SCTPCookie& other);
    virtual SCTPCookie *dup() const {return new SCTPCookie(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual simtime_t getCreationTime() const;
    virtual void setCreationTime(simtime_t creationTime);
    virtual uint32 getLocalTag() const;
    virtual void setLocalTag(uint32 localTag);
    virtual uint32 getPeerTag() const;
    virtual void setPeerTag(uint32 peerTag);
    virtual void setLocalTieTagArraySize(unsigned int size);
    virtual unsigned int getLocalTieTagArraySize() const;
    virtual uint8 getLocalTieTag(unsigned int k) const;
    virtual void setLocalTieTag(unsigned int k, uint8 localTieTag);
    virtual void setPeerTieTagArraySize(unsigned int size);
    virtual unsigned int getPeerTieTagArraySize() const;
    virtual uint8 getPeerTieTag(unsigned int k) const;
    virtual void setPeerTieTag(unsigned int k, uint8 peerTieTag);
};

inline void doPacking(cCommBuffer *b, SCTPCookie& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, SCTPCookie& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>transport/sctp/SCTPMessage.msg</tt> by opp_msgc.
 * <pre>
 * message SCTPCookieAckChunk extends SCTPChunk
 * {
 * }
 * </pre>
 */
class SCTPCookieAckChunk : public ::SCTPChunk
{
  protected:

  private:
    void copy(const SCTPCookieAckChunk& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPCookieAckChunk&);

  public:
    SCTPCookieAckChunk(const char *name=NULL, int kind=0);
    SCTPCookieAckChunk(const SCTPCookieAckChunk& other);
    virtual ~SCTPCookieAckChunk();
    SCTPCookieAckChunk& operator=(const SCTPCookieAckChunk& other);
    virtual SCTPCookieAckChunk *dup() const {return new SCTPCookieAckChunk(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
};

inline void doPacking(cCommBuffer *b, SCTPCookieAckChunk& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, SCTPCookieAckChunk& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>transport/sctp/SCTPMessage.msg</tt> by opp_msgc.
 * <pre>
 * message SCTPDataMsg extends cPacket
 * {
 *     
 *     bool eBit = 0;
 *     bool bBit = 0;
 *     simtime_t enqueuingTime;
 *     simtime_t expiryTime;
 *     uint32 ppid;
 *     IPvXAddress initialDestination;
 *     uint32 msgNum;
 *     uint16 sid;
 *     bool ordered;
 *     uint32 booksize;
 *     uint32 rtx;
 *     bool fragment;
 * }
 * </pre>
 */
class SCTPDataMsg : public ::cPacket
{
  protected:
    bool eBit_var;
    bool bBit_var;
    simtime_t enqueuingTime_var;
    simtime_t expiryTime_var;
    uint32 ppid_var;
    IPvXAddress initialDestination_var;
    uint32 msgNum_var;
    uint16 sid_var;
    bool ordered_var;
    uint32 booksize_var;
    uint32 rtx_var;
    bool fragment_var;

  private:
    void copy(const SCTPDataMsg& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPDataMsg&);

  public:
    SCTPDataMsg(const char *name=NULL, int kind=0);
    SCTPDataMsg(const SCTPDataMsg& other);
    virtual ~SCTPDataMsg();
    SCTPDataMsg& operator=(const SCTPDataMsg& other);
    virtual SCTPDataMsg *dup() const {return new SCTPDataMsg(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual bool getEBit() const;
    virtual void setEBit(bool eBit);
    virtual bool getBBit() const;
    virtual void setBBit(bool bBit);
    virtual simtime_t getEnqueuingTime() const;
    virtual void setEnqueuingTime(simtime_t enqueuingTime);
    virtual simtime_t getExpiryTime() const;
    virtual void setExpiryTime(simtime_t expiryTime);
    virtual uint32 getPpid() const;
    virtual void setPpid(uint32 ppid);
    virtual IPvXAddress& getInitialDestination();
    virtual const IPvXAddress& getInitialDestination() const {return const_cast<SCTPDataMsg*>(this)->getInitialDestination();}
    virtual void setInitialDestination(const IPvXAddress& initialDestination);
    virtual uint32 getMsgNum() const;
    virtual void setMsgNum(uint32 msgNum);
    virtual uint16 getSid() const;
    virtual void setSid(uint16 sid);
    virtual bool getOrdered() const;
    virtual void setOrdered(bool ordered);
    virtual uint32 getBooksize() const;
    virtual void setBooksize(uint32 booksize);
    virtual uint32 getRtx() const;
    virtual void setRtx(uint32 rtx);
    virtual bool getFragment() const;
    virtual void setFragment(bool fragment);
};

inline void doPacking(cCommBuffer *b, SCTPDataMsg& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, SCTPDataMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>transport/sctp/SCTPMessage.msg</tt> by opp_msgc.
 * <pre>
 * message SCTPDataChunk extends SCTPChunk
 * {
 *     
 *     bool eBit = 0;
 *     bool bBit = 0;
 *     bool uBit = 0;
 *     
 *     uint32 tsn;
 *     
 *     uint16 sid;
 *     
 *     uint16 ssn;
 *     
 *     uint32 ppid;
 *     simtime_t enqueuingTime;
 * }
 * </pre>
 */
class SCTPDataChunk : public ::SCTPChunk
{
  protected:
    bool eBit_var;
    bool bBit_var;
    bool uBit_var;
    uint32 tsn_var;
    uint16 sid_var;
    uint16 ssn_var;
    uint32 ppid_var;
    simtime_t enqueuingTime_var;

  private:
    void copy(const SCTPDataChunk& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPDataChunk&);

  public:
    SCTPDataChunk(const char *name=NULL, int kind=0);
    SCTPDataChunk(const SCTPDataChunk& other);
    virtual ~SCTPDataChunk();
    SCTPDataChunk& operator=(const SCTPDataChunk& other);
    virtual SCTPDataChunk *dup() const {return new SCTPDataChunk(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual bool getEBit() const;
    virtual void setEBit(bool eBit);
    virtual bool getBBit() const;
    virtual void setBBit(bool bBit);
    virtual bool getUBit() const;
    virtual void setUBit(bool uBit);
    virtual uint32 getTsn() const;
    virtual void setTsn(uint32 tsn);
    virtual uint16 getSid() const;
    virtual void setSid(uint16 sid);
    virtual uint16 getSsn() const;
    virtual void setSsn(uint16 ssn);
    virtual uint32 getPpid() const;
    virtual void setPpid(uint32 ppid);
    virtual simtime_t getEnqueuingTime() const;
    virtual void setEnqueuingTime(simtime_t enqueuingTime);
};

inline void doPacking(cCommBuffer *b, SCTPDataChunk& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, SCTPDataChunk& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>transport/sctp/SCTPMessage.msg</tt> by opp_msgc.
 * <pre>
 * message SCTPForwardTsnChunk extends SCTPChunk
 * {
 *      uint32 newCumTsn;
 *      uint16 sid[];
 *      short ssn[]; 
 * }
 * </pre>
 */
class SCTPForwardTsnChunk : public ::SCTPChunk
{
  protected:
    uint32 newCumTsn_var;
    uint16 *sid_var; // array ptr
    unsigned int sid_arraysize;
    short *ssn_var; // array ptr
    unsigned int ssn_arraysize;

  private:
    void copy(const SCTPForwardTsnChunk& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPForwardTsnChunk&);

  public:
    SCTPForwardTsnChunk(const char *name=NULL, int kind=0);
    SCTPForwardTsnChunk(const SCTPForwardTsnChunk& other);
    virtual ~SCTPForwardTsnChunk();
    SCTPForwardTsnChunk& operator=(const SCTPForwardTsnChunk& other);
    virtual SCTPForwardTsnChunk *dup() const {return new SCTPForwardTsnChunk(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual uint32 getNewCumTsn() const;
    virtual void setNewCumTsn(uint32 newCumTsn);
    virtual void setSidArraySize(unsigned int size);
    virtual unsigned int getSidArraySize() const;
    virtual uint16 getSid(unsigned int k) const;
    virtual void setSid(unsigned int k, uint16 sid);
    virtual void setSsnArraySize(unsigned int size);
    virtual unsigned int getSsnArraySize() const;
    virtual short getSsn(unsigned int k) const;
    virtual void setSsn(unsigned int k, short ssn);
};

inline void doPacking(cCommBuffer *b, SCTPForwardTsnChunk& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, SCTPForwardTsnChunk& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>transport/sctp/SCTPMessage.msg</tt> by opp_msgc.
 * <pre>
 * message SCTPSackChunk extends SCTPChunk
 * {
 *     
 *     uint32 cumTsnAck;
 *     
 *     uint32 a_rwnd;
 *     
 *     uint16 numGaps;
 *     
 *     uint16 numDupTsns;
 *     
 *     uint32 gapStart[];
 *     uint32 gapStop[];
 *     uint32 dupTsns[];
 *     uint32 sackSeqNum        = 0;
 * }
 * </pre>
 */
class SCTPSackChunk : public ::SCTPChunk
{
  protected:
    uint32 cumTsnAck_var;
    uint32 a_rwnd_var;
    uint16 numGaps_var;
    uint16 numDupTsns_var;
    uint32 *gapStart_var; // array ptr
    unsigned int gapStart_arraysize;
    uint32 *gapStop_var; // array ptr
    unsigned int gapStop_arraysize;
    uint32 *dupTsns_var; // array ptr
    unsigned int dupTsns_arraysize;
    uint32 sackSeqNum_var;

  private:
    void copy(const SCTPSackChunk& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPSackChunk&);

  public:
    SCTPSackChunk(const char *name=NULL, int kind=0);
    SCTPSackChunk(const SCTPSackChunk& other);
    virtual ~SCTPSackChunk();
    SCTPSackChunk& operator=(const SCTPSackChunk& other);
    virtual SCTPSackChunk *dup() const {return new SCTPSackChunk(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual uint32 getCumTsnAck() const;
    virtual void setCumTsnAck(uint32 cumTsnAck);
    virtual uint32 getA_rwnd() const;
    virtual void setA_rwnd(uint32 a_rwnd);
    virtual uint16 getNumGaps() const;
    virtual void setNumGaps(uint16 numGaps);
    virtual uint16 getNumDupTsns() const;
    virtual void setNumDupTsns(uint16 numDupTsns);
    virtual void setGapStartArraySize(unsigned int size);
    virtual unsigned int getGapStartArraySize() const;
    virtual uint32 getGapStart(unsigned int k) const;
    virtual void setGapStart(unsigned int k, uint32 gapStart);
    virtual void setGapStopArraySize(unsigned int size);
    virtual unsigned int getGapStopArraySize() const;
    virtual uint32 getGapStop(unsigned int k) const;
    virtual void setGapStop(unsigned int k, uint32 gapStop);
    virtual void setDupTsnsArraySize(unsigned int size);
    virtual unsigned int getDupTsnsArraySize() const;
    virtual uint32 getDupTsns(unsigned int k) const;
    virtual void setDupTsns(unsigned int k, uint32 dupTsns);
    virtual uint32 getSackSeqNum() const;
    virtual void setSackSeqNum(uint32 sackSeqNum);
};

inline void doPacking(cCommBuffer *b, SCTPSackChunk& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, SCTPSackChunk& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>transport/sctp/SCTPMessage.msg</tt> by opp_msgc.
 * <pre>
 * message SCTPAbortChunk extends SCTPChunk
 * {
 *      
 *      bool T_Bit = 0;
 * }
 * </pre>
 */
class SCTPAbortChunk : public ::SCTPChunk
{
  protected:
    bool T_Bit_var;

  private:
    void copy(const SCTPAbortChunk& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPAbortChunk&);

  public:
    SCTPAbortChunk(const char *name=NULL, int kind=0);
    SCTPAbortChunk(const SCTPAbortChunk& other);
    virtual ~SCTPAbortChunk();
    SCTPAbortChunk& operator=(const SCTPAbortChunk& other);
    virtual SCTPAbortChunk *dup() const {return new SCTPAbortChunk(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual bool getT_Bit() const;
    virtual void setT_Bit(bool T_Bit);
};

inline void doPacking(cCommBuffer *b, SCTPAbortChunk& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, SCTPAbortChunk& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>transport/sctp/SCTPMessage.msg</tt> by opp_msgc.
 * <pre>
 * message SCTPHeartbeatChunk extends SCTPChunk
 * {
 *      IPvXAddress remoteAddr;
 *      simtime_t timeField;
 *      char info[];
 * }
 * </pre>
 */
class SCTPHeartbeatChunk : public ::SCTPChunk
{
  protected:
    IPvXAddress remoteAddr_var;
    simtime_t timeField_var;
    char *info_var; // array ptr
    unsigned int info_arraysize;

  private:
    void copy(const SCTPHeartbeatChunk& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPHeartbeatChunk&);

  public:
    SCTPHeartbeatChunk(const char *name=NULL, int kind=0);
    SCTPHeartbeatChunk(const SCTPHeartbeatChunk& other);
    virtual ~SCTPHeartbeatChunk();
    SCTPHeartbeatChunk& operator=(const SCTPHeartbeatChunk& other);
    virtual SCTPHeartbeatChunk *dup() const {return new SCTPHeartbeatChunk(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual IPvXAddress& getRemoteAddr();
    virtual const IPvXAddress& getRemoteAddr() const {return const_cast<SCTPHeartbeatChunk*>(this)->getRemoteAddr();}
    virtual void setRemoteAddr(const IPvXAddress& remoteAddr);
    virtual simtime_t getTimeField() const;
    virtual void setTimeField(simtime_t timeField);
    virtual void setInfoArraySize(unsigned int size);
    virtual unsigned int getInfoArraySize() const;
    virtual char getInfo(unsigned int k) const;
    virtual void setInfo(unsigned int k, char info);
};

inline void doPacking(cCommBuffer *b, SCTPHeartbeatChunk& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, SCTPHeartbeatChunk& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>transport/sctp/SCTPMessage.msg</tt> by opp_msgc.
 * <pre>
 * message SCTPHeartbeatAckChunk extends SCTPChunk
 * {
 *      IPvXAddress remoteAddr;
 *      simtime_t timeField;
 *      char info[];
 * }
 * </pre>
 */
class SCTPHeartbeatAckChunk : public ::SCTPChunk
{
  protected:
    IPvXAddress remoteAddr_var;
    simtime_t timeField_var;
    char *info_var; // array ptr
    unsigned int info_arraysize;

  private:
    void copy(const SCTPHeartbeatAckChunk& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPHeartbeatAckChunk&);

  public:
    SCTPHeartbeatAckChunk(const char *name=NULL, int kind=0);
    SCTPHeartbeatAckChunk(const SCTPHeartbeatAckChunk& other);
    virtual ~SCTPHeartbeatAckChunk();
    SCTPHeartbeatAckChunk& operator=(const SCTPHeartbeatAckChunk& other);
    virtual SCTPHeartbeatAckChunk *dup() const {return new SCTPHeartbeatAckChunk(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual IPvXAddress& getRemoteAddr();
    virtual const IPvXAddress& getRemoteAddr() const {return const_cast<SCTPHeartbeatAckChunk*>(this)->getRemoteAddr();}
    virtual void setRemoteAddr(const IPvXAddress& remoteAddr);
    virtual simtime_t getTimeField() const;
    virtual void setTimeField(simtime_t timeField);
    virtual void setInfoArraySize(unsigned int size);
    virtual unsigned int getInfoArraySize() const;
    virtual char getInfo(unsigned int k) const;
    virtual void setInfo(unsigned int k, char info);
};

inline void doPacking(cCommBuffer *b, SCTPHeartbeatAckChunk& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, SCTPHeartbeatAckChunk& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>transport/sctp/SCTPMessage.msg</tt> by opp_msgc.
 * <pre>
 * message SCTPShutdownChunk extends SCTPChunk
 * {
 *      uint32 cumTsnAck;
 * }
 * </pre>
 */
class SCTPShutdownChunk : public ::SCTPChunk
{
  protected:
    uint32 cumTsnAck_var;

  private:
    void copy(const SCTPShutdownChunk& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPShutdownChunk&);

  public:
    SCTPShutdownChunk(const char *name=NULL, int kind=0);
    SCTPShutdownChunk(const SCTPShutdownChunk& other);
    virtual ~SCTPShutdownChunk();
    SCTPShutdownChunk& operator=(const SCTPShutdownChunk& other);
    virtual SCTPShutdownChunk *dup() const {return new SCTPShutdownChunk(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual uint32 getCumTsnAck() const;
    virtual void setCumTsnAck(uint32 cumTsnAck);
};

inline void doPacking(cCommBuffer *b, SCTPShutdownChunk& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, SCTPShutdownChunk& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>transport/sctp/SCTPMessage.msg</tt> by opp_msgc.
 * <pre>
 * message SCTPShutdownAckChunk extends SCTPChunk
 * {
 * }
 * </pre>
 */
class SCTPShutdownAckChunk : public ::SCTPChunk
{
  protected:

  private:
    void copy(const SCTPShutdownAckChunk& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPShutdownAckChunk&);

  public:
    SCTPShutdownAckChunk(const char *name=NULL, int kind=0);
    SCTPShutdownAckChunk(const SCTPShutdownAckChunk& other);
    virtual ~SCTPShutdownAckChunk();
    SCTPShutdownAckChunk& operator=(const SCTPShutdownAckChunk& other);
    virtual SCTPShutdownAckChunk *dup() const {return new SCTPShutdownAckChunk(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
};

inline void doPacking(cCommBuffer *b, SCTPShutdownAckChunk& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, SCTPShutdownAckChunk& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>transport/sctp/SCTPMessage.msg</tt> by opp_msgc.
 * <pre>
 * message SCTPShutdownCompleteChunk extends SCTPChunk
 * {
 *      bool TBit = 0;
 * }
 * </pre>
 */
class SCTPShutdownCompleteChunk : public ::SCTPChunk
{
  protected:
    bool TBit_var;

  private:
    void copy(const SCTPShutdownCompleteChunk& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPShutdownCompleteChunk&);

  public:
    SCTPShutdownCompleteChunk(const char *name=NULL, int kind=0);
    SCTPShutdownCompleteChunk(const SCTPShutdownCompleteChunk& other);
    virtual ~SCTPShutdownCompleteChunk();
    SCTPShutdownCompleteChunk& operator=(const SCTPShutdownCompleteChunk& other);
    virtual SCTPShutdownCompleteChunk *dup() const {return new SCTPShutdownCompleteChunk(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual bool getTBit() const;
    virtual void setTBit(bool TBit);
};

inline void doPacking(cCommBuffer *b, SCTPShutdownCompleteChunk& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, SCTPShutdownCompleteChunk& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>transport/sctp/SCTPMessage.msg</tt> by opp_msgc.
 * <pre>
 * message SCTPErrorChunk extends SCTPChunk
 * {
 *      @customize(true);
 *      bool TBit = 0;
 *      bool MBit = 0;
 *      abstract cPacketPtr parameters[];
 * }
 * </pre>
 *
 * SCTPErrorChunk_Base is only useful if it gets subclassed, and SCTPErrorChunk is derived from it.
 * The minimum code to be written for SCTPErrorChunk is the following:
 *
 * <pre>
 * class SCTPErrorChunk : public SCTPErrorChunk_Base
 * {
 *   private:
 *     void copy(const SCTPErrorChunk& other) { ... }

 *   public:
 *     SCTPErrorChunk(const char *name=NULL, int kind=0) : SCTPErrorChunk_Base(name,kind) {}
 *     SCTPErrorChunk(const SCTPErrorChunk& other) : SCTPErrorChunk_Base(other) {copy(other);}
 *     SCTPErrorChunk& operator=(const SCTPErrorChunk& other) {if (this==&other) return *this; SCTPErrorChunk_Base::operator=(other); copy(other); return *this;}
 *     virtual SCTPErrorChunk *dup() const {return new SCTPErrorChunk(*this);}
 *     // ADD CODE HERE to redefine and implement pure virtual functions from SCTPErrorChunk_Base
 * };
 * </pre>
 *
 * The following should go into a .cc (.cpp) file:
 *
 * <pre>
 * Register_Class(SCTPErrorChunk);
 * </pre>
 */
class SCTPErrorChunk_Base : public ::SCTPChunk
{
  protected:
    bool TBit_var;
    bool MBit_var;

  private:
    void copy(const SCTPErrorChunk_Base& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPErrorChunk_Base&);
    // make constructors protected to avoid instantiation
    SCTPErrorChunk_Base(const char *name=NULL, int kind=0);
    SCTPErrorChunk_Base(const SCTPErrorChunk_Base& other);
    // make assignment operator protected to force the user override it
    SCTPErrorChunk_Base& operator=(const SCTPErrorChunk_Base& other);

  public:
    virtual ~SCTPErrorChunk_Base();
    virtual SCTPErrorChunk_Base *dup() const {throw cRuntimeError("You forgot to manually add a dup() function to class SCTPErrorChunk");}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual bool getTBit() const;
    virtual void setTBit(bool TBit);
    virtual bool getMBit() const;
    virtual void setMBit(bool MBit);
    virtual void setParametersArraySize(unsigned int size) = 0;
    virtual unsigned int getParametersArraySize() const = 0;
    virtual cPacketPtr& getParameters(unsigned int k) = 0;
    virtual const cPacketPtr& getParameters(unsigned int k) const {return const_cast<SCTPErrorChunk_Base*>(this)->getParameters(k);}
    virtual void setParameters(unsigned int k, const cPacketPtr& parameters) = 0;
};

/**
 * Class generated from <tt>transport/sctp/SCTPMessage.msg</tt> by opp_msgc.
 * <pre>
 * message SCTPParameter extends cPacket
 * {
 *      uint16 parameterType;
 * }
 * </pre>
 */
class SCTPParameter : public ::cPacket
{
  protected:
    uint16 parameterType_var;

  private:
    void copy(const SCTPParameter& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const SCTPParameter&);

  public:
    SCTPParameter(const char *name=NULL, int kind=0);
    SCTPParameter(const SCTPParameter& other);
    virtual ~SCTPParameter();
    SCTPParameter& operator=(const SCTPParameter& other);
    virtual SCTPParameter *dup() const {return new SCTPParameter(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual uint16 getParameterType() const;
    virtual void setParameterType(uint16 parameterType);
};

inline void doPacking(cCommBuffer *b, SCTPParameter& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, SCTPParameter& obj) {obj.parsimUnpack(b);}


#endif // _SCTPMESSAGE_M_H_
