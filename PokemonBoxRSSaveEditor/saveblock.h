#ifndef SAVEBLOCK_H
#define SAVEBLOCK_H

#include <QByteArray>
#include <QIODevice>

class SaveBlock
{
public:
    SaveBlock();
    void load(QIODevice *device);
    const QByteArray &getData() const;
    quint32 getIndex() const;
    quint32 getSaveCount() const;
    bool isValid() const;
private:
    quint16 computeChecksum();
    QByteArray data;
    quint16 checksumA;
    quint16 checksumB;
    quint32 index;
    quint32 saveCount;
    quint32 footer;
    bool valid;
};

#endif // SAVEBLOCK_H
