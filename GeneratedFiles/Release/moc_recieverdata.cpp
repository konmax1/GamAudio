/****************************************************************************
** Meta object code from reading C++ file 'recieverdata.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../recieverdata.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'recieverdata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RecieverData_t {
    QByteArrayData data[17];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RecieverData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RecieverData_t qt_meta_stringdata_RecieverData = {
    {
QT_MOC_LITERAL(0, 0, 12), // "RecieverData"
QT_MOC_LITERAL(1, 13, 13), // "sendChartData"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 15), // "QVector<double>"
QT_MOC_LITERAL(4, 44, 3), // "_v1"
QT_MOC_LITERAL(5, 48, 3), // "_v2"
QT_MOC_LITERAL(6, 52, 23), // "QList<QVector<double> >"
QT_MOC_LITERAL(7, 76, 2), // "_v"
QT_MOC_LITERAL(8, 79, 10), // "addNewData"
QT_MOC_LITERAL(9, 90, 4), // "_vec"
QT_MOC_LITERAL(10, 95, 7), // "Gilbert"
QT_MOC_LITERAL(11, 103, 7), // "double&"
QT_MOC_LITERAL(12, 111, 6), // "sample"
QT_MOC_LITERAL(13, 118, 11), // "complexMult"
QT_MOC_LITERAL(14, 130, 14), // "complex_double"
QT_MOC_LITERAL(15, 145, 2), // "re"
QT_MOC_LITERAL(16, 148, 2) // "im"

    },
    "RecieverData\0sendChartData\0\0QVector<double>\0"
    "_v1\0_v2\0QList<QVector<double> >\0_v\0"
    "addNewData\0_vec\0Gilbert\0double&\0sample\0"
    "complexMult\0complex_double\0re\0im"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RecieverData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   47,    2, 0x0a /* Public */,
      10,    1,   50,    2, 0x0a /* Public */,
      13,    2,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    9,
    QMetaType::Double, 0x80000000 | 11,   12,
    0x80000000 | 14, 0x80000000 | 11, 0x80000000 | 11,   15,   16,

       0        // eod
};

void RecieverData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RecieverData *_t = static_cast<RecieverData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendChartData((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        case 1: _t->sendChartData((*reinterpret_cast< QList<QVector<double> >(*)>(_a[1]))); break;
        case 2: _t->addNewData((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 3: { double _r = _t->Gilbert((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 4: { complex_double _r = _t->complexMult((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< complex_double*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QVector<double> > >(); break;
            }
            break;
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
            using _t = void (RecieverData::*)(QVector<double> , QVector<double> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RecieverData::sendChartData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RecieverData::*)(QList<QVector<double> > );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RecieverData::sendChartData)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RecieverData::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RecieverData.data,
      qt_meta_data_RecieverData,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RecieverData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RecieverData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RecieverData.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RecieverData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void RecieverData::sendChartData(QVector<double> _t1, QVector<double> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RecieverData::sendChartData(QList<QVector<double> > _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
