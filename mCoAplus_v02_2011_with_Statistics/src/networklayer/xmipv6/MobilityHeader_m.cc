//
// Generated file, do not edit! Created by opp_msgc 4.4 from networklayer/xmipv6/MobilityHeader.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "MobilityHeader_m.h"

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




EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("MobOpts");
    if (!e) enums.getInstance()->add(e = new cEnum("MobOpts"));
    e->insert(OPTION_PAD1, "OPTION_PAD1");
    e->insert(OPTION_PADN, "OPTION_PADN");
    e->insert(OPTION_BINDING_REFRESH_ADVICE, "OPTION_BINDING_REFRESH_ADVICE");
    e->insert(OPTION_ALTERNATE_CARE_OF_ADDRESS, "OPTION_ALTERNATE_CARE_OF_ADDRESS");
    e->insert(OPTION_NONCES_INDICES, "OPTION_NONCES_INDICES");
    e->insert(OPTION_BINDING_AUTHORIZATION_DATA, "OPTION_BINDING_AUTHORIZATION_DATA");
    e->insert(OPTION_HOME_ADDRESS, "OPTION_HOME_ADDRESS");
    e->insert(OPTION_BINDING_IDENTIFIER_MOBILITY, "OPTION_BINDING_IDENTIFIER_MOBILITY");
);

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("MobOptsPayloadLen");
    if (!e) enums.getInstance()->add(e = new cEnum("MobOptsPayloadLen"));
    e->insert(LEN_MOBOPTS_HEADER_FIELDS, "LEN_MOBOPTS_HEADER_FIELDS");
    e->insert(LEN_BINDING_REFRESH_ADVICE, "LEN_BINDING_REFRESH_ADVICE");
    e->insert(LEN_NONCE_INDICES, "LEN_NONCE_INDICES");
    e->insert(LEN_BINDING_AUTHORIZATION_DATA, "LEN_BINDING_AUTHORIZATION_DATA");
    e->insert(LEN_BID_NO_COA, "LEN_BID_NO_COA");
    e->insert(LEN_BID_WITH_COA, "LEN_BID_WITH_COA");
);

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("MobilityHeaderType");
    if (!e) enums.getInstance()->add(e = new cEnum("MobilityHeaderType"));
    e->insert(BINDING_REFRESH_REQUEST, "BINDING_REFRESH_REQUEST");
    e->insert(HOME_TEST_INIT, "HOME_TEST_INIT");
    e->insert(CARE_OF_TEST_INIT, "CARE_OF_TEST_INIT");
    e->insert(HOME_TEST, "HOME_TEST");
    e->insert(CARE_OF_TEST, "CARE_OF_TEST");
    e->insert(BINDING_UPDATE, "BINDING_UPDATE");
    e->insert(BINDING_ACKNOWLEDGEMENT, "BINDING_ACKNOWLEDGEMENT");
    e->insert(BINDING_ERROR, "BINDING_ERROR");
);

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("BAStatus");
    if (!e) enums.getInstance()->add(e = new cEnum("BAStatus"));
    e->insert(BINDING_UPDATE_ACCEPTED, "BINDING_UPDATE_ACCEPTED");
    e->insert(BU_ACCEPT_BUT_DISCOVER_PREFIX, "BU_ACCEPT_BUT_DISCOVER_PREFIX");
    e->insert(REASON_UNSPECIFIED, "REASON_UNSPECIFIED");
    e->insert(ADMINISTRATIVELY_PROHIBITED, "ADMINISTRATIVELY_PROHIBITED");
    e->insert(INSUFFICIENT_RESOURCES, "INSUFFICIENT_RESOURCES");
    e->insert(HOME_REGISTRATION_NOT_SUPPORTED, "HOME_REGISTRATION_NOT_SUPPORTED");
    e->insert(NOT_HOME_SUBNET, "NOT_HOME_SUBNET");
    e->insert(NOT_HA_FOR_THIS_MN, "NOT_HA_FOR_THIS_MN");
    e->insert(DAD_FAILED, "DAD_FAILED");
    e->insert(SEQUENCE_NUMBER_OUT_OF_WINDOW, "SEQUENCE_NUMBER_OUT_OF_WINDOW");
    e->insert(EXPIRED_HOME_NONCE_INDEX, "EXPIRED_HOME_NONCE_INDEX");
    e->insert(EXPIRED_CARE_OF_NONCE_INDEX, "EXPIRED_CARE_OF_NONCE_INDEX");
    e->insert(EXPIRED_NONCES, "EXPIRED_NONCES");
    e->insert(REGISTRATION_TYPE_CHANGE_DISALLOWED, "REGISTRATION_TYPE_CHANGE_DISALLOWED");
    e->insert(MCOA_NOTCOMPLETE, "MCOA_NOTCOMPLETE");
    e->insert(MCOA_RETURNHOME_WO_NDP, "MCOA_RETURNHOME_WO_NDP");
    e->insert(MCOA_MALFORMED, "MCOA_MALFORMED");
    e->insert(MCOA_NON_MCOA_BINDING_EXISTS, "MCOA_NON_MCOA_BINDING_EXISTS");
    e->insert(MCOA_UNKOWN_COA, "MCOA_UNKOWN_COA");
    e->insert(MCOA_PROHIBITED, "MCOA_PROHIBITED");
    e->insert(MCOA_BULK_REGISTRATION_PROHIBITED, "MCOA_BULK_REGISTRATION_PROHIBITED");
    e->insert(MCOA_SIMULTANEOUS_HOME_AND_FOREIGN_PROHIBITED, "MCOA_SIMULTANEOUS_HOME_AND_FOREIGN_PROHIBITED");
);

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("BEStatus");
    if (!e) enums.getInstance()->add(e = new cEnum("BEStatus"));
    e->insert(UNKNOWN_BINDING_FOR_HOME_ADDRESS_DEST_OPTION, "UNKNOWN_BINDING_FOR_HOME_ADDRESS_DEST_OPTION");
    e->insert(UNKNOWN_MH_TYPE, "UNKNOWN_MH_TYPE");
);

Register_Class(MobOption);

MobOption::MobOption() : ::cObject()
{
    this->mobOptionType_var = 0;
    this->mobOptionLength_var = 0;
    this->payloadLength_var = 0;
}

MobOption::MobOption(const MobOption& other) : ::cObject(other)
{
    copy(other);
}

MobOption::~MobOption()
{
}

MobOption& MobOption::operator=(const MobOption& other)
{
    if (this==&other) return *this;
    ::cObject::operator=(other);
    copy(other);
    return *this;
}

void MobOption::copy(const MobOption& other)
{
    this->mobOptionType_var = other.mobOptionType_var;
    this->mobOptionLength_var = other.mobOptionLength_var;
    this->payloadLength_var = other.payloadLength_var;
}

void MobOption::parsimPack(cCommBuffer *b)
{
    doPacking(b,this->mobOptionType_var);
    doPacking(b,this->mobOptionLength_var);
    doPacking(b,this->payloadLength_var);
}

void MobOption::parsimUnpack(cCommBuffer *b)
{
    doUnpacking(b,this->mobOptionType_var);
    doUnpacking(b,this->mobOptionLength_var);
    doUnpacking(b,this->payloadLength_var);
}

unsigned int MobOption::getMobOptionType() const
{
    return mobOptionType_var;
}

void MobOption::setMobOptionType(unsigned int mobOptionType)
{
    this->mobOptionType_var = mobOptionType;
}

unsigned int MobOption::getMobOptionLength() const
{
    return mobOptionLength_var;
}

void MobOption::setMobOptionLength(unsigned int mobOptionLength)
{
    this->mobOptionLength_var = mobOptionLength;
}

int MobOption::getPayloadLength() const
{
    return payloadLength_var;
}

void MobOption::setPayloadLength(int payloadLength)
{
    this->payloadLength_var = payloadLength;
}

class MobOptionDescriptor : public cClassDescriptor
{
  public:
    MobOptionDescriptor();
    virtual ~MobOptionDescriptor();

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

Register_ClassDescriptor(MobOptionDescriptor);

MobOptionDescriptor::MobOptionDescriptor() : cClassDescriptor("MobOption", "cObject")
{
}

MobOptionDescriptor::~MobOptionDescriptor()
{
}

bool MobOptionDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MobOption *>(obj)!=NULL;
}

const char *MobOptionDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MobOptionDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int MobOptionDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *MobOptionDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "mobOptionType",
        "mobOptionLength",
        "payloadLength",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int MobOptionDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "mobOptionType")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "mobOptionLength")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "payloadLength")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MobOptionDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "unsigned int",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *MobOptionDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "MobOpts";
            return NULL;
        default: return NULL;
    }
}

int MobOptionDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MobOption *pp = (MobOption *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MobOptionDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MobOption *pp = (MobOption *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getMobOptionType());
        case 1: return ulong2string(pp->getMobOptionLength());
        case 2: return long2string(pp->getPayloadLength());
        default: return "";
    }
}

bool MobOptionDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MobOption *pp = (MobOption *)object; (void)pp;
    switch (field) {
        case 0: pp->setMobOptionType(string2ulong(value)); return true;
        case 1: pp->setMobOptionLength(string2ulong(value)); return true;
        case 2: pp->setPayloadLength(string2long(value)); return true;
        default: return false;
    }
}

const char *MobOptionDescriptor::getFieldStructName(void *object, int field) const
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

void *MobOptionDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MobOption *pp = (MobOption *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(MobOption_Binding_RefreshAdvice);

MobOption_Binding_RefreshAdvice::MobOption_Binding_RefreshAdvice() : ::MobOption()
{
    this->refreshInterval_var = 0;
}

MobOption_Binding_RefreshAdvice::MobOption_Binding_RefreshAdvice(const MobOption_Binding_RefreshAdvice& other) : ::MobOption(other)
{
    copy(other);
}

MobOption_Binding_RefreshAdvice::~MobOption_Binding_RefreshAdvice()
{
}

MobOption_Binding_RefreshAdvice& MobOption_Binding_RefreshAdvice::operator=(const MobOption_Binding_RefreshAdvice& other)
{
    if (this==&other) return *this;
    ::MobOption::operator=(other);
    copy(other);
    return *this;
}

void MobOption_Binding_RefreshAdvice::copy(const MobOption_Binding_RefreshAdvice& other)
{
    this->refreshInterval_var = other.refreshInterval_var;
}

void MobOption_Binding_RefreshAdvice::parsimPack(cCommBuffer *b)
{
    ::MobOption::parsimPack(b);
    doPacking(b,this->refreshInterval_var);
}

void MobOption_Binding_RefreshAdvice::parsimUnpack(cCommBuffer *b)
{
    ::MobOption::parsimUnpack(b);
    doUnpacking(b,this->refreshInterval_var);
}

unsigned int MobOption_Binding_RefreshAdvice::getRefreshInterval() const
{
    return refreshInterval_var;
}

void MobOption_Binding_RefreshAdvice::setRefreshInterval(unsigned int refreshInterval)
{
    this->refreshInterval_var = refreshInterval;
}

class MobOption_Binding_RefreshAdviceDescriptor : public cClassDescriptor
{
  public:
    MobOption_Binding_RefreshAdviceDescriptor();
    virtual ~MobOption_Binding_RefreshAdviceDescriptor();

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

Register_ClassDescriptor(MobOption_Binding_RefreshAdviceDescriptor);

MobOption_Binding_RefreshAdviceDescriptor::MobOption_Binding_RefreshAdviceDescriptor() : cClassDescriptor("MobOption_Binding_RefreshAdvice", "MobOption")
{
}

MobOption_Binding_RefreshAdviceDescriptor::~MobOption_Binding_RefreshAdviceDescriptor()
{
}

bool MobOption_Binding_RefreshAdviceDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MobOption_Binding_RefreshAdvice *>(obj)!=NULL;
}

const char *MobOption_Binding_RefreshAdviceDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MobOption_Binding_RefreshAdviceDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int MobOption_Binding_RefreshAdviceDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *MobOption_Binding_RefreshAdviceDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "refreshInterval",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int MobOption_Binding_RefreshAdviceDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "refreshInterval")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MobOption_Binding_RefreshAdviceDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *MobOption_Binding_RefreshAdviceDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int MobOption_Binding_RefreshAdviceDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MobOption_Binding_RefreshAdvice *pp = (MobOption_Binding_RefreshAdvice *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MobOption_Binding_RefreshAdviceDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MobOption_Binding_RefreshAdvice *pp = (MobOption_Binding_RefreshAdvice *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getRefreshInterval());
        default: return "";
    }
}

