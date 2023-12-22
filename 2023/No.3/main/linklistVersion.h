#pragma once
#ifndef QVGEVERSION_H 
#define QVGEVERSION_H 
#include <QVersionNumber> 
#include <QString> 
static QString linklistVersionString("0.6.2");
static QVersionNumber linklistVersion = QVersionNumber::fromString(linklistVersionString);

#endif // QVGEVERSION_H 