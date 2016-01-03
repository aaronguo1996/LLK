/****************************************************************************
** Meta object code from reading C++ file 'gamebutton.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gamebutton.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamebutton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GameButton[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   12,   11,   11, 0x05,
      29,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      43,   11,   11,   11, 0x08,
      50,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GameButton[] = {
    "GameButton\0\0,\0click(int,int)\0send(QString)\0"
    "save()\0sendSignal()\0"
};

void GameButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GameButton *_t = static_cast<GameButton *>(_o);
        switch (_id) {
        case 0: _t->click((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->send((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->save(); break;
        case 3: _t->sendSignal(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GameButton::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GameButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_GameButton,
      qt_meta_data_GameButton, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GameButton::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GameButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GameButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameButton))
        return static_cast<void*>(const_cast< GameButton*>(this));
    return QPushButton::qt_metacast(_clname);
}

int GameButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
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
void GameButton::click(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GameButton::send(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
