#include "gbasaveblock.h"

#include <QDataStream>
#include <QDebug>

const int GbaSaveBlock::blockSizes[] = { 0x0f2c, 0x0f80, 0x0f80, 0x0f80, 0x0f08, 0x0f80, 0x0f80, 0x0f80, 0x0f80, 0x0f80, 0x0f80, 0x0f80, 0x0f80, 0x07d0 };

GbaSaveBlock::GbaSaveBlock()
{
    valid = false;
}

void GbaSaveBlock::load(QIODevice *device)
{
    if (device->atEnd()) {
        return;
    }
    data = device->read(0xff0);
    QDataStream dataStream(device);
    dataStream.setByteOrder(QDataStream::LittleEndian);
    quint32 padding;
    dataStream >> padding;
    dataStream >> index;
    if (index > 13) {
        return;
    }
    data.truncate(getLength());
    dataStream >> checksum;
    dataStream >> footer;
    dataStream >> saveCount;
    quint16 sum = computeChecksum();
    valid = (sum == checksum);
}

void GbaSaveBlock::save(QIODevice *device) const
{
    device->write(data);
    QByteArray padArray(0xff0 - getLength(), 0);
    device->write(padArray);
    QDataStream dataStream(device);
    dataStream.setByteOrder(QDataStream::LittleEndian);
    dataStream << ((quint32)0);
    dataStream << index;
    dataStream << checksum;
    dataStream << footer;
    dataStream << saveCount;
}

const QByteArray &GbaSaveBlock::getData() const
{
    return data;
}

void GbaSaveBlock::setData(const QByteArray &data)
{
    this->data = data;
    checksum = computeChecksum();
}

int GbaSaveBlock::getLength() const
{
    return blockSizes[index];
}

quint32 GbaSaveBlock::getIndex() const
{
    return index;
}

quint32 GbaSaveBlock::getSaveCount() const
{
    return saveCount;
}

bool GbaSaveBlock::isValid() const
{
    return valid;
}

quint16 GbaSaveBlock::computeChecksum()
{
    //QDataStream dataStream(data);
    //dataStream.setByteOrder(QDataStream::LittleEndian);
    quint32 sum = 0;
    quint32 val;
    int length = getLength();
    for (int i = 0; i < length / 4; i++) {
        val = (quint8)data[i * 4 + 3];
        val <<= 8;
        val |= (quint8)data[i * 4 + 2];
        val <<= 8;
        val |= (quint8)data[i * 4 + 1];
        val <<= 8;
        val |= (quint8)data[i * 4];
        sum += val;
    }
    return sum + (sum >> 16);
}
