//
// Generated file, do not edit! Created by opp_msgc 4.4 from applications/mcoa/proxy_enhanced/messages/control_messages/ACK_RequestConnectionToLegacyServer.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "ACK_RequestConnectionToLegacyServer_m.h"

USING_NAMESPACE

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




Register_Class(ACK_RequestConnectionToLegacyServer);

ACK_RequestConnectionToLegacyServer::ACK_RequestConnectionToLegacyServer(const char *name, int kind) : ::cPacket(name,kind)
{
    this->SrcPort_var = 0;
    this->DestPort_var = 0;
    this->FlowSourceAddress_var = 0;
    this->SrcAddress_var = 0;
    this->DestAddress_var = 0;
}

ACK_RequestConnectionToLegacyServer::ACK_RequestConnectionToLegacyServer(const ACK_RequestConnectionToLegacyServer& other) : ::cPacket(other)
{
    copy(other);
}

ACK_RequestConnectionToLegacyServer::~ACK_RequestConnectionToLegacyServer()
{
}

ACK_RequestConnectionToLegacyServer& ACK_RequestConnectionToLegacyServer::operator=(const ACK_RequestConnectionToLegacyServer& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void ACK_RequestConnectionToLegacyServer::copy(const ACK_RequestConnectionToLegacyServer& other)
{
    this->SrcPort_var = other.SrcPort_var;
    this->DestPort_var = other.DestPort_var;
    this->FlowSourceAddress_var = other.FlowSourceAddress_var;
    this->SrcAddress_var = other.SrcAddress_var;
    this->DestAddress_var = other.DestAddress_var;
}

void ACK_RequestConnectionToLegacyServer::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->SrcPort_var);
    doPacking(b,this->DestPort_var);
    doPacking(b,this->FlowSourceAddress_var);
    doPacking(b,this->SrcAddress_var);
    doPacking(b,this->DestAddress_var);
}

void ACK_RequestConnectionToLegacyServer::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->SrcPort_var);
    doUnpacking(b,this->DestPort_var);
    doUnpacking(b,this->FlowSourceAddress_var);
    doUnpacking(b,this->SrcAddress_var);
    doUnpacking(b,this->DestAddress_var);
}

int ACK_RequestConnectionToLegacyServer::getSrcPort() const
{
    return SrcPort_var;
}

void ACK_RequestConnectionToLegacyServer::setSrcPort(int SrcPort)
{
    this->SrcPort_var = SrcPort;
}

int ACK_RequestConnectionToLegacyServer::getDestPort() const
{
    return DestPort_var;
}

void ACK_RequestConnectionToLegacyServer::setDestPort(int DestPort)
{
    this->DestPort_var = DestPort;
}

const char * ACK_RequestConnectionToLegacyServer::getFlowSourceAddress() const
{
    return FlowSourceAddress_var.c_str();
}

void ACK_RequestConnectionToLegacyServer::setFlowSourceAddress(const char * FlowSourceAddress)
{
    this->FlowSourceAddress_var = FlowSourceAddress;
}

const char * ACK_RequestConnectionToLegacyServer::getSrcAddress() const
{
    return SrcAddress_var.c_str();
}

void ACK_RequestConnectionToLegacyServer::setSrcAddress(const char * SrcAddress)
{
    this->SrcAddress_var = SrcAddress;
}

const char * ACK_RequestConnectionToLegacyServer::getDestAddress() const
{
    return DestAddress_var.c_str();
}

void ACK_RequestConnectionToLegacyServer::setDestAddress(const char * DestAddress)
{
    this->DestAddress_var = DestAddress;
}

class ACK_RequestConnectionToLegacyServerDescriptor : public cClassDescriptor
{
  public:
    ACK_RequestConnectionToLegacyServerDescriptor();
    virtual ~ACK_RequestConnectionToLegacyServerDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(ACK_RequestConnectionToLegacyServerDescriptor);

ACK_RequestConnectionToLegacyServerDescriptor::ACK_RequestConnectionToLegacyServerDescriptor() : cClassDescriptor("ACK_RequestConnectionToLegacyServer", "cPacket")
{
}

ACK_RequestConnectionToLegacyServerDescriptor::~ACK_RequestConnectionToLegacyServerDescriptor()
{
}

bool ACK_RequestConnectionToLegacyServerDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ACK_RequestConnectionToLegacyServer *>(obj)!=NULL;
}

const char *ACK_RequestConnectionToLegacyServerDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ACK_RequestConnectionToLegacyServerDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int ACK_RequestConnectionToLegacyServerDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *ACK_RequestConnectionToLegacyServerDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "SrcPort",
        "DestPort",
        "FlowSourceAddress",
        "SrcAddress",
        "DestAddress",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int ACK_RequestConnectionToLegacyServerDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='S' && strcmp(fieldName, "SrcPort")==0) return base+0;
    if (fieldName[0]=='D' && strcmp(fieldName, "DestPort")==0) return base+1;
    if (fieldName[0]=='F' && strcmp(fieldName, "FlowSourceAddress")==0) return base+2;
    if (fieldName[0]=='S' && strcmp(fieldName, "SrcAddress")==0) return base+3;
    if (fieldName[0]=='D' && strcmp(fieldName, "DestAddress")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ACK_RequestConnectionToLegacyServerDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "string",
        "string",
        "string",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *ACK_RequestConnectionToLegacyServerDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int ACK_RequestConnectionToLegacyServerDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ACK_RequestConnectionToLegacyServer *pp = (ACK_RequestConnectionToLegacyServer *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string ACK_RequestConnectionToLegacyServerDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ACK_RequestConnectionToLegacyServer *pp = (ACK_RequestConnectionToLegacyServer *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSrcPort());
        case 1: return long2string(pp->getDestPort());
        case 2: return oppstring2string(pp->getFlowSourceAddress());
        case 3: return oppstring2string(pp->getSrcAddress());
        case 4: return oppstring2string(pp->getDestAddress());
        default: return "";
    }
}

bool ACK_RequestConnectionToLegacyServerDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ACK_RequestConnectionToLegacyServer *pp = (ACK_RequestConnectionToLegacyServer *)object; (void)pp;
    switch (field) {
        case 0: pp->setSrcPort(string2long(value)); return true;
        case 1: pp->setDestPort(string2long(value)); return true;
        case 2: pp->setFlowSourceAddress((value)); return true;
        case 3: pp->setSrcAddress((value)); return true;
        case 4: pp->setDestAddress((value)); return true;
        default: return false;
    }
}

const char *ACK_RequestConnectionToLegacyServerDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<5) ? fieldStructNames[field] : NULL;
}

void *ACK_RequestConnectionToLegacyServerDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ACK_RequestConnectionToLegacyServer *pp = (ACK_RequestConnectionToLegacyServer *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


