#pragma once
#ifndef QVGEVERSION_H 
#define QVGEVERSION_H 
#include <QVersionNumber> 
#include <QString> 
static QString paintVersionString("0.6.2");
static QVersionNumber paintVersion =
QVersionNumber::fromString(paintVersionString);
#endif // QVGEVERSION_H