bool MobOption_Binding_RefreshAdviceDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MobOption_Binding_RefreshAdvice *pp = (MobOption_Binding_RefreshAdvice *)object; (void)pp;
    switch (field) {
        case 0: pp->setRefreshInterval(string2ulong(value)); return true;
        default: return false;
    }
}

const char *MobOption_Binding_RefreshAdviceDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *MobOption_Binding_RefreshAdviceDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MobOption_Binding_RefreshAdvice *pp = (MobOption_Binding_RefreshAdvice *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(MobOption_Nonce_Indices);

MobOption_Nonce_Indices::MobOption_Nonce_Indices() : ::MobOption()
{
    this->home_nonce_index_var = 0;
    this->care_of_nonce_index_var = 0;
}

MobOption_Nonce_Indices::MobOption_Nonce_Indices(const MobOption_Nonce_Indices& other) : ::MobOption(other)
{
    copy(other);
}

MobOption_Nonce_Indices::~MobOption_Nonce_Indices()
{
}

MobOption_Nonce_Indices& MobOption_Nonce_Indices::operator=(const MobOption_Nonce_Indices& other)
{
    if (this==&other) return *this;
    ::MobOption::operator=(other);
    copy(other);
    return *this;
}

void MobOption_Nonce_Indices::copy(const MobOption_Nonce_Indices& other)
{
    this->home_nonce_index_var = other.home_nonce_index_var;
    this->care_of_nonce_index_var = other.care_of_nonce_index_var;
}

void MobOption_Nonce_Indices::parsimPack(cCommBuffer *b)
{
    ::MobOption::parsimPack(b);
    doPacking(b,this->home_nonce_index_var);
    doPacking(b,this->care_of_nonce_index_var);
}

void MobOption_Nonce_Indices::parsimUnpack(cCommBuffer *b)
{
    ::MobOption::parsimUnpack(b);
    doUnpacking(b,this->home_nonce_index_var);
    doUnpacking(b,this->care_of_nonce_index_var);
}

int MobOption_Nonce_Indices::getHome_nonce_index() const
{
    return home_nonce_index_var;
}

void MobOption_Nonce_Indices::setHome_nonce_index(int home_nonce_index)
{
    this->home_nonce_index_var = home_nonce_index;
}

int MobOption_Nonce_Indices::getCare_of_nonce_index() const
{
    return care_of_nonce_index_var;
}

void MobOption_Nonce_Indices::setCare_of_nonce_index(int care_of_nonce_index)
{
    this->care_of_nonce_index_var = care_of_nonce_index;
}

class MobOption_Nonce_IndicesDescriptor : public cClassDescriptor
{
  public:
    MobOption_Nonce_IndicesDescriptor();
    virtual ~MobOption_Nonce_IndicesDescriptor();

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

Register_ClassDescriptor(MobOption_Nonce_IndicesDescriptor);

MobOption_Nonce_IndicesDescriptor::MobOption_Nonce_IndicesDescriptor() : cClassDescriptor("MobOption_Nonce_Indices", "MobOption")
{
}

MobOption_Nonce_IndicesDescriptor::~MobOption_Nonce_IndicesDescriptor()
{
}

bool MobOption_Nonce_IndicesDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MobOption_Nonce_Indices *>(obj)!=NULL;
}

const char *MobOption_Nonce_IndicesDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MobOption_Nonce_IndicesDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int MobOption_Nonce_IndicesDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *MobOption_Nonce_IndicesDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "home_nonce_index",
        "care_of_nonce_index",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int MobOption_Nonce_IndicesDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='h' && strcmp(fieldName, "home_nonce_index")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "care_of_nonce_index")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MobOption_Nonce_IndicesDescriptor::getFieldTypeString(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *MobOption_Nonce_IndicesDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int MobOption_Nonce_IndicesDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MobOption_Nonce_Indices *pp = (MobOption_Nonce_Indices *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MobOption_Nonce_IndicesDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MobOption_Nonce_Indices *pp = (MobOption_Nonce_Indices *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getHome_nonce_index());
        case 1: return long2string(pp->getCare_of_nonce_index());
        default: return "";
    }
}

bool MobOption_Nonce_IndicesDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MobOption_Nonce_Indices *pp = (MobOption_Nonce_Indices *)object; (void)pp;
    switch (field) {
        case 0: pp->setHome_nonce_index(string2long(value)); return true;
        case 1: pp->setCare_of_nonce_index(string2long(value)); return true;
        default: return false;
    }
}

const char *MobOption_Nonce_IndicesDescriptor::getFieldStructName(void *object, int field) const
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

void *MobOption_Nonce_IndicesDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MobOption_Nonce_Indices *pp = (MobOption_Nonce_Indices *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(MobOption_Binding_AuthorizationData);

MobOption_Binding_AuthorizationData::MobOption_Binding_AuthorizationData() : ::MobOption()
{
    this->authenticator_var = 0;
}

MobOption_Binding_AuthorizationData::MobOption_Binding_AuthorizationData(const MobOption_Binding_AuthorizationData& other) : ::MobOption(other)
{
    copy(other);
}

MobOption_Binding_AuthorizationData::~MobOption_Binding_AuthorizationData()
{
}

MobOption_Binding_AuthorizationData& MobOption_Binding_AuthorizationData::operator=(const MobOption_Binding_AuthorizationData& other)
{
    if (this==&other) return *this;
    ::MobOption::operator=(other);
    copy(other);
    return *this;
}

void MobOption_Binding_AuthorizationData::copy(const MobOption_Binding_AuthorizationData& other)
{
    this->authenticator_var = other.authenticator_var;
}

void MobOption_Binding_AuthorizationData::parsimPack(cCommBuffer *b)
{
    ::MobOption::parsimPack(b);
    doPacking(b,this->authenticator_var);
}

void MobOption_Binding_AuthorizationData::parsimUnpack(cCommBuffer *b)
{
    ::MobOption::parsimUnpack(b);
    doUnpacking(b,this->authenticator_var);
}

int MobOption_Binding_AuthorizationData::getAuthenticator() const
{
    return authenticator_var;
}

void MobOption_Binding_AuthorizationData::setAuthenticator(int authenticator)
{
    this->authenticator_var = authenticator;
}

class MobOption_Binding_AuthorizationDataDescriptor : public cClassDescriptor
{
  public:
    MobOption_Binding_AuthorizationDataDescriptor();
    virtual ~MobOption_Binding_AuthorizationDataDescriptor();

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

Register_ClassDescriptor(MobOption_Binding_AuthorizationDataDescriptor);

MobOption_Binding_AuthorizationDataDescriptor::MobOption_Binding_AuthorizationDataDescriptor() : cClassDescriptor("MobOption_Binding_AuthorizationData", "MobOption")
{
}

MobOption_Binding_AuthorizationDataDescriptor::~MobOption_Binding_AuthorizationDataDescriptor()
{
}

bool MobOption_Binding_AuthorizationDataDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MobOption_Binding_AuthorizationData *>(obj)!=NULL;
}

const char *MobOption_Binding_AuthorizationDataDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MobOption_Binding_AuthorizationDataDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int MobOption_Binding_AuthorizationDataDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *MobOption_Binding_AuthorizationDataDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "authenticator",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int MobOption_Binding_AuthorizationDataDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "authenticator")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MobOption_Binding_AuthorizationDataDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *MobOption_Binding_AuthorizationDataDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int MobOption_Binding_AuthorizationDataDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MobOption_Binding_AuthorizationData *pp = (MobOption_Binding_AuthorizationData *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MobOption_Binding_AuthorizationDataDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MobOption_Binding_AuthorizationData *pp = (MobOption_Binding_AuthorizationData *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getAuthenticator());
        default: return "";
    }
}

bool MobOption_Binding_AuthorizationDataDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MobOption_Binding_AuthorizationData *pp = (MobOption_Binding_AuthorizationData *)object; (void)pp;
    switch (field) {
        case 0: pp->setAuthenticator(string2long(value)); return true;
        default: return false;
    }
}

const char *MobOption_Binding_AuthorizationDataDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *MobOption_Binding_AuthorizationDataDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MobOption_Binding_AuthorizationData *pp = (MobOption_Binding_AuthorizationData *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(MobOption_Binding_Identifier_Mobility);

MobOption_Binding_Identifier_Mobility::MobOption_Binding_Identifier_Mobility() : ::MobOption()
{
    this->Reserved_var = 0;
    this->Status_var = 0;
    this->HFlag_var = 0;
}

MobOption_Binding_Identifier_Mobility::MobOption_Binding_Identifier_Mobility(const MobOption_Binding_Identifier_Mobility& other) : ::MobOption(other)
{
    copy(other);
}

MobOption_Binding_Identifier_Mobility::~MobOption_Binding_Identifier_Mobility()
{
}

MobOption_Binding_Identifier_Mobility& MobOption_Binding_Identifier_Mobility::operator=(const MobOption_Binding_Identifier_Mobility& other)
{
    if (this==&other) return *this;
    ::MobOption::operator=(other);
    copy(other);
    return *this;
}

void MobOption_Binding_Identifier_Mobility::copy(const MobOption_Binding_Identifier_Mobility& other)
{
    this->Reserved_var = other.Reserved_var;
    this->Status_var = other.Status_var;
    this->HFlag_var = other.HFlag_var;
    this->kMCoA_var = other.kMCoA_var;
}

void MobOption_Binding_Identifier_Mobility::parsimPack(cCommBuffer *b)
{
    ::MobOption::parsimPack(b);
    doPacking(b,this->Reserved_var);
    doPacking(b,this->Status_var);
    doPacking(b,this->HFlag_var);
    doPacking(b,this->kMCoA_var);
}

void MobOption_Binding_Identifier_Mobility::parsimUnpack(cCommBuffer *b)
{
    ::MobOption::parsimUnpack(b);
    doUnpacking(b,this->Reserved_var);
    doUnpacking(b,this->Status_var);
    doUnpacking(b,this->HFlag_var);
    doUnpacking(b,this->kMCoA_var);
}

unsigned int MobOption_Binding_Identifier_Mobility::getReserved() const
{
    return Reserved_var;
}

void MobOption_Binding_Identifier_Mobility::setReserved(unsigned int Reserved)
{
    this->Reserved_var = Reserved;
}

unsigned int MobOption_Binding_Identifier_Mobility::getStatus() const
{
    return Status_var;
}

void MobOption_Binding_Identifier_Mobility::setStatus(unsigned int Status)
{
    this->Status_var = Status;
}

bool MobOption_Binding_Identifier_Mobility::getHFlag() const
{
    return HFlag_var;
}

void MobOption_Binding_Identifier_Mobility::setHFlag(bool HFlag)
{
    this->HFlag_var = HFlag;
}

KeyMCoABind& MobOption_Binding_Identifier_Mobility::getKMCoA()
{
    return kMCoA_var;
}

void MobOption_Binding_Identifier_Mobility::setKMCoA(const KeyMCoABind& kMCoA)
{
    this->kMCoA_var = kMCoA;
}

class MobOption_Binding_Identifier_MobilityDescriptor : public cClassDescriptor
{
  public:
    MobOption_Binding_Identifier_MobilityDescriptor();
    virtual ~MobOption_Binding_Identifier_MobilityDescriptor();

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

Register_ClassDescriptor(MobOption_Binding_Identifier_MobilityDescriptor);

MobOption_Binding_Identifier_MobilityDescriptor::MobOption_Binding_Identifier_MobilityDescriptor() : cClassDescriptor("MobOption_Binding_Identifier_Mobility", "MobOption")
{
}

MobOption_Binding_Identifier_MobilityDescriptor::~MobOption_Binding_Identifier_MobilityDescriptor()
{
}

bool MobOption_Binding_Identifier_MobilityDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MobOption_Binding_Identifier_Mobility *>(obj)!=NULL;
}

const char *MobOption_Binding_Identifier_MobilityDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MobOption_Binding_Identifier_MobilityDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int MobOption_Binding_Identifier_MobilityDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *MobOption_Binding_Identifier_MobilityDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "Reserved",
        "Status",
        "HFlag",
        "kMCoA",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int MobOption_Binding_Identifier_MobilityDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='R' && strcmp(fieldName, "Reserved")==0) return base+0;
    if (fieldName[0]=='S' && strcmp(fieldName, "Status")==0) return base+1;
    if (fieldName[0]=='H' && strcmp(fieldName, "HFlag")==0) return base+2;
    if (fieldName[0]=='k' && strcmp(fieldName, "kMCoA")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MobOption_Binding_Identifier_MobilityDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "unsigned int",
        "bool",
        "KeyMCoABind",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *MobOption_Binding_Identifier_MobilityDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int MobOption_Binding_Identifier_MobilityDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MobOption_Binding_Identifier_Mobility *pp = (MobOption_Binding_Identifier_Mobility *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MobOption_Binding_Identifier_MobilityDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MobOption_Binding_Identifier_Mobility *pp = (MobOption_Binding_Identifier_Mobility *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getReserved());
        case 1: return ulong2string(pp->getStatus());
        case 2: return bool2string(pp->getHFlag());
        case 3: {std::stringstream out; out << pp->getKMCoA(); return out.str();}
        default: return "";
    }
}

