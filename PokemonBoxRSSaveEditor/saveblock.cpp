#include "saveblock.h"

#include <QDataStream>
#include <QDebug>

SaveBlock::SaveBlock()
{

}

void SaveBlock::load(QIODevice *device)
{
    QDataStream dataStream(device);
    dataStream.setByteOrder(QDataStream::BigEndian);
    dataStream >> checksumA;
    dataStream >> checksumB;
    dataStream >> index;
    dataStream >> saveCount;
    dataStream.setDevice(0);
    data = device->read(0x1ff0);
    dataStream.setDevice(device);
    dataStream >> footer;
    quint16 checksum = computeChecksum();
    valid = (checksum == checksumA) && ((quint16)(0xF004 - checksum) == checksumB);
}

const QByteArray &SaveBlock::getData() const
{
    return data;
}

quint32 SaveBlock::getIndex() const
{
    return index;
}

quint32 SaveBlock::getSaveCount() const
{
    return saveCount;
}

bool SaveBlock::isValid() const
{
    return valid;
}

quint16 SaveBlock::computeChecksum()
{
    quint16 checksum = (index & 0xFFFF) + (index >> 16) + (saveCount & 0xFFFF) + (saveCount >> 16);
    for (int i = 0; i < data.size() / 2; i++) {
        quint32 word = (quint8)data.at(i * 2);
        word <<= 8;
        word += (quint8)data.at(i * 2 + 1);
        checksum += word;
    }
    return checksum;
}
