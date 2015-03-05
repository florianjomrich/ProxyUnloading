//
// Generated file, do not edit! Created by opp_msgc 4.4 from applications/mcoa/VoIP/MCOAVoIPMsg.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "MCOAVoIPMsg_m.h"

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




Register_Class(MCoAVoIPMsg);

MCoAVoIPMsg::MCoAVoIPMsg(const char *name, int kind) : ::cPacket(name,kind)
{
    this->isRequest_var = true;
    this->curSeq_var = 0;
    this->curTime_var = 0;
}

MCoAVoIPMsg::MCoAVoIPMsg(const MCoAVoIPMsg& other) : ::cPacket(other)
{
    copy(other);
}

MCoAVoIPMsg::~MCoAVoIPMsg()
{
}

MCoAVoIPMsg& MCoAVoIPMsg::operator=(const MCoAVoIPMsg& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void MCoAVoIPMsg::copy(const MCoAVoIPMsg& other)
{
    this->isRequest_var = other.isRequest_var;
    this->curSeq_var = other.curSeq_var;
    this->curTime_var = other.curTime_var;
}

void MCoAVoIPMsg::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->isRequest_var);
    doPacking(b,this->curSeq_var);
    doPacking(b,this->curTime_var);
}

void MCoAVoIPMsg::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->isRequest_var);
    doUnpacking(b,this->curSeq_var);
    doUnpacking(b,this->curTime_var);
}

bool MCoAVoIPMsg::getIsRequest() const
{
    return isRequest_var;
}

void MCoAVoIPMsg::setIsRequest(bool isRequest)
{
    this->isRequest_var = isRequest;
}

int MCoAVoIPMsg::getCurSeq() const
{
    return curSeq_var;
}

void MCoAVoIPMsg::setCurSeq(int curSeq)
{
    this->curSeq_var = curSeq;
}

double MCoAVoIPMsg::getCurTime() const
{
    return curTime_var;
}

void MCoAVoIPMsg::setCurTime(double curTime)
{
    this->curTime_var = curTime;
}

class MCoAVoIPMsgDescriptor : public cClassDescriptor
{
  public:
    MCoAVoIPMsgDescriptor();
    virtual ~MCoAVoIPMsgDescriptor();

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

Register_ClassDescriptor(MCoAVoIPMsgDescriptor);

MCoAVoIPMsgDescriptor::MCoAVoIPMsgDescriptor() : cClassDescriptor("MCoAVoIPMsg", "cPacket")
{
}

MCoAVoIPMsgDescriptor::~MCoAVoIPMsgDescriptor()
{
}

bool MCoAVoIPMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MCoAVoIPMsg *>(obj)!=NULL;
}

const char *MCoAVoIPMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MCoAVoIPMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int MCoAVoIPMsgDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *MCoAVoIPMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "isRequest",
        "curSeq",
        "curTime",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int MCoAVoIPMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "isRequest")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "curSeq")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "curTime")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MCoAVoIPMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "int",
        "double",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *MCoAVoIPMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int MCoAVoIPMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MCoAVoIPMsg *pp = (MCoAVoIPMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MCoAVoIPMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MCoAVoIPMsg *pp = (MCoAVoIPMsg *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getIsRequest());
        case 1: return long2string(pp->getCurSeq());
        case 2: return double2string(pp->getCurTime());
        default: return "";
    }
}

bool MCoAVoIPMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MCoAVoIPMsg *pp = (MCoAVoIPMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setIsRequest(string2bool(value)); return true;
        case 1: pp->setCurSeq(string2long(value)); return true;
        case 2: pp->setCurTime(string2double(value)); return true;
        default: return false;
    }
}

const char *MCoAVoIPMsgDescriptor::getFieldStructName(void *object, int field) const
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
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *MCoAVoIPMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MCoAVoIPMsg *pp = (MCoAVoIPMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


