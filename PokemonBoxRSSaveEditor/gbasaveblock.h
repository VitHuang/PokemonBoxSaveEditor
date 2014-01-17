#ifndef GBASAVEBLOCK_H
#define GBASAVEBLOCK_H

#include <QByteArray>
#include <QIODevice>

class GbaSaveBlock
{
public:
    GbaSaveBlock();
    void load(QIODevice *device);
    void save(QIODevice *device) const;
    const QByteArray &getData() const;
    void setData(const QByteArray &data);
    int getLength() const;
    quint32 getIndex() const;
    quint32 getSaveCount() const;
    bool isValid() const;
private:
    quint16 computeChecksum();
    QByteArray data;
    quint16 checksum;
    quint16 index;
    quint32 saveCount;
    quint32 footer;
    bool valid;
    static const int blockSizes[];
};

#endif // GBASAVEBLOCK_H
