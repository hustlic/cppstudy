#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include <string>

class  Message
{
public:
    enum Type{
        TypeNull,
        TypeInt,
        TypeUInt,
        TypeDouble,
        TypeFloat,
        TypePointer,
        TypeString,
        TypeObject,
        //TypeBuffer,
    };

    Message(int what = 0);

    int what();
    void setWhat(int what);

    void clear();

    int setInt(int value);
    int setUInt(unsigned int value);
    int setDouble(double value);
    int setFloat(float value);
    int setPointer(void *value);
    int setString(const std::string &value);
    //int setObject(const android::sp<android::RefBase> &obj);
    //int setBuffer(const android::sp<Buffer> &buffer);

    bool getIntValue(int index, int *value) const;
    bool getUIntValue(int index, unsigned int *value) const;
    bool getDoubleValue(int index, double *value) const;
    bool getFloatValue(int index, float *value) const;
    bool getPointerValue(int index, void **value) const;
    bool getStringValue(int index, std::string *value) const;
    //bool getObject(int index, android::sp<android::RefBase> *value) const;
    //bool getBuffer(int index, android::sp<Buffer> *value) const;

    int valueCount();
    bool getItemType(int index, Type *type) const;
    virtual ~Message();

private:
    //DISABLE_COPY(Message)
    struct Item {
        union {
            int intValue;
            unsigned int uIntValue;
            double doubleValue;
            float floatValue;
            void *pointerValue;
            std::string *stringValue;
            //RefBase *refValue;
        } u;
        Type type;
    };

    enum {
        MaxNumItems = 32
    };

    Item *allocateItem();
    void freeItem(Item *item);
    const Item *findItem(int index) const;
    bool setItem(int index, Item &item);

    int m_what;
    Item m_items[MaxNumItems];
    int m_itemNum;
};

#endif
