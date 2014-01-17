#include "miscfunctions.h"

#include <QFile>
#include <QDebug>
#include <qstringlist.h>

const char* MiscFunctions::charEncoding[] = {
    " ", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f",
    "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f",
    "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f",
    "\u007f", "\u007f", "\u007f", "\u00e9", "\u007f", "\u007f", "\u007f", "\u007f",
    "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f",
    "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f",
    "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f",
    "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f",
    "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f",
    "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f",
    "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f",
    "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f",
    "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f",
    "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f",
    "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f",
    "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f",
    "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f",
    "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f",
    "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f",
    "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f",
    "\u007f", "0", "1", "2", "3", "4", "5", "6",
    "7", "8", "9", "!", "?", ".", "-", "\u00b7",
    "\u2026", "\u201c", "\u201d", "\u2018", "\u2019", "\u2642", "\u2640", "$",
    ",", "\u00d7", "/", "A", "B", "C", "D", "E",
    "F", "G", "H", "I", "J", "K", "L", "M",
    "N", "O", "P", "Q", "R", "S", "T", "U",
    "V", "W", "X", "Y", "Z", "a", "b", "c",
    "d", "e", "f", "g", "h", "i", "j", "k",
    "l", "m", "n", "o", "p", "q", "r", "s",
    "t", "u", "v", "w", "x", "y", "z", "\u007f",
    "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f",
    "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f", "\u007f"
};

bool MiscFunctions::loadedSpeciesNames = false;
QString MiscFunctions::speciesNames[388];

bool MiscFunctions::loadedStats = false;
int MiscFunctions::stats[387 * 6];

bool MiscFunctions::loadedGrowth = false;
int MiscFunctions::growth[387];

bool MiscFunctions::loadedExp = false;
int MiscFunctions::exp[100 * 6];

bool MiscFunctions::loadedGender = false;
int MiscFunctions::gender[387];

bool MiscFunctions::loadedMoveNames = false;
QString MiscFunctions::moveNames[355];

const QString MiscFunctions::natureNames[] = {
    "Hardy", "Lonely", "Brave", "Adamant", "Naughty",
    "Bold", "Docile", "Relaxed", "Impish", "Lax",
    "Timid", "Hasty", "Serious", "Jolly", "Naive",
    "Modest", "Mild", "Quiet", "Bashful", "Rash",
    "Calm", "Gentle", "Sassy", "Careful", "Quirky"
};

QString MiscFunctions::decodeString(const QByteArray &bytes)
{
    QString str;
    for (int i = 0; i < bytes.size(); i++) {
        quint8 b = (quint8)bytes[i];
        if (b == 0xFF) {
            return str;
        }
        str += QString::fromUtf8(charEncoding[b]);
    }
    return str;
}

QByteArray MiscFunctions::encodeString(const QString &string, int len)
{
    QByteArray bytes;
    for (int i = 0; i < string.size(); i++) {
        QChar c = string.at(i);
        for (quint8 j = 0; j != 0; j++) {
            if (c == QString::fromUtf8(charEncoding[j]).at(0)) {
                bytes.append(j);
                break;
            }
        }
    }
    for (int i = bytes.size(); i < len; i++) {
        bytes.append(0xFF);
    }
    return bytes;
}

const QString &MiscFunctions::getSpeciesName(int index)
{
    if (!loadedSpeciesNames) {
        QFile file("Data/speciesnames.txt");
        if (file.open(QFile::ReadOnly)) {
            for (int i = 0; i < 388; i++) {
                QByteArray bytes = file.readLine();
                speciesNames[i] = bytes;
                speciesNames[i].remove("\n");
            }
        }
        loadedSpeciesNames = true;
    }
    if (index <= 387) {
        return speciesNames[index];
    } else {
        return speciesNames[0];
    }
}

int MiscFunctions::getStat(int species, int index)
{
    if (!loadedStats) {
        QFile file("Data/stats.txt");
        if (file.open(QFile::ReadOnly)) {
            for (int i = 0; i < 387; i++) {
                QByteArray bytes = file.readLine();
                QString str = bytes;
                QStringList list = str.split(',');
                for (int j = 0; j < 6; j++) {
                    stats[i * 6 + j] = list[j].toInt();
                }
            }
        }
        loadedStats = true;
    }
    if (species <= 386 && index < 6) {
        return stats[species * 6 + index];
    } else {
        return 0;
    }
}

int MiscFunctions::getGrowth(int species)
{
    if (!loadedGrowth) {
        QFile file("Data/growth.txt");
        if (file.open(QFile::ReadOnly)) {
            for (int i = 0; i < 387; i++) {
                QByteArray bytes = file.readLine();
                growth[i] = QString(bytes).remove("\n").toInt();
            }
        }
        loadedGrowth = true;
    }
    if (species <= 386) {
        return growth[species];
    } else {
        return 0;
    }
}

int MiscFunctions::getExp(int level, int growthRate)
{
    if (!loadedExp) {
        QFile file("Data/experience.txt");
        if (file.open(QFile::ReadOnly)) {
            for (int i = 0; i < 100; i++) {
                QByteArray bytes = file.readLine();
                QString str = bytes;
                QStringList list = str.split(',');
                for (int j = 0; j < 6; j++) {
                    exp[i * 6 + j] = list[j].toInt();
                }
            }
        }
        loadedExp = true;
    }
    if (level > 0 && level <= 100 && growthRate < 6) {
        return exp[(level - 1) * 6 + growthRate];
    } else {
        return 0;
    }
}

int MiscFunctions::getLevel(int experience, int growthRate)
{
    if (!loadedExp) {
        QFile file("Data/experience.txt");
        if (file.open(QFile::ReadOnly)) {
            for (int i = 0; i < 100; i++) {
                QByteArray bytes = file.readLine();
                QString str = bytes;
                QStringList list = str.split(',');
                for (int j = 0; j < 6; j++) {
                    exp[i * 6 + j] = list[j].toInt();
                }
            }
        }
        loadedExp = true;
    }
    for (int i = 0; i < 99; i++) {
        if (experience < exp[i * 6 + growthRate]) {
            return i;
        }
    }
    return 100;
}

int MiscFunctions::getGender(int species)
{
    if (!loadedGender) {
        QFile file("Data/gender.txt");
        if (file.open(QFile::ReadOnly)) {
            for (int i = 0; i < 387; i++) {
                QByteArray bytes = file.readLine();
                gender[i] = QString(bytes).remove("\n").toInt();
            }
        }
        loadedGender = true;
    }
    if (species <= 386) {
        return gender[species];
    } else {
        return 0;
    }
}

const QString &MiscFunctions::getMoveName(int index)
{
    if (!loadedMoveNames) {
        QFile file("Data/movenames.txt");
        if (file.open(QFile::ReadOnly)) {
            for (int i = 0; i < 355; i++) {
                QByteArray bytes = file.readLine();
                moveNames[i] = bytes;
                moveNames[i].remove("\n");
            }
        }
        loadedMoveNames = true;
    }
    if (index <= 354) {
        return moveNames[index];
    } else {
        return moveNames[0];
    }
}

const QString &MiscFunctions::getNatureName(int index)
{
    if (index <= 24) {
        return natureNames[index];
    } else {
        return natureNames[0];
    }
}
