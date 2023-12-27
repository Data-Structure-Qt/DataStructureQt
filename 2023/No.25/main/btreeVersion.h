#pragma once
#ifndef QVGEVERSION_H 
#define QVGEVERSION_H 
#include <QVersionNumber> 
#include <QString> 
static QString btreeVersionString("0.6.2");
static QVersionNumber btreeVersion = QVersionNumber::fromString(btreeVersionString);

#endif // QVGEVERSION_H 