bool MobOption_Binding_Identifier_MobilityDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MobOption_Binding_Identifier_Mobility *pp = (MobOption_Binding_Identifier_Mobility *)object; (void)pp;
    switch (field) {
        case 0: pp->setReserved(string2ulong(value)); return true;
        case 1: pp->setStatus(string2ulong(value)); return true;
        case 2: pp->setHFlag(string2bool(value)); return true;
        default: return false;
    }
}

const char *MobOption_Binding_Identifier_MobilityDescriptor::getFieldStructName(void *object, int field) const
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
        "KeyMCoABind",
    };
    return (field>=0 && field<4) ? fieldStructNames[field] : NULL;
}

void *MobOption_Binding_Identifier_MobilityDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MobOption_Binding_Identifier_Mobility *pp = (MobOption_Binding_Identifier_Mobility *)object; (void)pp;
    switch (field) {
        case 3: return (void *)(&pp->getKMCoA()); break;
        default: return NULL;
    }
}

Register_Class(MobilityBIDOptions);

MobilityBIDOptions::MobilityBIDOptions() : ::cObject()
{
    mobOpts_arraysize = 0;
    this->mobOpts_var = 0;
}

MobilityBIDOptions::MobilityBIDOptions(const MobilityBIDOptions& other) : ::cObject(other)
{
    mobOpts_arraysize = 0;
    this->mobOpts_var = 0;
    copy(other);
}

MobilityBIDOptions::~MobilityBIDOptions()
{
    delete [] mobOpts_var;
}

MobilityBIDOptions& MobilityBIDOptions::operator=(const MobilityBIDOptions& other)
{
    if (this==&other) return *this;
    ::cObject::operator=(other);
    copy(other);
    return *this;
}

void MobilityBIDOptions::copy(const MobilityBIDOptions& other)
{
    delete [] this->mobOpts_var;
    this->mobOpts_var = (other.mobOpts_arraysize==0) ? NULL : new MobOption_Binding_Identifier_Mobility[other.mobOpts_arraysize];
    mobOpts_arraysize = other.mobOpts_arraysize;
    for (unsigned int i=0; i<mobOpts_arraysize; i++)
        this->mobOpts_var[i] = other.mobOpts_var[i];
}

void MobilityBIDOptions::parsimPack(cCommBuffer *b)
{
    b->pack(mobOpts_arraysize);
    doPacking(b,this->mobOpts_var,mobOpts_arraysize);
}

void MobilityBIDOptions::parsimUnpack(cCommBuffer *b)
{
    delete [] this->mobOpts_var;
    b->unpack(mobOpts_arraysize);
    if (mobOpts_arraysize==0) {
        this->mobOpts_var = 0;
    } else {
        this->mobOpts_var = new MobOption_Binding_Identifier_Mobility[mobOpts_arraysize];
        doUnpacking(b,this->mobOpts_var,mobOpts_arraysize);
    }
}

void MobilityBIDOptions::setMobOptsArraySize(unsigned int size)
{
    MobOption_Binding_Identifier_Mobility *mobOpts_var2 = (size==0) ? NULL : new MobOption_Binding_Identifier_Mobility[size];
    unsigned int sz = mobOpts_arraysize < size ? mobOpts_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        mobOpts_var2[i] = this->mobOpts_var[i];
    mobOpts_arraysize = size;
    delete [] this->mobOpts_var;
    this->mobOpts_var = mobOpts_var2;
}

unsigned int MobilityBIDOptions::getMobOptsArraySize() const
{
    return mobOpts_arraysize;
}

MobOption_Binding_Identifier_Mobility& MobilityBIDOptions::getMobOpts(unsigned int k)
{
    if (k>=mobOpts_arraysize) throw cRuntimeError("Array of size %d indexed by %d", mobOpts_arraysize, k);
    return mobOpts_var[k];
}

void MobilityBIDOptions::setMobOpts(unsigned int k, const MobOption_Binding_Identifier_Mobility& mobOpts)
{
    if (k>=mobOpts_arraysize) throw cRuntimeError("Array of size %d indexed by %d", mobOpts_arraysize, k);
    this->mobOpts_var[k] = mobOpts;
}

class MobilityBIDOptionsDescriptor : public cClassDescriptor
{
  public:
    MobilityBIDOptionsDescriptor();
    virtual ~MobilityBIDOptionsDescriptor();

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

Register_ClassDescriptor(MobilityBIDOptionsDescriptor);

MobilityBIDOptionsDescriptor::MobilityBIDOptionsDescriptor() : cClassDescriptor("MobilityBIDOptions", "cObject")
{
}

MobilityBIDOptionsDescriptor::~MobilityBIDOptionsDescriptor()
{
}

bool MobilityBIDOptionsDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MobilityBIDOptions *>(obj)!=NULL;
}

const char *MobilityBIDOptionsDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MobilityBIDOptionsDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int MobilityBIDOptionsDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *MobilityBIDOptionsDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "mobOpts",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int MobilityBIDOptionsDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "mobOpts")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MobilityBIDOptionsDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "MobOption_Binding_Identifier_Mobility",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *MobilityBIDOptionsDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int MobilityBIDOptionsDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MobilityBIDOptions *pp = (MobilityBIDOptions *)object; (void)pp;
    switch (field) {
        case 0: return pp->getMobOptsArraySize();
        default: return 0;
    }
}

std::string MobilityBIDOptionsDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MobilityBIDOptions *pp = (MobilityBIDOptions *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getMobOpts(i); return out.str();}
        default: return "";
    }
}

bool MobilityBIDOptionsDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MobilityBIDOptions *pp = (MobilityBIDOptions *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *MobilityBIDOptionsDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "MobOption_Binding_Identifier_Mobility",
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *MobilityBIDOptionsDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MobilityBIDOptions *pp = (MobilityBIDOptions *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<cObject *>(&pp->getMobOpts(i)); break;
        default: return NULL;
    }
}

Register_Class(MobilityHeader);

MobilityHeader::MobilityHeader(const char *name, int kind) : ::cPacket(name,kind)
{
    this->mobilityHeaderType_var = 0;
}

MobilityHeader::MobilityHeader(const MobilityHeader& other) : ::cPacket(other)
{
    copy(other);
}

MobilityHeader::~MobilityHeader()
{
}

MobilityHeader& MobilityHeader::operator=(const MobilityHeader& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void MobilityHeader::copy(const MobilityHeader& other)
{
    this->mobilityHeaderType_var = other.mobilityHeaderType_var;
}

void MobilityHeader::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->mobilityHeaderType_var);
}

void MobilityHeader::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->mobilityHeaderType_var);
}

int MobilityHeader::getMobilityHeaderType() const
{
    return mobilityHeaderType_var;
}

void MobilityHeader::setMobilityHeaderType(int mobilityHeaderType)
{
    this->mobilityHeaderType_var = mobilityHeaderType;
}

class MobilityHeaderDescriptor : public cClassDescriptor
{
  public:
    MobilityHeaderDescriptor();
    virtual ~MobilityHeaderDescriptor();

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

Register_ClassDescriptor(MobilityHeaderDescriptor);

MobilityHeaderDescriptor::MobilityHeaderDescriptor() : cClassDescriptor("MobilityHeader", "cPacket")
{
}

MobilityHeaderDescriptor::~MobilityHeaderDescriptor()
{
}

bool MobilityHeaderDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MobilityHeader *>(obj)!=NULL;
}

const char *MobilityHeaderDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MobilityHeaderDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int MobilityHeaderDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *MobilityHeaderDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "mobilityHeaderType",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int MobilityHeaderDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "mobilityHeaderType")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MobilityHeaderDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *MobilityHeaderDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "MobilityHeaderType";
            return NULL;
        default: return NULL;
    }
}

int MobilityHeaderDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MobilityHeader *pp = (MobilityHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string MobilityHeaderDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MobilityHeader *pp = (MobilityHeader *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getMobilityHeaderType());
        default: return "";
    }
}

bool MobilityHeaderDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MobilityHeader *pp = (MobilityHeader *)object; (void)pp;
    switch (field) {
        case 0: pp->setMobilityHeaderType(string2long(value)); return true;
        default: return false;
    }
}

