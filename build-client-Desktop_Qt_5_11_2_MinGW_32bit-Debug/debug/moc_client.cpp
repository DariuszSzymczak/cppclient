/****************************************************************************
** Meta object code from reading C++ file 'client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_client_t {
    QByteArrayData data[13];
    char stringdata0[185];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_client_t qt_meta_stringdata_client = {
    {
QT_MOC_LITERAL(0, 0, 6), // "client"
QT_MOC_LITERAL(1, 7, 9), // "loginData"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 11), // "readFortune"
QT_MOC_LITERAL(4, 30, 19), // "on_Register_clicked"
QT_MOC_LITERAL(5, 50, 15), // "getRegisterData"
QT_MOC_LITERAL(6, 66, 15), // "connectToServer"
QT_MOC_LITERAL(7, 82, 13), // "sendLoginData"
QT_MOC_LITERAL(8, 96, 16), // "on_logIn_clicked"
QT_MOC_LITERAL(9, 113, 16), // "sendFileToServer"
QT_MOC_LITERAL(10, 130, 20), // "disconnectFromServer"
QT_MOC_LITERAL(11, 151, 18), // "downloadFromServer"
QT_MOC_LITERAL(12, 170, 14) // "showMainWindow"

    },
    "client\0loginData\0\0readFortune\0"
    "on_Register_clicked\0getRegisterData\0"
    "connectToServer\0sendLoginData\0"
    "on_logIn_clicked\0sendFileToServer\0"
    "disconnectFromServer\0downloadFromServer\0"
    "showMainWindow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_client[] = {

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
       1,    1,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   72,    2, 0x08 /* Private */,
       4,    0,   73,    2, 0x08 /* Private */,
       5,    1,   74,    2, 0x08 /* Private */,
       6,    0,   77,    2, 0x08 /* Private */,
       7,    1,   78,    2, 0x08 /* Private */,
       8,    0,   81,    2, 0x08 /* Private */,
       9,    1,   82,    2, 0x08 /* Private */,
      10,    0,   85,    2, 0x08 /* Private */,
      11,    1,   86,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void,

       0        // eod
};

void client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        client *_t = static_cast<client *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loginData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->readFortune(); break;
        case 2: _t->on_Register_clicked(); break;
        case 3: _t->getRegisterData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: { bool _r = _t->connectToServer();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->sendLoginData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->on_logIn_clicked(); break;
        case 7: _t->sendFileToServer((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 8: _t->disconnectFromServer(); break;
        case 9: _t->downloadFromServer((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 10: _t->showMainWindow(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (client::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&client::loginData)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject client::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_client.data,
      qt_meta_data_client,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *client::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_client.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void client::loginData(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
