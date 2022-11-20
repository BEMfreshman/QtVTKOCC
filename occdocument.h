//
// Created by wenluyang on 2022/11/20.
//

#ifndef QTVIEWBDF_OCCDOCUMENT_H
#define QTVIEWBDF_OCCDOCUMENT_H

// document for OCC to manage data on backend
#include <string>
#include <QString>
#include <memory>
using std::shared_ptr;
using std::string;

namespace MK {
    class AbstractFileReader;
    class FEMInfo;
}

class OCCDocument {

public:

    OCCDocument();
    ~OCCDocument();

    int load(const string& filepath, const string& filename);

protected:

    void clear();

protected:
    string m_strfile;
    string m_strpath;

    MK::AbstractFileReader* m_reader;
    MK::FEMInfo* m_feminfo;
};


#endif //QTVIEWBDF_OCCDOCUMENT_H