const char *MobilityHeaderDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *MobilityHeaderDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MobilityHeader *pp = (MobilityHeader *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(BindingUpdate);

BindingUpdate::BindingUpdate(const char *name, int kind) : ::MobilityHeader(name,kind)
{
    this->lifetime_var = 0;
    this->sequence_var = 0;
    this->ackFlag_var = 0;
    this->homeRegistrationFlag_var = 0;
    this->linkLocalAddressCompatibilityFlag_var = 0;
    this->keyManagementFlag_var = false;
    this->mapHMIPv6Flag_var = 0;
    this->mobRouterFlag_var = 0;
    this->proxyRegistrationFlag_var = 0;
    this->forceUDPencap_var = 0;
    this->tunnelGREflag_var = 0;
    this->overwriteFlag_var = 0;
    this->bindingAuthorizationData_var = 0;
    mobBIDmobility_arraysize = 0;
    this->mobBIDmobility_var = 0;
}

BindingUpdate::BindingUpdate(const BindingUpdate& other) : ::MobilityHeader(other)
{
    mobBIDmobility_arraysize = 0;
    this->mobBIDmobility_var = 0;
    copy(other);
}

BindingUpdate::~BindingUpdate()
{
    delete [] mobBIDmobility_var;
}

BindingUpdate& BindingUpdate::operator=(const BindingUpdate& other)
{
    if (this==&other) return *this;
    ::MobilityHeader::operator=(other);
    copy(other);
    return *this;
}

void BindingUpdate::copy(const BindingUpdate& other)
{
    this->lifetime_var = other.lifetime_var;
    this->sequence_var = other.sequence_var;
    this->ackFlag_var = other.ackFlag_var;
    this->homeRegistrationFlag_var = other.homeRegistrationFlag_var;
    this->linkLocalAddressCompatibilityFlag_var = other.linkLocalAddressCompatibilityFlag_var;
    this->keyManagementFlag_var = other.keyManagementFlag_var;
    this->mapHMIPv6Flag_var = other.mapHMIPv6Flag_var;
    this->mobRouterFlag_var = other.mobRouterFlag_var;
    this->proxyRegistrationFlag_var = other.proxyRegistrationFlag_var;
    this->forceUDPencap_var = other.forceUDPencap_var;
    this->tunnelGREflag_var = other.tunnelGREflag_var;
    this->overwriteFlag_var = other.overwriteFlag_var;
    this->homeAddressMN_var = other.homeAddressMN_var;
    this->bindingAuthorizationData_var = other.bindingAuthorizationData_var;
    this->mobBindingAuthorization_var = other.mobBindingAuthorization_var;
    delete [] this->mobBIDmobility_var;
    this->mobBIDmobility_var = (other.mobBIDmobility_arraysize==0) ? NULL : new MobOption_Binding_Identifier_Mobility[other.mobBIDmobility_arraysize];
    mobBIDmobility_arraysize = other.mobBIDmobility_arraysize;
    for (unsigned int i=0; i<mobBIDmobility_arraysize; i++)
        this->mobBIDmobility_var[i] = other.mobBIDmobility_var[i];
}

void BindingUpdate::parsimPack(cCommBuffer *b)
{
    ::MobilityHeader::parsimPack(b);
    doPacking(b,this->lifetime_var);
    doPacking(b,this->sequence_var);
    doPacking(b,this->ackFlag_var);
    doPacking(b,this->homeRegistrationFlag_var);
    doPacking(b,this->linkLocalAddressCompatibilityFlag_var);
    doPacking(b,this->keyManagementFlag_var);
    doPacking(b,this->mapHMIPv6Flag_var);
    doPacking(b,this->mobRouterFlag_var);
    doPacking(b,this->proxyRegistrationFlag_var);
    doPacking(b,this->forceUDPencap_var);
    doPacking(b,this->tunnelGREflag_var);
    doPacking(b,this->overwriteFlag_var);
    doPacking(b,this->homeAddressMN_var);
    doPacking(b,this->bindingAuthorizationData_var);
    doPacking(b,this->mobBindingAuthorization_var);
    b->pack(mobBIDmobility_arraysize);
    doPacking(b,this->mobBIDmobility_var,mobBIDmobility_arraysize);
}

void BindingUpdate::parsimUnpack(cCommBuffer *b)
{
    ::MobilityHeader::parsimUnpack(b);
    doUnpacking(b,this->lifetime_var);
    doUnpacking(b,this->sequence_var);
    doUnpacking(b,this->ackFlag_var);
    doUnpacking(b,this->homeRegistrationFlag_var);
    doUnpacking(b,this->linkLocalAddressCompatibilityFlag_var);
    doUnpacking(b,this->keyManagementFlag_var);
    doUnpacking(b,this->mapHMIPv6Flag_var);
    doUnpacking(b,this->mobRouterFlag_var);
    doUnpacking(b,this->proxyRegistrationFlag_var);
    doUnpacking(b,this->forceUDPencap_var);
    doUnpacking(b,this->tunnelGREflag_var);
    doUnpacking(b,this->overwriteFlag_var);
    doUnpacking(b,this->homeAddressMN_var);
    doUnpacking(b,this->bindingAuthorizationData_var);
    doUnpacking(b,this->mobBindingAuthorization_var);
    delete [] this->mobBIDmobility_var;
    b->unpack(mobBIDmobility_arraysize);
    if (mobBIDmobility_arraysize==0) {
        this->mobBIDmobility_var = 0;
    } else {
        this->mobBIDmobility_var = new MobOption_Binding_Identifier_Mobility[mobBIDmobility_arraysize];
        doUnpacking(b,this->mobBIDmobility_var,mobBIDmobility_arraysize);
    }
}

unsigned int BindingUpdate::getLifetime() const
{
    return lifetime_var;
}

void BindingUpdate::setLifetime(unsigned int lifetime)
{
    this->lifetime_var = lifetime;
}

unsigned int BindingUpdate::getSequence() const
{
    return sequence_var;
}

void BindingUpdate::setSequence(unsigned int sequence)
{
    this->sequence_var = sequence;
}

bool BindingUpdate::getAckFlag() const
{
    return ackFlag_var;
}

void BindingUpdate::setAckFlag(bool ackFlag)
{
    this->ackFlag_var = ackFlag;
}

bool BindingUpdate::getHomeRegistrationFlag() const
{
    return homeRegistrationFlag_var;
}

void BindingUpdate::setHomeRegistrationFlag(bool homeRegistrationFlag)
{
    this->homeRegistrationFlag_var = homeRegistrationFlag;
}

bool BindingUpdate::getLinkLocalAddressCompatibilityFlag() const
{
    return linkLocalAddressCompatibilityFlag_var;
}

void BindingUpdate::setLinkLocalAddressCompatibilityFlag(bool linkLocalAddressCompatibilityFlag)
{
    this->linkLocalAddressCompatibilityFlag_var = linkLocalAddressCompatibilityFlag;
}

bool BindingUpdate::getKeyManagementFlag() const
{
    return keyManagementFlag_var;
}

void BindingUpdate::setKeyManagementFlag(bool keyManagementFlag)
{
    this->keyManagementFlag_var = keyManagementFlag;
}

bool BindingUpdate::getMapHMIPv6Flag() const
{
    return mapHMIPv6Flag_var;
}

void BindingUpdate::setMapHMIPv6Flag(bool mapHMIPv6Flag)
{
    this->mapHMIPv6Flag_var = mapHMIPv6Flag;
}

bool BindingUpdate::getMobRouterFlag() const
{
    return mobRouterFlag_var;
}

void BindingUpdate::setMobRouterFlag(bool mobRouterFlag)
{
    this->mobRouterFlag_var = mobRouterFlag;
}

bool BindingUpdate::getProxyRegistrationFlag() const
{
    return proxyRegistrationFlag_var;
}

void BindingUpdate::setProxyRegistrationFlag(bool proxyRegistrationFlag)
{
    this->proxyRegistrationFlag_var = proxyRegistrationFlag;
}

bool BindingUpdate::getForceUDPencap() const
{
    return forceUDPencap_var;
}

void BindingUpdate::setForceUDPencap(bool forceUDPencap)
{
    this->forceUDPencap_var = forceUDPencap;
}

bool BindingUpdate::getTunnelGREflag() const
{
    return tunnelGREflag_var;
}

void BindingUpdate::setTunnelGREflag(bool tunnelGREflag)
{
    this->tunnelGREflag_var = tunnelGREflag;
}

bool BindingUpdate::getOverwriteFlag() const
{
    return overwriteFlag_var;
}

void BindingUpdate::setOverwriteFlag(bool overwriteFlag)
{
    this->overwriteFlag_var = overwriteFlag;
}

IPv6Address& BindingUpdate::getHomeAddressMN()
{
    return homeAddressMN_var;
}

void BindingUpdate::setHomeAddressMN(const IPv6Address& homeAddressMN)
{
    this->homeAddressMN_var = homeAddressMN;
}

int BindingUpdate::getBindingAuthorizationData() const
{
    return bindingAuthorizationData_var;
}

void BindingUpdate::setBindingAuthorizationData(int bindingAuthorizationData)
{
    this->bindingAuthorizationData_var = bindingAuthorizationData;
}

MobOption_Binding_AuthorizationData& BindingUpdate::getMobBindingAuthorization()
{
    return mobBindingAuthorization_var;
}

void BindingUpdate::setMobBindingAuthorization(const MobOption_Binding_AuthorizationData& mobBindingAuthorization)
{
    this->mobBindingAuthorization_var = mobBindingAuthorization;
}

void BindingUpdate::setMobBIDmobilityArraySize(unsigned int size)
{
    MobOption_Binding_Identifier_Mobility *mobBIDmobility_var2 = (size==0) ? NULL : new MobOption_Binding_Identifier_Mobility[size];
    unsigned int sz = mobBIDmobility_arraysize < size ? mobBIDmobility_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        mobBIDmobility_var2[i] = this->mobBIDmobility_var[i];
    mobBIDmobility_arraysize = size;
    delete [] this->mobBIDmobility_var;
    this->mobBIDmobility_var = mobBIDmobility_var2;
}

unsigned int BindingUpdate::getMobBIDmobilityArraySize() const
{
    return mobBIDmobility_arraysize;
}

MobOption_Binding_Identifier_Mobility& BindingUpdate::getMobBIDmobility(unsigned int k)
{
    if (k>=mobBIDmobility_arraysize) throw cRuntimeError("Array of size %d indexed by %d", mobBIDmobility_arraysize, k);
    return mobBIDmobility_var[k];
}

void BindingUpdate::setMobBIDmobility(unsigned int k, const MobOption_Binding_Identifier_Mobility& mobBIDmobility)
{
    if (k>=mobBIDmobility_arraysize) throw cRuntimeError("Array of size %d indexed by %d", mobBIDmobility_arraysize, k);
    this->mobBIDmobility_var[k] = mobBIDmobility;
}

class BindingUpdateDescriptor : public cClassDescriptor
{
  public:
    BindingUpdateDescriptor();
    virtual ~BindingUpdateDescriptor();

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

Register_ClassDescriptor(BindingUpdateDescriptor);

BindingUpdateDescriptor::BindingUpdateDescriptor() : cClassDescriptor("BindingUpdate", "MobilityHeader")
{
}

BindingUpdateDescriptor::~BindingUpdateDescriptor()
{
}

bool BindingUpdateDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BindingUpdate *>(obj)!=NULL;
}

const char *BindingUpdateDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BindingUpdateDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 16+basedesc->getFieldCount(object) : 16;
}

unsigned int BindingUpdateDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISCOMPOUND | FD_ISCOBJECT,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
    };
    return (field>=0 && field<16) ? fieldTypeFlags[field] : 0;
}

const char *BindingUpdateDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "lifetime",
        "sequence",
        "ackFlag",
        "homeRegistrationFlag",
        "linkLocalAddressCompatibilityFlag",
        "keyManagementFlag",
        "mapHMIPv6Flag",
        "mobRouterFlag",
        "proxyRegistrationFlag",
        "forceUDPencap",
        "tunnelGREflag",
        "overwriteFlag",
        "homeAddressMN",
        "bindingAuthorizationData",
        "mobBindingAuthorization",
        "mobBIDmobility",
    };
    return (field>=0 && field<16) ? fieldNames[field] : NULL;
}

int BindingUpdateDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "lifetime")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sequence")==0) return base+1;
    if (fieldName[0]=='a' && strcmp(fieldName, "ackFlag")==0) return base+2;
    if (fieldName[0]=='h' && strcmp(fieldName, "homeRegistrationFlag")==0) return base+3;
    if (fieldName[0]=='l' && strcmp(fieldName, "linkLocalAddressCompatibilityFlag")==0) return base+4;
    if (fieldName[0]=='k' && strcmp(fieldName, "keyManagementFlag")==0) return base+5;
    if (fieldName[0]=='m' && strcmp(fieldName, "mapHMIPv6Flag")==0) return base+6;
    if (fieldName[0]=='m' && strcmp(fieldName, "mobRouterFlag")==0) return base+7;
    if (fieldName[0]=='p' && strcmp(fieldName, "proxyRegistrationFlag")==0) return base+8;
    if (fieldName[0]=='f' && strcmp(fieldName, "forceUDPencap")==0) return base+9;
    if (fieldName[0]=='t' && strcmp(fieldName, "tunnelGREflag")==0) return base+10;
    if (fieldName[0]=='o' && strcmp(fieldName, "overwriteFlag")==0) return base+11;
    if (fieldName[0]=='h' && strcmp(fieldName, "homeAddressMN")==0) return base+12;
    if (fieldName[0]=='b' && strcmp(fieldName, "bindingAuthorizationData")==0) return base+13;
    if (fieldName[0]=='m' && strcmp(fieldName, "mobBindingAuthorization")==0) return base+14;
    if (fieldName[0]=='m' && strcmp(fieldName, "mobBIDmobility")==0) return base+15;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BindingUpdateDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "unsigned int",
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "IPv6Address",
        "int",
        "MobOption_Binding_AuthorizationData",
        "MobOption_Binding_Identifier_Mobility",
    };
    return (field>=0 && field<16) ? fieldTypeStrings[field] : NULL;
}

const char *BindingUpdateDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int BindingUpdateDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BindingUpdate *pp = (BindingUpdate *)object; (void)pp;
    switch (field) {
        case 15: return pp->getMobBIDmobilityArraySize();
        default: return 0;
    }
}

std::string BindingUpdateDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BindingUpdate *pp = (BindingUpdate *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getLifetime());
        case 1: return ulong2string(pp->getSequence());
        case 2: return bool2string(pp->getAckFlag());
        case 3: return bool2string(pp->getHomeRegistrationFlag());
        case 4: return bool2string(pp->getLinkLocalAddressCompatibilityFlag());
        case 5: return bool2string(pp->getKeyManagementFlag());
        case 6: return bool2string(pp->getMapHMIPv6Flag());
        case 7: return bool2string(pp->getMobRouterFlag());
        case 8: return bool2string(pp->getProxyRegistrationFlag());
        case 9: return bool2string(pp->getForceUDPencap());
        case 10: return bool2string(pp->getTunnelGREflag());
        case 11: return bool2string(pp->getOverwriteFlag());
        case 12: {std::stringstream out; out << pp->getHomeAddressMN(); return out.str();}
        case 13: return long2string(pp->getBindingAuthorizationData());
        case 14: {std::stringstream out; out << pp->getMobBindingAuthorization(); return out.str();}
        case 15: {std::stringstream out; out << pp->getMobBIDmobility(i); return out.str();}
        default: return "";
    }
}

