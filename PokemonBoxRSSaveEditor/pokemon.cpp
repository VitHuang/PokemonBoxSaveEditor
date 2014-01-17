#include "pokemon.h"
#include <QDataStream>
#include <QDebug>
#include "miscfunctions.h"

const quint16 Pokemon::speciesMap[] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
    23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43,
    44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64,
    65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85,
    86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105,
    106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122,
    123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139,
    140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156,
    157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173,
    174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190,
    191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207,
    208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224,
    225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241,
    242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 252, 253, 254, 255, 256, 257, 258, 259, 260,
    261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 290, 291,
    292, 276, 277, 285, 286, 327, 278, 279, 283, 284, 320, 321, 300, 301, 352, 343, 344,
    299, 324, 302, 339, 340, 370, 341, 342, 349, 350, 318, 319, 328, 329, 330, 296, 297,
    309, 310, 322, 323, 363, 364, 365, 331, 332, 361, 362, 337, 338, 298, 325, 326, 311,
    312, 303, 307, 308, 333, 334, 360, 355, 356, 315, 287, 288, 289, 316, 317, 357, 293,
    294, 295, 366, 367, 368, 359, 353, 354, 336, 335, 369, 304, 305, 306, 351, 313, 314,
    345, 346, 347, 348, 280, 281, 282, 371, 372, 373, 374, 375, 376, 377, 378, 379, 382,
    383, 384, 380, 381, 385, 386, 358};

Pokemon::Pokemon()
{
    //reset();
}

void Pokemon::loadEncrypted(const QByteArray &bytes, bool boxData)
{
    encryptedData = bytes;
    QDataStream dataStream(bytes);
    dataStream.setByteOrder(QDataStream::LittleEndian);
    dataStream >> pid;
    if (pid == 0) {
        reset();
        return;
    }
    dataStream >> tid;
    dataStream >> sid;
    dataStream.skipRawData(10); // nickname
    dataStream >> language;
    dataStream.skipRawData(7); // ot name
    dataStream >> mark;
    dataStream >> checksum;
    dataStream.skipRawData(2); // padding
    quint32 key = pid ^ tid ^ (sid << 16);
    QByteArray data;
    for (int i = 0; i < 12; i++) {
        quint32 decrypted;
        dataStream >> decrypted;
        decrypted ^= key;
        data.append((char)(decrypted & 0xFF));
        data.append((char)((decrypted >> 8) & 0xFF));
        data.append((char)((decrypted >> 16) & 0xFF));
        data.append((char)((decrypted >> 24) & 0xFF));
    }
    QDataStream decryptedStream(data);
    decryptedStream.setByteOrder(QDataStream::LittleEndian);
    int shuffleVal = pid % 24;
    ReadFunc funcs[] = {&Pokemon::readGrowth, &Pokemon::readMoves, &Pokemon::readEVs, &Pokemon::readMisc};
    (this->*funcs[shuffleVal / 6])(decryptedStream);
    for (int i = (shuffleVal / 6); i < 3; i++) {
        funcs[i] = funcs[i+1];
    }
    (this->*funcs[(shuffleVal / 2) % 3])(decryptedStream);
    for (int i = ((shuffleVal / 2) % 3); i < 2; i++) {
        funcs[i] = funcs[i+1];
    }
    (this->*funcs[shuffleVal % 2])(decryptedStream);
    (this->*funcs[1 - (shuffleVal % 2)])(decryptedStream);
    nickname = MiscFunctions::decodeString(bytes.mid(8, 10));
    otName = MiscFunctions::decodeString(bytes.mid(20, 7));
    if (boxData) {
        dataStream >> depositorTid;
        dataStream >> depositorSid;
    }
}

void Pokemon::loadByteArray(const QByteArray &bytes, bool boxData)
{
    QDataStream dataStream(bytes);
    dataStream.setByteOrder(QDataStream::LittleEndian);
    dataStream >> pid;
    if (pid == 0) {
        reset();
        return;
    }
    dataStream >> tid;
    dataStream >> sid;
    dataStream.skipRawData(10); // nickname
    dataStream >> language;
    dataStream.skipRawData(7); // ot name
    dataStream >> mark;
    dataStream >> checksum;
    dataStream.skipRawData(2); // padding
    readGrowth(dataStream);
    readMoves(dataStream);
    readEVs(dataStream);
    readMisc(dataStream);
    nickname = MiscFunctions::decodeString(bytes.mid(8, 10));
    otName = MiscFunctions::decodeString(bytes.mid(20, 7));
    if (boxData) {
        dataStream >> depositorTid;
        dataStream >> depositorSid;
    }
}

int Pokemon::getGender() const
{
    int genderRate = MiscFunctions::getGender(species);
    if (genderRate == -1) {
        return -1;
    }
    if ((pid & 0xFF) < (genderRate * 32)) {
        return 1;
    } else {
        return 0;
    }
}

bool Pokemon::isShiny() const
{
    return ((pid >> 16) ^ (pid & 0xFFFF) ^ tid ^ sid) < 8;
}

int Pokemon::getNature() const
{
    return pid % 25;
}

quint16 Pokemon::getTid() const
{
    return tid;
}

quint16 Pokemon::getSid() const
{
    return sid;
}

void Pokemon::readGrowth(QDataStream &dataStream)
{
    dataStream >> species;
    species = speciesMap[species];
    dataStream >> heldItem;
    dataStream >> experience;
    quint8 ppUps;
    dataStream >> ppUps;
    for (int i = 0; i < 4; i++) {
        moves[i].ppUps = ppUps & 3;
        ppUps >>= 2;
    }
    dataStream >> friendship;
    dataStream.skipRawData(2); // padding
}

