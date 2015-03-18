//
// Generated file, do not edit! Created by opp_msgc 4.4 from applications/mcoa/proxy_enhanced/messages/control_messages/ACK_RequestConnectionToLegacyServer.msg.
//

#ifndef _ACK_REQUESTCONNECTIONTOLEGACYSERVER_M_H_
#define _ACK_REQUESTCONNECTIONTOLEGACYSERVER_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0404
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif



/**
 * Class generated from <tt>applications/mcoa/proxy_enhanced/messages/control_messages/ACK_RequestConnectionToLegacyServer.msg</tt> by opp_msgc.
 * <pre>
 * packet ACK_RequestConnectionToLegacyServer {
 *     int someField;
 *     string anotherField;
 *     double arrayField1[];
 *     double arrayField2[10];
 * }
 * </pre>
 */
class ACK_RequestConnectionToLegacyServer : public ::cPacket
{
  protected:
    int someField_var;
    opp_string anotherField_var;
    double *arrayField1_var; // array ptr
    unsigned int arrayField1_arraysize;
    double arrayField2_var[10];

  private:
    void copy(const ACK_RequestConnectionToLegacyServer& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const ACK_RequestConnectionToLegacyServer&);

  public:
    ACK_RequestConnectionToLegacyServer(const char *name="ACK_RequestConnectionToLegacyServer", int kind=0);
    ACK_RequestConnectionToLegacyServer(const ACK_RequestConnectionToLegacyServer& other);
    virtual ~ACK_RequestConnectionToLegacyServer();
    ACK_RequestConnectionToLegacyServer& operator=(const ACK_RequestConnectionToLegacyServer& other);
    virtual ACK_RequestConnectionToLegacyServer *dup() const {return new ACK_RequestConnectionToLegacyServer(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getSomeField() const;
    virtual void setSomeField(int someField);
    virtual const char * getAnotherField() const;
    virtual void setAnotherField(const char * anotherField);
    virtual void setArrayField1ArraySize(unsigned int size);
    virtual unsigned int getArrayField1ArraySize() const;
    virtual double getArrayField1(unsigned int k) const;
    virtual void setArrayField1(unsigned int k, double arrayField1);
    virtual unsigned int getArrayField2ArraySize() const;
    virtual double getArrayField2(unsigned int k) const;
    virtual void setArrayField2(unsigned int k, double arrayField2);
};

inline void doPacking(cCommBuffer *b, ACK_RequestConnectionToLegacyServer& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, ACK_RequestConnectionToLegacyServer& obj) {obj.parsimUnpack(b);}


#endif // _ACK_REQUESTCONNECTIONTOLEGACYSERVER_M_H_