bool BindingUpdateDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BindingUpdate *pp = (BindingUpdate *)object; (void)pp;
    switch (field) {
        case 0: pp->setLifetime(string2ulong(value)); return true;
        case 1: pp->setSequence(string2ulong(value)); return true;
        case 2: pp->setAckFlag(string2bool(value)); return true;
        case 3: pp->setHomeRegistrationFlag(string2bool(value)); return true;
        case 4: pp->setLinkLocalAddressCompatibilityFlag(string2bool(value)); return true;
        case 5: pp->setKeyManagementFlag(string2bool(value)); return true;
        case 6: pp->setMapHMIPv6Flag(string2bool(value)); return true;
        case 7: pp->setMobRouterFlag(string2bool(value)); return true;
        case 8: pp->setProxyRegistrationFlag(string2bool(value)); return true;
        case 9: pp->setForceUDPencap(string2bool(value)); return true;
        case 10: pp->setTunnelGREflag(string2bool(value)); return true;
        case 11: pp->setOverwriteFlag(string2bool(value)); return true;
        case 13: pp->setBindingAuthorizationData(string2long(value)); return true;
        default: return false;
    }
}

const char *BindingUpdateDescriptor::getFieldStructName(void *object, int field) const
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
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        "IPv6Address",
        NULL,
        "MobOption_Binding_AuthorizationData",
        "MobOption_Binding_Identifier_Mobility",
    };
    return (field>=0 && field<16) ? fieldStructNames[field] : NULL;
}

void *BindingUpdateDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BindingUpdate *pp = (BindingUpdate *)object; (void)pp;
    switch (field) {
        case 12: return (void *)(&pp->getHomeAddressMN()); break;
        case 14: return (void *)static_cast<cObject *>(&pp->getMobBindingAuthorization()); break;
        case 15: return (void *)static_cast<cObject *>(&pp->getMobBIDmobility(i)); break;
        default: return NULL;
    }
}

Register_Class(BindingAcknowledgement);

BindingAcknowledgement::BindingAcknowledgement(const char *name, int kind) : ::MobilityHeader(name,kind)
{
    this->status_var = 0;
    this->sequenceNumber_var = 0;
    this->lifetime_var = 0;
    this->keyManagementFlag_var = false;
    this->bindingAuthorizationData_var = 0;
    mobBIDmobility_arraysize = 0;
    this->mobBIDmobility_var = 0;
}

BindingAcknowledgement::BindingAcknowledgement(const BindingAcknowledgement& other) : ::MobilityHeader(other)
{
    mobBIDmobility_arraysize = 0;
    this->mobBIDmobility_var = 0;
    copy(other);
}

BindingAcknowledgement::~BindingAcknowledgement()
{
    delete [] mobBIDmobility_var;
}

BindingAcknowledgement& BindingAcknowledgement::operator=(const BindingAcknowledgement& other)
{
    if (this==&other) return *this;
    ::MobilityHeader::operator=(other);
    copy(other);
    return *this;
}

void BindingAcknowledgement::copy(const BindingAcknowledgement& other)
{
    this->status_var = other.status_var;
    this->sequenceNumber_var = other.sequenceNumber_var;
    this->lifetime_var = other.lifetime_var;
    this->keyManagementFlag_var = other.keyManagementFlag_var;
    this->bindingAuthorizationData_var = other.bindingAuthorizationData_var;
    this->mobBindingRefreshAdvice_var = other.mobBindingRefreshAdvice_var;
    this->mobBindingAuthorization_var = other.mobBindingAuthorization_var;
    delete [] this->mobBIDmobility_var;
    this->mobBIDmobility_var = (other.mobBIDmobility_arraysize==0) ? NULL : new MobOption_Binding_Identifier_Mobility[other.mobBIDmobility_arraysize];
    mobBIDmobility_arraysize = other.mobBIDmobility_arraysize;
    for (unsigned int i=0; i<mobBIDmobility_arraysize; i++)
        this->mobBIDmobility_var[i] = other.mobBIDmobility_var[i];
}

void BindingAcknowledgement::parsimPack(cCommBuffer *b)
{
    ::MobilityHeader::parsimPack(b);
    doPacking(b,this->status_var);
    doPacking(b,this->sequenceNumber_var);
    doPacking(b,this->lifetime_var);
    doPacking(b,this->keyManagementFlag_var);
    doPacking(b,this->bindingAuthorizationData_var);
    doPacking(b,this->mobBindingRefreshAdvice_var);
    doPacking(b,this->mobBindingAuthorization_var);
    b->pack(mobBIDmobility_arraysize);
    doPacking(b,this->mobBIDmobility_var,mobBIDmobility_arraysize);
}

void BindingAcknowledgement::parsimUnpack(cCommBuffer *b)
{
    ::MobilityHeader::parsimUnpack(b);
    doUnpacking(b,this->status_var);
    doUnpacking(b,this->sequenceNumber_var);
    doUnpacking(b,this->lifetime_var);
    doUnpacking(b,this->keyManagementFlag_var);
    doUnpacking(b,this->bindingAuthorizationData_var);
    doUnpacking(b,this->mobBindingRefreshAdvice_var);
    doUnpacking(b,this->mobBindingAuthorization_var);
    delete [] this->mobBIDmobility_var;
    b->unpack(mobBIDmobility_arraysize);
    if (mobBIDmobility_arraysize==0) {
        this->mobBIDmobility_var = 0;
    } else {
        this->mobBIDmobility_var = new MobOption_Binding_Identifier_Mobility[mobBIDmobility_arraysize];
        doUnpacking(b,this->mobBIDmobility_var,mobBIDmobility_arraysize);
    }
}

int BindingAcknowledgement::getStatus() const
{
    return status_var;
}

void BindingAcknowledgement::setStatus(int status)
{
    this->status_var = status;
}

unsigned int BindingAcknowledgement::getSequenceNumber() const
{
    return sequenceNumber_var;
}

void BindingAcknowledgement::setSequenceNumber(unsigned int sequenceNumber)
{
    this->sequenceNumber_var = sequenceNumber;
}

unsigned int BindingAcknowledgement::getLifetime() const
{
    return lifetime_var;
}

void BindingAcknowledgement::setLifetime(unsigned int lifetime)
{
    this->lifetime_var = lifetime;
}

bool BindingAcknowledgement::getKeyManagementFlag() const
{
    return keyManagementFlag_var;
}

void BindingAcknowledgement::setKeyManagementFlag(bool keyManagementFlag)
{
    this->keyManagementFlag_var = keyManagementFlag;
}

int BindingAcknowledgement::getBindingAuthorizationData() const
{
    return bindingAuthorizationData_var;
}

void BindingAcknowledgement::setBindingAuthorizationData(int bindingAuthorizationData)
{
    this->bindingAuthorizationData_var = bindingAuthorizationData;
}

MobOption_Binding_RefreshAdvice& BindingAcknowledgement::getMobBindingRefreshAdvice()
{
    return mobBindingRefreshAdvice_var;
}

void BindingAcknowledgement::setMobBindingRefreshAdvice(const MobOption_Binding_RefreshAdvice& mobBindingRefreshAdvice)
{
    this->mobBindingRefreshAdvice_var = mobBindingRefreshAdvice;
}

MobOption_Binding_AuthorizationData& BindingAcknowledgement::getMobBindingAuthorization()
{
    return mobBindingAuthorization_var;
}

void BindingAcknowledgement::setMobBindingAuthorization(const MobOption_Binding_AuthorizationData& mobBindingAuthorization)
{
    this->mobBindingAuthorization_var = mobBindingAuthorization;
}

void BindingAcknowledgement::setMobBIDmobilityArraySize(unsigned int size)
{
    MobOption_Binding_Identifier_Mobility *mobBIDmobility_var2 = (size==0) ? NULL : new MobOption_Binding_Identifier_Mobility[size];
    unsigned int sz = mobBIDmobility_arraysize < size ? mobBIDmobility_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        mobBIDmobility_var2[i] = this->mobBIDmobility_var[i];
    mobBIDmobility_arraysize = size;
    delete [] this->mobBIDmobility_var;
    this->mobBIDmobility_var = mobBIDmobility_var2;
}

unsigned int BindingAcknowledgement::getMobBIDmobilityArraySize() const
{
    return mobBIDmobility_arraysize;
}

MobOption_Binding_Identifier_Mobility& BindingAcknowledgement::getMobBIDmobility(unsigned int k)
{
    if (k>=mobBIDmobility_arraysize) throw cRuntimeError("Array of size %d indexed by %d", mobBIDmobility_arraysize, k);
    return mobBIDmobility_var[k];
}

void BindingAcknowledgement::setMobBIDmobility(unsigned int k, const MobOption_Binding_Identifier_Mobility& mobBIDmobility)
{
    if (k>=mobBIDmobility_arraysize) throw cRuntimeError("Array of size %d indexed by %d", mobBIDmobility_arraysize, k);
    this->mobBIDmobility_var[k] = mobBIDmobility;
}

class BindingAcknowledgementDescriptor : public cClassDescriptor
{
  public:
    BindingAcknowledgementDescriptor();
    virtual ~BindingAcknowledgementDescriptor();

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

Register_ClassDescriptor(BindingAcknowledgementDescriptor);

BindingAcknowledgementDescriptor::BindingAcknowledgementDescriptor() : cClassDescriptor("BindingAcknowledgement", "MobilityHeader")
{
}

BindingAcknowledgementDescriptor::~BindingAcknowledgementDescriptor()
{
}

bool BindingAcknowledgementDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BindingAcknowledgement *>(obj)!=NULL;
}

const char *BindingAcknowledgementDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BindingAcknowledgementDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount(object) : 8;
}

unsigned int BindingAcknowledgementDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISCOMPOUND | FD_ISCOBJECT,
        FD_ISCOMPOUND | FD_ISCOBJECT,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *BindingAcknowledgementDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "status",
        "sequenceNumber",
        "lifetime",
        "keyManagementFlag",
        "bindingAuthorizationData",
        "mobBindingRefreshAdvice",
        "mobBindingAuthorization",
        "mobBIDmobility",
    };
    return (field>=0 && field<8) ? fieldNames[field] : NULL;
}

int BindingAcknowledgementDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "status")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sequenceNumber")==0) return base+1;
    if (fieldName[0]=='l' && strcmp(fieldName, "lifetime")==0) return base+2;
    if (fieldName[0]=='k' && strcmp(fieldName, "keyManagementFlag")==0) return base+3;
    if (fieldName[0]=='b' && strcmp(fieldName, "bindingAuthorizationData")==0) return base+4;
    if (fieldName[0]=='m' && strcmp(fieldName, "mobBindingRefreshAdvice")==0) return base+5;
    if (fieldName[0]=='m' && strcmp(fieldName, "mobBindingAuthorization")==0) return base+6;
    if (fieldName[0]=='m' && strcmp(fieldName, "mobBIDmobility")==0) return base+7;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BindingAcknowledgementDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "unsigned int",
        "unsigned int",
        "bool",
        "int",
        "MobOption_Binding_RefreshAdvice",
        "MobOption_Binding_AuthorizationData",
        "MobOption_Binding_Identifier_Mobility",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : NULL;
}

const char *BindingAcknowledgementDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "BAStatus";
            return NULL;
        default: return NULL;
    }
}

int BindingAcknowledgementDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BindingAcknowledgement *pp = (BindingAcknowledgement *)object; (void)pp;
    switch (field) {
        case 7: return pp->getMobBIDmobilityArraySize();
        default: return 0;
    }
}

std::string BindingAcknowledgementDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BindingAcknowledgement *pp = (BindingAcknowledgement *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getStatus());
        case 1: return ulong2string(pp->getSequenceNumber());
        case 2: return ulong2string(pp->getLifetime());
        case 3: return bool2string(pp->getKeyManagementFlag());
        case 4: return long2string(pp->getBindingAuthorizationData());
        case 5: {std::stringstream out; out << pp->getMobBindingRefreshAdvice(); return out.str();}
        case 6: {std::stringstream out; out << pp->getMobBindingAuthorization(); return out.str();}
        case 7: {std::stringstream out; out << pp->getMobBIDmobility(i); return out.str();}
        default: return "";
    }
}

bool BindingAcknowledgementDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BindingAcknowledgement *pp = (BindingAcknowledgement *)object; (void)pp;
    switch (field) {
        case 0: pp->setStatus(string2long(value)); return true;
        case 1: pp->setSequenceNumber(string2ulong(value)); return true;
        case 2: pp->setLifetime(string2ulong(value)); return true;
        case 3: pp->setKeyManagementFlag(string2bool(value)); return true;
        case 4: pp->setBindingAuthorizationData(string2long(value)); return true;
        default: return false;
    }
}

