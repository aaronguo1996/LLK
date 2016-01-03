/****************************************************************************
** Meta object code from reading C++ file 'finalwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../finalwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'finalwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FinalWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      24,   12,   12,   12, 0x05,
      35,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      48,   12,   12,   12, 0x08,
      59,   12,   12,   12, 0x08,
      72,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FinalWindow[] = {
    "FinalWindow\0\0thisGame()\0nextGame()\0"
    "returnHome()\0goToHome()\0replayGame()\0"
    "goToGame()\0"
};

void FinalWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FinalWindow *_t = static_cast<FinalWindow *>(_o);
        switch (_id) {
        case 0: _t->thisGame(); break;
        case 1: _t->nextGame(); break;
        case 2: _t->returnHome(); break;
        case 3: _t->goToHome(); break;
        case 4: _t->replayGame(); break;
        case 5: _t->goToGame(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData FinalWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FinalWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FinalWindow,
      qt_meta_data_FinalWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FinalWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FinalWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FinalWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FinalWindow))
        return static_cast<void*>(const_cast< FinalWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int FinalWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void FinalWindow::thisGame()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void FinalWindow::nextGame()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void FinalWindow::returnHome()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
