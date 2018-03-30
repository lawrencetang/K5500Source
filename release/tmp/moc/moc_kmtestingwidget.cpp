/****************************************************************************
** Meta object code from reading C++ file 'kmtestingwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../applications/kitmethodwindow/kmtestingwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kmtestingwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KMTestingWidget_t {
    QByteArrayData data[22];
    char stringdata0[270];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KMTestingWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KMTestingWidget_t qt_meta_stringdata_KMTestingWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "KMTestingWidget"
QT_MOC_LITERAL(1, 16, 14), // "backBtnClicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 13), // "toSettingPage"
QT_MOC_LITERAL(4, 46, 12), // "toStartBlank"
QT_MOC_LITERAL(5, 59, 14), // "toStartMeasure"
QT_MOC_LITERAL(6, 74, 14), // "toStartFitting"
QT_MOC_LITERAL(7, 89, 15), // "toUpdateSetting"
QT_MOC_LITERAL(8, 105, 6), // "record"
QT_MOC_LITERAL(9, 112, 10), // "saveResult"
QT_MOC_LITERAL(10, 123, 8), // "fileName"
QT_MOC_LITERAL(11, 132, 4), // "data"
QT_MOC_LITERAL(12, 137, 10), // "saveRecord"
QT_MOC_LITERAL(13, 148, 10), // "showResult"
QT_MOC_LITERAL(14, 159, 1), // "c"
QT_MOC_LITERAL(15, 161, 7), // "capture"
QT_MOC_LITERAL(16, 169, 8), // "clearAll"
QT_MOC_LITERAL(17, 178, 8), // "showData"
QT_MOC_LITERAL(18, 187, 15), // "doubleClickPlot"
QT_MOC_LITERAL(19, 203, 28), // "doubleClickRecordTableWidget"
QT_MOC_LITERAL(20, 232, 17), // "onBlankBtnClicked"
QT_MOC_LITERAL(21, 250, 19) // "onMeasureBtnClicked"

    },
    "KMTestingWidget\0backBtnClicked\0\0"
    "toSettingPage\0toStartBlank\0toStartMeasure\0"
    "toStartFitting\0toUpdateSetting\0record\0"
    "saveResult\0fileName\0data\0saveRecord\0"
    "showResult\0c\0capture\0clearAll\0showData\0"
    "doubleClickPlot\0doubleClickRecordTableWidget\0"
    "onBlankBtnClicked\0onMeasureBtnClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KMTestingWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    0,   95,    2, 0x06 /* Public */,
       4,    0,   96,    2, 0x06 /* Public */,
       5,    0,   97,    2, 0x06 /* Public */,
       6,    0,   98,    2, 0x06 /* Public */,
       7,    1,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    2,  102,    2, 0x0a /* Public */,
      12,    1,  107,    2, 0x0a /* Public */,
      13,    1,  110,    2, 0x0a /* Public */,
      15,    0,  113,    2, 0x08 /* Private */,
      16,    0,  114,    2, 0x08 /* Private */,
      17,    1,  115,    2, 0x08 /* Private */,
      18,    0,  118,    2, 0x08 /* Private */,
      19,    0,  119,    2, 0x08 /* Private */,
      20,    0,  120,    2, 0x08 /* Private */,
      21,    0,  121,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,   10,   11,
    QMetaType::Void, QMetaType::QStringList,   11,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void KMTestingWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KMTestingWidget *_t = static_cast<KMTestingWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->backBtnClicked(); break;
        case 1: _t->toSettingPage(); break;
        case 2: _t->toStartBlank(); break;
        case 3: _t->toStartMeasure(); break;
        case 4: _t->toStartFitting(); break;
        case 5: _t->toUpdateSetting((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 6: _t->saveResult((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 7: _t->saveRecord((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 8: _t->showResult((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->capture(); break;
        case 10: _t->clearAll(); break;
        case 11: _t->showData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->doubleClickPlot(); break;
        case 13: _t->doubleClickRecordTableWidget(); break;
        case 14: _t->onBlankBtnClicked(); break;
        case 15: _t->onMeasureBtnClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (KMTestingWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KMTestingWidget::backBtnClicked)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (KMTestingWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KMTestingWidget::toSettingPage)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (KMTestingWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KMTestingWidget::toStartBlank)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (KMTestingWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KMTestingWidget::toStartMeasure)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (KMTestingWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KMTestingWidget::toStartFitting)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (KMTestingWidget::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KMTestingWidget::toUpdateSetting)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject KMTestingWidget::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_KMTestingWidget.data,
      qt_meta_data_KMTestingWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KMTestingWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KMTestingWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KMTestingWidget.stringdata0))
        return static_cast<void*>(const_cast< KMTestingWidget*>(this));
    return QFrame::qt_metacast(_clname);
}

int KMTestingWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void KMTestingWidget::backBtnClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void KMTestingWidget::toSettingPage()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void KMTestingWidget::toStartBlank()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void KMTestingWidget::toStartMeasure()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void KMTestingWidget::toStartFitting()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void KMTestingWidget::toUpdateSetting(QStringList _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
