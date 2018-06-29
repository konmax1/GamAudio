/****************************************************************************
** Meta object code from reading C++ file 'datachart.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../datachart.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datachart.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_dataChart_t {
    QByteArrayData data[16];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dataChart_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dataChart_t qt_meta_stringdata_dataChart = {
    {
QT_MOC_LITERAL(0, 0, 9), // "dataChart"
QT_MOC_LITERAL(1, 10, 10), // "initSeries"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 16), // "QAbstractSeries*"
QT_MOC_LITERAL(4, 39, 7), // "_series"
QT_MOC_LITERAL(5, 47, 5), // "param"
QT_MOC_LITERAL(6, 53, 13), // "sendChartData"
QT_MOC_LITERAL(7, 67, 15), // "QVector<double>"
QT_MOC_LITERAL(8, 83, 3), // "_v1"
QT_MOC_LITERAL(9, 87, 3), // "_v2"
QT_MOC_LITERAL(10, 91, 23), // "QList<QVector<double> >"
QT_MOC_LITERAL(11, 115, 2), // "_v"
QT_MOC_LITERAL(12, 118, 8), // "destruct"
QT_MOC_LITERAL(13, 127, 9), // "setActive"
QT_MOC_LITERAL(14, 137, 4), // "_act"
QT_MOC_LITERAL(15, 142, 4) // "_len"

    },
    "dataChart\0initSeries\0\0QAbstractSeries*\0"
    "_series\0param\0sendChartData\0QVector<double>\0"
    "_v1\0_v2\0QList<QVector<double> >\0_v\0"
    "destruct\0setActive\0_act\0_len"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dataChart[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x0a /* Public */,
       6,    2,   44,    2, 0x0a /* Public */,
       6,    1,   49,    2, 0x0a /* Public */,
      12,    1,   52,    2, 0x0a /* Public */,
      13,    2,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::UInt,    4,    5,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7,    8,    9,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,   14,   15,

       0        // eod
};

void dataChart::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        dataChart *_t = static_cast<dataChart *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initSeries((*reinterpret_cast< QAbstractSeries*(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 1: _t->sendChartData((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        case 2: _t->sendChartData((*reinterpret_cast< QList<QVector<double> >(*)>(_a[1]))); break;
        case 3: _t->destruct((*reinterpret_cast< QAbstractSeries*(*)>(_a[1]))); break;
        case 4: _t->setActive((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< qint32(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSeries* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QVector<double> > >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSeries* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject dataChart::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_dataChart.data,
      qt_meta_data_dataChart,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *dataChart::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dataChart::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dataChart.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int dataChart::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
