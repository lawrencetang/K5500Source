/****************************************************************************
** Meta object code from reading C++ file 'kmfittingwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../applications/kitmethodwindow/kmfittingwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kmfittingwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KMFittingWidget_t {
    QByteArrayData data[19];
    char stringdata0[215];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KMFittingWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KMFittingWidget_t qt_meta_stringdata_KMFittingWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "KMFittingWidget"
QT_MOC_LITERAL(1, 16, 18), // "toDrawFittingCurve"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 5), // "title"
QT_MOC_LITERAL(4, 42, 15), // "QVector<double>"
QT_MOC_LITERAL(5, 58, 1), // "x"
QT_MOC_LITERAL(6, 60, 1), // "y"
QT_MOC_LITERAL(7, 62, 18), // "toDrawScatterCurve"
QT_MOC_LITERAL(8, 81, 12), // "toSaveResult"
QT_MOC_LITERAL(9, 94, 8), // "fileName"
QT_MOC_LITERAL(10, 103, 6), // "result"
QT_MOC_LITERAL(11, 110, 12), // "toSaveRecord"
QT_MOC_LITERAL(12, 123, 6), // "record"
QT_MOC_LITERAL(13, 130, 11), // "toExcuteFit"
QT_MOC_LITERAL(14, 142, 13), // "toClearCurves"
QT_MOC_LITERAL(15, 156, 11), // "showAddView"
QT_MOC_LITERAL(16, 168, 14), // "showRemoveView"
QT_MOC_LITERAL(17, 183, 15), // "showFittingView"
QT_MOC_LITERAL(18, 199, 15) // "showMeasureView"

    },
    "KMFittingWidget\0toDrawFittingCurve\0\0"
    "title\0QVector<double>\0x\0y\0toDrawScatterCurve\0"
    "toSaveResult\0fileName\0result\0toSaveRecord\0"
    "record\0toExcuteFit\0toClearCurves\0"
    "showAddView\0showRemoveView\0showFittingView\0"
    "showMeasureView"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KMFittingWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   64,    2, 0x06 /* Public */,
       7,    3,   71,    2, 0x06 /* Public */,
       8,    2,   78,    2, 0x06 /* Public */,
      11,    1,   83,    2, 0x06 /* Public */,
      13,    0,   86,    2, 0x06 /* Public */,
      14,    0,   87,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    0,   88,    2, 0x08 /* Private */,
      16,    0,   89,    2, 0x08 /* Private */,
      17,    0,   90,    2, 0x08 /* Private */,
      18,    0,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4, 0x80000000 | 4,    3,    5,    6,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4, 0x80000000 | 4,    3,    5,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,    9,   10,
    QMetaType::Void, QMetaType::QStringList,   12,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void KMFittingWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KMFittingWidget *_t = static_cast<KMFittingWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->toDrawFittingCurve((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2])),(*reinterpret_cast< QVector<double>(*)>(_a[3]))); break;
        case 1: _t->toDrawScatterCurve((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2])),(*reinterpret_cast< QVector<double>(*)>(_a[3]))); break;
        case 2: _t->toSaveResult((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 3: _t->toSaveRecord((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 4: _t->toExcuteFit(); break;
        case 5: _t->toClearCurves(); break;
        case 6: _t->showAddView(); break;
        case 7: _t->showRemoveView(); break;
        case 8: _t->showFittingView(); break;
        case 9: _t->showMeasureView(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (KMFittingWidget::*_t)(QString , QVector<double> , QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KMFittingWidget::toDrawFittingCurve)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (KMFittingWidget::*_t)(QString , QVector<double> , QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KMFittingWidget::toDrawScatterCurve)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (KMFittingWidget::*_t)(QString , QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KMFittingWidget::toSaveResult)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (KMFittingWidget::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KMFittingWidget::toSaveRecord)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (KMFittingWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KMFittingWidget::toExcuteFit)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (KMFittingWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KMFittingWidget::toClearCurves)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject KMFittingWidget::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_KMFittingWidget.data,
      qt_meta_data_KMFittingWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KMFittingWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KMFittingWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KMFittingWidget.stringdata0))
        return static_cast<void*>(const_cast< KMFittingWidget*>(this));
    return QFrame::qt_metacast(_clname);
}

int KMFittingWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
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
void KMFittingWidget::toDrawFittingCurve(QString _t1, QVector<double> _t2, QVector<double> _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void KMFittingWidget::toDrawScatterCurve(QString _t1, QVector<double> _t2, QVector<double> _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void KMFittingWidget::toSaveResult(QString _t1, QStringList _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void KMFittingWidget::toSaveRecord(QStringList _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void KMFittingWidget::toExcuteFit()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void KMFittingWidget::toClearCurves()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
