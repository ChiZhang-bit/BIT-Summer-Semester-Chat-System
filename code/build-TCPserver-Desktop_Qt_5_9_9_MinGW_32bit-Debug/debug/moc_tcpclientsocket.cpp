/****************************************************************************
** Meta object code from reading C++ file 'tcpclientsocket.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TCPserver/tcpclientsocket.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpclientsocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_tcpclientsocket_t {
    QByteArrayData data[8];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_tcpclientsocket_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_tcpclientsocket_t qt_meta_stringdata_tcpclientsocket = {
    {
QT_MOC_LITERAL(0, 0, 15), // "tcpclientsocket"
QT_MOC_LITERAL(1, 16, 16), // "sig_updateServer"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 22), // "sig_clientDisconnected"
QT_MOC_LITERAL(4, 57, 12), // "sig_verusers"
QT_MOC_LITERAL(5, 70, 12), // "sig_regusers"
QT_MOC_LITERAL(6, 83, 11), // "receiveData"
QT_MOC_LITERAL(7, 95, 23) // "slot_clientDisconnected"

    },
    "tcpclientsocket\0sig_updateServer\0\0"
    "sig_clientDisconnected\0sig_verusers\0"
    "sig_regusers\0receiveData\0"
    "slot_clientDisconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_tcpclientsocket[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       3,    1,   47,    2, 0x06 /* Public */,
       4,    2,   50,    2, 0x06 /* Public */,
       5,    2,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   60,    2, 0x09 /* Protected */,
       7,    0,   61,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void tcpclientsocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        tcpclientsocket *_t = static_cast<tcpclientsocket *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_updateServer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sig_clientDisconnected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sig_verusers((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->sig_regusers((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->receiveData(); break;
        case 5: _t->slot_clientDisconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (tcpclientsocket::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&tcpclientsocket::sig_updateServer)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (tcpclientsocket::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&tcpclientsocket::sig_clientDisconnected)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (tcpclientsocket::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&tcpclientsocket::sig_verusers)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (tcpclientsocket::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&tcpclientsocket::sig_regusers)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject tcpclientsocket::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_tcpclientsocket.data,
      qt_meta_data_tcpclientsocket,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *tcpclientsocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tcpclientsocket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_tcpclientsocket.stringdata0))
        return static_cast<void*>(this);
    return QTcpSocket::qt_metacast(_clname);
}

int tcpclientsocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void tcpclientsocket::sig_updateServer(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void tcpclientsocket::sig_clientDisconnected(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void tcpclientsocket::sig_verusers(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void tcpclientsocket::sig_regusers(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