const char *BindingAcknowledgementDescriptor::getFieldStructName(void *object, int field) const
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
        "MobOption_Binding_RefreshAdvice",
        "MobOption_Binding_AuthorizationData",
        "MobOption_Binding_Identifier_Mobility",
    };
    return (field>=0 && field<8) ? fieldStructNames[field] : NULL;
}

void *BindingAcknowledgementDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BindingAcknowledgement *pp = (BindingAcknowledgement *)object; (void)pp;
    switch (field) {
        case 5: return (void *)static_cast<cObject *>(&pp->getMobBindingRefreshAdvice()); break;
        case 6: return (void *)static_cast<cObject *>(&pp->getMobBindingAuthorization()); break;
        case 7: return (void *)static_cast<cObject *>(&pp->getMobBIDmobility(i)); break;
        default: return NULL;
    }
}

Register_Class(BindingError);

BindingError::BindingError(const char *name, int kind) : ::MobilityHeader(name,kind)
{
    this->status_var = 0;
}

BindingError::BindingError(const BindingError& other) : ::MobilityHeader(other)
{
    copy(other);
}

BindingError::~BindingError()
{
}

BindingError& BindingError::operator=(const BindingError& other)
{
    if (this==&other) return *this;
    ::MobilityHeader::operator=(other);
    copy(other);
    return *this;
}

void BindingError::copy(const BindingError& other)
{
    this->status_var = other.status_var;
    this->homeAddress_var = other.homeAddress_var;
}

void BindingError::parsimPack(cCommBuffer *b)
{
    ::MobilityHeader::parsimPack(b);
    doPacking(b,this->status_var);
    doPacking(b,this->homeAddress_var);
}

void BindingError::parsimUnpack(cCommBuffer *b)
{
    ::MobilityHeader::parsimUnpack(b);
    doUnpacking(b,this->status_var);
    doUnpacking(b,this->homeAddress_var);
}

int BindingError::getStatus() const
{
    return status_var;
}

void BindingError::setStatus(int status)
{
    this->status_var = status;
}

IPv6Address& BindingError::getHomeAddress()
{
    return homeAddress_var;
}

void BindingError::setHomeAddress(const IPv6Address& homeAddress)
{
    this->homeAddress_var = homeAddress;
}

class BindingErrorDescriptor : public cClassDescriptor
{
  public:
    BindingErrorDescriptor();
    virtual ~BindingErrorDescriptor();

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

Register_ClassDescriptor(BindingErrorDescriptor);

BindingErrorDescriptor::BindingErrorDescriptor() : cClassDescriptor("BindingError", "MobilityHeader")
{
}

BindingErrorDescriptor::~BindingErrorDescriptor()
{
}

bool BindingErrorDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BindingError *>(obj)!=NULL;
}

const char *BindingErrorDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BindingErrorDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int BindingErrorDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *BindingErrorDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "status",
        "homeAddress",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int BindingErrorDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "status")==0) return base+0;
    if (fieldName[0]=='h' && strcmp(fieldName, "homeAddress")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BindingErrorDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "IPv6Address",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *BindingErrorDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "BEStatus";
            return NULL;
        default: return NULL;
    }
}

int BindingErrorDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BindingError *pp = (BindingError *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string BindingErrorDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BindingError *pp = (BindingError *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getStatus());
        case 1: {std::stringstream out; out << pp->getHomeAddress(); return out.str();}
        default: return "";
    }
}

bool BindingErrorDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BindingError *pp = (BindingError *)object; (void)pp;
    switch (field) {
        case 0: pp->setStatus(string2long(value)); return true;
        default: return false;
    }
}

const char *BindingErrorDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        "IPv6Address",
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *BindingErrorDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BindingError *pp = (BindingError *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getHomeAddress()); break;
        default: return NULL;
    }
}

Register_Class(HomeTestInit);

HomeTestInit::HomeTestInit(const char *name, int kind) : ::MobilityHeader(name,kind)
{
    this->homeInitCookie_var = 0;
    mobBIDmobility_arraysize = 0;
    this->mobBIDmobility_var = 0;
}

HomeTestInit::HomeTestInit(const HomeTestInit& other) : ::MobilityHeader(other)
{
    mobBIDmobility_arraysize = 0;
    this->mobBIDmobility_var = 0;
    copy(other);
}

HomeTestInit::~HomeTestInit()
{
    delete [] mobBIDmobility_var;
}

HomeTestInit& HomeTestInit::operator=(const HomeTestInit& other)
{
    if (this==&other) return *this;
    ::MobilityHeader::operator=(other);
    copy(other);
    return *this;
}

void HomeTestInit::copy(const HomeTestInit& other)
{
    this->homeInitCookie_var = other.homeInitCookie_var;
    delete [] this->mobBIDmobility_var;
    this->mobBIDmobility_var = (other.mobBIDmobility_arraysize==0) ? NULL : new MobOption_Binding_Identifier_Mobility[other.mobBIDmobility_arraysize];
    mobBIDmobility_arraysize = other.mobBIDmobility_arraysize;
    for (unsigned int i=0; i<mobBIDmobility_arraysize; i++)
        this->mobBIDmobility_var[i] = other.mobBIDmobility_var[i];
}

void HomeTestInit::parsimPack(cCommBuffer *b)
{
    ::MobilityHeader::parsimPack(b);
    doPacking(b,this->homeInitCookie_var);
    b->pack(mobBIDmobility_arraysize);
    doPacking(b,this->mobBIDmobility_var,mobBIDmobility_arraysize);
}

void HomeTestInit::parsimUnpack(cCommBuffer *b)
{
    ::MobilityHeader::parsimUnpack(b);
    doUnpacking(b,this->homeInitCookie_var);
    delete [] this->mobBIDmobility_var;
    b->unpack(mobBIDmobility_arraysize);
    if (mobBIDmobility_arraysize==0) {
        this->mobBIDmobility_var = 0;
    } else {
        this->mobBIDmobility_var = new MobOption_Binding_Identifier_Mobility[mobBIDmobility_arraysize];
        doUnpacking(b,this->mobBIDmobility_var,mobBIDmobility_arraysize);
    }
}

unsigned int HomeTestInit::getHomeInitCookie() const
{
    return homeInitCookie_var;
}

void HomeTestInit::setHomeInitCookie(unsigned int homeInitCookie)
{
    this->homeInitCookie_var = homeInitCookie;
}

void HomeTestInit::setMobBIDmobilityArraySize(unsigned int size)
{
    MobOption_Binding_Identifier_Mobility *mobBIDmobility_var2 = (size==0) ? NULL : new MobOption_Binding_Identifier_Mobility[size];
    unsigned int sz = mobBIDmobility_arraysize < size ? mobBIDmobility_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        mobBIDmobility_var2[i] = this->mobBIDmobility_var[i];
    mobBIDmobility_arraysize = size;
    delete [] this->mobBIDmobility_var;
    this->mobBIDmobility_var = mobBIDmobility_var2;
}

unsigned int HomeTestInit::getMobBIDmobilityArraySize() const
{
    return mobBIDmobility_arraysize;
}

MobOption_Binding_Identifier_Mobility& HomeTestInit::getMobBIDmobility(unsigned int k)
{
    if (k>=mobBIDmobility_arraysize) throw cRuntimeError("Array of size %d indexed by %d", mobBIDmobility_arraysize, k);
    return mobBIDmobility_var[k];
}

void HomeTestInit::setMobBIDmobility(unsigned int k, const MobOption_Binding_Identifier_Mobility& mobBIDmobility)
{
    if (k>=mobBIDmobility_arraysize) throw cRuntimeError("Array of size %d indexed by %d", mobBIDmobility_arraysize, k);
    this->mobBIDmobility_var[k] = mobBIDmobility;
}

class HomeTestInitDescriptor : public cClassDescriptor
{
  public:
    HomeTestInitDescriptor();
    virtual ~HomeTestInitDescriptor();

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

Register_ClassDescriptor(HomeTestInitDescriptor);

HomeTestInitDescriptor::HomeTestInitDescriptor() : cClassDescriptor("HomeTestInit", "MobilityHeader")
{
}

HomeTestInitDescriptor::~HomeTestInitDescriptor()
{
}

bool HomeTestInitDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<HomeTestInit *>(obj)!=NULL;
}

const char *HomeTestInitDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int HomeTestInitDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int HomeTestInitDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *HomeTestInitDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "homeInitCookie",
        "mobBIDmobility",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int HomeTestInitDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='h' && strcmp(fieldName, "homeInitCookie")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "mobBIDmobility")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *HomeTestInitDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "MobOption_Binding_Identifier_Mobility",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *HomeTestInitDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int HomeTestInitDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    HomeTestInit *pp = (HomeTestInit *)object; (void)pp;
    switch (field) {
        case 1: return pp->getMobBIDmobilityArraySize();
        default: return 0;
    }
}

std::string HomeTestInitDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    HomeTestInit *pp = (HomeTestInit *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getHomeInitCookie());
        case 1: {std::stringstream out; out << pp->getMobBIDmobility(i); return out.str();}
        default: return "";
    }
}

bool HomeTestInitDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    HomeTestInit *pp = (HomeTestInit *)object; (void)pp;
    switch (field) {
        case 0: pp->setHomeInitCookie(string2ulong(value)); return true;
        default: return false;
    }
}

const char *HomeTestInitDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        "MobOption_Binding_Identifier_Mobility",
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *HomeTestInitDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    HomeTestInit *pp = (HomeTestInit *)object; (void)pp;
    switch (field) {
        case 1: return (void *)static_cast<cObject *>(&pp->getMobBIDmobility(i)); break;
        default: return NULL;
    }
}

Register_Class(HomeTest);

HomeTest::HomeTest(const char *name, int kind) : ::MobilityHeader(name,kind)
{
    this->homeInitCookie_var = 0;
    this->homeKeyGenToken_var = 0;
    mobBIDmobility_arraysize = 0;
    this->mobBIDmobility_var = 0;
}

HomeTest::HomeTest(const HomeTest& other) : ::MobilityHeader(other)
{
    mobBIDmobility_arraysize = 0;
    this->mobBIDmobility_var = 0;
    copy(other);
}

HomeTest::~HomeTest()
{
    delete [] mobBIDmobility_var;
}

HomeTest& HomeTest::operator=(const HomeTest& other)
{
    if (this==&other) return *this;
    ::MobilityHeader::operator=(other);
    copy(other);
    return *this;
}

void HomeTest::copy(const HomeTest& other)
{
    this->homeInitCookie_var = other.homeInitCookie_var;
    this->homeKeyGenToken_var = other.homeKeyGenToken_var;
    delete [] this->mobBIDmobility_var;
    this->mobBIDmobility_var = (other.mobBIDmobility_arraysize==0) ? NULL : new MobOption_Binding_Identifier_Mobility[other.mobBIDmobility_arraysize];
    mobBIDmobility_arraysize = other.mobBIDmobility_arraysize;
    for (unsigned int i=0; i<mobBIDmobility_arraysize; i++)
        this->mobBIDmobility_var[i] = other.mobBIDmobility_var[i];
}

void HomeTest::parsimPack(cCommBuffer *b)
{
    ::MobilityHeader::parsimPack(b);
    doPacking(b,this->homeInitCookie_var);
    doPacking(b,this->homeKeyGenToken_var);
    b->pack(mobBIDmobility_arraysize);
    doPacking(b,this->mobBIDmobility_var,mobBIDmobility_arraysize);
}

void HomeTest::parsimUnpack(cCommBuffer *b)
{
    ::MobilityHeader::parsimUnpack(b);
    doUnpacking(b,this->homeInitCookie_var);
    doUnpacking(b,this->homeKeyGenToken_var);
    delete [] this->mobBIDmobility_var;
    b->unpack(mobBIDmobility_arraysize);
    if (mobBIDmobility_arraysize==0) {
        this->mobBIDmobility_var = 0;
    } else {
        this->mobBIDmobility_var = new MobOption_Binding_Identifier_Mobility[mobBIDmobility_arraysize];
        doUnpacking(b,this->mobBIDmobility_var,mobBIDmobility_arraysize);
    }
}

unsigned int HomeTest::getHomeInitCookie() const
{
    return homeInitCookie_var;
}

void HomeTest::setHomeInitCookie(unsigned int homeInitCookie)
{
    this->homeInitCookie_var = homeInitCookie;
}

