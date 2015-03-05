//
// Generated file, do not edit! Created by opp_msgc 4.4 from linklayer/contract/Radio80211aControlInfo.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "Radio80211aControlInfo_m.h"

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




Register_Class(Radio80211aControlInfo);

Radio80211aControlInfo::Radio80211aControlInfo() : ::cObject()
{
    this->snr_var = 0;
    this->lossRate_var = 0;
    this->recPow_var = 0;
}

Radio80211aControlInfo::Radio80211aControlInfo(const Radio80211aControlInfo& other) : ::cObject(other)
{
    copy(other);
}

Radio80211aControlInfo::~Radio80211aControlInfo()
{
}

Radio80211aControlInfo& Radio80211aControlInfo::operator=(const Radio80211aControlInfo& other)
{
    if (this==&other) return *this;
    ::cObject::operator=(other);
    copy(other);
    return *this;
}

void Radio80211aControlInfo::copy(const Radio80211aControlInfo& other)
{
    this->snr_var = other.snr_var;
    this->lossRate_var = other.lossRate_var;
    this->recPow_var = other.recPow_var;
    this->modulationType_var = other.modulationType_var;
}

void Radio80211aControlInfo::parsimPack(cCommBuffer *b)
{
    doPacking(b,this->snr_var);
    doPacking(b,this->lossRate_var);
    doPacking(b,this->recPow_var);
    doPacking(b,this->modulationType_var);
}

void Radio80211aControlInfo::parsimUnpack(cCommBuffer *b)
{
    doUnpacking(b,this->snr_var);
    doUnpacking(b,this->lossRate_var);
    doUnpacking(b,this->recPow_var);
    doUnpacking(b,this->modulationType_var);
}

double Radio80211aControlInfo::getSnr() const
{
    return snr_var;
}

void Radio80211aControlInfo::setSnr(double snr)
{
    this->snr_var = snr;
}

double Radio80211aControlInfo::getLossRate() const
{
    return lossRate_var;
}

void Radio80211aControlInfo::setLossRate(double lossRate)
{
    this->lossRate_var = lossRate;
}

double Radio80211aControlInfo::getRecPow() const
{
    return recPow_var;
}

void Radio80211aControlInfo::setRecPow(double recPow)
{
    this->recPow_var = recPow;
}

ModulationType& Radio80211aControlInfo::getModulationType()
{
    return modulationType_var;
}

void Radio80211aControlInfo::setModulationType(const ModulationType& modulationType)
{
    this->modulationType_var = modulationType;
}

class Radio80211aControlInfoDescriptor : public cClassDescriptor
{
  public:
    Radio80211aControlInfoDescriptor();
    virtual ~Radio80211aControlInfoDescriptor();

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

Register_ClassDescriptor(Radio80211aControlInfoDescriptor);

Radio80211aControlInfoDescriptor::Radio80211aControlInfoDescriptor() : cClassDescriptor("Radio80211aControlInfo", "cObject")
{
}

Radio80211aControlInfoDescriptor::~Radio80211aControlInfoDescriptor()
{
}

bool Radio80211aControlInfoDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<Radio80211aControlInfo *>(obj)!=NULL;
}

const char *Radio80211aControlInfoDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int Radio80211aControlInfoDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int Radio80211aControlInfoDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *Radio80211aControlInfoDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "snr",
        "lossRate",
        "recPow",
        "modulationType",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int Radio80211aControlInfoDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "snr")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "lossRate")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "recPow")==0) return base+2;
    if (fieldName[0]=='m' && strcmp(fieldName, "modulationType")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *Radio80211aControlInfoDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "double",
        "double",
        "double",
        "ModulationType",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *Radio80211aControlInfoDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int Radio80211aControlInfoDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    Radio80211aControlInfo *pp = (Radio80211aControlInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string Radio80211aControlInfoDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    Radio80211aControlInfo *pp = (Radio80211aControlInfo *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getSnr());
        case 1: return double2string(pp->getLossRate());
        case 2: return double2string(pp->getRecPow());
        case 3: {std::stringstream out; out << pp->getModulationType(); return out.str();}
        default: return "";
    }
}

bool Radio80211aControlInfoDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    Radio80211aControlInfo *pp = (Radio80211aControlInfo *)object; (void)pp;
    switch (field) {
        case 0: pp->setSnr(string2double(value)); return true;
        case 1: pp->setLossRate(string2double(value)); return true;
        case 2: pp->setRecPow(string2double(value)); return true;
        default: return false;
    }
}

const char *Radio80211aControlInfoDescriptor::getFieldStructName(void *object, int field) const
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
        "ModulationType",
    };
    return (field>=0 && field<4) ? fieldStructNames[field] : NULL;
}

void *Radio80211aControlInfoDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    Radio80211aControlInfo *pp = (Radio80211aControlInfo *)object; (void)pp;
    switch (field) {
        case 3: return (void *)(&pp->getModulationType()); break;
        default: return NULL;
    }
}


