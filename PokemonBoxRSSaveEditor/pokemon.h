#ifndef POKEMON_H
#define POKEMON_H

#include <QByteArray>
#include <QString>

class Pokemon
{
public:
    Pokemon();

    struct Move {
        quint16 id;
        quint8 pp;
        quint8 ppUps;
    };

    void loadEncrypted(const QByteArray &bytes, bool boxData);
    void loadByteArray(const QByteArray &bytes, bool boxData);

    int getGender() const;
    bool isShiny() const;
    int getNature() const;
    quint16 getTid() const;
    quint16 getSid() const;
    const QString &getNickname() const;
    const QString &getOtName() const;
    quint16 getSpecies() const;
    int getExp() const;
    int getLevel() const;
    bool isEgg() const;
    const Move &getMove(int index) const;
    int getStat(int index) const;
    quint8 getIv(int index) const;
    quint8 getEv(int index) const;

    QByteArray toByteArray() const;
    const QByteArray &getEncryptedData() const;

private:

    typedef void (Pokemon::*ReadFunc)(QDataStream &);

    void readGrowth(QDataStream &dataStream);
    void readMoves(QDataStream &dataStream);
    void readEVs(QDataStream &dataStream);
    void readMisc(QDataStream &dataStream);

    void reset();

    static const quint16 speciesMap[];

    QByteArray encryptedData;

    quint32 pid;
    quint16 tid;
    quint16 sid;
    QString nickname;
    quint16 language;
    QString otName;
    quint8 mark;
    quint16 checksum;
    quint16 species;
    quint16 heldItem;
    quint32 experience;
    quint8 friendship;
    Move moves[4];
    quint8 evs[6];
    quint8 ivs[6];
    quint8 contest[6];
    quint8 pokerus;
    quint8 metLocation;
    quint8 metLevel;
    quint8 metGame;
    quint8 ball;
    quint8 otGender;
    quint32 ribbons;
    quint8 ability;
    quint8 egg;
    quint16 depositorTid;
    quint16 depositorSid;
};

#endif // POKEMON_H
