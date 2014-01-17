#ifndef MISCFUNCTIONS_H
#define MISCFUNCTIONS_H

#include <QString>

class MiscFunctions {
public:
    static QString decodeString(const QByteArray &bytes);
    static QByteArray encodeString(const QString &string, int len);
    static const QString &getSpeciesName(int index);
    static int getStat(int species, int index);
    static int getGrowth(int species);
    static int getExp(int level, int growthRate);
    static int getLevel(int experience, int growthRate);
    static int getGender(int species);
    static const QString &getMoveName(int index);
    static const QString &getNatureName(int index);
private:
    static const char* charEncoding[];
    static bool loadedSpeciesNames;
    static QString speciesNames[];
    static bool loadedStats;
    static int stats[];
    static bool loadedGrowth;
    static int growth[];
    static bool loadedExp;
    static int exp[];
    static bool loadedGender;
    static int gender[];
    static bool loadedMoveNames;
    static QString moveNames[];
    static const QString natureNames[];
};
#endif // MISCFUNCTIONS_H
