/****************************************************************************
** Meta object code from reading C++ file 'nucleicacidtesting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../applications/nucleicacidwindow/nucleicacidtesting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nucleicacidtesting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NucleicAcidTesting_t {
    QByteArrayData data[21];
    char stringdata0[255];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NucleicAcidTesting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NucleicAcidTesting_t qt_meta_stringdata_NucleicAcidTesting = {
    {
QT_MOC_LITERAL(0, 0, 18), // "NucleicAcidTesting"
QT_MOC_LITERAL(1, 19, 14), // "backBtnClicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 13), // "toSettingPage"
QT_MOC_LITERAL(4, 49, 12), // "toStartBlank"
QT_MOC_LITERAL(5, 62, 14), // "toStartMeasure"
QT_MOC_LITERAL(6, 77, 15), // "drawStaticCurve"
QT_MOC_LITERAL(7, 93, 5), // "title"
QT_MOC_LITERAL(8, 99, 15), // "QVector<double>"
QT_MOC_LITERAL(9, 115, 1), // "x"
QT_MOC_LITERAL(10, 117, 1), // "y"
QT_MOC_LITERAL(11, 119, 10), // "saveResult"
QT_MOC_LITERAL(12, 130, 8), // "fileName"
QT_MOC_LITERAL(13, 139, 4), // "data"
QT_MOC_LITERAL(14, 144, 10), // "saveRecord"
QT_MOC_LITERAL(15, 155, 7), // "capture"
QT_MOC_LITERAL(16, 163, 8), // "showData"
QT_MOC_LITERAL(17, 172, 15), // "doubleClickPlot"
QT_MOC_LITERAL(18, 188, 28), // "doubleClickRecordTableWidget"
QT_MOC_LITERAL(19, 217, 17), // "onBlankBtnClicked"
QT_MOC_LITERAL(20, 235, 19) // "onMeasureBtnClicked"

    },
    "NucleicAcidTesting\0backBtnClicked\0\0"
    "toSettingPage\0toStartBlank\0toStartMeasure\0"
    "drawStaticCurve\0title\0QVector<double>\0"
    "x\0y\0saveResult\0fileName\0data\0saveRecord\0"
    "capture\0showData\0doubleClickPlot\0"
    "doubleClickRecordTableWidget\0"
    "onBlankBtnClicked\0onMeasureBtnClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NucleicAcidTesting[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    0,   81,    2, 0x06 /* Public */,
       5,    0,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    3,   83,    2, 0x0a /* Public */,
      11,    2,   90,    2, 0x0a /* Public */,
      14,    1,   95,    2, 0x0a /* Public */,
      15,    0,   98,    2, 0x08 /* Private */,
      16,    1,   99,    2, 0x08 /* Private */,
      17,    0,  102,    2, 0x08 /* Private */,
      18,    0,  103,    2, 0x08 /* Private */,
      19,    0,  104,    2, 0x08 /* Private */,
      20,    0,  105,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 8, 0x80000000 | 8,    7,    9,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QStringList,   12,   13,
    QMetaType::Void, QMetaType::QStringList,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void NucleicAcidTesting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NucleicAcidTesting *_t = static_cast<NucleicAcidTesting *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->backBtnClicked(); break;
        case 1: _t->toSettingPage(); break;
        case 2: _t->toStartBlank(); break;
        case 3: _t->toStartMeasure(); break;
        case 4: _t->drawStaticCurve((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2])),(*reinterpret_cast< QVector<double>(*)>(_a[3]))); break;
        case 5: _t->saveResult((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2]))); break;
        case 6: _t->saveRecord((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 7: _t->capture(); break;
        case 8: _t->showData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->doubleClickPlot(); break;
        case 10: _t->doubleClickRecordTableWidget(); break;
        case 11: _t->onBlankBtnClicked(); break;
        case 12: _t->onMeasureBtnClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
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
            typedef void (NucleicAcidTesting::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NucleicAcidTesting::backBtnClicked)) {
                *result = 0;
            }
        }
        {
            typedef void (NucleicAcidTesting::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NucleicAcidTesting::toSettingPage)) {
                *result = 1;
            }
        }
        {
            typedef void (NucleicAcidTesting::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NucleicAcidTesting::toStartBlank)) {
                *result = 2;
            }
        }
        {
            typedef void (NucleicAcidTesting::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NucleicAcidTesting::toStartMeasure)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject NucleicAcidTesting::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_NucleicAcidTesting.data,
      qt_meta_data_NucleicAcidTesting,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NucleicAcidTesting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NucleicAcidTesting::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NucleicAcidTesting.stringdata0))
        return static_cast<void*>(const_cast< NucleicAcidTesting*>(this));
    return QFrame::qt_metacast(_clname);
}

int NucleicAcidTesting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void NucleicAcidTesting::backBtnClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void NucleicAcidTesting::toSettingPage()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void NucleicAcidTesting::toStartBlank()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void NucleicAcidTesting::toStartMeasure()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
