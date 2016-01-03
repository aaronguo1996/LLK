/****************************************************************************
** Meta object code from reading C++ file 'setmenu.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../setmenu.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SetMenu[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      26,    8,    8,    8, 0x05,
      49,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      61,   58,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SetMenu[] = {
    "SetMenu\0\0turnOnMusic(int)\0"
    "setBackground(QString)\0change()\0id\0"
    "buttonGroupChanged(int)\0"
};

void SetMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SetMenu *_t = static_cast<SetMenu *>(_o);
        switch (_id) {
        case 0: _t->turnOnMusic((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setBackground((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->change(); break;
        case 3: _t->buttonGroupChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SetMenu::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SetMenu::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SetMenu,
      qt_meta_data_SetMenu, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SetMenu::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SetMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SetMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SetMenu))
        return static_cast<void*>(const_cast< SetMenu*>(this));
    return QWidget::qt_metacast(_clname);
}

int SetMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void SetMenu::turnOnMusic(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SetMenu::setBackground(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SetMenu::change()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