unsigned int HomeTest::getHomeKeyGenToken() const
{
    return homeKeyGenToken_var;
}

void HomeTest::setHomeKeyGenToken(unsigned int homeKeyGenToken)
{
    this->homeKeyGenToken_var = homeKeyGenToken;
}

void HomeTest::setMobBIDmobilityArraySize(unsigned int size)
{
    MobOption_Binding_Identifier_Mobility *mobBIDmobility_var2 = (size==0) ? NULL : new MobOption_Binding_Identifier_Mobility[size];
    unsigned int sz = mobBIDmobility_arraysize < size ? mobBIDmobility_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        mobBIDmobility_var2[i] = this->mobBIDmobility_var[i];
    mobBIDmobility_arraysize = size;
    delete [] this->mobBIDmobility_var;
    this->mobBIDmobility_var = mobBIDmobility_var2;
}

unsigned int HomeTest::getMobBIDmobilityArraySize() const
{
    return mobBIDmobility_arraysize;
}

MobOption_Binding_Identifier_Mobility& HomeTest::getMobBIDmobility(unsigned int k)
{
    if (k>=mobBIDmobility_arraysize) throw cRuntimeError("Array of size %d indexed by %d", mobBIDmobility_arraysize, k);
    return mobBIDmobility_var[k];
}

void HomeTest::setMobBIDmobility(unsigned int k, const MobOption_Binding_Identifier_Mobility& mobBIDmobility)
{
    if (k>=mobBIDmobility_arraysize) throw cRuntimeError("Array of size %d indexed by %d", mobBIDmobility_arraysize, k);
    this->mobBIDmobility_var[k] = mobBIDmobility;
}

class HomeTestDescriptor : public cClassDescriptor
{
  public:
    HomeTestDescriptor();
    virtual ~HomeTestDescriptor();

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

Register_ClassDescriptor(HomeTestDescriptor);

HomeTestDescriptor::HomeTestDescriptor() : cClassDescriptor("HomeTest", "MobilityHeader")
{
}

HomeTestDescriptor::~HomeTestDescriptor()
{
}

bool HomeTestDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<HomeTest *>(obj)!=NULL;
}

const char *HomeTestDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int HomeTestDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int HomeTestDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *HomeTestDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "homeInitCookie",
        "homeKeyGenToken",
        "mobBIDmobility",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int HomeTestDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='h' && strcmp(fieldName, "homeInitCookie")==0) return base+0;
    if (fieldName[0]=='h' && strcmp(fieldName, "homeKeyGenToken")==0) return base+1;
    if (fieldName[0]=='m' && strcmp(fieldName, "mobBIDmobility")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *HomeTestDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "unsigned int",
        "MobOption_Binding_Identifier_Mobility",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *HomeTestDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int HomeTestDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    HomeTest *pp = (HomeTest *)object; (void)pp;
    switch (field) {
        case 2: return pp->getMobBIDmobilityArraySize();
        default: return 0;
    }
}

std::string HomeTestDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    HomeTest *pp = (HomeTest *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getHomeInitCookie());
        case 1: return ulong2string(pp->getHomeKeyGenToken());
        case 2: {std::stringstream out; out << pp->getMobBIDmobility(i); return out.str();}
        default: return "";
    }
}

bool HomeTestDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    HomeTest *pp = (HomeTest *)object; (void)pp;
    switch (field) {
        case 0: pp->setHomeInitCookie(string2ulong(value)); return true;
        case 1: pp->setHomeKeyGenToken(string2ulong(value)); return true;
        default: return false;
    }
}

const char *HomeTestDescriptor::getFieldStructName(void *object, int field) const
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
        "MobOption_Binding_Identifier_Mobility",
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *HomeTestDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    HomeTest *pp = (HomeTest *)object; (void)pp;
    switch (field) {
        case 2: return (void *)static_cast<cObject *>(&pp->getMobBIDmobility(i)); break;
        default: return NULL;
    }
}

Register_Class(CareOfTestInit);

CareOfTestInit::CareOfTestInit(const char *name, int kind) : ::MobilityHeader(name,kind)
{
    this->careOfInitCookie_var = 0;
    mobBIDmobility_arraysize = 0;
    this->mobBIDmobility_var = 0;
}

CareOfTestInit::CareOfTestInit(const CareOfTestInit& other) : ::MobilityHeader(other)
{
    mobBIDmobility_arraysize = 0;
    this->mobBIDmobility_var = 0;
    copy(other);
}

CareOfTestInit::~CareOfTestInit()
{
    delete [] mobBIDmobility_var;
}

CareOfTestInit& CareOfTestInit::operator=(const CareOfTestInit& other)
{
    if (this==&other) return *this;
    ::MobilityHeader::operator=(other);
    copy(other);
    return *this;
}

void CareOfTestInit::copy(const CareOfTestInit& other)
{
    this->careOfInitCookie_var = other.careOfInitCookie_var;
    delete [] this->mobBIDmobility_var;
    this->mobBIDmobility_var = (other.mobBIDmobility_arraysize==0) ? NULL : new MobOption_Binding_Identifier_Mobility[other.mobBIDmobility_arraysize];
    mobBIDmobility_arraysize = other.mobBIDmobility_arraysize;
    for (unsigned int i=0; i<mobBIDmobility_arraysize; i++)
        this->mobBIDmobility_var[i] = other.mobBIDmobility_var[i];
}

void CareOfTestInit::parsimPack(cCommBuffer *b)
{
    ::MobilityHeader::parsimPack(b);
    doPacking(b,this->careOfInitCookie_var);
    b->pack(mobBIDmobility_arraysize);
    doPacking(b,this->mobBIDmobility_var,mobBIDmobility_arraysize);
}

void CareOfTestInit::parsimUnpack(cCommBuffer *b)
{
    ::MobilityHeader::parsimUnpack(b);
    doUnpacking(b,this->careOfInitCookie_var);
    delete [] this->mobBIDmobility_var;
    b->unpack(mobBIDmobility_arraysize);
    if (mobBIDmobility_arraysize==0) {
        this->mobBIDmobility_var = 0;
    } else {
        this->mobBIDmobility_var = new MobOption_Binding_Identifier_Mobility[mobBIDmobility_arraysize];
        doUnpacking(b,this->mobBIDmobility_var,mobBIDmobility_arraysize);
    }
}

unsigned int CareOfTestInit::getCareOfInitCookie() const
{
    return careOfInitCookie_var;
}

void CareOfTestInit::setCareOfInitCookie(unsigned int careOfInitCookie)
{
    this->careOfInitCookie_var = careOfInitCookie;
}

void CareOfTestInit::setMobBIDmobilityArraySize(unsigned int size)
{
    MobOption_Binding_Identifier_Mobility *mobBIDmobility_var2 = (size==0) ? NULL : new MobOption_Binding_Identifier_Mobility[size];
    unsigned int sz = mobBIDmobility_arraysize < size ? mobBIDmobility_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        mobBIDmobility_var2[i] = this->mobBIDmobility_var[i];
    mobBIDmobility_arraysize = size;
    delete [] this->mobBIDmobility_var;
    this->mobBIDmobility_var = mobBIDmobility_var2;
}

unsigned int CareOfTestInit::getMobBIDmobilityArraySize() const
{
    return mobBIDmobility_arraysize;
}

MobOption_Binding_Identifier_Mobility& CareOfTestInit::getMobBIDmobility(unsigned int k)
{
    if (k>=mobBIDmobility_arraysize) throw cRuntimeError("Array of size %d indexed by %d", mobBIDmobility_arraysize, k);
    return mobBIDmobility_var[k];
}

void CareOfTestInit::setMobBIDmobility(unsigned int k, const MobOption_Binding_Identifier_Mobility& mobBIDmobility)
{
    if (k>=mobBIDmobility_arraysize) throw cRuntimeError("Array of size %d indexed by %d", mobBIDmobility_arraysize, k);
    this->mobBIDmobility_var[k] = mobBIDmobility;
}

class CareOfTestInitDescriptor : public cClassDescriptor
{
  public:
    CareOfTestInitDescriptor();
    virtual ~CareOfTestInitDescriptor();

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

Register_ClassDescriptor(CareOfTestInitDescriptor);

CareOfTestInitDescriptor::CareOfTestInitDescriptor() : cClassDescriptor("CareOfTestInit", "MobilityHeader")
{
}

CareOfTestInitDescriptor::~CareOfTestInitDescriptor()
{
}

bool CareOfTestInitDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<CareOfTestInit *>(obj)!=NULL;
}

const char *CareOfTestInitDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int CareOfTestInitDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int CareOfTestInitDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *CareOfTestInitDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "careOfInitCookie",
        "mobBIDmobility",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int CareOfTestInitDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "careOfInitCookie")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "mobBIDmobility")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *CareOfTestInitDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "MobOption_Binding_Identifier_Mobility",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *CareOfTestInitDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int CareOfTestInitDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    CareOfTestInit *pp = (CareOfTestInit *)object; (void)pp;
    switch (field) {
        case 1: return pp->getMobBIDmobilityArraySize();
        default: return 0;
    }
}

std::string CareOfTestInitDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    CareOfTestInit *pp = (CareOfTestInit *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getCareOfInitCookie());
        case 1: {std::stringstream out; out << pp->getMobBIDmobility(i); return out.str();}
        default: return "";
    }
}

bool CareOfTestInitDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    CareOfTestInit *pp = (CareOfTestInit *)object; (void)pp;
    switch (field) {
        case 0: pp->setCareOfInitCookie(string2ulong(value)); return true;
        default: return false;
    }
}

const char *CareOfTestInitDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        "MobOption_Binding_Identifier_Mobility",
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *CareOfTestInitDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    CareOfTestInit *pp = (CareOfTestInit *)object; (void)pp;
    switch (field) {
        case 1: return (void *)static_cast<cObject *>(&pp->getMobBIDmobility(i)); break;
        default: return NULL;
    }
}

Register_Class(CareOfTest);

CareOfTest::CareOfTest(const char *name, int kind) : ::MobilityHeader(name,kind)
{
    this->careOfInitCookie_var = 0;
    this->careOfKeyGenToken_var = 0;
    mobBIDmobility_arraysize = 0;
    this->mobBIDmobility_var = 0;
}

CareOfTest::CareOfTest(const CareOfTest& other) : ::MobilityHeader(other)
{
    mobBIDmobility_arraysize = 0;
    this->mobBIDmobility_var = 0;
    copy(other);
}

CareOfTest::~CareOfTest()
{
    delete [] mobBIDmobility_var;
}

CareOfTest& CareOfTest::operator=(const CareOfTest& other)
{
    if (this==&other) return *this;
    ::MobilityHeader::operator=(other);
    copy(other);
    return *this;
}

void CareOfTest::copy(const CareOfTest& other)
{
    this->careOfInitCookie_var = other.careOfInitCookie_var;
    this->careOfKeyGenToken_var = other.careOfKeyGenToken_var;
    delete [] this->mobBIDmobility_var;
    this->mobBIDmobility_var = (other.mobBIDmobility_arraysize==0) ? NULL : new MobOption_Binding_Identifier_Mobility[other.mobBIDmobility_arraysize];
    mobBIDmobility_arraysize = other.mobBIDmobility_arraysize;
    for (unsigned int i=0; i<mobBIDmobility_arraysize; i++)
        this->mobBIDmobility_var[i] = other.mobBIDmobility_var[i];
}

void CareOfTest::parsimPack(cCommBuffer *b)
{
    ::MobilityHeader::parsimPack(b);
    doPacking(b,this->careOfInitCookie_var);
    doPacking(b,this->careOfKeyGenToken_var);
    b->pack(mobBIDmobility_arraysize);
    doPacking(b,this->mobBIDmobility_var,mobBIDmobility_arraysize);
}

void CareOfTest::parsimUnpack(cCommBuffer *b)
{
    ::MobilityHeader::parsimUnpack(b);
    doUnpacking(b,this->careOfInitCookie_var);
    doUnpacking(b,this->careOfKeyGenToken_var);
    delete [] this->mobBIDmobility_var;
    b->unpack(mobBIDmobility_arraysize);
    if (mobBIDmobility_arraysize==0) {
        this->mobBIDmobility_var = 0;
    } else {
        this->mobBIDmobility_var = new MobOption_Binding_Identifier_Mobility[mobBIDmobility_arraysize];
        doUnpacking(b,this->mobBIDmobility_var,mobBIDmobility_arraysize);
    }
}

