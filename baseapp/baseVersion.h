#pragma once
#ifndef QVGEVERSION_H
#define QVGEVERSION_H
#include <QVersionNumber>
static QString baseVersionString("0.6.2");
static QVersionNumber qvgeVersion =
QVersionNumber::fromString(baseVersionString);
#endif // QVGEVERSION_H