void Pokemon::readMoves(QDataStream &dataStream)
{
    for (int i = 0; i < 4; i++) {
        dataStream >> moves[i].id;
    }
    for (int i = 0; i < 4; i++) {
        dataStream >> moves[i].pp;
    }
}

void Pokemon::readEVs(QDataStream &dataStream)
{
    for (int i = 0; i < 6; i++) {
        dataStream >> evs[i];
    }
    for (int i = 0; i < 6; i++) {
        dataStream >> contest[i];
    }
}

void Pokemon::readMisc(QDataStream &dataStream)
{
    dataStream >> pokerus;
    dataStream >> metLocation;
    quint16 stuff;
    dataStream >> stuff;
    metLevel = stuff & 0x7F;
    metGame = (stuff >> 7) & 0x0F;
    ball = (stuff >> 11) & 0x0F;
    otGender = stuff >> 15;
    quint32 packedIvs;
    dataStream >> packedIvs;
    for (int i = 0; i < 6; i++) {
        ivs[i] = packedIvs & 0x1F;
        packedIvs >>= 5;
    }
    egg = packedIvs & 1;
    ability = packedIvs >> 1;
    dataStream >> ribbons;
}

const QString &Pokemon::getNickname() const
{
    return nickname;
}

const QString &Pokemon::getOtName() const
{
    return otName;
}

quint16 Pokemon::getSpecies() const
{
    return species;
}

int Pokemon::getExp() const
{
    return experience;
}

int Pokemon::getLevel() const
{
    return MiscFunctions::getLevel(experience, MiscFunctions::getGrowth(species));
}

bool Pokemon::isEgg() const
{
    return egg > 0;
}

const Pokemon::Move &Pokemon::getMove(int index) const
{
    return moves[index];
}

int Pokemon::getStat(int index) const
{
    int baseStat = MiscFunctions::getStat(species, index);
    if (baseStat == 1) {
        return 1;
    }
    int level = getLevel();
    if (index == 0) {
        return ((100 + baseStat * 2 + (evs[index] / 4) + ivs[index]) * level) / 100 + 10;
    } else {
        int natureBoost = 10;
        int nature = getNature();
        if ((nature / 5) == (index - 1)) {
            natureBoost += 1;
        }
        if ((nature % 5) == (index - 1)) {
            natureBoost -= 1;
        }
        return ((((baseStat * 2 + (evs[index] / 4) + ivs[index]) * level) / 100 + 5) * natureBoost) / 10;
    }
}

quint8 Pokemon::getIv(int index) const
{
    return ivs[index];
}

quint8 Pokemon::getEv(int index) const
{
    return evs[index];
}

void Pokemon::reset()
{
    pid = 0;
    tid = 0;
    sid = 0;
    nickname = "";
    language = 0;
    otName = "";
    mark = 0;
    checksum = 0;
    species = 0;
    heldItem = 0;
    experience = 0;
    friendship = 0;
    for (int i = 0; i < 4; i++) {
        moves[i].id = 0;
        moves[i].pp = 0;
        moves[i].ppUps = 0;
    }
    for (int i = 0; i < 6; i++) {
        evs[i] = 0;
        ivs[i] = 0;
        contest[i] = 0;
    }
    pokerus = 0;
    metLocation = 0;
    metLevel = 0;
    metGame = 0;
    ball = 0;
    otGender = 0;
    ribbons = 0;
    ability = 0;
    egg = 0;
    depositorTid = 0;
    depositorSid = 0;
}

QByteArray Pokemon::toByteArray() const
{
    QByteArray bytes;
    QDataStream dataStream(&bytes, QIODevice::WriteOnly);
    dataStream.setByteOrder(QDataStream::LittleEndian);
    dataStream << pid;
    dataStream << tid;
    dataStream << sid;
    QByteArray encodedName = MiscFunctions::encodeString(nickname, 10);
    for (int i = 0; i < 10; i++) {
        dataStream << (quint8)encodedName[i];
    }
    dataStream << language;
    QByteArray encodedOtName = MiscFunctions::encodeString(otName, 7);
    for (int i = 0; i < 7; i++) {
        dataStream << (quint8)encodedOtName[i];
    }
    dataStream << mark;
    dataStream << checksum;
    dataStream << (quint16)0;
    quint16 encodedSpecies = 0;
    for (int i = 0; i < 412; i++) {
        if (speciesMap[i] == species) {
            encodedSpecies = i;
        }
    }
    dataStream << encodedSpecies;
    dataStream << heldItem;
    dataStream << experience;
    dataStream << (quint8)(moves[0].ppUps | (moves[1].ppUps << 2) | (moves[2].ppUps << 4) | (moves[3].ppUps << 6));
    dataStream << friendship;
    dataStream << (quint16)0;
    for (int i = 0; i < 4; i++) {
        dataStream << moves[i].id;
    }
    for (int i = 0; i < 4; i++) {
        dataStream << moves[i].pp;
    }
    for (int i = 0; i < 6; i++) {
        dataStream << evs[i];
    }
    for (int i = 0; i < 6; i++) {
        dataStream << contest[i];
    }
    dataStream << pokerus;
    dataStream << metLocation;
    quint16 stuff = otGender;
    stuff <<= 5;
    stuff |= ball;
    stuff <<= 5;
    stuff |= metGame;
    stuff <<= 7;
    stuff |= metLevel;
    dataStream << stuff;
    quint32 packedIvs = (ability << 1) | egg;
    for (int i = 0; i < 6; i++) {
        packedIvs <<= 5;
        packedIvs |= ivs[5 - i];
    }
    dataStream << packedIvs;
    dataStream << ribbons;
    dataStream << depositorTid;
    dataStream << depositorSid;
    return bytes;
}

const QByteArray &Pokemon::getEncryptedData() const
{
    return encryptedData;
}