unsigned int CareOfTest::getCareOfInitCookie() const
{
    return careOfInitCookie_var;
}

void CareOfTest::setCareOfInitCookie(unsigned int careOfInitCookie)
{
    this->careOfInitCookie_var = careOfInitCookie;
}

unsigned int CareOfTest::getCareOfKeyGenToken() const
{
    return careOfKeyGenToken_var;
}

void CareOfTest::setCareOfKeyGenToken(unsigned int careOfKeyGenToken)
{
    this->careOfKeyGenToken_var = careOfKeyGenToken;
}

void CareOfTest::setMobBIDmobilityArraySize(unsigned int size)
{
    MobOption_Binding_Identifier_Mobility *mobBIDmobility_var2 = (size==0) ? NULL : new MobOption_Binding_Identifier_Mobility[size];
    unsigned int sz = mobBIDmobility_arraysize < size ? mobBIDmobility_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        mobBIDmobility_var2[i] = this->mobBIDmobility_var[i];
    mobBIDmobility_arraysize = size;
    delete [] this->mobBIDmobility_var;
    this->mobBIDmobility_var = mobBIDmobility_var2;
}

unsigned int CareOfTest::getMobBIDmobilityArraySize() const
{
    return mobBIDmobility_arraysize;
}

MobOption_Binding_Identifier_Mobility& CareOfTest::getMobBIDmobility(unsigned int k)
{
    if (k>=mobBIDmobility_arraysize) throw cRuntimeError("Array of size %d indexed by %d", mobBIDmobility_arraysize, k);
    return mobBIDmobility_var[k];
}

void CareOfTest::setMobBIDmobility(unsigned int k, const MobOption_Binding_Identifier_Mobility& mobBIDmobility)
{
    if (k>=mobBIDmobility_arraysize) throw cRuntimeError("Array of size %d indexed by %d", mobBIDmobility_arraysize, k);
    this->mobBIDmobility_var[k] = mobBIDmobility;
}

class CareOfTestDescriptor : public cClassDescriptor
{
  public:
    CareOfTestDescriptor();
    virtual ~CareOfTestDescriptor();

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

Register_ClassDescriptor(CareOfTestDescriptor);

CareOfTestDescriptor::CareOfTestDescriptor() : cClassDescriptor("CareOfTest", "MobilityHeader")
{
}

CareOfTestDescriptor::~CareOfTestDescriptor()
{
}

bool CareOfTestDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<CareOfTest *>(obj)!=NULL;
}

const char *CareOfTestDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int CareOfTestDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int CareOfTestDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *CareOfTestDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "careOfInitCookie",
        "careOfKeyGenToken",
        "mobBIDmobility",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int CareOfTestDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "careOfInitCookie")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "careOfKeyGenToken")==0) return base+1;
    if (fieldName[0]=='m' && strcmp(fieldName, "mobBIDmobility")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *CareOfTestDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "unsigned int",
        "MobOption_Binding_Identifier_Mobility",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *CareOfTestDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int CareOfTestDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    CareOfTest *pp = (CareOfTest *)object; (void)pp;
    switch (field) {
        case 2: return pp->getMobBIDmobilityArraySize();
        default: return 0;
    }
}

std::string CareOfTestDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    CareOfTest *pp = (CareOfTest *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getCareOfInitCookie());
        case 1: return ulong2string(pp->getCareOfKeyGenToken());
        case 2: {std::stringstream out; out << pp->getMobBIDmobility(i); return out.str();}
        default: return "";
    }
}

bool CareOfTestDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    CareOfTest *pp = (CareOfTest *)object; (void)pp;
    switch (field) {
        case 0: pp->setCareOfInitCookie(string2ulong(value)); return true;
        case 1: pp->setCareOfKeyGenToken(string2ulong(value)); return true;
        default: return false;
    }
}

const char *CareOfTestDescriptor::getFieldStructName(void *object, int field) const
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
        "MobOption_Binding_Identifier_Mobility",
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *CareOfTestDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    CareOfTest *pp = (CareOfTest *)object; (void)pp;
    switch (field) {
        case 2: return (void *)static_cast<cObject *>(&pp->getMobBIDmobility(i)); break;
        default: return NULL;
    }
}

Register_Class(BindingRefreshRequest);

BindingRefreshRequest::BindingRefreshRequest(const char *name, int kind) : ::MobilityHeader(name,kind)
{
    mobBIDmobility_arraysize = 0;
    this->mobBIDmobility_var = 0;
}

BindingRefreshRequest::BindingRefreshRequest(const BindingRefreshRequest& other) : ::MobilityHeader(other)
{
    mobBIDmobility_arraysize = 0;
    this->mobBIDmobility_var = 0;
    copy(other);
}

BindingRefreshRequest::~BindingRefreshRequest()
{
    delete [] mobBIDmobility_var;
}

BindingRefreshRequest& BindingRefreshRequest::operator=(const BindingRefreshRequest& other)
{
    if (this==&other) return *this;
    ::MobilityHeader::operator=(other);
    copy(other);
    return *this;
}

void BindingRefreshRequest::copy(const BindingRefreshRequest& other)
{
    delete [] this->mobBIDmobility_var;
    this->mobBIDmobility_var = (other.mobBIDmobility_arraysize==0) ? NULL : new MobOption_Binding_Identifier_Mobility[other.mobBIDmobility_arraysize];
    mobBIDmobility_arraysize = other.mobBIDmobility_arraysize;
    for (unsigned int i=0; i<mobBIDmobility_arraysize; i++)
        this->mobBIDmobility_var[i] = other.mobBIDmobility_var[i];
}

void BindingRefreshRequest::parsimPack(cCommBuffer *b)
{
    ::MobilityHeader::parsimPack(b);
    b->pack(mobBIDmobility_arraysize);
    doPacking(b,this->mobBIDmobility_var,mobBIDmobility_arraysize);
}

void BindingRefreshRequest::parsimUnpack(cCommBuffer *b)
{
    ::MobilityHeader::parsimUnpack(b);
    delete [] this->mobBIDmobility_var;
    b->unpack(mobBIDmobility_arraysize);
    if (mobBIDmobility_arraysize==0) {
        this->mobBIDmobility_var = 0;
    } else {
        this->mobBIDmobility_var = new MobOption_Binding_Identifier_Mobility[mobBIDmobility_arraysize];
        doUnpacking(b,this->mobBIDmobility_var,mobBIDmobility_arraysize);
    }
}

void BindingRefreshRequest::setMobBIDmobilityArraySize(unsigned int size)
{
    MobOption_Binding_Identifier_Mobility *mobBIDmobility_var2 = (size==0) ? NULL : new MobOption_Binding_Identifier_Mobility[size];
    unsigned int sz = mobBIDmobility_arraysize < size ? mobBIDmobility_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        mobBIDmobility_var2[i] = this->mobBIDmobility_var[i];
    mobBIDmobility_arraysize = size;
    delete [] this->mobBIDmobility_var;
    this->mobBIDmobility_var = mobBIDmobility_var2;
}

unsigned int BindingRefreshRequest::getMobBIDmobilityArraySize() const
{
    return mobBIDmobility_arraysize;
}

MobOption_Binding_Identifier_Mobility& BindingRefreshRequest::getMobBIDmobility(unsigned int k)
{
    if (k>=mobBIDmobility_arraysize) throw cRuntimeError("Array of size %d indexed by %d", mobBIDmobility_arraysize, k);
    return mobBIDmobility_var[k];
}

void BindingRefreshRequest::setMobBIDmobility(unsigned int k, const MobOption_Binding_Identifier_Mobility& mobBIDmobility)
{
    if (k>=mobBIDmobility_arraysize) throw cRuntimeError("Array of size %d indexed by %d", mobBIDmobility_arraysize, k);
    this->mobBIDmobility_var[k] = mobBIDmobility;
}

class BindingRefreshRequestDescriptor : public cClassDescriptor
{
  public:
    BindingRefreshRequestDescriptor();
    virtual ~BindingRefreshRequestDescriptor();

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

Register_ClassDescriptor(BindingRefreshRequestDescriptor);

BindingRefreshRequestDescriptor::BindingRefreshRequestDescriptor() : cClassDescriptor("BindingRefreshRequest", "MobilityHeader")
{
}

BindingRefreshRequestDescriptor::~BindingRefreshRequestDescriptor()
{
}

bool BindingRefreshRequestDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BindingRefreshRequest *>(obj)!=NULL;
}

const char *BindingRefreshRequestDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BindingRefreshRequestDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int BindingRefreshRequestDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *BindingRefreshRequestDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "mobBIDmobility",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int BindingRefreshRequestDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "mobBIDmobility")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BindingRefreshRequestDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "MobOption_Binding_Identifier_Mobility",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *BindingRefreshRequestDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int BindingRefreshRequestDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BindingRefreshRequest *pp = (BindingRefreshRequest *)object; (void)pp;
    switch (field) {
        case 0: return pp->getMobBIDmobilityArraySize();
        default: return 0;
    }
}

std::string BindingRefreshRequestDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BindingRefreshRequest *pp = (BindingRefreshRequest *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getMobBIDmobility(i); return out.str();}
        default: return "";
    }
}

bool BindingRefreshRequestDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BindingRefreshRequest *pp = (BindingRefreshRequest *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *BindingRefreshRequestDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "MobOption_Binding_Identifier_Mobility",
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *BindingRefreshRequestDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BindingRefreshRequest *pp = (BindingRefreshRequest *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<cObject *>(&pp->getMobBIDmobility(i)); break;
        default: return NULL;
    }
}

HomeAddressOption_Base::HomeAddressOption_Base() : ::IPv6DestinationOptionsHeader()
{
}

HomeAddressOption_Base::HomeAddressOption_Base(const HomeAddressOption_Base& other) : ::IPv6DestinationOptionsHeader(other)
{
    copy(other);
}

HomeAddressOption_Base::~HomeAddressOption_Base()
{
}

HomeAddressOption_Base& HomeAddressOption_Base::operator=(const HomeAddressOption_Base& other)
{
    if (this==&other) return *this;
    ::IPv6DestinationOptionsHeader::operator=(other);
    copy(other);
    return *this;
}

void HomeAddressOption_Base::copy(const HomeAddressOption_Base& other)
{
    this->homeAddress_var = other.homeAddress_var;
}

void HomeAddressOption_Base::parsimPack(cCommBuffer *b)
{
    doPacking(b,(::IPv6DestinationOptionsHeader&)*this);
    doPacking(b,this->homeAddress_var);
}

void HomeAddressOption_Base::parsimUnpack(cCommBuffer *b)
{
    doUnpacking(b,(::IPv6DestinationOptionsHeader&)*this);
    doUnpacking(b,this->homeAddress_var);
}

IPv6Address& HomeAddressOption_Base::getHomeAddress()
{
    return homeAddress_var;
}

void HomeAddressOption_Base::setHomeAddress(const IPv6Address& homeAddress)
{
    this->homeAddress_var = homeAddress;
}

class HomeAddressOptionDescriptor : public cClassDescriptor
{
  public:
    HomeAddressOptionDescriptor();
    virtual ~HomeAddressOptionDescriptor();

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

Register_ClassDescriptor(HomeAddressOptionDescriptor);

HomeAddressOptionDescriptor::HomeAddressOptionDescriptor() : cClassDescriptor("HomeAddressOption", "IPv6DestinationOptionsHeader")
{
}

HomeAddressOptionDescriptor::~HomeAddressOptionDescriptor()
{
}

bool HomeAddressOptionDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<HomeAddressOption_Base *>(obj)!=NULL;
}

const char *HomeAddressOptionDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int HomeAddressOptionDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int HomeAddressOptionDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *HomeAddressOptionDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "homeAddress",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int HomeAddressOptionDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='h' && strcmp(fieldName, "homeAddress")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *HomeAddressOptionDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "IPv6Address",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *HomeAddressOptionDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int HomeAddressOptionDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    HomeAddressOption_Base *pp = (HomeAddressOption_Base *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string HomeAddressOptionDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    HomeAddressOption_Base *pp = (HomeAddressOption_Base *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getHomeAddress(); return out.str();}
        default: return "";
    }
}

bool HomeAddressOptionDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    HomeAddressOption_Base *pp = (HomeAddressOption_Base *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *HomeAddressOptionDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "IPv6Address",
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *HomeAddressOptionDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    HomeAddressOption_Base *pp = (HomeAddressOption_Base *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getHomeAddress()); break;
        default: return NULL;
    }
}


