#ifndef KEYS_H
#define KEYS_H
#include <QString>
class keys
{
private:
     QString keyID;
     QString imagePath;

public:
    keys(QString keyID = "",QString imagePath="");
    QString getKeyID();
    QString getimagePath();
};

#endif //keys_h
