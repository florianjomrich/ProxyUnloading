//
// Generated file, do not edit! Created by opp_msgc 4.4 from applications/mcoa/proxy_enhanced/messages/control_messages/FlowBindingUpdate.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "FlowBindingUpdate_m.h"

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




Register_Class(FlowBindingUpdate);

FlowBindingUpdate::FlowBindingUpdate(const char *name, int kind) : ::cPacket(name,kind)
{
    this->HomeAddress_var = 0;
    this->NewCoAdress_var = 0;
    this->DestAddress_var = 0;
    this->wasSendFromHA_var = 0;
}

FlowBindingUpdate::FlowBindingUpdate(const FlowBindingUpdate& other) : ::cPacket(other)
{
    copy(other);
}

FlowBindingUpdate::~FlowBindingUpdate()
{
}

FlowBindingUpdate& FlowBindingUpdate::operator=(const FlowBindingUpdate& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void FlowBindingUpdate::copy(const FlowBindingUpdate& other)
{
    this->HomeAddress_var = other.HomeAddress_var;
    this->NewCoAdress_var = other.NewCoAdress_var;
    this->DestAddress_var = other.DestAddress_var;
    this->wasSendFromHA_var = other.wasSendFromHA_var;
}

void FlowBindingUpdate::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->HomeAddress_var);
    doPacking(b,this->NewCoAdress_var);
    doPacking(b,this->DestAddress_var);
    doPacking(b,this->wasSendFromHA_var);
}

void FlowBindingUpdate::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->HomeAddress_var);
    doUnpacking(b,this->NewCoAdress_var);
    doUnpacking(b,this->DestAddress_var);
    doUnpacking(b,this->wasSendFromHA_var);
}

const char * FlowBindingUpdate::getHomeAddress() const
{
    return HomeAddress_var.c_str();
}

void FlowBindingUpdate::setHomeAddress(const char * HomeAddress)
{
    this->HomeAddress_var = HomeAddress;
}

const char * FlowBindingUpdate::getNewCoAdress() const
{
    return NewCoAdress_var.c_str();
}

void FlowBindingUpdate::setNewCoAdress(const char * NewCoAdress)
{
    this->NewCoAdress_var = NewCoAdress;
}

const char * FlowBindingUpdate::getDestAddress() const
{
    return DestAddress_var.c_str();
}

void FlowBindingUpdate::setDestAddress(const char * DestAddress)
{
    this->DestAddress_var = DestAddress;
}

bool FlowBindingUpdate::getWasSendFromHA() const
{
    return wasSendFromHA_var;
}

void FlowBindingUpdate::setWasSendFromHA(bool wasSendFromHA)
{
    this->wasSendFromHA_var = wasSendFromHA;
}

class FlowBindingUpdateDescriptor : public cClassDescriptor
{
  public:
    FlowBindingUpdateDescriptor();
    virtual ~FlowBindingUpdateDescriptor();

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

Register_ClassDescriptor(FlowBindingUpdateDescriptor);

FlowBindingUpdateDescriptor::FlowBindingUpdateDescriptor() : cClassDescriptor("FlowBindingUpdate", "cPacket")
{
}

FlowBindingUpdateDescriptor::~FlowBindingUpdateDescriptor()
{
}

bool FlowBindingUpdateDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<FlowBindingUpdate *>(obj)!=NULL;
}

const char *FlowBindingUpdateDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int FlowBindingUpdateDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int FlowBindingUpdateDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *FlowBindingUpdateDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "HomeAddress",
        "NewCoAdress",
        "DestAddress",
        "wasSendFromHA",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int FlowBindingUpdateDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='H' && strcmp(fieldName, "HomeAddress")==0) return base+0;
    if (fieldName[0]=='N' && strcmp(fieldName, "NewCoAdress")==0) return base+1;
    if (fieldName[0]=='D' && strcmp(fieldName, "DestAddress")==0) return base+2;
    if (fieldName[0]=='w' && strcmp(fieldName, "wasSendFromHA")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *FlowBindingUpdateDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
        "string",
        "bool",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *FlowBindingUpdateDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int FlowBindingUpdateDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    FlowBindingUpdate *pp = (FlowBindingUpdate *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string FlowBindingUpdateDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    FlowBindingUpdate *pp = (FlowBindingUpdate *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getHomeAddress());
        case 1: return oppstring2string(pp->getNewCoAdress());
        case 2: return oppstring2string(pp->getDestAddress());
        case 3: return bool2string(pp->getWasSendFromHA());
        default: return "";
    }
}

bool FlowBindingUpdateDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    FlowBindingUpdate *pp = (FlowBindingUpdate *)object; (void)pp;
    switch (field) {
        case 0: pp->setHomeAddress((value)); return true;
        case 1: pp->setNewCoAdress((value)); return true;
        case 2: pp->setDestAddress((value)); return true;
        case 3: pp->setWasSendFromHA(string2bool(value)); return true;
        default: return false;
    }
}

const char *FlowBindingUpdateDescriptor::getFieldStructName(void *object, int field) const
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
    };
    return (field>=0 && field<4) ? fieldStructNames[field] : NULL;
}

void *FlowBindingUpdateDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    FlowBindingUpdate *pp = (FlowBindingUpdate *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


