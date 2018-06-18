/****************************************************************************
** Meta object code from reading C++ file 'audioclass.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../audioclass.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'audioclass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AudioClass_t {
    QByteArrayData data[14];
    char stringdata0[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AudioClass_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AudioClass_t qt_meta_stringdata_AudioClass = {
    {
QT_MOC_LITERAL(0, 0, 10), // "AudioClass"
QT_MOC_LITERAL(1, 11, 16), // "comboListChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 12), // "countChanged"
QT_MOC_LITERAL(4, 42, 15), // "createAudioList"
QT_MOC_LITERAL(5, 58, 20), // "setAudioOutputDevice"
QT_MOC_LITERAL(6, 79, 3), // "dev"
QT_MOC_LITERAL(7, 83, 10), // "addElement"
QT_MOC_LITERAL(8, 94, 7), // "element"
QT_MOC_LITERAL(9, 102, 13), // "removeElement"
QT_MOC_LITERAL(10, 116, 5), // "index"
QT_MOC_LITERAL(11, 122, 14), // "clearAudioList"
QT_MOC_LITERAL(12, 137, 9), // "comboList"
QT_MOC_LITERAL(13, 147, 5) // "count"

    },
    "AudioClass\0comboListChanged\0\0countChanged\0"
    "createAudioList\0setAudioOutputDevice\0"
    "dev\0addElement\0element\0removeElement\0"
    "index\0clearAudioList\0comboList\0count"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AudioClass[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       2,   62, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   51,    2, 0x0a /* Public */,
       5,    1,   52,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       7,    1,   55,    2, 0x02 /* Public */,
       9,    1,   58,    2, 0x02 /* Public */,
      11,    0,   61,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,

 // properties: name, type, flags
      12, QMetaType::QStringList, 0x00495103,
      13, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void AudioClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AudioClass *_t = static_cast<AudioClass *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->comboListChanged(); break;
        case 1: _t->countChanged(); break;
        case 2: _t->createAudioList(); break;
        case 3: _t->setAudioOutputDevice((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->addElement((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->removeElement((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->clearAudioList(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AudioClass::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AudioClass::comboListChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AudioClass::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AudioClass::countChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        AudioClass *_t = static_cast<AudioClass *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QStringList*>(_v) = _t->comboList(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->count(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        AudioClass *_t = static_cast<AudioClass *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setComboList(*reinterpret_cast< QStringList*>(_v)); break;
        case 1: _t->setCount(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject AudioClass::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AudioClass.data,
      qt_meta_data_AudioClass,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AudioClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AudioClass::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AudioClass.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AudioClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void AudioClass::comboListChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AudioClass::countChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
