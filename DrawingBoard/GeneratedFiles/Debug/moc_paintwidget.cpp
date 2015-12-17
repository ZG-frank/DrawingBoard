/****************************************************************************
** Meta object code from reading C++ file 'paintwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../paintwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paintwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PaintWidget_t {
    QByteArrayData data[8];
    char stringdata[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PaintWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PaintWidget_t qt_meta_stringdata_PaintWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "PaintWidget"
QT_MOC_LITERAL(1, 12, 15), // "SetCurrentShape"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 9), // "shapetype"
QT_MOC_LITERAL(4, 39, 15), // "SetCurrentWidth"
QT_MOC_LITERAL(5, 55, 8), // "Penwidth"
QT_MOC_LITERAL(6, 64, 15), // "SetCurrentColor"
QT_MOC_LITERAL(7, 80, 8) // "Pencolor"

    },
    "PaintWidget\0SetCurrentShape\0\0shapetype\0"
    "SetCurrentWidth\0Penwidth\0SetCurrentColor\0"
    "Pencolor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PaintWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       4,    1,   32,    2, 0x0a /* Public */,
       6,    1,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 7,    2,

       0        // eod
};

void PaintWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PaintWidget *_t = static_cast<PaintWidget *>(_o);
        switch (_id) {
        case 0: _t->SetCurrentShape((*reinterpret_cast< shapetype(*)>(_a[1]))); break;
        case 1: _t->SetCurrentWidth((*reinterpret_cast< Penwidth(*)>(_a[1]))); break;
        case 2: _t->SetCurrentColor((*reinterpret_cast< Pencolor(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject PaintWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PaintWidget.data,
      qt_meta_data_PaintWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PaintWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PaintWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PaintWidget.stringdata))
        return static_cast<void*>(const_cast< PaintWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int PaintWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
