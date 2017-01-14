#include <iostream>
#include <string>
#include <cmath>
#include <assert.h>
#include <inttypes.h>
#include "../hashmap/HashMap.h"
#include "../hashmap/KeyHash.h"

class Param {
public:
    enum Type {
        FLOAT = 0,
        INT = 1,
    };
    typedef HashMap<const char *, Param *, 8, KeyHash<const char *, 8> > DictType;
    union Value {
        static Value fromInt(int val) {
            Value v;
            v.i = val;
            return v;
        }
        static Value fromFloat(float val) {
            Value v;
            v.f = val;
            return v;
        }
        int i;
        float f;
    };
    Param(const char * name, Value defaultValue, Type type) :
        _name(name),
        _def(defaultValue),
        _type(type)
    {
        getDict().put(name, this);
    }
    Param(const Param & p) :
        _name(p._name),
        _def(p._def),
        _type(p._type)
    {
        _dict.remove(p._name);
        _dict.put(p._name, this);
    };
    const char * getName() {
        return _name;
    }
    Type getType() {
        return (Type)_type;
    }
    int getInt() {
        if (getType() == FLOAT) {
            return int(_def.f);
        } else if (getType() == INT) {
            return _def.i;
        } else {
            return 0;
        }
    }
    float getFloat() {
        if (getType() == FLOAT) {
            return _def.f;
        } else if (getType() == INT) {
            return float(_def.i);
        } else {
            return 0;
        }
    }
    static Param fromFloat(const char * name, float defaultValue) {
        return Param(name, Value::fromFloat(defaultValue), FLOAT);
    }
    static Param fromInt(const char * name, int defaultValue) {
        return Param(name, Value::fromInt(defaultValue), INT);
    }
    static DictType & getDict() {
        return _dict;
    }
private:
    const char * _name;
    Value _def;
    Type _type;
    static DictType _dict;
};
Param::DictType Param::_dict = Param::DictType();

Param paramList[] = {
    Param::fromFloat("param1", 1.0f),
    Param::fromInt("param2", 2),
    Param::fromFloat("param3", 1.3f),
};

int main()
{
    Param * p = NULL;
    bool result = false;

    // param1
    result = Param::getDict().get("param1", p);
    assert(result);
    assert(p->getType() == Param::FLOAT);
    assert(fabs(p->getFloat() - 1.0f) < 1e-20);
    assert(p->getInt() == 1);

    // param2
    result = Param::getDict().get("param2", p);
    assert(result);
    assert(p->getType() == Param::INT);
    assert(fabs(p->getFloat() - 2.0f) < 1e-20);
    assert(p->getInt() == 2);

    // param3
    result = Param::getDict().get("param3", p);
    assert(result);
    assert(p->getType() == Param::FLOAT);
    assert(fabs(p->getFloat() - 1.3f) < 1e-20);
    assert(p->getInt() == 1);
};
