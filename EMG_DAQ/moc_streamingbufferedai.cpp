/****************************************************************************
** Meta object code from reading C++ file 'streamingbufferedai.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "streamingbufferedai.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'streamingbufferedai.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AI_StreamingBufferedAi_t {
    QByteArrayData data[11];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AI_StreamingBufferedAi_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AI_StreamingBufferedAi_t qt_meta_stringdata_AI_StreamingBufferedAi = {
    {
QT_MOC_LITERAL(0, 0, 22), // "AI_StreamingBufferedAi"
QT_MOC_LITERAL(1, 23, 6), // "ontick"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 15), // "onRestTimerTick"
QT_MOC_LITERAL(4, 47, 15), // "DivValueChanged"
QT_MOC_LITERAL(5, 63, 5), // "value"
QT_MOC_LITERAL(6, 69, 22), // "ButtonConfigureClicked"
QT_MOC_LITERAL(7, 92, 18), // "ButtonStartClicked"
QT_MOC_LITERAL(8, 111, 18), // "ButtonPauseClicked"
QT_MOC_LITERAL(9, 130, 17), // "ButtonStopClicked"
QT_MOC_LITERAL(10, 148, 21) // "on_pushButton_clicked"

    },
    "AI_StreamingBufferedAi\0ontick\0\0"
    "onRestTimerTick\0DivValueChanged\0value\0"
    "ButtonConfigureClicked\0ButtonStartClicked\0"
    "ButtonPauseClicked\0ButtonStopClicked\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AI_StreamingBufferedAi[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    1,   56,    2, 0x08 /* Private */,
       6,    0,   59,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AI_StreamingBufferedAi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AI_StreamingBufferedAi *_t = static_cast<AI_StreamingBufferedAi *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ontick(); break;
        case 1: _t->onRestTimerTick(); break;
        case 2: _t->DivValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->ButtonConfigureClicked(); break;
        case 4: _t->ButtonStartClicked(); break;
        case 5: _t->ButtonPauseClicked(); break;
        case 6: _t->ButtonStopClicked(); break;
        case 7: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject AI_StreamingBufferedAi::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AI_StreamingBufferedAi.data,
      qt_meta_data_AI_StreamingBufferedAi,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AI_StreamingBufferedAi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AI_StreamingBufferedAi::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AI_StreamingBufferedAi.stringdata0))
        return static_cast<void*>(const_cast< AI_StreamingBufferedAi*>(this));
    return QDialog::qt_metacast(_clname);
}

int AI_StreamingBufferedAi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
