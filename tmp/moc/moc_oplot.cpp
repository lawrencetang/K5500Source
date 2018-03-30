/****************************************************************************
** Meta object code from reading C++ file 'oplot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../oleplugins/oplot/oplot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'oplot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_OPlot_t {
    QByteArrayData data[21];
    char stringdata[214];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OPlot_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OPlot_t qt_meta_stringdata_OPlot = {
    {
QT_MOC_LITERAL(0, 0, 5), // "OPlot"
QT_MOC_LITERAL(1, 6, 13), // "doubleClicked"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 11), // "clearRulers"
QT_MOC_LITERAL(4, 33, 11), // "clearCurves"
QT_MOC_LITERAL(5, 45, 10), // "hideRulers"
QT_MOC_LITERAL(6, 56, 10), // "hideCurves"
QT_MOC_LITERAL(7, 67, 12), // "hideScatters"
QT_MOC_LITERAL(8, 80, 12), // "QwtPlotItem*"
QT_MOC_LITERAL(9, 93, 4), // "item"
QT_MOC_LITERAL(10, 98, 3), // "off"
QT_MOC_LITERAL(11, 102, 15), // "drawStaticCurve"
QT_MOC_LITERAL(12, 118, 5), // "title"
QT_MOC_LITERAL(13, 124, 15), // "QVector<double>"
QT_MOC_LITERAL(14, 140, 1), // "x"
QT_MOC_LITERAL(15, 142, 1), // "y"
QT_MOC_LITERAL(16, 144, 16), // "drawFittingCurve"
QT_MOC_LITERAL(17, 161, 16), // "drawScatterCurve"
QT_MOC_LITERAL(18, 178, 16), // "drawDynamicCurve"
QT_MOC_LITERAL(19, 195, 15), // "onLegendChecked"
QT_MOC_LITERAL(20, 211, 2) // "ok"

    },
    "OPlot\0doubleClicked\0\0clearRulers\0"
    "clearCurves\0hideRulers\0hideCurves\0"
    "hideScatters\0QwtPlotItem*\0item\0off\0"
    "drawStaticCurve\0title\0QVector<double>\0"
    "x\0y\0drawFittingCurve\0drawScatterCurve\0"
    "drawDynamicCurve\0onLegendChecked\0ok"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OPlot[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   70,    2, 0x0a /* Public */,
       4,    0,   71,    2, 0x0a /* Public */,
       5,    0,   72,    2, 0x0a /* Public */,
       6,    0,   73,    2, 0x0a /* Public */,
       7,    2,   74,    2, 0x0a /* Public */,
      11,    3,   79,    2, 0x0a /* Public */,
      16,    3,   86,    2, 0x0a /* Public */,
      17,    3,   93,    2, 0x0a /* Public */,
      18,    2,  100,    2, 0x0a /* Public */,
      19,    2,  105,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8, QMetaType::Bool,    9,   10,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 13, 0x80000000 | 13,   12,   14,   15,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 13, 0x80000000 | 13,   12,   14,   15,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 13, 0x80000000 | 13,   12,   14,   15,
    QMetaType::Void, QMetaType::Double, 0x80000000 | 13,   14,   15,
    QMetaType::Void, 0x80000000 | 8, QMetaType::Bool,    9,   20,

       0        // eod
};

void OPlot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OPlot *_t = static_cast<OPlot *>(_o);
        switch (_id) {
        case 0: _t->doubleClicked(); break;
        case 1: _t->clearRulers(); break;
        case 2: _t->clearCurves(); break;
        case 3: _t->hideRulers(); break;
        case 4: _t->hideCurves(); break;
        case 5: _t->hideScatters((*reinterpret_cast< QwtPlotItem*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->drawStaticCurve((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2])),(*reinterpret_cast< QVector<double>(*)>(_a[3]))); break;
        case 7: _t->drawFittingCurve((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2])),(*reinterpret_cast< QVector<double>(*)>(_a[3]))); break;
        case 8: _t->drawScatterCurve((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2])),(*reinterpret_cast< QVector<double>(*)>(_a[3]))); break;
        case 9: _t->drawDynamicCurve((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        case 10: _t->onLegendChecked((*reinterpret_cast< QwtPlotItem*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QwtPlotItem* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QwtPlotItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (OPlot::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OPlot::doubleClicked)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject OPlot::staticMetaObject = {
    { &QwtPlot::staticMetaObject, qt_meta_stringdata_OPlot.data,
      qt_meta_data_OPlot,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *OPlot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OPlot::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_OPlot.stringdata))
        return static_cast<void*>(const_cast< OPlot*>(this));
    return QwtPlot::qt_metacast(_clname);
}

int OPlot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QwtPlot::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void OPlot::doubleClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
