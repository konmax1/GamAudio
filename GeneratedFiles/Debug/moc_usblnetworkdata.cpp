/****************************************************************************
** Meta object code from reading C++ file 'usblnetworkdata.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../usblnetworkdata.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'usblnetworkdata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_USBLNetworkData_t {
    QByteArrayData data[14];
    char stringdata0[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_USBLNetworkData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_USBLNetworkData_t qt_meta_stringdata_USBLNetworkData = {
    {
QT_MOC_LITERAL(0, 0, 15), // "USBLNetworkData"
QT_MOC_LITERAL(1, 16, 18), // "connectToUSBLthSig"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 3), // "_ip"
QT_MOC_LITERAL(4, 40, 4), // "freq"
QT_MOC_LITERAL(5, 45, 7), // "channel"
QT_MOC_LITERAL(6, 53, 13), // "addNewDataSig"
QT_MOC_LITERAL(7, 67, 15), // "QVector<double>"
QT_MOC_LITERAL(8, 83, 4), // "_vec"
QT_MOC_LITERAL(9, 88, 15), // "connectToUSBLth"
QT_MOC_LITERAL(10, 104, 20), // "disconnectFromUSBLth"
QT_MOC_LITERAL(11, 125, 13), // "startedThread"
QT_MOC_LITERAL(12, 139, 9), // "readyRead"
QT_MOC_LITERAL(13, 149, 13) // "connectToUSBL"

    },
    "USBLNetworkData\0connectToUSBLthSig\0\0"
    "_ip\0freq\0channel\0addNewDataSig\0"
    "QVector<double>\0_vec\0connectToUSBLth\0"
    "disconnectFromUSBLth\0startedThread\0"
    "readyRead\0connectToUSBL"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_USBLNetworkData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   64,    2, 0x06 /* Public */,
       1,    2,   71,    2, 0x26 /* Public | MethodCloned */,
       6,    1,   76,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    3,   79,    2, 0x0a /* Public */,
       9,    2,   86,    2, 0x2a /* Public | MethodCloned */,
      10,    0,   91,    2, 0x0a /* Public */,
      11,    0,   92,    2, 0x0a /* Public */,
      12,    0,   93,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      13,    3,   94,    2, 0x02 /* Public */,
      13,    2,  101,    2, 0x22 /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::UInt,    3,    4,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt,    3,    4,
    QMetaType::Void, 0x80000000 | 7,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::UInt,    3,    4,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UInt, QMetaType::UInt,    3,    4,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt,    3,    4,

       0        // eod
};

void USBLNetworkData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        USBLNetworkData *_t = static_cast<USBLNetworkData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connectToUSBLthSig((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3]))); break;
        case 1: _t->connectToUSBLthSig((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 2: _t->addNewDataSig((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 3: _t->connectToUSBLth((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3]))); break;
        case 4: _t->connectToUSBLth((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 5: _t->disconnectFromUSBLth(); break;
        case 6: _t->startedThread(); break;
        case 7: _t->readyRead(); break;
        case 8: _t->connectToUSBL((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3]))); break;
        case 9: _t->connectToUSBL((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (USBLNetworkData::*)(QString , quint32 , quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&USBLNetworkData::connectToUSBLthSig)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (USBLNetworkData::*)(QVector<double> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&USBLNetworkData::addNewDataSig)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject USBLNetworkData::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_USBLNetworkData.data,
      qt_meta_data_USBLNetworkData,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *USBLNetworkData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *USBLNetworkData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_USBLNetworkData.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int USBLNetworkData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void USBLNetworkData::connectToUSBLthSig(QString _t1, quint32 _t2, quint32 _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 2
void USBLNetworkData::addNewDataSig(QVector<double> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
