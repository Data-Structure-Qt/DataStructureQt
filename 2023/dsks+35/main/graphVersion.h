#pragma once
#ifndef QVGEVERSION_H 
#define QVGEVERSION_H 
#include <QVersionNumber> 
#include <QString> 
static QString graphVersionString("0.6.2");
static QVersionNumber graphVersion = QVersionNumber::fromString(graphVersionString);

#endif // QVGEVERSION_H 