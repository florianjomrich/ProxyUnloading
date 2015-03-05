//
// Generated file, do not edit! Created by opp_msgc 4.4 from applications/mcoa/Video/MCoAVideoStreaming.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "MCoAVideoStreaming_m.h"

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




Register_Class(MCoAVideoStreaming);

MCoAVideoStreaming::MCoAVideoStreaming(const char *name, int kind) : ::cPacket(name,kind)
{
    this->curSeq_var = 0;
    this->curTime_var = 0;
}

MCoAVideoStreaming::MCoAVideoStreaming(const MCoAVideoStreaming& other) : ::cPacket(other)
{
    copy(other);
}

MCoAVideoStreaming::~MCoAVideoStreaming()
{
}

MCoAVideoStreaming& MCoAVideoStreaming::operator=(const MCoAVideoStreaming& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void MCoAVideoStreaming::copy(const MCoAVideoStreaming& other)
{
    this->curSeq_var = other.curSeq_var;
    this->curTime_var = other.curTime_var;
}

void MCoAVideoStreaming::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->curSeq_var);
    doPacking(b,this->curTime_var);
}

void MCoAVideoStreaming::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->curSeq_var);
    doUnpacking(b,this->curTime_var);
}

int MCoAVideoStreaming::getCurSeq() const
{
    return curSeq_var;
}

void MCoAVideoStreaming::setCurSeq(int curSeq)
{
    this->curSeq_var = curSeq;
}

double MCoAVideoStreaming::getCurTime() const
{
    return curTime_var;
}

void MCoAVideoStreaming::setCurTime(double curTime)
{
    this->curTime_var = curTime;
}

class MCoAVideoStreamingDescriptor : public cClassDescriptor
{
  public:
    MCoAVideoStreamingDescriptor();
    virtual ~MCoAVideoStreamingDescriptor();

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

Register_ClassDescriptor(MCoAVideoStreamingDescriptor);

MCoAVideoStreamingDescriptor::MCoAVideoStreamingDescriptor() : cClassDescriptor("MCoAVideoStreaming", "cPacket")
{
}

MCoAVideoStreamingDescriptor::~MCoAVideoStreamingDescriptor()
{
}

bool MCoAVideoStreamingDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MCoAVideoStreaming *>(obj)!=NULL;
}

const char *MCoAVideoStreamingDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MCoAVideoStreamingDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int MCoAVideoStreamingDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *MCoAVideoStreamingDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "curSeq",
        "curTime",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int MCoAVideoStreamingDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "curSeq")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "curTime")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MCoAVideoStreamingDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "double",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *MCoAVideoStreamingDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int MCoAVideoStreamingDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MCoAVideoStreaming *pp = (MCoAVideoStreaming *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MCoAVideoStreamingDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MCoAVideoStreaming *pp = (MCoAVideoStreaming *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getCurSeq());
        case 1: return double2string(pp->getCurTime());
        default: return "";
    }
}

bool MCoAVideoStreamingDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MCoAVideoStreaming *pp = (MCoAVideoStreaming *)object; (void)pp;
    switch (field) {
        case 0: pp->setCurSeq(string2long(value)); return true;
        case 1: pp->setCurTime(string2double(value)); return true;
        default: return false;
    }
}

const char *MCoAVideoStreamingDescriptor::getFieldStructName(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *MCoAVideoStreamingDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MCoAVideoStreaming *pp = (MCoAVideoStreaming *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


